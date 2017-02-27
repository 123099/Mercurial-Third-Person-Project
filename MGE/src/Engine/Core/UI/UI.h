#pragma once
#include <SFML\Graphics\RenderWindow.hpp>

class UI
{
public:
	UI();
	virtual ~UI();

	virtual void Draw(sf::RenderWindow& window) = 0;
};

