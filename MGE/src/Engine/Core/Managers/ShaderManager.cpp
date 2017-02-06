#include "ShaderManager.hpp"
#include <experimental\filesystem>
#include <Core\config.hpp>

namespace fs = std::experimental::filesystem;

InstanceCache<Shader> ShaderManager::s_loadedShaders;

Shader* ShaderManager::FindShader(const std::string & shaderName)
{
	if (IsShaderLoaded(shaderName) == false)
	{
		//The shader wasn't found
		std::cerr << "Warning: Shader " << shaderName << " was not found!" << '\n';
		return nullptr;
	}
	else
	{
		//Return the shader pointer
		return s_loadedShaders.GetValue(shaderName);
	}
}

bool ShaderManager::IsShaderLoaded(const std::string & shaderName)
{
	return s_loadedShaders.HasValue(shaderName);
}

void ShaderManager::AddShader(Shader* shader)
{
	s_loadedShaders.AddValue(shader);
}

InstanceCache<Shader>& ShaderManager::GetShaders()
{
	return s_loadedShaders;
}

void ShaderManager::LoadShaders()
{
	//Modify the shaders path and replace forward slashes with back slashes
	std::string filesystemShadersPath = config::MGE_SHADERS_PATH;
	std::replace(filesystemShadersPath.begin(), filesystemShadersPath.end(), '/', '\\');

	//Iterate through the shaders directory
	for (fs::recursive_directory_iterator dir(fs::path(filesystemShadersPath.c_str())), end; dir != end; ++dir)
	{
		//Retrieve the current path
		fs::path path = dir->path();
		
		//Make sure the current path is a file ending with .vs
		if (path.has_extension() && path.extension() == ".vs")
		{
			//Remove the file extension
			path.replace_extension("");

			//Remove the shaders path from the relative path of the shader file
			const std::string shaderRelativePath = path.relative_path().generic_string().replace(0, filesystemShadersPath.length(), "");

			//Load the shader using the relative path
			Shader* shader = new Shader(shaderRelativePath);

			//Cache the shader
			AddShader(shader);
		}
	}
}
