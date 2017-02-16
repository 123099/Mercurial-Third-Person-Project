#include <Behaviours\Lua\LuaEnvironment.hpp>
#include <Managers\SceneManager.hpp>
#include <Core\GameObject.hpp>
#include <Core\Scene.hpp>
#include <Lua\Script.hpp>

LuaEnvironment * LuaEnvironment::GetLua()
{
	//Try to find a lua environment in the scene
	LuaEnvironment* environment = GameObject::FindObjectOfType<LuaEnvironment>();
	
	//If nothing was found, create a new environment
	if (environment == nullptr)
	{
		GameObject* envGO = SceneManager::Instance().GetActiveScene()->CreateGameObject("LuaEnvironment");
		environment = envGO->AddBehaviour<LuaEnvironment>();
	}

	if (environment->m_environment == nullptr)
	{
		environment->m_environment = std::make_unique<Environment>();
	}

	return environment;
}

void LuaEnvironment::Awake()
{
	if (m_environment == nullptr)
	{
		m_environment = std::make_unique<Environment>();
	}
}

void LuaEnvironment::Update()
{
	m_environment->StepCoroutines();
}

Script* LuaEnvironment::LoadScript(const std::string & scriptName)
{
	if (m_environment == nullptr)
	{
		Awake();
	}

	return new Script(*m_environment, scriptName);
}
