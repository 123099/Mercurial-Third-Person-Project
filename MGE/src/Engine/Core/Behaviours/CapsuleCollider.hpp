#pragma once
#include <Behaviours\Collider.hpp>

class CapsuleCollider final : public Collider
{
public:
	CapsuleCollider();

	void SetHeight(float height);
	void SetRadius(float radius);
protected:
	void SetupCollisionShape() override final;
private:
	float m_height;
	float m_radius;
};