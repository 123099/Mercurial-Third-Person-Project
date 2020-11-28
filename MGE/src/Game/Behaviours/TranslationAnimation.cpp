#include <Game\Behaviours\TranslationAnimation.hpp>
#include <Behaviours\Transform.hpp>
#include <Behaviours\Rigidbody.hpp>
#include <Core\GameObject.hpp>

void TranslationAnimation::Start()
{
	m_rigidbody = m_gameObject->GetBehaviour<Rigidbody>();
	if (m_rigidbody != nullptr)
	{
		m_rigidbody->SetKinematic(true);
	}
}

void TranslationAnimation::Update()
{
	if (m_isMoving == true)
	{
		if (m_timer.IsReady())
		{
			m_gameObject->GetTransform()->Translate(m_stepMovement, Space::World);

			//If the distance is close enough, we have arrived at our destination
			const glm::vec3 vectorFromToStart = m_gameObject->GetTransform()->GetWorldPosition() - m_startLocation;
			if (glm::length(vectorFromToStart) >= m_distance)
			{
				m_isMoving = false;
			}
		}
	}
}

void TranslationAnimation::MoveInDirection(float distance, glm::vec3 direction, float movementTime)
{
	MoveTowards(distance, m_gameObject->GetTransform()->GetWorldPosition() + direction, movementTime);
}

void TranslationAnimation::MoveTowards(float distance, glm::vec3 position, float movementTime)
{
	m_isMoving = true;
	m_distance = distance;
	m_startLocation = m_gameObject->GetTransform()->GetWorldPosition();
	m_timer = Timer(movementTime / m_movementSteps);

	const float stepDistance = distance / m_movementSteps;
	m_stepMovement = stepDistance * glm::normalize(position - m_startLocation);
}

void TranslationAnimation::MoveTowards(float distance, Transform * target, float movementTime)
{
	MoveTowards(distance, target->GetWorldPosition(), movementTime);
}

bool TranslationAnimation::IsMoving()
{
	return m_isMoving;
}
