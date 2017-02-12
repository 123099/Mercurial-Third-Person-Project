#include "SphereCollider.hpp"
#include <Core\GameObject.hpp>
#include <Behaviours\Transform.hpp>
#include <Utils\glm.hpp>

SphereCollider::SphereCollider() : m_radius(1.0f) {}

float SphereCollider::GetRadius() const
{
	return m_radius;
}

void SphereCollider::SetRadius(float radius)
{
	m_radius = radius;
}

void SphereCollider::SetupCollisionShape()
{
	m_collisionShape = std::make_unique<btSphereShape>(m_radius);
}
