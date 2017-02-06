#pragma once
#include <string>
#include <Lua\Environment.hpp>

class Closure;

class Script 
{
public:
	Script(Environment& luaEnvironment, const std::string& scriptName);

	void Execute();
private:
	Environment& m_luaEnvironment;
	std::string m_scriptName;

	Closure* m_luaFunction;
};