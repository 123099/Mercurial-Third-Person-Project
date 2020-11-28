#include "Sun.hpp"
#include <Core\Time.hpp>
#include <Core\GameObject.hpp>
#include <Behaviours\PostProcessors\Transition.hpp>
#include <Behaviours\Transform.hpp>

void Sun::Awake()
{
	m_lost = false;
	SetTimeToLose(3000.0f);
	m_timeWhenGameStarted= Time::s_gameTime;

	m_meshRenderer = m_gameObject->GetBehaviour<MeshRenderer>();
}

void Sun::Update()
{
	if (m_lost == true)
	{
		return;
	}

	//lose game
	if (GetPassedTime() >= m_timeToLoseGame)
	{
		Debug::Instance().LogError("You Lose!");
		m_lost = true;
		Transition* t = m_gameObject->AddBehaviour<Transition>();
		t->SetColor(glm::vec3(1.0f));
		t->SetDirection(1);
		t->Play();
	}

	m_gameObject->GetTransform()->SetLocalScale(m_gameObject->GetTransform()->GetLocalScale() * 2 * GetPassedTime() / m_timeToLoseGame + glm::vec3(3.0f));

	m_meshRenderer->GetSharedMaterial()->SetFloat("time", Time::s_gameTime);
}

void Sun::SetTimeToLose(float time)
{
	m_timeToLoseGame = time;
}

float Sun::GetPassedTime()
{
	return Time::s_gameTime - m_timeWhenGameStarted;
}
