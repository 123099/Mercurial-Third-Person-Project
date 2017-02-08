#include "Cursor.hpp"
#include <SFML\Window.hpp>
#include <Core\Time.hpp>

void Cursor::SetWindow(sf::RenderWindow * window)
{
	m_window = window;
}

void Cursor::SetCursorVisible(bool visible)
{
	if (m_window != nullptr)
	{
		m_window->setMouseCursorVisible(visible);
	}
}

void Cursor::SetCursorMode(Mode cursorMode)
{
	if (m_window != nullptr)
	{
		m_cursorMode = cursorMode;

		switch (cursorMode)
		{
		case Mode::Unlocked:
			m_window->setMouseCursorGrabbed(false);
			break;
		case Mode::Locked:
		case Mode::LockedAndCentered:
			m_window->setMouseCursorGrabbed(true);
			break;
		}
	}
}

Cursor::Mode Cursor::GetCursorMode() const
{
	return m_cursorMode;
}

void Cursor::Update()
{
	//Update the cursor's position if it should be centered
	if (m_cursorMode == Mode::LockedAndCentered && Time::s_frameCount % 5 == 0)
	{
		sf::Mouse::setPosition(sf::Vector2i(m_window->getSize().x / 2, m_window->getSize().y / 2), *m_window);
	}
}
