#pragma once
#include <Behaviours\BehaviourAttributesBases.hpp>
#include <Behaviours\Transform.hpp>
#include <Managers\SceneManager.hpp>
#include <Core\Scene.hpp>
#include <vector>
#include <string>
#include <memory>

class Scene;
class AbstractBehaviour;

class GameObject final
{
friend Transform;
friend Scene;

public:
#pragma region Behaviour Templates

	template <typename T>
	T* AddBehaviour(bool checkIfExists = false) 
	{
		//Make sure the type is a behaviour
		static_assert(std::is_base_of<AbstractBehaviour, T>(), "Only behaviours can be added to a Game Object using AddBehaviour!");

		//Special Case: Make sure the behaviour isn't a transform since the gameobject adds it on its own, and only 1 transform is allowed
		static_assert(std::is_base_of<Transform, T>() == false, "Only 1 instance of Transform can be attached to a GameObject!");

		if (std::is_base_of<DisallowMultiple, T>() == true && GetBehaviour<T>() != nullptr)
		{
			std::cerr << "[Warning - GameObject: " << m_name << "] Only 1 Instance of type " << typeid(T).name() << " is allowed!" << '\n';
		}

		//If check is enabled, check if we already have the behaviour attached
		if (checkIfExists == true)
		{
			//Try to retrieve the behaviour
			T* behaviour = GetBehaviour<T>();
			if (behaviour != nullptr)
			{
				//If the behaviour was already attached, return it
				return behaviour;
			}
		}

		//Create a new instance of the behaviour
		std::unique_ptr<T> behaviour = std::make_unique<T>();

		//Retrieve the address of the pointer to return later
		T* behaviourPtr = behaviour.get();

		//Check if the behaviour requires any other behaviours
		if (std::is_base_of<RequireBehavioursBase, T>() == true)
		{
			//Add all the required behaviours
			RequireBehavioursBase* requireAttribute = dynamic_cast<RequireBehavioursBase*>(behaviourPtr);
			requireAttribute->AddRequiredBehaviours(this);

			//Make sure that this behaviour hasn't already been added as part of the requirements list
			//This way we avoid adding ourselves twice as a circular dependency
			T* addedBehaviour = GetBehaviour<T>();
			if (addedBehaviour != nullptr)
			{
				return addedBehaviour;
			}
		}

		//Set ourselves as the owner of the behaviour
		behaviour->SetGameObject(this);

		//Add the behaviour to the list
		m_behaviours.push_back(std::move(behaviour));
			
		//Return the behaviour
		return behaviourPtr;
	}

	template <typename T>
	T* GetBehaviour() const
	{
		//Make sure the type is a behaviour
		static_assert(std::is_base_of<AbstractBehaviour, T>(), "Type must be a behaviour!");

		//Loop through the list of behaviours
		for ( const auto& behaviour : m_behaviours)
		{
			//Check if the behaviour is of the given type
			if (T* cast_behaviour = dynamic_cast<T*>(behaviour.get()))
			{
				//Return the converted behaviour
				return cast_behaviour;
			}
		}

		//No such behaviour is found, return nullptr
		return nullptr;
	}

	template <typename T>
	std::vector<T*> GetBehavioursInChildren() const
	{
		//Make sure the type is a behaviour
		static_assert(std::is_base_of<AbstractBehaviour, T>(), "Type must be a behaviour!");

		//Create a vector of the behaviours to return
		std::vector<T*> behaviours;

		//Loop through the list of behaviours
		for ( const auto& behaviour : m_behaviours)
		{
			//Check if the behaviour is of the given type
			if (T* cast_behaviour = dynamic_cast<T*>(behaviour.get()))
			{
				//Add the behaviour to the vector
				behaviours.push_back(cast_behaviour);
			}
		}

		//Go through all the children and retrieve all their behaviours
		const int childCount = GetTransform()->GetChildCount();
		for (int i = 0; i < childCount; ++i)
		{
			const std::vector<T*> childBehaviours = GetTransform()->GetChildAt(i)->GetGameObject()->GetBehavioursInChildren<T>();
			behaviours.insert(behaviours.end(), childBehaviours.begin(), childBehaviours.end());
		}

		//Return the vector
		return behaviours;
	}

#pragma endregion

#pragma region Object Templates

	template <typename T>
	static T* FindObjectOfType()
	{
		//Do a sweep search through only the root game objects in the scene
		const auto& rootGameObjects = SceneManager::Instance().GetActiveScene()->GetRootGameObjects();
		for ( const auto& rootObject : rootGameObjects)
		{
			//Retrieve the behaviour
			T* behaviour = rootObject->GetBehaviour<T>();
			if (behaviour != nullptr)
			{
				return behaviour;
			}
		}

		//If we are here, none of the root game objects contained the behaviour. Do a deep search
		const auto object = FindObjectsOfType<T>(true);
		if (object.size() == 1)
		{
			return object[0];
		}
		else
		{
			return nullptr;
		}
	}

	template <typename T>
	static std::vector<T*> FindObjectsOfType(bool returnFirst = false)
	{
		//Make sure T is a behaviour
		static_assert(std::is_base_of<AbstractBehaviour, T>(), "Type must be a behaviour!");

		std::vector<T*> objects;

		const auto& rootGameObjects = SceneManager::Instance().GetActiveScene()->GetRootGameObjects();
		for (const auto& rootObject : rootGameObjects)
		{
			//Retrieve all the children of the game object
			auto children = rootObject->GetTransform()->GetAllChildrenRecursively();

			//Add the game object to the list to be included in the search
			children.push_back(rootObject->GetTransform());

			//Go through all the objects and find the behaviour
			for (const auto& child : children)
			{
				T* behaviour = child->GetGameObject()->GetBehaviour<T>();
				if (behaviour != nullptr)
				{
					objects.push_back(behaviour);

					if (returnFirst == true)
					{
						return objects;
					}
				}
			}
		}

		return objects;
	}

#pragma endregion

	~GameObject();

    void SetName (const std::string& name);
    std::string GetName() const;

	Transform* GetTransform() const;

	void Initialize();
	void FixedUpdate();
	void Update();

	bool IsInitialized();
private:
	GameObject(const std::string& name = "New GameObject");

	std::string m_name;
	bool m_initialized;

	std::vector<std::unique_ptr<AbstractBehaviour>> m_behaviours;
	Transform* m_transform;

    GameObject(const GameObject&) = delete;
	GameObject& operator=(const GameObject&) = delete;
};
