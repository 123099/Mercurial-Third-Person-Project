#pragma once
#include <Behaviours\AbstractBehaviour.hpp>
class Sun final : public AbstractBehaviour
{
public:
	void Awake() override final;
	void Update() override final;
	void SetTimeToLose(float time);

private:
	float m_timeToLoseGame;
	float m_timeWhenGameStarted;
};