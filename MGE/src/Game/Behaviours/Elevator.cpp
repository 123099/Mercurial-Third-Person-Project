#include "Elevator.hpp"
#include <Core\GameObject.hpp>
#include <Core\Time.hpp>
#include <Behaviours\Transform.hpp>
#include <Input\Input.hpp>
void Elevator::Awake()
{
	m_positionA = m_gameObject->GetTransform()->GetLocalPosition();
	m_targetPosition = m_positionA;
}

void Elevator::Update()
{
	if (Input::IsKeyPressed(sf::Keyboard::Num9))
		GoToPointA();
	if (Input::IsKeyPressed(sf::Keyboard::Num0))
		GoToPointB();

	if (m_gameObject->GetTransform()->GetLocalPosition() != m_targetPosition)
	{
		Move();
	}
}

void Elevator::SetSpeed(float speed)
{
	m_speed = speed;
}

void Elevator::SetPointB(glm::vec3 pointB)
{
	m_positionB = pointB;
}

void Elevator::GoToPointA()
{
	m_targetPosition = m_positionA;
}

void Elevator::GoToPointB()
{
	m_targetPosition = m_positionB;
}

bool Elevator::IsAtPointA()
{
	return m_gameObject->GetTransform()->GetLocalPosition() == m_positionA;
}

void Elevator::Move()
{
	const glm::vec3 direction = glm::normalize(m_targetPosition - m_gameObject->GetTransform()->GetLocalPosition());
	const glm::vec3 translation = direction * m_speed * Time::s_deltaTime;

	if (glm::distance(m_gameObject->GetTransform()->GetLocalPosition() + translation, m_targetPosition) < 0.02f)
	{
		m_gameObject->GetTransform()->SetLocalPosition(m_targetPosition);
	}
	else
	{
		m_gameObject->GetTransform()->Translate(direction * m_speed * Time::s_deltaTime);
	}
}
