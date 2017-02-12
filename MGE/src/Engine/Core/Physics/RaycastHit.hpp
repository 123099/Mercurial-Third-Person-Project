#pragma once
#include <Utils\glm.hpp>

class Collider;
class Transform;

class RaycastHit final
{
public:
	void SetPoint(const glm::vec3& point);
	void SetNormal(const glm::vec3& normal);
	void SetCollider(Collider* collider);

	glm::vec3 GetPoint();
	glm::vec3 GetNormal();

	Transform* GetTransform();
	Collider* GetCollider();
private:
	glm::vec3 m_point;
	glm::vec3 m_normal;

	Transform* m_transform;
	Collider* m_collider;
};
