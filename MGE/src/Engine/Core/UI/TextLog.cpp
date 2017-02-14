#include <UI\TextLog.hpp>
#include <Core\config.hpp>

void TextLog::createLog()
{
	gameFont.loadFromFile(config::MGE_FONTS_PATH + "couree.fon");

	logText.setString("");
	logText.setFont(gameFont);
	logText.setCharacterSize(18);
	logText.setFillColor(sf::Color::White);
}


void TextLog::setLogInfo(std::string logInfo)
{
	logText.setString(logInfo);
	logText.setPosition(10, 10);
}


void TextLog::Draw()
{
	window->draw(logText);
}


