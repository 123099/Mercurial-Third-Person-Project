#pragma once
#include <UI\UI.h>
#include <SFML\Graphics\Font.hpp>
#include <SFML\Graphics\Text.hpp>
#include <Utils\glm.hpp>
#include <string>

class TextLog :	public UI
{
public:
	TextLog(const std::string& fontFileName);

	void SetFontColor(sf::Color color);
	void SetFontSize(unsigned size);

	void AddText(const std::string& text);
	void SetText(const std::string& text);
	std::string GetText();

	void SetPositionOnScreen(float x, float y);

	void Draw(sf::RenderWindow& window) override;
private:
	sf::Font m_gameFont;
	sf::Text m_logText;
	sf::Color m_fontColor;
};

