#include <Game\Behaviours\RotatingBehaviour.hpp>
#include <Core\GameObject.hpp>
#include <Core\Time.hpp>
#include <Behaviours\Transform.hpp>
#include <Core\Material.hpp>

void RotatingBehaviour::SetSpeed(float speed)
{
	m_speed = speed;
}

void RotatingBehaviour::Update()
{
	m_gameObject->GetTransform()->Rotate(glm::vec3(0, Time::s_deltaTime * m_speed, 0));
}
