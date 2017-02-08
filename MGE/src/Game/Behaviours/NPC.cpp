#include <Game\Behaviours\NPC.hpp>
#include <Core\GameObject.hpp>
#include <Behaviours\Transform.hpp>
#include <Game\Behaviours\Player.hpp>
#include <Behaviours\Lua\LuaEnvironment.hpp>
#include <Input\Input.hpp>
#include <Utils\glm.hpp>
#include <string>

void NPC::SetID(int ID)
{
	m_ID = ID;
}

void NPC::Awake()
{
	LuaEnvironment::GetLua()->RegisterType<NPC>("NPC");
	LuaEnvironment::GetLua()->BindObject<NPC>(this, "NPC", "npc" + std::to_string(m_ID));

	m_script = m_gameObject->GetBehaviour<LuaScript>();
	m_script->SetScript("npcs/" + std::to_string(m_ID));
}

void NPC::StartInteraction()
{
	m_script->Execute();
}

int NPC::GetTransform(lua_State * luaState)
{
	//Push the transform as a light user data
	lua_pushlightuserdata(luaState, m_gameObject->GetTransform());

	return 1;
}

int NPC::DestroySelf(lua_State * luaState)
{
	GameObject::Destroy(m_gameObject);

	return 0;
}

static const luaL_Reg functions[]
{
	{"gettransform", lua_asmethod<NPC, &NPC::GetTransform>},
	{"destroy", lua_asmethod<NPC, &NPC::DestroySelf> },
	{NULL, NULL}
};

const luaL_Reg * NPC::GetFunctionList()
{
	return functions;
}
