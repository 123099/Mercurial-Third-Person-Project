#include <Game\LuaGame.hpp>
#include <Lua\LevelImporter.hpp>
#include <Managers\SceneManager.hpp>
#include <Managers\LightManager.hpp>
#include <GameObject.hpp>
#include <Behaviours\MeshRenderer.hpp>
#include <Importers\ObjImporter.hpp>
#include <Importers\MaterialImporter.hpp>
#include <Game\Behaviours\RotatingBehaviour.hpp>
#include <Behaviours\FreeLookCamera.hpp>
#include <Behaviours\Camera.hpp>

void LuaGame::InitializeScene()
{
	LightManager::Instance().SetGlobalAmbientColor(glm::vec4(0.05, 0.05, 0, 1));
	SceneManager::CreateScene("Scene1");
	LevelImporter::LoadLevel("Escape_Room");

	GameObject* cam = new GameObject("Camera");
	cam->AddBehaviour<Camera>();
	FreeLookCamera* flc = cam->AddBehaviour<FreeLookCamera>();
	flc->SetMoveSpeed(5);
	flc->SetRotationSpeed(0.005f);
	cam->GetTransform()->SetLocalPosition(glm::vec3(0, 1, 105));
}
