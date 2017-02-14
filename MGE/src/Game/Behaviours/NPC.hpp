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
	void SetInteractble(bool interactble);
	void SetRunEveryFrame(bool runEveryFrame);

	void Awake() override final;
	void Update() override final;

	void StartInteraction();

	static const luaL_Reg* GetFunctionList();

	int GetTransform(lua_State* luaState);
	int DestroySelf(lua_State* luaState);

	int GetPosition(lua_State* luaState);

	int SetEnabled(lua_State* luaState);
	int IsEnabled(lua_State* luaState);

	int SwapTexture(lua_State* luaState);
private:
	int m_ID;
	LuaScript* m_script;

	bool m_isInteractble;
	bool m_runEveryFrame;
};