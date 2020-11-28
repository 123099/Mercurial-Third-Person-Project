#pragma once

#include <string>
#include <vector>

class GameObject;
class SceneManager;

class Scene final
{
friend SceneManager;

public:
	~Scene();
	
	std::string GetName() const;

	GameObject* CreateGameObject(const std::string& name);
	void DestroyGameObject(GameObject* gameObject);

	void AddToRoot(GameObject* gameObject);
	void RemoveFromRoot(GameObject* gameObject);

	void ProcessUninitializedObjects();
	void ProcessObjectsToBeDestroyed();

	size_t GetRootCount() const;
	const std::vector<GameObject*>& GetRootGameObjects() const;

	bool ContainsGameObject(GameObject* gameObject);
private:
	Scene(const std::string& name);

	std::string m_name;

	std::vector<GameObject*> m_rootGameObjects;
	std::vector<GameObject*> m_uninitializedGameObjects;
	std::vector<GameObject*> m_objectsToBeDestroyed;

	bool ContainsGameObjectInVector(GameObject* gameObject, std::vector<GameObject*>& vector);
};

