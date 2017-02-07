#include "SphereCollider.hpp"
#include <Core\GameObject.hpp>
#include <Behaviours\Transform.hpp>
#include <Utils\glm.hpp>

float SphereCollider::GetRadius() const
{
	return m_radius;
}

void SphereCollider::SetRadius(float radius)
{
	m_radius = radius;
}

bool SphereCollider::IsCollidingWith(const SphereCollider & sphereCollider)
{
	const glm::vec3 centerToOtherCenter = sphereCollider.GetGameObject()->GetTransform()->GetWorldPosition() - m_gameObject->GetTransform()->GetWorldPosition();
	const float distanceSquared = glm::dot(centerToOtherCenter, centerToOtherCenter);
	const float radiiSum = m_radius + sphereCollider.GetRadius();
	return distanceSquared <= radiiSum * radiiSum;
}
