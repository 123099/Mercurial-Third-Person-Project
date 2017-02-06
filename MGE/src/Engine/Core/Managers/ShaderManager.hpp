#pragma once
#include <unordered_map>
#include <string>
#include <memory>
#include <Core\Shader.hpp>
#include <Utils\InstanceCache.hpp>

class ShaderManager
{
public:
	ShaderManager() = delete;

	static void LoadShaders();

	static Shader* FindShader(const std::string& shaderName);
	static bool IsShaderLoaded(const std::string& shaderName);
	static void AddShader(Shader* shader);

	static InstanceCache<Shader>& GetShaders();
private:
	static InstanceCache<Shader> s_loadedShaders;
};

