#include <Core\GameObject.hpp>
#include <Behaviours\AbstractBehaviour.hpp>

GameObject::GameObject(const std::string& name) : m_name(name), m_transform(nullptr)
{
	//Make a unique pointer for the transform
	std::unique_ptr<Transform> transform = std::make_unique<Transform>();

	//Cache the address of the transform for faster access
	m_transform = transform.get();

	//Initialize the transform component
	transform->SetGameObject(this);

	//Put the transform in the behaviours list for use with GetComponent
	m_behaviours.push_back(std::move(transform));
}

GameObject::~GameObject()
{
	m_transform = nullptr;

	//Set the game object reference in all the behaviours to null
	for (const auto& behaviour : m_behaviours)
	{
		behaviour->SetGameObject(nullptr);
	}
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

void GameObject::Initialize()
{
	if (IsInitialized() == false)
	{
		//Get all behaviours
		const std::vector<AbstractBehaviour*> behaviours = GetBehavioursInChildren<AbstractBehaviour>();

		//Call Awake
		for (const auto& behaviour : behaviours)
		{
			behaviour->Awake();
		}

		//Call Start
		for (const auto& behaviour : behaviours)
		{
			behaviour->Start();
		}

		//Mark self as initialized
		m_initialized = true;

		//Mark all children as initialized
		const std::vector<Transform*> children = GetTransform()->GetAllChildrenRecursively();
		for (Transform* child : children)
		{
			child->GetGameObject()->m_initialized = true;
		}
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

