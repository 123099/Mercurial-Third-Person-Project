#include "Shader.hpp"
#include <iostream>
#include <fstream>
#include <Core\config.hpp>
#include <Utils\File.hpp>
#include <Managers\ShaderManager.hpp>
#include <experimental\filesystem>

namespace fs = std::experimental::filesystem;

#pragma region Shader Helpers Defs

static const std::string vertexShaderExtension = ".vs";
static const std::string fragmentShaderExtension = ".fs";

static bool CheckShaderFilesExist(const std::string& shaderName);
static void CheckProgramError(GLuint program, GLuint testParameter, const std::string& errorMessage);
static void CheckShaderError(GLuint shader, GLuint testParameter, const std::string& errorMessage);
static GLuint CreateShader(const std::string& shaderName, const std::string& shaderCode, GLenum shaderType);
static std::unordered_map<std::string, GLint> LoadUniforms(GLuint program);

#pragma endregion

Shader* Shader::Find(const std::string & shaderName)
{
	return ShaderManager::FindShader(shaderName);
}

Shader::Shader(const std::string& shaderName)
{
	//Make sure that this shader wasn't already loaded
	if (ShaderManager::IsShaderLoaded(shaderName) == false)
	{
		//Make sure that the shader files exist
		if (CheckShaderFilesExist(shaderName) == false)
		{
			return;
		}

		//Create a new shader program
		m_programID = glCreateProgram();

		//Create the shaders
		m_shaders[ShaderType::VERTEX] = CreateShader(m_name, File::GetContents(config::MGE_SHADERS_PATH + shaderName + ".vs"), GL_VERTEX_SHADER);
		m_shaders[ShaderType::FRAGMENT] = CreateShader(m_name, File::GetContents(config::MGE_SHADERS_PATH + shaderName + ".fs"), GL_FRAGMENT_SHADER);

		//Optionally load a geometry shader
		if (fs::exists(config::MGE_SHADERS_PATH + shaderName + ".gs"))
		{
			m_shaders[ShaderType::GEOMETRY] = CreateShader(m_name, File::GetContents(config::MGE_SHADERS_PATH + shaderName + ".gs"), GL_GEOMETRY_SHADER);
		}

		//Attach shaders to program
		for (unsigned int i = 0; i < ShaderType::NUM_SHADERS; ++i)
		{
			glAttachShader(m_programID, m_shaders[i]);
		}

		//Link the shader program
		glLinkProgram(m_programID);
		CheckProgramError(m_programID, GL_LINK_STATUS, "Error: Shader Program linking failed [" + m_name + "]");

		std::cout << "Shader " << shaderName << " ID " << m_programID << " created successfully!" << '\n';

		//Register all the uniforms in the shader
		m_uniforms = LoadUniforms(m_programID);

		//Load the light buffer index
		m_lightDataBufferBlockIndex = glGetProgramResourceIndex(m_programID, GL_SHADER_STORAGE_BLOCK, "lightData");
	}
	else
	{
		//Make this instance a copy of the already loaded shader
		*this = *ShaderManager::FindShader(shaderName);
	}

	m_name = shaderName;
}

Shader::~Shader() 
{
	//Delete the individual shaders
	for (unsigned int i = 0; i < ShaderType::NUM_SHADERS; ++i)
	{
		//Detach the shader from the program
		glDetachShader(m_programID, m_shaders[i]);

		//Delete the shader
		glDeleteShader(m_shaders[i]);
	}
	//Delete the shader program
	glDeleteProgram(m_programID);
}

GLuint Shader::GetProgramID()
{
	return m_programID;
}

void Shader::Bind()
{
	glUseProgram(m_programID);
}

void Shader::Validate()
{
	glValidateProgram(m_programID);
	CheckProgramError(m_programID, GL_VALIDATE_STATUS, "Error: Shader Program is invalid [" + m_name + "]");
}

void Shader::Unbind()
{
	glUseProgram(0);
}

GLuint Shader::GetAttribute(const std::string& attributeName)
{
	//Try to locate the attribute in the cache
	auto itr = m_attributes.find(attributeName);

	if (itr != m_attributes.end())
	{
		//The attribute was cached. Return the ID from the cache
		return itr->second;
	}
	else
	{
		//Locate the attribute and cache it for future use
		GLint attribID = glGetAttribLocation(m_programID, attributeName.c_str());
		m_attributes[attributeName] = attribID;
		return attribID;
	}
}

GLuint Shader::GetUniform(const std::string& uniformName)
{
	if (m_uniforms.find(uniformName) != m_uniforms.end())
	{
		return m_uniforms[uniformName];
	}
	else
	{
		return -1;
	}
}

GLuint Shader::GetLightBufferBlockIndex()
{
	return m_lightDataBufferBlockIndex;
}

void Shader::SetProperty(const ShaderProperty & property)
{
	GLuint propertyID = GetUniform(property.name);

	if (propertyID == -1)
	{
		return;
	}

	switch (property.type)
	{
	case PropertyType::Integer:
		glUniform1i(propertyID, property.intValue);
		break;
	case PropertyType::Float:
		glUniform1f(propertyID, property.floatValue);
		break;
	case PropertyType::Matrix:
		glUniformMatrix4fv(propertyID, 1, GL_FALSE, glm::value_ptr(property.matrixValue));
		break;
	case PropertyType::Texture:
	{
		//Retrieve the currently active texture unit
		GLint activeTextureUnit = 0;
		glGetIntegerv(GL_ACTIVE_TEXTURE, &activeTextureUnit);
		activeTextureUnit -= GL_TEXTURE0;
		
		//Pass the currently active texture unit to the shader as the uniform variable
		glUniform1i(propertyID, activeTextureUnit);
	}
		break;
	case PropertyType::Vector:
		//TODO: Add dimensions property to the vector to allow vec2, 3 and 4
		glUniform4fv(propertyID, 1, glm::value_ptr(property.vectorValue));
		break;
	}
}

