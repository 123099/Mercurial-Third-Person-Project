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

	Cursor::Instance().SetCursorMode(Cursor::Mode::LockedAndCentered);
	Cursor::Instance().SetCursorVisible(false);
	Renderer::Instance().SetClearColor(0.5, 0, 0);

	std::cout << "Initializing HUD" << '\n';
	m_hud = new DebugHud(m_window.get());
	std::cout << "HUD initialized." << '\n' << '\n';
}

int hudVerts;
int hudTris;
#include <Audio\AudioClip.hpp>
#include <Behaviours\AudioSource.hpp>
#include <Behaviours\AudioListener.hpp>
#include <Behaviours\SphereCollider.hpp>
#include <Game\Behaviours\Player.hpp>
void Application::InitializeScene()
{
	InitSceneLighting();

	AudioClip* ac = AudioClip::Load("test.wav", true, false);
	AudioClip* ac2 = AudioClip::Load("test.wav", true, false);
	AudioClip* ac3 = AudioClip::Load("test.wav", true, false);
	GameObject* bgm = new GameObject("BGM");
	bgm->GetTransform()->SetLocalPosition(glm::vec3(20, 10, 20));
	AudioSource* as = bgm->AddBehaviour<AudioSource>();
	as->SetAudioClip(ac);
	as->SetPlayOnAwake(true);
	as->SetLooping(true);
	as->SetPitch(1.0f);
	as->SetVolume(0.7f);
	as->SetAttenuation(0.1f);
	as->SetSpatialBlend(AudioSource::Type::TwoD);

	GameObject* quitter = new GameObject("Quit");
	quitter->AddBehaviour<QuitBehaviour>();


	Camera::GetMainCamera()->GetGameObject()->AddBehaviour<AudioListener>();
	std::cout << Camera::GetMainCamera()->GetGameObject()->GetTransform()->GetForwardVector() << '\n';
	std::cout << quitter->AddBehaviour<Camera>()->GetGameObject()->GetTransform()->GetForwardVector() << '\n';
	std::vector<Player*> players = GameObject::FindObjectsOfType<Player>();
	for(auto player : players)
		std::cout << player->GetGameObject()->GetTransform()->GetForwardVector() << '\n';
}

void Application::Render() 
{
    AbstractGame::Render();
    UpdateHud();
}

void Application::InitSceneLighting()
{
	Scene* scene = SceneManager::Instance().CreateScene("Main Scene");
	//SceneManager::Instance().SetActiveScene(scene);

	CubeMap* cubeMap = new CubeMap();
	cubeMap->SetCubeFaces(config::MGE_TEXTURES_PATH + "skybox/SunSet/", ".png");

	GameObject* skyboxObject = new GameObject("SkyBox");
	skyboxObject->AddBehaviour<MeshRenderer>();
	Skybox* skybox = skyboxObject->AddBehaviour<Skybox>();
	skybox->SetSkyboxCubeMap(cubeMap);
	skybox->SetExposure(5);

	Material* litMaterial = MaterialImporter::LoadMaterial("lit");
	litMaterial->SetTexture("environmentMap", cubeMap);

	LevelImporter::LoadLevel("Greybox Level");

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
		debugInfo += "FixedUpdate: " + std::to_string(Profiler::GetSampleData("FixedUpdate")) + "s\n";
		debugInfo += "Update: " + std::to_string(Profiler::GetSampleData("Update")) + "s\n";
		debugInfo += "Pre-Render: \n";
		debugInfo += "\tLight: " + std::to_string(Profiler::GetSampleData("UpdateLight")) + "s\n";
		debugInfo += "Render: " + std::to_string(Profiler::GetSampleData("Render")) + "s\n";
		debugInfo += "Post-Render: " + std::to_string(Profiler::GetSampleData("PostRender")) + "s\n";
		debugInfo += "Events: " + std::to_string(Profiler::GetSampleData("Events")) + "s\n";
		debugInfo += "Vertices: " + std::to_string(hudVerts) + "\n";
		debugInfo += "Triangles: " + std::to_string(hudTris) + "\n";

		m_hud->setDebugInfo(debugInfo);

		c.restart();
	}
    m_hud->draw();
}
