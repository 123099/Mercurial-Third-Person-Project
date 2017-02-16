#pragma once
#include<string>
#include <SFML/Graphics.hpp>
class UI
{
public:
	virtual void Draw() = 0;

private:
	sf::RenderWindow * _window;
};

