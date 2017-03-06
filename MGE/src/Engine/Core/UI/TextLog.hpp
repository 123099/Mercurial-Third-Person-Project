#pragma once
#include <UI\UI.h>
#include <SFML\Graphics\Font.hpp>
#include <SFML\Graphics\Text.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Texture.hpp>
#include <Utils\glm.hpp>
#include <string>

class TextLog :	public UI
{
public:
	TextLog(const std::string& fontFileName);
	
	void SetBackground(const std::string& boxFileName);
	void SetFontColor(sf::Color color);
	void SetFontSize(unsigned size);

	void AddText(const std::string& text);
	void AddTextOnTop(const std::string& text);

	void SetText(const std::string& text);
	std::string GetText();

	void SetPositionOnScreen(float x, float y);

	void OnDraw(sf::RenderWindow& window) override;
private:
	sf::Font m_gameFont;
	sf::Text m_logText;
	sf::Color m_fontColor;
	sf::Sprite m_boxSprite;
	sf::Texture m_boxTexture;
};

