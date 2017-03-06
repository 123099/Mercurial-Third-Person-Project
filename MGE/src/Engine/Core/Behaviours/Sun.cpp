#include "Sun.hpp"
#include <Core\Time.hpp>
#include <Core\GameObject.hpp>
#include <Behaviours\PostProcessors\Trannsition.hpp>

void Sun::Awake()
{
	SetTimeToLose(1200.0f);
	m_timeWhenGameStarted= Time::s_gameTime;
}

void Sun::Update()
{
	//lose game
	if (Time::s_gameTime - m_timeWhenGameStarted >= m_timeToLoseGame)
	{
		m_gameObject->AddBehaviour<Transition>();
		if (Time::s_gameTime - m_timeWhenGameStarted >= m_timeToLoseGame + 5);
			//TODO: Restart game;

	}
}

void Sun::SetTimeToLose(float time)
{
	m_timeToLoseGame = time;
}
