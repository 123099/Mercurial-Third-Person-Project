#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <cassert>
#include <vector>
#include <string>
#include <Utils\glm.hpp>
#include <memory>
#include <Behaviours\BehaviourAttributesBases.hpp>
#include <Behaviours\Transform.hpp>
#include <Managers\SceneManager.hpp>
#include <Core\Scene.hpp>

class AbstractBehaviour;

/**
 * A GameObject is a container of everything that can be in the scene.
 * Every GameObject by default comes with a transform component.
 * The GameObject class cannot be extended, and all additional functionality should be defined as Behaviours.
 */
class GameObject final
{
friend Transform;

public:
	static void Destroy(GameObject* gameObject);

#pragma region Behaviour Templates

	template <typename T>
	T* AddBehaviour() 
	{
		//Make sure the type is a behaviour
		static_assert(std::is_base_of<AbstractBehaviour, T>(), "Only behaviours can be added to a Game Object using AddBehaviour!");

		//Special Case: Make sure the behaviour isn't a transform since the gameobject adds it on its own, and only 1 transform is allowed
		static_assert(std::is_base_of<Transform, T>() == false, "Only 1 instance of Transform can be attached to a GameObject!");

		if (std::is_base_of<DisallowMultiple, T>() == true && GetBehaviour<T>() != nullptr)
		{
			std::cerr << "[Warning - GameObject: " << m_name << "] Only 1 Instance of type " << typeid(T).name() << " is allowed!" << '\n';
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
		for (const auto& behaviour : m_behaviours)
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
		for (const auto& behaviour : m_behaviours)
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
		if (SceneManager::GetActiveScene() != nullptr)
		{
			//Do a sweep search through only the root game objects in the scene
			for (auto rootObject : SceneManager::GetActiveScene()->GetRootGameObjects())
			{
				//Retrieve the behaviour
				T* behaviour = rootObject->GetBehaviour<T>();
				if (behaviour != nullptr)
				{
					return behaviour;
				}
			}
		}

		//If we are here, none of the root game objects contained the behaviour. Do a deep search
		const std::vector<T*> object = FindObjectsOfType<T>(true);
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

		if (SceneManager::GetActiveScene() != nullptr)
		{
			for (auto rootObject : SceneManager::GetActiveScene()->GetRootGameObjects())
			{
				//Retrieve all the children of the game object
				auto children = rootObject->GetTransform()->GetAllChildrenRecursively();

				//Add the game object to the list to be included in the search
				children.push_back(rootObject->GetTransform());

				//Go through all the objects and find the behaviour
				for (auto child : children)
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
		}

		return objects;
	}

#pragma endregion

	GameObject(const std::string& name = "");
	~GameObject();

    void SetName (const std::string& name);
    std::string GetName() const;

	Transform* GetTransform() const;
	Scene* GetScene() const;

	void Initialize();
	void FixedUpdate();
	void Update();

	bool IsInitialized();
private:
	std::string m_name;
	bool m_initialized;

	std::vector<std::unique_ptr<AbstractBehaviour>> m_behaviours;
	Transform* m_transform;
	
	Scene* m_scene;

	void AddToSceneRootList();
	void RemoveFromSceneRootList();

    GameObject(const GameObject&) = delete;
	GameObject& operator=(const GameObject&) = delete;
};

#endif // GAMEOBJECT_H
