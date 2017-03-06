#include "TextLogBehaviour.hpp"
#include <Core\Time.hpp>
#include <Input\Input.hpp>

TextLogBehaviour::TextLogBehaviour() : m_textlog("arial.ttf") {}

void TextLogBehaviour::Awake()
{
	SetTimeToFade(10.0f);
	SetTimeToErase(150.0f);
	m_lastFadeTime = Time::s_gameTime;
	m_lastEraseTime = Time::s_gameTime;
}

void TextLogBehaviour::SetTimeToFade(float time)
{
	m_timeToFade = time;
}

void TextLogBehaviour::SetTimeToErase(float time)
{
	m_timeToErase = time;
}

void TextLogBehaviour::Update()
{
	if (Time::s_gameTime - m_lastFadeTime >= m_timeToFade)
	{
		m_textlog.SetVisible(false);
	}
	if (Input::IsKeyPressed(sf::Keyboard::Return)) 
	{
		Appear();
	}
	if (Time::s_gameTime - m_lastEraseTime >= m_timeToErase)
	{
		m_textlog.SetText("");
	}
}

void TextLogBehaviour::Appear()
{
	m_lastFadeTime = Time::s_gameTime;
	m_textlog.SetVisible(true);
}

TextLog & TextLogBehaviour::GetTextLog()
{
	return m_textlog;
}
