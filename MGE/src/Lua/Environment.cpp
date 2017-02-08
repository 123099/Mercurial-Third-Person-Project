#include "Environment.hpp"
#include <stdarg.h>
#include <algorithm>
#include <Lua\LuaUtils.hpp>
#include <Lua\Closure.hpp>
#include <Core\config.hpp>

#pragma region Statics
//Define the static state-script map
std::map<lua_State*, Environment*> Environment::s_stateToScriptMap;

Environment * Environment::StateToScript(lua_State * l_luaState)
{
	if (s_stateToScriptMap.count(l_luaState) > 0)
	{
		return s_stateToScriptMap[l_luaState];
	}
	else
	{
		return nullptr;
	}
}

static const char* s_functionsTableName = "_EnvironmentFunctionsTable";
#pragma endregion

Environment::Environment() : m_luaUtils(std::make_unique<LuaUtils>())
{
	//Initialize a new main state for Lua
	m_luaState = luaL_newstate();

	//Load the Lua libraries
	luaL_openlibs(m_luaState);

	//Create a global table for the functions belonging to this environment
	lua_newtable(m_luaState);

	//Store the new table in the global lua table
	lua_setglobal(m_luaState, s_functionsTableName);
	
	//Register and bind the LuaUtils class to lua
	RegisterLuaType<LuaUtils>("LuaUtils", false);
	BindObject<LuaUtils>(m_luaUtils.get(), "LuaUtils", "luautils");

	//Require the extra utils.lua module by default
	RequireModule("utils", "utils");

	//Bind this script to the lua state that belongs to it
	s_stateToScriptMap.insert(std::pair<lua_State*, Environment*>(m_luaState, this));
}

Environment::~Environment()
{
	lua_close(m_luaState);
}

#pragma region Public members
void Environment::RegisterFunction(lua_CFunction function, const std::string& functionName)
{	
	//Register the function in lua
	lua_register(m_luaState, functionName.c_str(), function);
}

void Environment::RequireModule(const std::string & moduleName, const std::string& bindingName)
{
	//Load module as script
	Closure* module = LoadScriptAsFunction(moduleName);

	//Execute the module
	ExecuteFunction(module, 1);

	//Store the module table returned at the top of the stack in the globals table
	lua_setglobal(m_luaState, bindingName.c_str());
}

Closure * Environment::LoadScriptAsFunction(const std::string & scriptName)
{
	//Pull up the functions table
	lua_getglobal(m_luaState, s_functionsTableName);

	//Create a closure to identify the function
	Closure* closure = new Closure(*this);

	//Push the pointer of the closure to the lua stack to act as a key to the function
	lua_pushlightuserdata(m_luaState, closure);

	//Load the script
	CheckLuaError(luaL_loadfile(m_luaState, (config::MGE_SCRIPTS_PATH + scriptName + ".lua").c_str()));

	//Store the compiled function chunk in the functions table
	lua_settable(m_luaState, -3);

	//Pop the functions table from the stack
	lua_pop(m_luaState, 1);
	
	return closure;
}

void Environment::ExecuteFunction(Closure* closure, int results, char* typesList, ...)
{
	//Make sure the closure is not null, and belongs to this environment
	if (closure != nullptr && &closure->m_ownerEnvironment == this)
	{
		//Push the functions table to the top of the Lua stack
		lua_getglobal(m_luaState, s_functionsTableName);

		//Push the pointer of the closure to the top of the stack to use as key for the function to retrieve
		lua_pushlightuserdata(m_luaState, closure);

		//Retrieve the function from the functions table
		lua_gettable(m_luaState, -2);

		//Remove the functions table from the stack
		lua_remove(m_luaState, -2); 

		//Store parameter count to pass on to the function
		int i = 0;

		//Check that there are variables to pass
		if (typesList[0] != '\0')
		{
			//Create a variable argument list
			va_list variableList;

			//Start retrieving arguments into the variable list after the typesList parameter
			va_start(variableList, typesList);

			//Go through the parameters provided in the ellipsis operator following the list of types provided in the char array
			//in the form of i(int), f(float), s(string)
			for (i = 0; typesList[i] != '\0'; ++i)
			{
				switch (typesList[i])
				{
				case 'i':
					lua_pushinteger(m_luaState, va_arg(variableList, int));
					break;
				case 'f':
					lua_pushnumber(m_luaState, va_arg(variableList, double));
					break;
				case 's':
					lua_pushstring(m_luaState, va_arg(variableList, char*));
					break;
				}
			}

			//End the retrieval for facilitated return?
			va_end(variableList);
		}

		//Invoke the function
		CheckLuaError(lua_pcall(m_luaState, i, results, 0));
	}
}

void Environment::ExecuteCode(const std::string & code)
{
	luaL_dostring(m_luaState, code.c_str());
}

void Environment::StepCoroutines()
{
	//Step the coroutines in LuaUtils using our current state as the resuming state
	m_luaUtils->StepCoroutines(m_luaState);
}

#pragma endregion

void Environment::CheckLuaError(int error)
{
	if (error != LUA_OK)
	{
		std::cerr << lua_tostring(m_luaState, -1) << '\n';
	}
}