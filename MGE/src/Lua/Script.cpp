#include <Lua\Script.hpp>
#include <LuaAPI\lua.hpp>
#include <Lua\Environment.hpp>
#include <Lua\Closure.hpp>

Script::Script(Environment & luaEnvironment, const std::string & scriptName) :
	m_luaEnvironment(luaEnvironment),
	m_scriptName(scriptName)
{
	m_luaFunction = luaEnvironment.LoadScriptAsFunction(scriptName);
}

void Script::Execute() 
{
	m_luaFunction->Call();
}
