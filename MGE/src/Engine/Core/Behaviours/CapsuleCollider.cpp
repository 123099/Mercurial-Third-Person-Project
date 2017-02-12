#include "CapsuleCollider.hpp"

CapsuleCollider::CapsuleCollider() : m_radius(1.0f), m_height(2.0f) {}

void CapsuleCollider::SetHeight(float height)
{
	m_height = height;
}

void CapsuleCollider::SetRadius(float radius)
{
	m_radius = radius;
}

void CapsuleCollider::SetupCollisionShape()
{
	m_collisionShape = std::make_unique<btCapsuleShape>(m_radius, m_height);
}
