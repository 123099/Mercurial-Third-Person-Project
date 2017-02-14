#pragma once
#include "UI.h"
#include <SFML/Graphics.hpp>
class TextLog :
	public UI
{
public:
	void createLog();
	void setLogInfo(std::string logInfo);
	void Draw() override;
	

private:
	sf::Font gameFont;
	sf::Text logText;
	sf::RenderWindow * window;
};

