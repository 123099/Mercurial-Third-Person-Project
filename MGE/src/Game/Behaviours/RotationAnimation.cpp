#include <Game\Behaviours\RotationAnimation.hpp>
#include <Core\Time.hpp>
#include <Core\GameObject.hpp>
#include <Behaviours\Transform.hpp>

void RotationAnimation::SetSpeed(glm::vec3 speed)
{
	m_speed = speed;
}

void RotationAnimation::Update()
{
	m_gameObject->GetTransform()->Rotate(m_speed * Time::s_deltaTime);
}
