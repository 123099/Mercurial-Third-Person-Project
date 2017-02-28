#pragma once
#ifndef MGE_SHADER_H
#define MGE_SHADER_H

#include <string>
#include <unordered_map>
#include <GL\glew.h>
#include <Core\ShaderProperty.hpp>
#include <Utils\ICacheable.hpp>

//Create Shader program
//Create a shader
//Upload shader source to opengl
//Compile the shader
//Attach the shader to the program
//Link the program
class Shader final : public ICacheable
{
public:
	static Shader* Find(const std::string& shaderName);

	Shader(const std::string& shaderName);
	~Shader();
	Shader(const Shader& shader) = default;

	GLuint GetProgramID();

	void Bind();
	void Validate();
	void Unbind();

	GLint GetAttribute(const std::string& attributeName);
	GLint GetUniform(const std::string& uniformName);

	bool HasLightBuffer();
	GLuint GetLightBufferBlockIndex();

	void SetProperty(const ShaderProperty& property);
protected:
private:
	enum ShaderType {
		VERTEX,
		GEOMETRY,
		FRAGMENT,
		NUM_SHADERS
	};

	GLuint m_shaders[NUM_SHADERS];

	GLuint m_programID;

	GLuint m_lightDataBufferBlockIndex;
	std::unordered_map<std::string, GLint> m_uniforms;
	std::unordered_map<std::string, GLint> m_attributes;
};

#endif // !MGE_SHADER_H