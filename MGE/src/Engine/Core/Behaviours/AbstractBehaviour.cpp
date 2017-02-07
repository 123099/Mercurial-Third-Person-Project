#include <Behaviours\AbstractBehaviour.hpp>

AbstractBehaviour::AbstractBehaviour() : m_gameObject(nullptr) {}

AbstractBehaviour::~AbstractBehaviour() = default;

void AbstractBehaviour::SetGameObject(GameObject* gameObject) 
{
    m_gameObject = gameObject;
}

GameObject * AbstractBehaviour::GetGameObject() const
{
	return m_gameObject;
}

