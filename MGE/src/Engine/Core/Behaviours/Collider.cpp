#include "Collider.hpp"

Collider::~Collider() = default;

btCollisionShape * Collider::GetBulletCollisionShape()
{
	if (m_collisionShape == nullptr)
	{
		SetupCollisionShape();
	}
	return m_collisionShape.get();
}
