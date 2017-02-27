#include <Game\Behaviours\TranslationAnimation.hpp>
#include <Behaviours\Transform.hpp>
#include <Behaviours\Rigidbody.hpp>
#include <Core\GameObject.hpp>

void TranslationAnimation::Start()
{
	m_target = nullptr;
	m_rigidbody = m_gameObject->GetBehaviour<Rigidbody>();
}

void TranslationAnimation::Update()
{
	if (m_target != nullptr)
	{
		if (m_timer.IsReady())
		{
			if (m_rigidbody != nullptr)
			{
				m_rigidbody->Translate(m_stepMovement);
			}
			else
			{
				m_gameObject->GetTransform()->Translate(m_stepMovement, Space::World);
			}

			//If the distance is close enough, we have arrived at our destination
			const glm::vec3 vectorFromToTarget = m_targetLocation - m_gameObject->GetTransform()->GetWorldPosition();
			if (glm::dot(vectorFromToTarget, vectorFromToTarget) < 0.1f)
			{
				//We are done, target is no longer necessary
				m_target = nullptr;
			}
		}
	}
}

void TranslationAnimation::MoveTowards(float distance, Transform * target, float movementTime)
{
	m_target = target;
	m_timer = Timer(movementTime / m_movementSteps);
	m_targetLocation = m_target->GetWorldPosition();

	const float stepDistance = distance / m_movementSteps;
	m_stepMovement = stepDistance * glm::normalize(m_targetLocation - m_gameObject->GetTransform()->GetWorldPosition());
}
