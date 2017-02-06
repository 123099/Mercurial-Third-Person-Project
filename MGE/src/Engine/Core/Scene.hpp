#pragma once

#include <string>
#include <vector>

class GameObject;
class SceneManager;

class Scene final
{
friend SceneManager;
friend GameObject;

public:
	Scene(const std::string& name);
	~Scene();
	
	std::string GetName();

	void ProcessUninitializedObjects();

	int GetRootCount();
	const std::vector<GameObject*>& GetRootGameObjects() const;

	bool ContainsGameObject(GameObject* gameObject);
private:
	std::string m_name;

	std::vector<GameObject*> m_rootGameObjects;
	std::vector<GameObject*> m_uninitializedGameObjects;

	void AddGameObject(GameObject* gameObject);
	void RemoveGameObject(GameObject* gameObject);
};

