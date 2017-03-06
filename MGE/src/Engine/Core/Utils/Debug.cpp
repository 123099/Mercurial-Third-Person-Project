#include "Debug.hpp"
#include <Windows.h>
#include <iostream>

void Debug::Log(const std::string & text, int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	std::cout << text << '\n';
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void Debug::LogSuccess(const std::string & text)
{
	Log("[Success] " + text, 10);
}

void Debug::LogWarning(const std::string & text)
{
	Log("[Warning] " + text, 14);
}

void Debug::LogError(const std::string & text)
{
	Log("[Error] " + text, 12);
}
