#pragma once
#include <Behaviours\AbstractBehaviour.hpp>
#include <Lua\Environment.hpp>
#include <memory>
#include <string>

class Script;

class LuaEnvironment final : public AbstractBehaviour
{
public:
	static LuaEnvironment* GetLua();

	void Awake() override final;
	void Update() override final;

	Script* LoadScript(const std::string& scriptName);

	template <typename T>
	void BindObject(T* instance, const std::string& typeName, const std::string& bindingName)
	{
		m_environment->BindObject(instance, typeName, bindingName);
	}

	template <typename T>
	void RegisterType(const std::string& typeName)
	{
		m_environment->RegisterLuaType<T>(typeName, false);
	}
private:
	std::unique_ptr<Environment> m_environment;
};