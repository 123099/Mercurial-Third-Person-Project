#include "LuaUtils.hpp"
#include <Time.hpp>
#include <string>

#pragma region Public members

void LuaUtils::CheckParameterCount(lua_State* l_luaState, int expectedCount)
{
	//Get the current amount of parameters from the provided state
	int parameterCount = lua_gettop(l_luaState);

	//Make sure there are enough parameters
	if (parameterCount < expectedCount)
	{
		DisplayError(l_luaState, "Wrong parameter count! Expected " + std::to_string(expectedCount) + ", got " + std::to_string(parameterCount));
	}
}

void LuaUtils::DisplayError(lua_State* l_luaState, const std::string & errorMessage)
{
	//Push the error message to the stack
	lua_pushstring(l_luaState, errorMessage.c_str());

	//Tell lua to display the error
	lua_error(l_luaState);
}

void LuaUtils::StepCoroutines(lua_State* l_resumingState) 
{
	//Go through all the coroutines being tracked and resume them
	for (auto itr = m_coroutines.begin(), end = m_coroutines.end(); itr != end; ++itr)
	{
		//Resume the coroutine
		int executionResult = lua_resume(*itr, l_resumingState, 0);

		//If the coroutine finished its execution and is no longer in a yielded state, remove it from the vector
		if (executionResult == LUA_OK)
		{
			m_coroutines.erase(itr);

			//Decrement the iterator to prevent skipping an element
			--itr;
		}
	}
}
#pragma endregion

#pragma region Lua Function Wrappers
static const luaL_Reg functions[]
{
	{"startcoroutine", lua_asmethod<LuaUtils, &LuaUtils::AddCoroutine>},
	{"getgametime", lua_asmethod<LuaUtils, &LuaUtils::GetGameTime>},
	{nullptr, nullptr}
};

const luaL_Reg * LuaUtils::GetFunctionList()
{
	return functions;
}

int LuaUtils::AddCoroutine(lua_State * l_luaState)
{
	//Check the parameter count
	CheckParameterCount(l_luaState, 1);

	//Make sure the parameter is a function
	if (lua_isfunction(l_luaState, -1) == false)
	{
		DisplayError(l_luaState, "Wrong parameter type! Expected function.");
	}

	//Create a new coroutine
	lua_State* coroutine = lua_newthread(l_luaState);

	//Push the function to the top of the state stack
	lua_pushvalue(l_luaState, -2);

	//Transfer the function from the top of the state stack to the top of the coroutine stack
	lua_xmove(l_luaState, coroutine, 1);

	//Start the coroutine
	int executionResult = lua_resume(coroutine, l_luaState, 0);

	//If the coroutine is in a yielded state, add it to the coroutine list to resume it on update
	if (executionResult == LUA_YIELD)
	{
		m_coroutines.push_back(coroutine);
	}

	//Return the lua_State coroutine to lua
	return 1;
}

int LuaUtils::GetGameTime(lua_State * l_luaState)
{
	//Push the game time to lua
	lua_pushnumber(l_luaState, Time::s_gameTime);

	return 1;
}
#pragma endregion