#pragma region Shader Helpers Imp

static GLuint CreateShader(const std::string& shaderName, const std::string& shaderCode, GLenum shaderType)
{
	GLuint shader = glCreateShader(shaderType);

	//Handle shader creation failure in case of out of memory or something else
	if (shader == 0)
	{
		std::cerr << "Error: Failed to create shader!" << '\n';
		return 0;
	}

	//Create an array of c-style strings containing the source codes of the shaders
	const GLchar* shaderSourceCodes[1] = { shaderCode.c_str() };

	//Create an array of the lengths of each source code
	const GLint shaderSourceCodeLengths[1] = { (GLint) shaderCode.length() };

	//Feed the source codes to OpenGL
	glShaderSource(shader, 1, shaderSourceCodes, shaderSourceCodeLengths);

	//Compile the shader
	glCompileShader(shader);

	//Check for possible compilation errors
	CheckShaderError(shader, GL_COMPILE_STATUS, "Error: Shader compilation failed [" + shaderName + "]");

	return shader;
}

static bool CheckShaderFilesExist(const std::string& shaderName)
{
	//Get the full shader file path
	std::string shaderPath = config::MGE_SHADERS_PATH + shaderName;

	if (fs::exists(shaderPath + vertexShaderExtension) == false)
	{
		std::cerr << "Error: Couldn't find vertex shader file at " << shaderPath << vertexShaderExtension << '\n';
		return false;
	}

	if (fs::exists(shaderPath + fragmentShaderExtension) == false)
	{
		std::cerr << "Error: Couldn't find fragment shader file at " << shaderPath << fragmentShaderExtension << '\n';
		return false;
	}

	return true;
}

static void CheckProgramError(GLuint program, GLuint testParameter, const std::string& errorMessage)
{
	//Get the specified test parameter from the program
	GLint success = 0;
	glGetProgramiv(program, testParameter, &success);

	//If the result of the specified test parameter is FALSE, get the error log and output it to the user
	if (success == GL_FALSE)
	{
		//Retrieve the info log length
		GLint logLength = 0;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);

		//Construct a char vector the length of the log length
		std::vector<char> log(logLength);

		//Retrieve the log of the error
		glGetProgramInfoLog(program, log.size(), nullptr, &log[0]);

		//Display the log
		std::cerr << errorMessage << ": (" << std::string(log.begin(), log.end() - 1) << ") " << '\n';

		//Break the program
		throw std::exception();
	}
 }

static void CheckShaderError(GLuint shader, GLuint testParameter, const std::string& errorMessage)
{
	//Get the specified test parameter from the shader
	GLint success = 0;
	glGetShaderiv(shader, testParameter, &success);

	//If the result of the specified test parameter is FALSE, get the error log and output it to the user
	if (success == GL_FALSE)
	{
		//Retrieve the info log length
		GLint logLength = 0;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);

		//Construct a char vector the length of the log length
		std::vector<char> log(logLength);
		
		//Retrieve the log of the error
		glGetShaderInfoLog(shader, log.size(), nullptr, &log[0]);

		//Display the log
		std::cerr << errorMessage << ": (" << std::string(log.begin(), log.end() - 1) << ") " << '\n';

		//Break the program
		throw std::exception();
	}
}

std::unordered_map<std::string, GLint> LoadUniforms(GLuint program)
{
	//Create a map to contain all the uniforms
	std::unordered_map<std::string, GLint> uniforms;

	//Retrieve the number of active uniforms in the shader
	GLint uniformCount = 0;
	glGetProgramInterfaceiv(program, GL_UNIFORM, GL_ACTIVE_RESOURCES, &uniformCount);

	//Array defining the properties to query
	const GLenum properties[3] = { GL_BLOCK_INDEX, GL_NAME_LENGTH, GL_LOCATION };

	//Retrieve every uniform from the shader
	for (int i = 0; i < uniformCount; ++i)
	{
		//Create an array that will store the queried data
		GLint values[3];

		//Query the program for the uniform's information
		glGetProgramResourceiv(program, GL_UNIFORM, i, 3, properties, 3, nullptr, values);

		//If the block index is not -1, then the uniform is part of a uniform block and should be ignored
		if (values[0] == -1)
		{
			//Create a character vector for the name
			std::vector<char> uniformName(values[1]);

			//Retrieve the name of the uniform
			glGetProgramResourceName(program, GL_UNIFORM, i, uniformName.size(), nullptr, &uniformName[0]);

			//Convert the char vector to a string, excluding the null terminator in the last cell
			const std::string stringName = std::string(uniformName.begin(), uniformName.end() - 1);

			//Add the information to the map
			uniforms[stringName] = values[2];

			std::cout << "\tLoaded uniform " << stringName << '\n';
		}
	}

	return uniforms;
}

#pragma endregion