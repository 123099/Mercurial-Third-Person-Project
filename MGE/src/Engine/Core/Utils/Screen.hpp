#pragma once
#include <SFML\Graphics\RenderWindow.hpp>
#include <Utils\Singleton.hpp>

class Screen final : public Singleton<Screen>
{
friend Singleton<Screen>;
public:
	void SetWindow(sf::RenderWindow* window);

	int GetWidth() const;
	int GetHeight() const;
private:
	sf::RenderWindow* m_window;
};