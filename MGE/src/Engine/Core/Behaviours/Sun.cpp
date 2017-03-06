#include "Sun.hpp"
#include <Core\Time.hpp>
#include <Core\GameObject.hpp>
#include <Behaviours\PostProcessors\Trannsition.hpp>
#include <Behaviours\Transform.hpp>

void Sun::Awake()
{
	SetTimeToLose(1200.0f);
	m_timeWhenGameStarted= Time::s_gameTime;
}

void Sun::Update()
{
	//lose game
	if (GetPassedTime() >= m_timeToLoseGame)
	{
		m_gameObject->AddBehaviour<Transition>();
		if (GetPassedTime() >= m_timeToLoseGame + 5);
			//TODO: Restart game;

	}
	m_gameObject->GetTransform()->SetLocalScale(m_gameObject->GetTransform()->GetLocalScale()*GetPassedTime() / m_timeToLoseGame+glm::vec3(0.8f));
	
}

void Sun::SetTimeToLose(float time)
{
	m_timeToLoseGame = time;
}

float Sun::GetPassedTime()
{
	return Time::s_gameTime - m_timeWhenGameStarted;
}
