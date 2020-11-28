#pragma once
#include <UI\textLog.h>
#include <SFML/Graphics.hpp>
class TextInput :
	public textLog
{
public:
	void CreateInputBox(sf::Font inputFont, sf::Sprite inputBox);
	void Draw() override;


private:
	sf::Sprite inputBox
	sf::Font inputFont;
	sf::Text inputText;
	sf::RenderWindow * window;
};

