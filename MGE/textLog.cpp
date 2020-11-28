#include <UI\textLog.h>

void textLog::createLog(sf::Font gameFont) 
{
	logText.setString("");
	logText.setFont(gameFont);
	logText.setCharacterSize(18);
	logText.setFillColor(sf::Color::White);
}


void textLog::setLogInfo(std::string logInfo)
{
	logText.setString(logInfo);
	logText.setPosition(10, 10);
}


void textLog::Draw()
{
	window->draw(logText);
}


