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
	~Scene();
	
	std::string GetName() const;

	void ProcessUninitializedObjects();

	int GetRootCount() const;
	const std::vector<GameObject*>& GetRootGameObjects() const;

	bool ContainsGameObject(GameObject* gameObject);
private:
	Scene(const std::string& name);

	std::string m_name;

	std::vector<GameObject*> m_rootGameObjects;
	std::vector<GameObject*> m_uninitializedGameObjects;

	void AddGameObject(GameObject* gameObject);
	void RemoveGameObject(GameObject* gameObject);
};

