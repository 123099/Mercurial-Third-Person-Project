#pragma once
#include <Utils\glm.hpp>

class SphereCollider;
class Transform;

class RaycastHit final
{
public:
	void SetPoint(glm::vec3 point);
	void SetCollider(SphereCollider* collider);

	glm::vec3 GetPoint();
	Transform* GetTransform();
	SphereCollider* GetCollider();
private:
	glm::vec3 m_point;
	Transform* m_transform;
	SphereCollider* m_collider;
};
