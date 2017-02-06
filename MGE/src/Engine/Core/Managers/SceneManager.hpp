#pragma once

#include <vector>
#include <string>

class Scene;
class GameObject;

class SceneManager
{
public:
	SceneManager() = delete;

	static Scene* CreateScene(const std::string& name);

	static void SetActiveScene(Scene* scene);

	static Scene* GetActiveScene();
	static Scene* GetSceneByName(const std::string& name);
	static Scene* GetSceneByIndex(int index);

	static int GetSceneCount();
private:
	static std::vector<Scene*> s_scenes;
	static Scene* s_activeScene;
};

