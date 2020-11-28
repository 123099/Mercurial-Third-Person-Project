#include "Door.hpp"
#include <Core\GameObject.hpp>
#include <Behaviours\Transform.hpp>

void Door::Awake()
{
	m_isOpen = false;
	m_rightDirection = m_gameObject->GetTransform()->GetRightVector();

	m_leftPart = m_gameObject->GetBehavioursInChildren<TranslationAnimation>()[0];
	m_rightPart = m_gameObject->GetBehavioursInChildren<TranslationAnimation>()[1];
}

void Door::Open()
{
	if (m_isOpen == false && m_leftPart->IsMoving() == false && m_rightPart->IsMoving() == false)
	{
		m_isOpen = true;
		Move();
	}
}

void Door::Close()
{
	if (m_isOpen == true && m_leftPart->IsMoving() == false && m_rightPart->IsMoving() == false)
	{
		m_isOpen = false;
		Move();
	}
}

bool Door::IsOpen()
{
	return m_isOpen;
}

bool Door::IsMoving()
{
	return m_leftPart->IsMoving() == true || m_rightPart->IsMoving() == true;
}

void Door::Move()
{
	const float distance = 2.5f;
	const float time = 1.5f;
	
	if (m_isOpen == true)
	{
		m_leftPart->MoveInDirection(distance, -m_rightDirection, time);
		m_rightPart->MoveInDirection(distance, m_rightDirection, time);
	}
	else
	{
		m_leftPart->MoveInDirection(distance, m_rightDirection, time);
		m_rightPart->MoveInDirection(distance, -m_rightDirection, time);
	}
}
