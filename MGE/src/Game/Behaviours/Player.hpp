#pragma once
#include <Behaviours\AbstractBehaviour.hpp>
#include <LuaAPI\lua.hpp>

class Player final : public AbstractBehaviour
{
public:
	void Awake() override final;

	void SetHasKeyCode(bool hasKeyCode);
	bool HasKeyCode();

	void SetHasDragon(bool hasDragon);
	bool HasDragon();

	void Teleport(float x, float y, float z);

	int SetHasKeyCode(lua_State* luaState);
	int HasKeyCode(lua_State* luaState);

	int SetHasDragon(lua_State* luaState);
	int HasDragon(lua_State* luaState);

	int Teleport(lua_State* luaState);

	static const luaL_Reg* GetFunctionList();
private:
	bool m_hasKeyCode;
	bool m_hasDragon;
};