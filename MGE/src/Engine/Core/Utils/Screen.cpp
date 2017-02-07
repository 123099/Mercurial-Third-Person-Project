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
