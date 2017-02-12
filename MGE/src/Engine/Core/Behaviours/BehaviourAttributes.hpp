#pragma once
#include <Core\GameObject.hpp>

#pragma region Attributes
#include <Behaviours\BehaviourAttributesBases.hpp>
#include <vector>

template <typename First, typename... Rest>
struct RequireBehaviours : public RequireBehavioursBase
{
	void AddRequiredBehaviours(GameObject* gameObject) override
	{
		const std::vector<AbstractBehaviour*> {gameObject->AddBehaviour<First>(true), gameObject->AddBehaviour<Rest>(true)...};
	}
};

#pragma endregion
