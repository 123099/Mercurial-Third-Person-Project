#include <Game\Behaviours\NPC.hpp>
#include <Core\GameObject.hpp>
#include <Behaviours\Transform.hpp>
#include <Game\Behaviours\Player.hpp>
#include <Behaviours\Lua\LuaEnvironment.hpp>
#include <Behaviours\MeshRenderer.hpp>
#include <Textures\Texture.hpp>
#include <Input\Input.hpp>
#include <Utils\glm.hpp>
#include <string>

void NPC::SetID(int ID)
{
	m_ID = ID;
}

void NPC::SetInteractble(bool interactble)
{
	m_isInteractble = interactble;
}

void NPC::SetRunEveryFrame(bool runEveryFrame)
{
	m_runEveryFrame = runEveryFrame;
}

void NPC::Awake()
{
	LuaEnvironment::GetLua()->RegisterType<NPC>("NPC");
	LuaEnvironment::GetLua()->BindObject<NPC>(this, "NPC", "npc" + std::to_string(m_ID));

	m_script = m_gameObject->GetBehaviour<LuaScript>();
	m_script->SetScript("npcs/" + std::to_string(m_ID));
}

void NPC::Update()
{
	if (m_runEveryFrame == true && m_isInteractble == false)
	{
		StartInteraction();
	}
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

int NPC::GetPosition(lua_State * luaState)
{
	//Get the world position
	const glm::vec3 worldPosition = m_gameObject->GetTransform()->GetWorldPosition();

	//Push the x,y,z world coordinates to lua
	lua_pushnumber(luaState, worldPosition.x);
	lua_pushnumber(luaState, worldPosition.y);
	lua_pushnumber(luaState, worldPosition.z);

	return 3;
}

int NPC::SetEnabled(lua_State * luaState)
{
	//Retrieve whether enabled or not
	const bool isInteractble = (bool)lua_toboolean(luaState, 1);

	SetInteractble(isInteractble);

	return 0;
}

int NPC::IsEnabled(lua_State * luaState)
{
	//Push whether npc is interactable
	lua_pushboolean(luaState, m_isInteractble);

	return 1;
}

int NPC::SwapTexture(lua_State * luaState)
{
	//Retrieve the texture file name
	const std::string textureFile = luaL_checkstring(luaState, 1);

	//Swap the texture if the npc has a material
	MeshRenderer* meshRenderer = m_gameObject->GetBehaviour<MeshRenderer>();
	if (meshRenderer != nullptr)
	{
		Material* material = meshRenderer->GetMaterial();
		if (material != nullptr)
		{
			material->SetTexture("diffuseTexture", Texture::Load(textureFile, false));
		}
	}

	return 0;
}

static const luaL_Reg functions[]
{
	{"gettransform", lua_asmethod<NPC, &NPC::GetTransform>},
	{"destroy", lua_asmethod<NPC, &NPC::DestroySelf> },
	{"getposition", lua_asmethod<NPC, &NPC::GetPosition>},
	{"setenabled", lua_asmethod<NPC, &NPC::SetEnabled>},
	{"isenabled", lua_asmethod<NPC, &NPC::IsEnabled>},
	{"swaptexture", lua_asmethod<NPC, &NPC::SwapTexture>},
	{NULL, NULL}
};

const luaL_Reg * NPC::GetFunctionList()
{
	return functions;
}
