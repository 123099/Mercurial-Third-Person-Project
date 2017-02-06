#include "SceneManager.hpp"
#include <Core\Scene.hpp>
#include <algorithm>

std::vector<Scene*> SceneManager::s_scenes;
Scene* SceneManager::s_activeScene;

Scene * SceneManager::CreateScene(const std::string & name)
{
	//Create a new scene
	Scene* scene = new Scene(name);

	//If there is currently no active scene, set the new scene as the active one
	if (GetActiveScene() == nullptr)
	{
		SetActiveScene(scene);
	}

	//Return the new scene
	return scene;
}

void SceneManager::SetActiveScene(Scene * scene)
{
	s_activeScene = scene;
}

Scene * SceneManager::GetActiveScene()
{
	return s_activeScene;
}

Scene * SceneManager::GetSceneByName(const std::string & name)
{
	//Try to find the scene that matches the name
	auto foundSceneItr = std::find_if(s_scenes.begin(), s_scenes.end(), [&](auto scene) { return scene->GetName() == name; });

	//If the scene was found, return it
	if (foundSceneItr != s_scenes.end())
	{
		return *foundSceneItr;
	}
	else
	{
		//Scene wasn't found, return null
		return nullptr;
	}
}

Scene * SceneManager::GetSceneByIndex(int index)
{
	return s_scenes[index];
}

int SceneManager::GetSceneCount()
{
	return s_scenes.size();
}
