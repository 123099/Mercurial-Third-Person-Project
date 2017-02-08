#pragma once

#include <Utils\Singleton.hpp>
#include <vector>
#include <string>
#include <memory>

class Scene;
class GameObject;

class SceneManager final : public Singleton<SceneManager>
{
friend Singleton<SceneManager>;

public:
	~SceneManager();

	Scene* CreateScene(const std::string& name);
	void DestroyScene(Scene* scene);
	void DestroyActiveScene();

	void SetActiveScene(Scene* scene);

	Scene* GetActiveScene();
	Scene* GetSceneByName(const std::string& name);
	Scene* GetSceneByIndex(int index);

	int GetSceneCount();
private:
	std::vector<std::unique_ptr<Scene>> m_scenes;
	Scene* m_activeScene;

	SceneManager() = default;
};

