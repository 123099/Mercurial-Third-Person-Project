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
#include <Utils\Profiler.hpp>

#include <Textures\CubeMap.hpp>

#include <Lua\LevelImporter.hpp>

void Application::Initialize() 
{
    AbstractGame::Initialize();

	m_window->setMouseCursorGrabbed(true);
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

	GameObject* cockpit = new GameObject("Cockpit");
	MeshRenderer* ms = cockpit->AddBehaviour<MeshRenderer>();
	ms->SetSharedMaterial(MaterialImporter::LoadMaterial("lit"));
	ms->SetSharedMesh(ObjImporter::LoadObj("Cockpit"));

	GameObject* windows = new GameObject("Windows");
	ms = windows->AddBehaviour<MeshRenderer>();
	ms->SetSharedMaterial(MaterialImporter::LoadMaterial("litWindows"));
	ms->SetSharedMesh(ObjImporter::LoadObj("Windows"));

	GameObject* sphere = new GameObject("Sphere");
	sphere->GetTransform()->SetLocalScale(glm::vec3(3, 3, 3));
	ms = sphere->AddBehaviour<MeshRenderer>();
	ms->SetSharedMaterial(MaterialImporter::LoadMaterial("lit"));
	ms->SetSharedMesh(ObjImporter::LoadObj("Shape"));
	sphere->AddBehaviour<SphereCollider>()->SetRadius(3);
}

void Application::Render() {
    AbstractGame::Render();
    UpdateHud();
}

void Application::InitSceneWobble()
{
	Scene* scene = SceneManager::CreateScene("WobbleScene");

	GameObject* wobbleObject = new GameObject("Wobble");
	MeshRenderer* wobbleMesh = wobbleObject->AddBehaviour<MeshRenderer>();
	wobbleMesh->SetSharedMesh(ObjImporter::LoadObj("Shape"));
	wobbleMesh->SetSharedMaterial(MaterialImporter::LoadMaterial("wobble"));
	wobbleObject->AddBehaviour<WobbleBehaviour>();
	KeysBehaviour* keys = wobbleObject->AddBehaviour<KeysBehaviour>();
	keys->SetMoveSpeed(5);
	keys->SetTurnSpeed(50);

	GameObject* cameraObject = new GameObject("Camera");
	cameraObject->GetTransform()->SetLocalPosition(glm::vec3(0, 3, 10));
	cameraObject->AddBehaviour<Camera>()->SetAspect((float)m_window->getSize().x, (float)m_window->getSize().y);
	CameraOrbit* cameraOrbit = cameraObject->AddBehaviour<CameraOrbit>();
	cameraOrbit->SetTarget(wobbleObject);
	cameraOrbit->SetDistance(10);
	cameraOrbit->SetMinTiltAngle(-90);
	cameraOrbit->SetMaxTiltAngle(90);
	cameraOrbit->SetRotationSpeed(0.5f);

	GameObject* plane = new GameObject("Plane");
	plane->GetTransform()->SetLocalScale(glm::vec3(50, 1, 50));
	MeshRenderer* planeMesh = plane->AddBehaviour<MeshRenderer>();
	planeMesh->SetSharedMesh(ObjImporter::LoadObj("plane"));
	planeMesh->SetSharedMaterial(MaterialImporter::LoadMaterial("color"));
}

