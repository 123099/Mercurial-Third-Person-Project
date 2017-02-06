#pragma once
#include <Behaviours\AbstractBehaviour.hpp>
#include <SFML\System\Vector2.hpp>
#include <SFML\System\Clock.hpp>

class FreeLookCamera final : public AbstractBehaviour
{
public:
	void SetMoveSpeed(float speed);
	void SetRotationSpeed(float speed);

	void Awake() override final;
	void Update() override final;
private:
	float m_moveSpeed;
	float m_rotationSpeed;

	sf::Vector2i m_previousMousePos;
	float m_accumulatedXRotation;
	float m_accumulatedYRotation;

	sf::Clock m_accelerationClock;

	void Rotate();
	void Move();
};

