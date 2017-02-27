#include "Application.hpp"
#include <Utils\glm.hpp>
#include <iostream>
#include <string>

#include <Core\Time.hpp>
#include <Core\Mesh.hpp>
#include <Core\Scene.hpp>
#include <Core\config.hpp>
#include <Core\Material.hpp>
#include <Core\GameObject.hpp>

#include <Managers\Renderer.hpp>
#include <Managers\SceneManager.hpp>
#include <Managers\LightManager.hpp>

#include <Importers\ObjImporter.hpp>
#include <Importers\MaterialImporter.hpp>

#include <Behaviours\Light.hpp>
#include <Behaviours\Skybox.hpp>
#include <Behaviours\Camera.hpp>
#include <Behaviours\Terrain.hpp>
#include <Behaviours\Transform.hpp>
#include <Behaviours\MeshRenderer.hpp>
#include <Behaviours\FreeLookCamera.hpp>
#include <Behaviours\BehaviourAttributes.hpp>

#include <Game\Behaviours\RotatingBehaviour.hpp>
#include <Game\Behaviours\WobbleBehaviour.hpp>
#include <Game\Behaviours\Flashlight.hpp>
#include <Game\Behaviours\QuitBehaviour.hpp>
#include <Game\Behaviours\CameraOrbit.hpp>
#include <Game\Behaviours\KeysBehaviour.hpp>

#include <Input\Input.hpp>

#include <Utils\DebugHud.hpp>
#include <Utils\Cursor.hpp>
#include <Utils\Profiler.hpp>

#include <Textures\CubeMap.hpp>

#include <Lua\LevelImporter.hpp>

void Application::Initialize() 
{
    AbstractGame::Initialize();

	SetFPSLimit(60);
	Cursor::Instance().SetCursorMode(Cursor::Mode::LockedAndCentered);
	Cursor::Instance().SetCursorVisible(false);
	Renderer::Instance().SetClearColor(0.5, 0, 0);

	std::cout << "Initializing HUD" << '\n';
	m_hud = new DebugHud(m_window.get());
	std::cout << "HUD initialized." << '\n' << '\n';
}

int hudVerts;
int hudTris;

#include <bullet\btBulletDynamicsCommon.h>
#include <Physics\Physics.hpp>
#include <Behaviours\SphereCollider.hpp>
#include <Behaviours\BoxCollider.hpp>
#include <Behaviours\CapsuleCollider.hpp>
#include <Behaviours\Rigidbody.hpp>
#include <Behaviours\PlayerInput.hpp>

void Application::InitializeScene()
{
	InitSceneLighting();

	GameObject* quitter = SceneManager::Instance().GetActiveScene()->CreateGameObject("Quit");
	quitter->AddBehaviour<QuitBehaviour>();

	Physics::Instance().SetGravity(glm::vec3(0, -10, 0));
}

void Application::Render() 
{
    AbstractGame::Render();
    UpdateHud();
}

void Application::InitSceneLighting()
{
	Scene* scene = SceneManager::Instance().CreateScene("Main Scene");

	CubeMap* cubeMap = new CubeMap();
	cubeMap->SetCubeFaces(config::MGE_TEXTURES_PATH + "skybox/SunSet/", ".png");

	GameObject* skyboxObject = SceneManager::Instance().GetActiveScene()->CreateGameObject("SkyBox");
	Skybox* skybox = skyboxObject->AddBehaviour<Skybox>();
	skybox->SetSkyboxCubeMap(cubeMap);
	skybox->SetExposure(5);

	Material* litMaterial = MaterialImporter::LoadMaterial("lit");
	litMaterial->SetTexture("environmentMap", cubeMap);

	LevelImporter::LoadLevel("Level2");

	for (const auto& rootGameObject : SceneManager::Instance().GetActiveScene()->GetRootGameObjects())
	{
		auto sceneGraph = rootGameObject->GetTransform()->GetAllChildrenRecursively();
		sceneGraph.push_back(rootGameObject->GetTransform());
		for (auto child : sceneGraph)
		{
			if (child->GetGameObject()->GetBehaviour<MeshRenderer>() != nullptr && child->GetGameObject()->GetBehaviour<MeshRenderer>()->GetSharedMesh() != nullptr)
			{
				hudVerts += child->GetGameObject()->GetBehaviour<MeshRenderer>()->GetSharedMesh()->GetVertexCount();
				hudTris += child->GetGameObject()->GetBehaviour<MeshRenderer>()->GetSharedMesh()->GetTriangleCount();
			}
		}
	}
}

sf::Clock c;

//This reduces FPS by around 1-2
void Application::UpdateHud() {
	if (c.getElapsedTime().asSeconds() > 0.12f)
	{
		std::string debugInfo = "";
		debugInfo += "FPS: " + std::to_string((int)Time::s_frameRate) + "\n";
		debugInfo += "Vertices: " + std::to_string(hudVerts) + "\n";
		debugInfo += "Triangles: " + std::to_string(hudTris) + "\n";
		debugInfo += Profiler::Instance().GetAllSampleDataAsString();

		m_hud->setDebugInfo(debugInfo);

		c.restart();
	}
    m_hud->draw();
}
