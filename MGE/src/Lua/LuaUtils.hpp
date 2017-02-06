#pragma once

#include <LuaAPI\lua.hpp>
#include <vector>
#include <iostream>

//Helper method that retrieves the instance from the lua stack and calls the member function of the instance
template <typename T, int(T::*Function)(lua_State*)>
int lua_asmethod(lua_State* l_luaState)
{
	//Get the instance type from the top of the stack ("__self")
	T* typeInstance = lua_checkType<T>(l_luaState, 1);

	//Remove the self instance from the lua stack
	lua_remove(l_luaState, 1);

	//Call the specified function from the instance
	return ((*typeInstance).*Function)(l_luaState);
}

//Helper method that retrieves the instance of the type from the top of the lua stack
//If the type name is an empty string, the function will assume that the correct user data type is at the top of the stack
template <typename T>
T* lua_checkType(lua_State* l_luaState, int index, const std::string& typeName = "")
{
	void* userdata = nullptr;

	if (typeName != "")
		userdata = luaL_checkudata(l_luaState, index, typeName.c_str());
	else
		userdata = lua_touserdata(l_luaState, index);

	if (userdata == nullptr)
	{
		std::cerr << "The " << typeName << " userdata at index " << index << " is null!" << '\n';
		return nullptr;
	}
	else
	{
		return *(T**)userdata;
	}
}

class LuaUtils
{
public:
	static void CheckParameterCount(lua_State* l_luaState, int expectedCount);
	static void DisplayError(lua_State* l_luaState, const std::string& errorMessage);

	void StepCoroutines(lua_State* l_resumingState);

	static const luaL_Reg* GetFunctionList();
	int AddCoroutine(lua_State* l_luaState);
	int GetGameTime(lua_State* l_luaState);


private:
	std::vector<lua_State*> m_coroutines;
};

