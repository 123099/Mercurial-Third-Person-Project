#pragma once
#include <Behaviours\AbstractBehaviour.hpp>
#include <Utils\glm.hpp>

class Elevator final : public AbstractBehaviour
{
public:
	void Awake() override final;
	void Update() override final;

	void SetSpeed(float speed);
	void SetPointB(glm::vec3 pointB);

	void GoToPointA();
	void GoToPointB();
private:	
	float m_speed;
	
	glm::vec3 m_positionA;
	glm::vec3 m_positionB;

	glm::vec3 m_targetPosition;
	bool m_isAtTarget;

	void Move();
};