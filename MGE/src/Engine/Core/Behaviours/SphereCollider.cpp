#include "SphereCollider.hpp"
#include <Core\GameObject.hpp>
#include <Behaviours\Transform.hpp>
#include <Utils\glm.hpp>

void SphereCollider::SetRadius(float radius)
{
	m_radius = radius;
}

bool SphereCollider::IsCollidingWith(const SphereCollider & sphereCollider)
{
	const glm::vec3 centerToOtherCenter = sphereCollider.GetGameObject()->GetTransform()->GetWorldPosition() - m_gameObject->GetTransform()->GetWorldPosition();
	const float distanceSquared = glm::dot(centerToOtherCenter, centerToOtherCenter);
	const float radiiSum = m_radius + sphereCollider.m_radius;
	return distanceSquared <= radiiSum * radiiSum;
}
