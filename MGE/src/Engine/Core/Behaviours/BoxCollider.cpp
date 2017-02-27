#include "BoxCollider.hpp"
#include <Behaviours\Transform.hpp>
#include <Core\GameObject.hpp>

BoxCollider::BoxCollider() : m_halfExtents(0.5f, 0.5f, 0.5f) {}

void BoxCollider::SetHalfExtents(glm::vec3 halfExtents)
{
	m_halfExtents = halfExtents;
}

void BoxCollider::SetupCollisionShape()
{
	m_collisionShape = std::make_unique<btBoxShape>(btVector3(m_halfExtents.x, m_halfExtents.y, m_halfExtents.z));
	std::cout << "Box Collider extents for " << m_gameObject->GetName() << ": " << m_halfExtents << '\n';
}


