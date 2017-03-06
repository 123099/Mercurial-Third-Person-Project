#pragma once
#include <Behaviours\AbstractBehaviour.hpp>
class Sun final : public AbstractBehaviour
{
public:
	void Awake() override final;
	void Update() override final;
	void SetTimeToLose(float time);
	float GetPassedTime();

private:
	float m_timeToLoseGame;
	float m_timeWhenGameStarted;
	float passedTime;
};