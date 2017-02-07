#pragma once
#include <Behaviours\AbstractBehaviour.hpp>

class SphereCollider final : public AbstractBehaviour
{
public:
	void SetRadius(float radius);

	bool IsCollidingWith(const SphereCollider& sphereCollider);
private:
	float m_radius;
};