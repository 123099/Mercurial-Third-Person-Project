#include "BoxCollider.hpp"

BoxCollider::BoxCollider() : m_halfExtents(0.5f, 0.5f, 0.5f) {}

void BoxCollider::SetHalfExtents(glm::vec3 halfExtents)
{
	m_halfExtents = halfExtents;
}

void BoxCollider::SetupCollisionShape()
{
	m_collisionShape = std::make_unique<btBoxShape>(btVector3(m_halfExtents.x, m_halfExtents.y, m_halfExtents.z));
}


