#pragma once
#include <Behaviours\AbstractBehaviour.hpp>
#include <Utils\Timer.hpp>
#include <Utils\glm.hpp>

class Transform;
class Rigidbody;

class TranslationAnimation final : public AbstractBehaviour
{
public:
	void Start() override;
	void Update() override;

	void MoveTowards(float distance, Transform* target, float movementTime);
private:
	Timer m_timer;

	const int m_movementSteps = 20;

	Transform* m_target;
	Rigidbody* m_targetRigidbody;

	glm::vec3 m_targetLocation;
	glm::vec3 m_stepMovement;
};