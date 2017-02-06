#pragma once
#include <Behaviours\AbstractBehaviour.hpp>
#include <string>

class LuaEnvironment;
class Script;

class LuaScript final : public AbstractBehaviour
{
public:
	void SetScript(const std::string& scriptName);
	void SetEnvironment(LuaEnvironment* environment);

	void Execute();

	void Start() override final;
private:
	LuaEnvironment* m_environment;
	Script* m_script;

	std::string m_scriptName;
};