#include <Core\Scene.hpp>
#include <Core\GameObject.hpp>
#include <algorithm>

Scene::Scene(const std::string & name) : m_name(name) {}

Scene::~Scene()
{
	std::cout << "Scene destructor" << '\n';
	for (GameObject* gameObject : m_rootGameObjects)
	{
		DestroyGameObject(gameObject);
	}

	for (GameObject* gameObject : m_uninitializedGameObjects)
	{
		DestroyGameObject(gameObject);
	}

	ProcessObjectsToBeDestroyed();

	m_rootGameObjects.clear();
	m_uninitializedGameObjects.clear();

	std::cout << "Scene Destrcutor end" << '\n';
}

std::string Scene::GetName() const
{
	return m_name;
}

GameObject * Scene::CreateGameObject(const std::string& name)
{
	//Create a new game object
	GameObject* gameObject = new GameObject(name);

	//Add to uninitialized list
	m_uninitializedGameObjects.push_back(gameObject);

	//Add to root list
	AddToRoot(gameObject);

	return gameObject;
}

void Scene::DestroyGameObject(GameObject * gameObject)
{
	//Remove the object from uninitialized list if it was there
	if (ContainsGameObjectInVector(gameObject, m_uninitializedGameObjects) == true)
	{
		m_uninitializedGameObjects.erase(std::remove(m_uninitializedGameObjects.begin(), m_uninitializedGameObjects.end(), gameObject));
	}

	//Mark object as to be detroyed
	gameObject->m_destroyed = true;
	m_objectsToBeDestroyed.push_back(gameObject);
}

void Scene::AddToRoot(GameObject * gameObject)
{
	if (ContainsGameObjectInVector(gameObject, m_rootGameObjects) == false)
	{
		m_rootGameObjects.push_back(gameObject);
	}
}

void Scene::RemoveFromRoot(GameObject * gameObject)
{
	if (ContainsGameObjectInVector(gameObject, m_rootGameObjects) == true)
	{
		m_rootGameObjects.erase(std::remove(m_rootGameObjects.begin(), m_rootGameObjects.end(), gameObject));
	}
}

void Scene::ProcessUninitializedObjects()
{
	//Initialize all uninitialized objects and add them to the root objects list
	const size_t uninitializedObjectsCount = m_uninitializedGameObjects.size();
	for (size_t i = 0; i < uninitializedObjectsCount; ++i)
	{
		GameObject* gameObject = m_uninitializedGameObjects[i];
		gameObject->Initialize();
	}

	m_uninitializedGameObjects.clear();
}

void Scene::ProcessObjectsToBeDestroyed()
{
	//Destroy all objects in the to be destroyed list
	for (size_t i = 0; i < m_objectsToBeDestroyed.size(); ++i)
	{
		GameObject* gameObject = m_objectsToBeDestroyed[i];

		//Remove the game object from the root list
		RemoveFromRoot(gameObject);

		//Delete the object
		delete gameObject;
	}

	m_objectsToBeDestroyed.clear();
}

size_t Scene::GetRootCount() const
{
	return m_rootGameObjects.size();
}

const std::vector<GameObject*>& Scene::GetRootGameObjects() const
{
	return m_rootGameObjects;
}

bool Scene::ContainsGameObject(GameObject * gameObject)
{
	return ContainsGameObjectInVector(gameObject, m_rootGameObjects);
}

bool Scene::ContainsGameObjectInVector(GameObject * gameObject, std::vector<GameObject*>& vector)
{
	return std::find(vector.begin(), vector.end(), gameObject) != vector.end();
}
