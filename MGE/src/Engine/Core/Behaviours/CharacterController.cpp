#include "CharacterController.hpp"
#include <Physics\Physics.hpp>
#include <Core\GameObject.hpp>
#include <Behaviours\Transform.hpp>
#include <Core\Time.hpp>

CharacterController::~CharacterController()
{
	Physics::Instance().RemoveCollisionObject(m_ghostObject.get());
	Physics::Instance().RemoveAction(m_characterController.get());
}

void CharacterController::Awake()
{
	m_ghostObject = std::make_unique<btPairCachingGhostObject>();
	m_capsuleCollider = std::make_unique<btCapsuleShapeZ>(m_radius, m_height);

	const glm::vec3 transformWorldPosition = m_gameObject->GetTransform()->GetWorldPosition();
	const btTransform startTransform(m_gameObject->GetTransform()->GetWorldRotation(), btVector3(transformWorldPosition.x, transformWorldPosition.y, transformWorldPosition.z));
	m_ghostObject->setWorldTransform(startTransform);

	m_ghostObject->setActivationState(DISABLE_DEACTIVATION);
	m_ghostObject->setCollisionShape(m_capsuleCollider.get());
	m_ghostObject->setCollisionFlags(btCollisionObject::CF_CHARACTER_OBJECT | btCollisionObject::CF_STATIC_OBJECT);

	m_characterController = std::make_unique<btKinematicCharacterController>(m_ghostObject.get(), m_capsuleCollider.get(), m_stepHeight, btVector3(0, 1, 0));
	m_characterController->setMaxSlope(btRadians(m_slopeLimit));

	const glm::vec3 gravity = Physics::Instance().GetGravity();
	m_characterController->setGravity(btVector3(gravity.x, gravity.y, gravity.z));

	m_characterController->setMaxJumpHeight(5);

	Physics::Instance().AddCollisionObject(m_ghostObject.get());
	Physics::Instance().AddAction(m_characterController.get());
}

void CharacterController::FixedUpdate()
{
	//Move character based on walk direction and velocity
	m_characterController->setWalkDirection(btVector3(m_walkDirection.x, m_walkDirection.y, m_walkDirection.z) * m_walkVelocity * Time::s_deltaTime);

	//Rotate character bsaed on angular velocity
	m_characterController->setAngularVelocity(btVector3(glm::radians(m_angularVelocity.x), glm::radians(m_angularVelocity.y), glm::radians(m_angularVelocity.z)));
}

void CharacterController::Update()
{
	//Retrieve the physical transform of the controller
	const btTransform transform = m_ghostObject->getWorldTransform();

	//Apply transform to engine transform
	const btVector3 origin = transform.getOrigin();
	const Quaternion rotation = transform.getRotation();

	m_gameObject->GetTransform()->SetWorldPosition(glm::vec3(origin.getX(), origin.getY(), origin.getZ()));
	m_gameObject->GetTransform()->SetWorldRotation(rotation);

	std::cout << m_characterController->getAngularVelocity().getY() << ',' << rotation.GetEulerAngles() << '\n';
}

void CharacterController::SetHeight(float height)
{
	m_height = height;
}

void CharacterController::SetRadius(float radius)
{
	m_radius = radius;
}

void CharacterController::SetSlopeLimit(float slopeLimit)
{
	m_slopeLimit = slopeLimit;
}

void CharacterController::SetStepHeight(float stepHeight)
{
	m_stepHeight = stepHeight;
}

void CharacterController::SetWalkVelocity(float velocity)
{
	m_walkVelocity = velocity;
}

void CharacterController::SetWalkDirection(glm::vec3 direction)
{
	m_walkDirection = direction;
}

void CharacterController::SetAngularVelocity(glm::vec3 velocity)
{
	m_angularVelocity = velocity;
}

void CharacterController::Jump()
{
	if (m_characterController->canJump())
	{
		m_characterController->jump(btVector3(0, 5, 0));
	}
}
