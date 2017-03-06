#pragma once
#include <Behaviours\AbstractBehaviour.hpp>
#include <UI\TextLog.hpp>


class TextLogBehaviour final : public AbstractBehaviour 
{
public:
	TextLogBehaviour();

	void Awake() override final;
	void SetTimeToFade(float time);
	void SetTimeToErase(float time);
	void Update() override final;
	void Appear();
	TextLog& GetTextLog();

private:
	float m_timeToFade;
	float m_timeToErase;
	float m_lastFadeTime;
	float m_lastEraseTime;
	TextLog m_textlog;
};