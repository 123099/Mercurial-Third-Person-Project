#pragma once
#include <Behaviours\AbstractBehaviour.hpp>
#include <Behaviours\BehaviourAttributes.hpp>
#include <Behaviours\Lua\LuaScript.hpp>
#include <LuaAPI\lua.hpp>

class Transform;

class NPC final : public AbstractBehaviour, public RequireBehaviours<LuaScript>
{
public:
	void SetID(int ID);

	void Awake() override final;

	void StartInteraction();

	int GetTransform(lua_State* luaState);
	int DestroySelf(lua_State* luaState);
	static const luaL_Reg* GetFunctionList();
private:
	int m_ID;
	LuaScript* m_script;
};