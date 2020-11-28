#pragma once
#include <Behaviours\AbstractBehaviour.hpp>
#include <Utils\glm.hpp>

class RotationAnimation final : public AbstractBehaviour
{
public:
	void SetSpeed(glm::vec3 speed);

	void Update() override final;
private:
	glm::vec3 m_speed;
};