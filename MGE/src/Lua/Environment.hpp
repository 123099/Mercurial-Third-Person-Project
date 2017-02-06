#pragma once
#include <LuaAPI\lua.hpp>
#include <Lua\LuaUtils.hpp>
#include <string>
#include <cassert>
#include <map>
#include <iostream>
#include <vector>
#include <memory>

class Closure;

inline void lua_stackdump(lua_State* l)
{
	int i;
	int top = lua_gettop(l);

	printf("--Total in stack %d--\n", top);

	for (i = top; i >= 1; --i)
	{  /* repeat for each level */
		printf("[%d|%d] ", -(top - i) - 1, i);
		int t = lua_type(l, i);
		switch (t) {
		case LUA_TSTRING:  /* strings */
			printf("string: '%s'", lua_tostring(l, i));
			break;
		case LUA_TBOOLEAN:  /* booleans */
			printf("boolean %s", lua_toboolean(l, i) ? "true" : "false");
			break;
		case LUA_TNUMBER:  /* numbers */
			printf("number: %g", lua_tonumber(l, i));
			break;
		default:  /* other values */
			printf("%s", lua_typename(l, t));
			break;
		}
		printf("\n");
	}
	printf("\n");  /* end the listing */
}

#pragma region Lua Templated Helpers

//Helper method that defines general garbage collection for all c++ objects
template <typename T>
int GCMethod(lua_State* l_luaState)
{
	//Get the pointer to the c++ instance
	T* instance = lua_checkType<T>(l_luaState, 1);

	//Set the registry of this pointer to nil
	lua_pushlightuserdata(l_luaState, instance);
	lua_pushnil(l_luaState);
	lua_settable(l_luaState, LUA_REGISTRYINDEX);

	//Set the metatable of the instance to nil
	lua_pushnil(l_luaState);
	lua_setmetatable(l_luaState, -2);

	//Delete the instance from c++
	delete instance;

	return 0;
}

#pragma endregion

class Environment
{
public:
	static Environment* StateToScript(lua_State* l_luaState);

	Environment();

	//Registers a C++ object type with Lua. Instances of the type can then be passed to lua or created within lua if a Create method is specified
	template <typename T>
	void RegisterLuaType(const std::string& typeName, bool allowGC = true)
	{
		//Check if the type is already registered
		bool metaTableExists = luaL_getmetatable(m_luaState, typeName.c_str());

		if (metaTableExists == false)
		{
			//Create a new metatable for the type
			luaL_newmetatable(m_luaState, typeName.c_str());

			//Retrieve all the functions of the specified type
			const luaL_Reg* typeFunctions = T::GetFunctionList();

			//Register the functions to the metatable just created
			luaL_setfuncs(m_luaState, typeFunctions, 0);

			if (allowGC == true)
			{
				//Register the garbage collection method
				lua_pushcfunction(m_luaState, GCMethod<T>);

				//Metatable['__gc'] = GCMethod<T>
				lua_setfield(m_luaState, -2, "__gc");
			}

			//Push a copy of the metatable to the top of the stack
			lua_pushvalue(m_luaState, -1);

			//Set the __index field of the metatable point to itself
			lua_setfield(m_luaState, -2, "__index");

			//Expose the metatable to lua under the name of the class type
			lua_setglobal(m_luaState, typeName.c_str());
		}
	}

	//Passes an instance of a registered type with lua to lua by leaving it on top of the lua stack
	//If the binding name is an empty string, the function will leave the userdata at the top of the stack
	template <typename T>
	void BindObject(T* instance, const std::string& typeName, const std::string& bindingName = "")
	{
		//Retrieve the meta table for the type
		bool metaTableExists = luaL_getmetatable(m_luaState, typeName.c_str());
		
		//If the metatable doesn't exist, the type isn't registered, so no way of binding the type
		if (metaTableExists == false)
		{
			std::cerr << "The type " << typeName << " was not registered. Cannot bind an instance of it to lua!" << '\n';
			return;
		}

		//Check if the instance is already bound
		lua_pushlightuserdata(m_luaState, (void*)instance);
		lua_gettable(m_luaState, LUA_REGISTRYINDEX); //Retrieves Registry[instancePtr]
		
		//Define the user data pointer pointer
		T** p_p_type = nullptr;

		if (lua_isnil(m_luaState, -1))
		{
			//Create memory location for the instance
			p_p_type = (T**)lua_newuserdata(m_luaState, sizeof(T*));

			//Push the instance pointer to act as key in the registry table
			lua_pushlightuserdata(m_luaState, (void*)instance);

			//Push a copy of the user data (to be popped by the settable function)
			lua_pushvalue(m_luaState, -2);

			//Store the new user data in the registry for later access
			lua_settable(m_luaState, LUA_REGISTRYINDEX);
		}
		else
		{
			//Retrieve the pointer of the instance from the stack
			p_p_type = (T**)lua_touserdata(m_luaState, -1);
		}
		
		//Store the instance at the new memory location
		*p_p_type = instance;

		//Push the metatable of the type to the top of the stack
		luaL_getmetatable(m_luaState, typeName.c_str());
		
		//Set the type metatable as the metatable of the instance userdata
		lua_setmetatable(m_luaState, -2);
		
		//If the binding name was specified, bind the user data to the binding name and clear the stack
		if (bindingName != "")
		{
			//Set the instance userdata to the global variable named bindingName
			lua_setglobal(m_luaState, bindingName.c_str());

			//Clear the stack
			lua_settop(m_luaState, 0);
		}
		else
		{
			//Clear the stack
			lua_settop(m_luaState, 0);

			//Push the userdata to the top
			lua_pushlightuserdata(m_luaState, (void*)instance);
			lua_gettable(m_luaState, LUA_REGISTRYINDEX);
		}
	}
	void RegisterFunction(lua_CFunction function, const std::string& functionName);

	void RequireModule(const std::string& moduleName, const std::string& bindingName);
	Closure* LoadScriptAsFunction(const std::string& scriptName);
	void ExecuteFunction(Closure* closure, int results = 0, char* typesList = "", ...);
	void ExecuteCode(const std::string& code);

	void CheckLuaError(int error);

	void StepCoroutines();

	virtual ~Environment();
private:
	static std::map<lua_State*, Environment*> s_stateToScriptMap;
	lua_State* m_luaState;

	std::unique_ptr<LuaUtils> m_luaUtils;
};
