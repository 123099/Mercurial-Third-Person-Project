#pragma once
#include <Behaviours\Collider.hpp>
#include <Utils\glm.hpp>

class BoxCollider final : public Collider
{
public:
	BoxCollider();

	void SetHalfExtents(glm::vec3 halfExtents);
protected:
	void SetupCollisionShape() override final;
private:
	glm::vec3 m_halfExtents;
};