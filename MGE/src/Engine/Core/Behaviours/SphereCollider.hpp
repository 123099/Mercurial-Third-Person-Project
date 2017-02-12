#pragma once
#include <Behaviours\Collider.hpp>

class SphereCollider final : public Collider
{
public:
	SphereCollider();

	float GetRadius() const;
	void SetRadius(float radius);
protected:
	void SetupCollisionShape() override final;
private:
	float m_radius;
};