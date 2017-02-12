#include "RaycastHit.hpp"
#include <Core\GameObject.hpp>
#include <Behaviours\Transform.hpp>
#include <Behaviours\SphereCollider.hpp>

void RaycastHit::SetPoint(glm::vec3 point)
{
	m_point = point;
}

void RaycastHit::SetCollider(SphereCollider * collider)
{
	m_collider = collider;
	m_transform = collider->GetGameObject()->GetTransform();
}

glm::vec3 RaycastHit::GetPoint()
{
	return m_point;
}

Transform * RaycastHit::GetTransform()
{
	return m_transform;
}

SphereCollider * RaycastHit::GetCollider()
{
	return m_collider;
}
