#pragma once
#include <Behaviours\AbstractBehaviour.hpp>
#include <Behaviours\BehaviourAttributes.hpp>
#include <Behaviours\Collider.hpp>

#include <bullet\btBulletDynamicsCommon.h>
#include <memory>

class Rigidbody final : public AbstractBehaviour
{
public:
	Rigidbody();

	void Awake() override final;
	void Update() override final;

	void SetMass(float mass);
private:
	std::unique_ptr<btRigidBody> m_rigidbody;
	std::unique_ptr<btDefaultMotionState> m_rigidbodyMotion;
	float m_mass;

	Collider* m_collider;
};