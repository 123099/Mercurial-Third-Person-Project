#pragma once

class GameObject;

struct RequireBehavioursBase
{
public:
	virtual void AddRequiredBehaviours(GameObject* gameObject) = 0;
protected:
	void Add(GameObject* gameoObject);
};

#pragma region Basic Attributes

struct DisallowMultiple {};

#pragma endregion

