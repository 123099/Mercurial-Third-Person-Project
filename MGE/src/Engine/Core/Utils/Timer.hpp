#pragma once
#include <Core\Time.hpp>

class Timer
{
public:
	Timer() : m_period(2) {}
	Timer(float period);

	void Restart();

	bool IsReady();
private:
	float m_startTime;
	float m_period;
};