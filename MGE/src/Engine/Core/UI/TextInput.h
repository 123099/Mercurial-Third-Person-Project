#pragma once
#include <textLog.h>
class TextInput :
	public UI
{
public:
	void createInputBox(sf::Font inputFont, sf::Sprite inputBox);
	void Draw() override;


private:
	sf::Font inputFont;
	sf::Text inputText;
	sf::RenderWindow * window;
};