void Application::InitSceneLighting()
{
	Scene* scene = SceneManager::CreateScene("Main Scene");

	GameObject* cameraObject = new GameObject("Camera");
	cameraObject->GetTransform()->SetLocalPosition(glm::vec3(0, 3, 10));
	cameraObject->AddBehaviour<Camera>()->SetAspect((float) m_window->getSize().x, (float) m_window->getSize().y);
	FreeLookCamera* flc = cameraObject->AddBehaviour<FreeLookCamera>();
	flc->SetRotationSpeed(0.005f);
	flc->SetMoveSpeed(3.5f);

	Mesh* cubeMesh = ObjImporter::LoadObj("cube_flat");

	CubeMap* cubeMap = new CubeMap();
	cubeMap->SetCubeFaces(config::MGE_TEXTURES_PATH + "skybox/SunSet/", ".png");

	GameObject* skyboxObject = new GameObject("SkyBox");
	skyboxObject->AddBehaviour<MeshRenderer>();
	Skybox* skybox = skyboxObject->AddBehaviour<Skybox>();
	skybox->SetSkyboxCubeMap(cubeMap);
	skybox->SetExposure(5);

	Material* colorMaterial = MaterialImporter::LoadMaterial("color");
	Material* litMaterial = MaterialImporter::LoadMaterial("lit");
	litMaterial->SetTexture("environmentMap", cubeMap);

	LightManager::Instance().SetGlobalAmbientColor(glm::vec4(0.2, 0.2, 0.1, 1));

	GameObject* FlashlightObject = new GameObject("Flashlight");
	FlashlightObject->GetTransform()->SetLocalPosition(glm::vec3(0, 3, 0));
	FlashlightObject->GetTransform()->Rotate(glm::vec3(0, 90, 0));
	FlashlightObject->GetTransform()->SetLocalScale(glm::vec3(0.1, 0.1, 0.5));
	FlashlightObject->AddBehaviour<MeshRenderer>();
	FlashlightObject->GetBehaviour<MeshRenderer>()->SetSharedMesh(cubeMesh);
	FlashlightObject->GetBehaviour<MeshRenderer>()->SetSharedMaterial(colorMaterial);
	FlashlightObject->AddBehaviour<Flashlight>();

	//Spot
	Light* light = FlashlightObject->AddBehaviour<Light>();
	light->SetType(Light::Type::Spot);

	light->SetAmbientColor(glm::vec4(0.2f));
	light->SetDiffuseColor(glm::vec4(1, 0, 0, 1));
	light->SetSpecularColor(glm::vec4(1));
	light->SetIntensity(3.0f);
	light->SetAttenuation(glm::vec3(0, 0, 0.05f));
	light->SetSpotInnerAngle(70.0f);
	light->SetSpotOuterAngle(80.0f);

	//Point
	light = FlashlightObject->AddBehaviour<Light>();
	light->SetType(Light::Type::Point);

	light->SetAmbientColor(glm::vec4(0.2f));
	light->SetDiffuseColor(glm::vec4(0, 0, 1, 1));
	light->SetSpecularColor(glm::vec4(1));
	light->SetIntensity(2.0f);
	light->SetAttenuation(glm::vec3(0, 0, 0.3f));

	//Directional
	light = FlashlightObject->AddBehaviour<Light>();
	light->SetType(Light::Type::Directional);

	light->SetAmbientColor(glm::vec4(0.2f));
	light->SetDiffuseColor(glm::vec4(0.9, 0.9, 0.7, 1));
	light->SetSpecularColor(glm::vec4(1));
	light->SetIntensity(0.5f);

	for (const auto& rootGameObject : SceneManager::GetActiveScene()->GetRootGameObjects())
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

void Application::InitSceneTerrain()
{
	Scene* scene2 = SceneManager::CreateScene("Terrain Scene");
	SceneManager::SetActiveScene(scene2);

	GameObject* terrainObj = new GameObject("terrain");
	MeshRenderer* mesh = terrainObj->AddBehaviour<MeshRenderer>();
	mesh->SetSharedMaterial(MaterialImporter::LoadMaterial("terrain"));
	Terrain* terrain = terrainObj->AddBehaviour<Terrain>();
	terrain->SetHeight(512);
	terrain->SetSize(512, 512);
	terrainObj->AddBehaviour<WobbleBehaviour>();

	CubeMap* cubeMap = new CubeMap();
	cubeMap->SetCubeFaces(config::MGE_TEXTURES_PATH + "skybox/FullMoon/", ".png");

	GameObject* skyboxObject = new GameObject("SkyBox");
	Skybox* skybox = skyboxObject->AddBehaviour<Skybox>();
	skybox->SetSkyboxCubeMap(cubeMap);
	skybox->SetExposure(3);

	GameObject* cameraObject = new GameObject("Camera");
	cameraObject->GetTransform()->SetLocalPosition(glm::vec3(256, 3, 230));cameraObject->AddBehaviour<Camera>()->SetAspect((float)m_window->getSize().x, (float)m_window->getSize().y);
	FreeLookCamera* flc = cameraObject->AddBehaviour<FreeLookCamera>();
	flc->SetRotationSpeed(0.005f);
	flc->SetMoveSpeed(15);

	GameObject* lightObject = new GameObject("Light");
	Light* light = lightObject->AddBehaviour<Light>();
	light->SetType(Light::Type::Directional);
	light->SetColor(glm::vec4(0.08f, 0.32f, 0.63f, 1));
	light->SetIntensity(2.f);

	GameObject* FlashlightObject = new GameObject("Flashlight");
	FlashlightObject->GetTransform()->SetLocalPosition(glm::vec3(225, 50, 227));
	FlashlightObject->GetTransform()->Rotate(glm::vec3(0, 90, 0));
	FlashlightObject->GetTransform()->SetLocalScale(glm::vec3(0.1, 0.1, 0.5));
	FlashlightObject->AddBehaviour<Flashlight>();

	Light* flashlight = FlashlightObject->AddBehaviour<Light>();
	flashlight->SetType(Light::Type::Spot);
	flashlight->SetAmbientColor(glm::vec4(0.2f));
	flashlight->SetDiffuseColor(glm::vec4(1, 0, 0, 1));
	flashlight->SetSpecularColor(glm::vec4(1));
	flashlight->SetIntensity(5.0f);
	flashlight->SetAttenuation(glm::vec3(0, 0, 0.0f));
	flashlight->SetSpotInnerAngle(70.0f);
	flashlight->SetSpotOuterAngle(80.0f);
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
