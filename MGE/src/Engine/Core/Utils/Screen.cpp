#include "Screen.hpp"

void Screen::SetWindow(sf::RenderWindow * window)
{
	m_window = window;
}

int Screen::GetWidth() const
{
	return m_window->getSize().x;
}

int Screen::GetHeight() const
{
	return m_window->getSize().y;
}

glm::vec2 Screen::GetResolution()
{
	return glm::vec2(GetWidth(), GetHeight());
}

glm::vec2 Screen::GetWindowCenter()
{
	return GetResolution() * 0.5f;
}
