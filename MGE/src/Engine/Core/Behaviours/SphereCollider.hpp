#pragma once
#include <Behaviours\AbstractBehaviour.hpp>

class SphereCollider final : public AbstractBehaviour
{
public:
	float GetRadius() const;
	void SetRadius(float radius);

	bool IsCollidingWith(const SphereCollider& sphereCollider);
private:
	float m_radius;
};