#pragma once
#include <Utils\Singleton.hpp>
#include <string>

class Debug final : public Singleton<Debug>
{
friend Singleton<Debug>;

public:
	void Log(const std::string& text, int color = 15);
	void LogSuccess(const std::string& text);
	void LogWarning(const std::string& text);
	void LogError(const std::string& text);
private:
	Debug() = default;
};