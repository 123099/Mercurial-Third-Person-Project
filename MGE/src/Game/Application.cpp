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

#include <Utils\Cursor.hpp>
#include <Utils\Profiler.hpp>

#include <Textures\CubeMap.hpp>

#include <Lua\LevelImporter.hpp>

#include <bullet\btBulletDynamicsCommon.h>
#include <Physics\Physics.hpp>
#include <Behaviours\SphereCollider.hpp>
#include <Behaviours\BoxCollider.hpp>
#include <Behaviours\CapsuleCollider.hpp>
#include <Behaviours\Rigidbody.hpp>
#include <Behaviours\PlayerInput.hpp>

void Application::OnInitialized()
{
	SetFPSLimit(60);
	SetDebugHudEnabled(true);
	Cursor::Instance().SetCursorMode(Cursor::Mode::LockedAndCentered);
	Cursor::Instance().SetCursorVisible(false);
}

void Application::InitializeScene()
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
	
	GameObject* input = SceneManager::Instance().GetActiveScene()->CreateGameObject("Input");
	input->AddBehaviour<PlayerInput>();

	GameObject* quitter = SceneManager::Instance().GetActiveScene()->CreateGameObject("Quit");
	quitter->AddBehaviour<QuitBehaviour>();

	GameObject* test = SceneManager::Instance().GetActiveScene()->CreateGameObject("Test");
	test->GetTransform()->SetWorldPosition(glm::vec3(5, 10, 0));
	test->AddBehaviour<SphereCollider>()->SetRadius(5);
	test->AddBehaviour<Rigidbody>()->SetMass(100);
	MeshRenderer* ms = test->AddBehaviour<MeshRenderer>();
	ms->SetSharedMaterial(MaterialImporter::LoadMaterial("lit"));
	ms->SetSharedMesh(ObjImporter::LoadObj("Shape"));
}
