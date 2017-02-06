#include <Core\Scene.hpp>
#include <algorithm>
#include <Core\GameObject.hpp>

Scene::Scene(const std::string & name) : m_name(name) {}

Scene::~Scene()
{
	for (auto gameObject : m_rootGameObjects)
	{
		delete gameObject;
	}
}

std::string Scene::GetName()
{
	return m_name;
}

void Scene::ProcessUninitializedObjects()
{
	for (const auto& object : m_uninitializedGameObjects)
	{
		object->Initialize();
	}

	m_uninitializedGameObjects.clear();
}

int Scene::GetRootCount()
{
	return m_rootGameObjects.size();
}

const std::vector<GameObject*>& Scene::GetRootGameObjects() const
{
	return m_rootGameObjects;
}

bool Scene::ContainsGameObject(GameObject * gameObject)
{
	return std::find(m_rootGameObjects.begin(), m_rootGameObjects.end(), gameObject) != m_rootGameObjects.end();
}

void Scene::AddGameObject(GameObject * gameObject)
{
	m_rootGameObjects.push_back(gameObject);

	if (gameObject->IsInitialized() == false)
	{
		m_uninitializedGameObjects.push_back(gameObject);
	}
}

void Scene::RemoveGameObject(GameObject * gameObject)
{
	m_rootGameObjects.erase(std::remove(m_rootGameObjects.begin(), m_rootGameObjects.end(), gameObject));
}
