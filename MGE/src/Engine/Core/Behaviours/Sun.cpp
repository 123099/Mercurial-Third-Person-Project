#include "Sun.hpp"
#include <Core\Time.hpp>

void Sun::Awake()
{
	SetTimeToLose(1200.0f);
	m_timeWhenGameStarted= Time::s_gameTime;
}

void Sun::Update()
{
	if(Time::s_gameTime - m_timeWhenGameStarted >=m_timeToLoseGame)
		//lose game


}

void Sun::SetTimeToLose(float time)
{
	m_timeToLoseGame = time;
}
