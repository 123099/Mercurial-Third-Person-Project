#pragma once
#include <Behaviours\AbstractBehaviour.hpp>
#include <SFML\Graphics.hpp>

class CameraOrbit :	public AbstractBehaviour
{
public:
	CameraOrbit();

	void SetTarget(GameObject* l_target);
	void SetDistance(float distance);
	void SetMinTiltAngle(float angle);
	void SetMaxTiltAngle(float angle);
	void SetRotationSpeed(float rotationSpeed);

	void Update() override;

private:
	float m_distance;
	float m_minTiltAngle;
	float m_maxTiltAngle;
	float m_rotationSpeed;
	GameObject* m_target;

	float m_accumulatedYRotation;
	float m_accumulatedXRotation;
	sf::Vector2i m_previousMousePos;
};

