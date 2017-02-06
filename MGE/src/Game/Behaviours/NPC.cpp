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

	Player* player = GameObject::FindObjectOfType<Player>();
	if (player != nullptr)
	{
		m_player = player->GetGameObject()->GetTransform();
	}

	m_script = m_gameObject->GetBehaviour<LuaScript>();
	m_script->SetScript("npcs/" + std::to_string(m_ID));
}

void NPC::Update()
{
	if (Input::IsKeyPressed(sf::Keyboard::F))
	{
		if (glm::distance(m_gameObject->GetTransform()->GetWorldPosition(), m_player->GetWorldPosition()) < 2.5f)
		{
			m_script->Execute();
		}
	}
}

int NPC::DestroySelf(lua_State * luaState)
{
	GameObject::Destroy(m_gameObject);

	return 0;
}

static const luaL_Reg functions[]
{
	{"destroy", lua_asmethod<NPC, &NPC::DestroySelf> },
	{NULL, NULL}
};

const luaL_Reg * NPC::GetFunctionList()
{
	return functions;
}
