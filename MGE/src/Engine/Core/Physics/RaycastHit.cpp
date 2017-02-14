#include "RaycastHit.hpp"
#include <Core\GameObject.hpp>
#include <Behaviours\Transform.hpp>
#include <Behaviours\Collider.hpp>

void RaycastHit::SetPoint(const glm::vec3& point)
{
	m_point = point;
}

void RaycastHit::SetNormal(const glm::vec3 & normal)
{
	m_normal = normal;
}

void RaycastHit::SetCollider(Collider * collider)
{
	m_collider = collider;
	m_transform = collider->GetGameObject()->GetTransform();
}

glm::vec3 RaycastHit::GetPoint()
{
	return m_point;
}

glm::vec3 RaycastHit::GetNormal()
{
	return m_normal;
}

Transform * RaycastHit::GetTransform()
{
	return m_transform;
}

Collider * RaycastHit::GetCollider()
{
	return m_collider;
}
