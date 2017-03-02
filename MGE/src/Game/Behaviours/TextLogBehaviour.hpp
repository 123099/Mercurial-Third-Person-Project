#pragma once
#include <Behaviours\AbstractBehaviour.hpp>
#include <UI\TextLog.hpp>


class TextLogBehaviour final : public AbstractBehaviour 
{
public:
	void Awake() override final;
	void SetTimeToFade(float time);
	void Update() override final;
	void Appear();
	TextLog& GetTextLog();

private:
	float m_timeToFade;
	float m_lastFadeTime;
	TextLog m_textlog;
};