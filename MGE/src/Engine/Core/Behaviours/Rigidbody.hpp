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
	~Rigidbody();

	void Awake() override final;
	void Update() override final;

	void SetMass(float mass);
	void SetKinematic(bool kinematic);

	void AddForce(const glm::vec3& force);
	void AddRelativeForce(const glm::vec3& force);

	void FreezePosition(bool xAxis, bool yAxis, bool zAxis);
	void FreezeRotation(bool xAxis, bool yAxis, bool zAxis);

	void Translate(const glm::vec3& translation);
	void SetRotation(Quaternion& rotation);

	btRigidBody* GetBulletRigidbody();
private:
	std::unique_ptr<btRigidBody> m_rigidbody;
	std::unique_ptr<btDefaultMotionState> m_rigidbodyMotion;

	float m_mass;
	bool m_isKinematic;

	bool m_freezePositionX;
	bool m_freezePositionY;
	bool m_freezePositionZ;

	bool m_freezeRotationX;
	bool m_freezeRotationY;
	bool m_freezeRotationZ;

	Collider* m_collider;
};