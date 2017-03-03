#include "TextLogBehaviour.hpp"
#include <Core\Time.hpp>
#include <Input\Input.hpp>

void TextLogBehaviour::Awake()
{
	SetTimeToFade(10.0f);
	m_lastFadeTime = Time::s_gameTime;
}

void TextLogBehaviour::SetTimeToFade(float time)
{
	m_timeToFade = time;
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
