#include <Behaviours\Lua\LuaScript.hpp>
#include <Behaviours\Lua\LuaEnvironment.hpp>
#include <Lua\Script.hpp>
#include <iostream>

void LuaScript::SetScript(const std::string & scriptName)
{
	m_scriptName = scriptName;
}

void LuaScript::SetEnvironment(LuaEnvironment* environment)
{
	m_environment = environment;
}

void LuaScript::Execute() 
{
	if (m_script != nullptr)
	{
		m_script->Execute();
	}
}

void LuaScript::Start()
{
	if (m_environment == nullptr)
	{
		SetEnvironment(LuaEnvironment::GetLua());
	}

	if (m_environment != nullptr && m_scriptName != "")
	{
		m_script = m_environment->LoadScript(m_scriptName);
	}
}
