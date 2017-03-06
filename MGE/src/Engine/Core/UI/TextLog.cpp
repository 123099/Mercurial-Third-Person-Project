#include <UI\TextLog.hpp>
#include <Core\config.hpp>

TextLog::TextLog(const std::string& fontFileName)
{
	m_gameFont.loadFromFile(config::MGE_FONTS_PATH + fontFileName);
	m_logText.setFont(m_gameFont);

	SetText("");
	SetFontSize(14);
	SetFontColor(sf::Color::White);
}

void TextLog::SetBackground(const std::string& boxFileName)
{
	m_boxTexture.loadFromFile(config::MGE_SPRITES_PATH + boxFileName);
	m_boxSprite.setTexture(m_boxTexture);
}

void TextLog::SetFontColor(sf::Color color)
{
	m_fontColor = color;
	m_logText.setFillColor(color);
}

void TextLog::SetFontSize(unsigned size)
{
	m_logText.setCharacterSize(size);
}

void TextLog::AddText(const std::string & text)
{
	SetText(GetText() + text);
}

void TextLog::AddTextOnTop(const std::string & text)
{
	SetText(text + GetText());
}

void TextLog::SetText(const std::string & text)
{
	m_logText.setString(text);
}

std::string TextLog::GetText()
{
	return m_logText.getString();
}

void TextLog::SetPositionOnScreen(float x, float y)
{
	m_logText.setPosition(x, y);
	m_boxSprite.setPosition(x, y);
}

void TextLog::OnDraw(sf::RenderWindow& window)
{
	window.draw(m_boxSprite);
	window.draw(m_logText);
}


