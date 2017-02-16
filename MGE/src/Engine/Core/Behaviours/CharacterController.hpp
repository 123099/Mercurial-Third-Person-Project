#pragma once
#include <Behaviours\AbstractBehaviour.hpp>
#include <bullet\btBulletDynamicsCommon.h>
#include <bullet\BulletCollision\CollisionDispatch\btGhostObject.h>
#include <bullet\BulletDynamics\Character\btKinematicCharacterController.h>
#include <Utils\Quaternion.hpp>
#include <Utils\glm.hpp>
#include <memory>

class CharacterController final : public AbstractBehaviour
{
public:
	~CharacterController();

	void Awake() override final;
	void FixedUpdate() override final;
	void Update() override final;
	
	void SetHeight(float height);
	void SetRadius(float radius);
	void SetSlopeLimit(float slopeLimit);
	void SetStepHeight(float stepHeight);
	void SetWalkVelocity(float velocity);
	void SetWalkDirection(glm::vec3 direction);
	void SetAngularVelocity(glm::vec3 velocity);

	void Jump(float jumpSpeed);
private:
	std::unique_ptr<btKinematicCharacterController> m_characterController;
	std::unique_ptr<btCapsuleShape> m_capsuleCollider;
	std::unique_ptr<btPairCachingGhostObject> m_ghostObject;

	float m_height = 2;
	float m_radius = 0.5f;
	float m_slopeLimit;
	float m_stepHeight;
	float m_walkVelocity;
	
	glm::vec3 m_walkDirection;
	glm::vec3 m_angularVelocity;
};