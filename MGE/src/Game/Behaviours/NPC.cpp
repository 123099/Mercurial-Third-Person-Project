#include <Game\Behaviours\NPC.hpp>
#include <Core\GameObject.hpp>

#include <Behaviours\Transform.hpp>
#include <Behaviours\Lua\LuaEnvironment.hpp>
#include <Behaviours\MeshRenderer.hpp>

#include <Game\Behaviours\Player.hpp>
#include <Game\Behaviours\Elevator.hpp>
#include <Game\Behaviours\TranslationAnimation.hpp>

#include <Importers\ObjImporter.hpp>

#include <Textures\Texture.hpp>
#include <Managers\SceneManager.hpp>
#include <Core\Scene.hpp>
#include <Utils\glm.hpp>
#include <Core\config.hpp>
#include <string>

#include <Utils\StringUtils.hpp>
#include <experimental\filesystem>

namespace fs = std::experimental::filesystem;

static std::string GetNpcScriptPath(int npcID)
{
	const fs::path npcScriptsPath(config::MGE_SCRIPTS_PATH + "npcs/");
	for (fs::directory_iterator dir(npcScriptsPath), end; dir != end; ++dir)
	{
		const fs::path path = dir->path();
		const std::string fileNameStem = path.stem().string();
		const std::vector<std::string> split = StringUtils::Split(fileNameStem, '_');
		if (split[0] == std::to_string(npcID))
		{
			return "npcs/" + fileNameStem;
		}
	}
	
	return "npcs/";
}

void NPC::Awake()
{
	LuaEnvironment::GetLua()->RegisterType<NPC>("NPC");
	LuaEnvironment::GetLua()->BindObject<NPC>(this, "NPC", "npc" + std::to_string(m_ID));
	
	m_script = m_gameObject->GetBehaviour<LuaScript>();
	m_script->SetScript(GetNpcScriptPath(m_ID));
}

void NPC::Update()
{
	if (m_runEveryFrame == true)
	{
		StartInteraction();
	}
}

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
	SceneManager::Instance().GetActiveScene()->DestroyGameObject(m_gameObject);

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

int NPC::SwapMesh(lua_State * luaState)
{
	//Retrieve the mesh name
	const std::string meshName = luaL_checkstring(luaState, 1);

	//Swap the mesh if the npc has a mesh renderer
	MeshRenderer* meshRenderer = m_gameObject->GetBehaviour<MeshRenderer>();
	if (meshRenderer != nullptr)
	{
		meshRenderer->SetSharedMesh(ObjImporter::LoadObj(meshName));
	}

	return 0;
}

int NPC::DistanceTo(lua_State * luaState)
{
	//Retrieve the player
	Player* player = (Player*)lua_checkType<Player>(luaState, 1);

	//Get distance to player
	float distance = glm::distance(m_gameObject->GetTransform()->GetWorldPosition(), player->GetGameObject()->GetTransform()->GetWorldPosition());

	//Push distance to lua
	lua_pushnumber(luaState, distance);

	return 1;
}

int NPC::Translate(lua_State * luaState)
{
	//Get translation component
	TranslationAnimation* animation = m_gameObject->GetBehaviour<TranslationAnimation>();

	if (animation != nullptr)
	{
		//Get distance to travel
		const float distance = (float)luaL_checknumber(luaState, 1);

		//Get NPC to travel to
		const NPC* npc = (NPC*)lua_checkType<NPC>(luaState, 2);

		//Get travel time
		const float movementTime = (float)luaL_checknumber(luaState, 3);

		//Start translation
		animation->MoveTowards(distance, npc->GetGameObject()->GetTransform(), movementTime);
	}

	return 0;
}

int NPC::MoveElevatorToPointA(lua_State * luaState)
{
	Elevator* elevator = m_gameObject->GetBehaviour<Elevator>();
	if (elevator != nullptr)
	{
		elevator->GoToPointA();
	}

	return 0;
}

int NPC::MoveElevatorToPointB(lua_State * luaState)
{
	Elevator* elevator = m_gameObject->GetBehaviour<Elevator>();
	if (elevator != nullptr)
	{
		elevator->GoToPointB();
	}

	return 0;
}

static const luaL_Reg functions[]
{
	{"gettransform", lua_asmethod<NPC, &NPC::GetTransform>},
	{"open", lua_asmethod<NPC, &NPC::DestroySelf> },
	{"destroyself", lua_asmethod<NPC, &NPC::DestroySelf> },
	{"getposition", lua_asmethod<NPC, &NPC::GetPosition>},
	{"setenabled", lua_asmethod<NPC, &NPC::SetEnabled>},
	{"isenabled", lua_asmethod<NPC, &NPC::IsEnabled>},
	{"settexture", lua_asmethod<NPC, &NPC::SwapTexture>},
	{"setmesh", lua_asmethod<NPC, &NPC::SwapMesh>},
	{"distanceTo", lua_asmethod<NPC, &NPC::DistanceTo>},
	{"translate", lua_asmethod<NPC, &NPC::Translate>},
	{"elevatorpointa", lua_asmethod<NPC, &NPC::MoveElevatorToPointA>},
	{ "elevatorpointb", lua_asmethod<NPC, &NPC::MoveElevatorToPointB> },
	{NULL, NULL}
};

const luaL_Reg * NPC::GetFunctionList()
{
	return functions;
}
