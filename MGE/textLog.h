#pragma once
#include <UI\UI.h>
#include <SFML/Graphics.hpp>
class textLog :
	public UI
{
public:
	void createLog(sf::Font gameFont);
	void setLogInfo(std::string logInfo);
	void Draw() override;
	

private:
	sf::Font gameFont;
	sf::Text logText;
	sf::RenderWindow * window;
};

