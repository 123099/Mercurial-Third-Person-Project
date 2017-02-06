#include <Core\GameObject.hpp>
#include <Behaviours\AbstractBehaviour.hpp>
#include <Behaviours\Transform.hpp>
#include <Core\Material.hpp>
#include <Managers\SceneManager.hpp>
#include <Core\Scene.hpp>
#include <Core\Mesh.hpp>

void GameObject::Destroy(GameObject * gameObject)
{
	delete gameObject;
}

GameObject::GameObject(const std::string& name) :
	m_name(name),
	m_scene(nullptr)
{
	//Make a unique pointer for the transform
	std::unique_ptr<Transform> transform = std::make_unique<Transform>();

	//Cache the address of the transform unique pointer for faster access of this object's transform
	//The behaviours vector is still the owner of all the behaviours, including the transform
	m_transform = transform.get();

	//Initialize the transform component
	transform->SetGameObject(this);

	//Put the transform in the behaviours list for use with GetComponent
	m_behaviours.push_back(std::move(transform));

	//Add the game object to the currently active scene
	AddToSceneRootList();
}

GameObject::~GameObject()
{
	//Remove this game object from the active scene
	RemoveFromSceneRootList();
}

void GameObject::SetName (const std::string& name)
{
    m_name = name;
}

std::string GameObject::GetName() const
{
	return m_name;
}

Transform * GameObject::GetTransform() const
{
	return m_transform;
}

Scene * GameObject::GetScene() const
{
	return m_scene;
}

void GameObject::Initialize()
{
	if (m_initialized == false)
	{
		//Get all behaviours
		const std::vector<AbstractBehaviour*> behaviours = GetBehavioursInChildren<AbstractBehaviour>();

		//Call Awake
		for (auto behaviour : behaviours)
		{
			behaviour->Awake();
		}

		//Call Start
		for (auto behaviour : behaviours)
		{
			behaviour->Start();
		}

		m_initialized = true;
	}
}

void GameObject::FixedUpdate()
{
	//Update all the behaviours
	for (const auto& behaviour : m_behaviours)
	{
		behaviour->FixedUpdate();
	}

	//Go through all the children and update them
	for (int i = m_transform->GetChildCount() - 1; i >= 0; --i)
	{
		m_transform->GetChildAt(i)->GetGameObject()->FixedUpdate();
	}
}

void GameObject::Update()
{
	//Update all the behaviours
	for (const auto& behaviour : m_behaviours)
	{
		behaviour->Update();
	}

	//Go through all the children and update them
    for (int i = m_transform->GetChildCount()-1; i >= 0; --i ) 
	{
        m_transform->GetChildAt(i)->GetGameObject()->Update();
    }
}

bool GameObject::IsInitialized()
{
	return m_initialized;
}

void GameObject::AddToSceneRootList()
{
	if (SceneManager::GetActiveScene() == nullptr) throw std::exception();
	SceneManager::GetActiveScene()->AddGameObject(this);
	m_scene = SceneManager::GetActiveScene();
}

void GameObject::RemoveFromSceneRootList()
{
	if (SceneManager::GetActiveScene() == nullptr) throw std::exception();
	SceneManager::GetActiveScene()->RemoveGameObject(this);
}

