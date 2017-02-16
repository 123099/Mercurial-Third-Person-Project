#include "Timer.hpp"

Timer::Timer(float period)
{
	m_period = period;
	Restart();
}

void Timer::Restart()
{
	m_startTime = Time::s_gameTime;
}

bool Timer::IsReady()
{
	if (Time::s_gameTime - m_startTime <= m_period)
	{
		Restart();
		return true;
	}

	return false;
}
