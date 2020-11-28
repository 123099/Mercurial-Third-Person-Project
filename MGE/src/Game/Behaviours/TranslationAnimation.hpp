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

	void MoveInDirection(float distance, glm::vec3 direction, float movementTime);
	void MoveTowards(float distance, glm::vec3 position, float movementTime);
	void MoveTowards(float distance, Transform* target, float movementTime);

	bool IsMoving();
private:
	Timer m_timer;

	const int m_movementSteps = 35;

	Rigidbody* m_rigidbody;

	glm::vec3 m_startLocation;
	glm::vec3 m_stepMovement;
	float m_distance;

	bool m_isMoving;
};