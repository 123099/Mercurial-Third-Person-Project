#pragma once
#include <SFML\Graphics\RenderWindow.hpp>

class UI
{
public:
	UI();
	virtual ~UI();

	void SetVisible(bool visible);
	
	void Draw(sf::RenderWindow& window);
	virtual void OnDraw(sf::RenderWindow& window) = 0;
protected:
	bool m_isVisible;
};

