#include <Core\Material.hpp>
#include <Managers\LightManager.hpp>
#include <Behaviours\Light.hpp>
#include <Core\Mesh.hpp>
#include <Core\config.hpp>
#include <fstream>

InstanceCache<Material> Material::s_materialCache;
Shader* Material::s_simpleShader = nullptr;

InstanceCache<Material>& Material::GetCache()
{
	return s_materialCache;
}

Material::Material(Shader* shader, const std::string& name) : m_shader(shader != nullptr ? *shader : *Shader::Find("unlit/default")), m_setTextureCount(0)
{
	m_name = name;
}

void Material::SetInteger(const std::string & propertyName, int value)
{
	ShaderProperty intProperty{
		propertyName,
		value
	};

	SetProperty(intProperty);
}

void Material::SetColor(const std::string & propertyName, glm::vec4 color)
{
	//Clamp the color to 0..1 range
	color = glm::clamp(color, glm::vec4(0), glm::vec4(1));

	//Pass the clamped value to the set vector method
	SetVector(propertyName, color);
}

void Material::SetFloat(const std::string & propertyName, float value)
{
	ShaderProperty floatProperty{
		propertyName,
		value
	};

	SetProperty(floatProperty);
}

void Material::SetMatrix(const std::string & propertyName, glm::mat4 matrix)
{
	ShaderProperty matrixProperty{
		propertyName,
		matrix
	};

	SetProperty(matrixProperty);
}

void Material::SetTexture(const std::string & propertyName, Texture* texture)
{
	//Make sure that the texture was already registered, thus, only replacing the value of the property, or that the material can have more textures registered
	if (CanBindExtraTexture() || HasProperty(propertyName))
	{
		ShaderProperty textureProperty{
			propertyName,
			texture
		};

		SetProperty(textureProperty);

		if (CanBindExtraTexture())
		{
			++m_setTextureCount;
		}
	}
}

void Material::SetVector(const std::string & propertyName, glm::vec4 vector)
{
	ShaderProperty vectorProperty{
		propertyName,
		vector
	};

	SetProperty(vectorProperty);
}

void Material::Render(Mesh * mesh, const glm::mat4 & modelMatrix, const glm::mat4 & viewMatrix, const glm::mat4 & projectionMatrix, const glm::mat4& viewProjectionMatrix, bool simpleRender, bool castShadows)
{
	if (simpleRender == true)
	{
		SimpleRender(mesh, modelMatrix, viewMatrix, projectionMatrix, viewProjectionMatrix, castShadows);
	}
	else
	{
		FullRender(mesh, modelMatrix, viewMatrix, projectionMatrix, viewProjectionMatrix);
	}
}

void Material::SaveToFile(const std::string & materialName)
{
	//Create an output file stream
	std::ofstream file(config::MGE_MATERIALS_PATH + materialName + ".mat");

	//The first line of the file would define the shader name
	file << "shader " << m_shader.GetName() << '\n';

	//The rest of the lines define the properties in the following structure
	//name type value
	//For example: diffuseColor vector 1 1 1 1
	//Go through all the properties and add them to the contents of the file
	for (const auto& propertyPair : m_shaderProperties)
	{
		file << *propertyPair.second << '\n';
	}

	//Close the file stream
	file.close();
}

void Material::SetProperty(const ShaderProperty& property)
{
	m_shaderProperties[property.name] = std::make_shared<ShaderProperty>(property);
}

ShaderProperty* Material::GetProperty(const std::string & propertyName)
{
	if (HasProperty(propertyName))
	{
		return m_shaderProperties[propertyName].get();
	}
	else
	{
		return nullptr;
	}
}

bool Material::HasProperty(const std::string & propertyName)
{
	return m_shaderProperties.find(propertyName) != m_shaderProperties.end();
}

bool Material::CanBindExtraTexture()
{
	GLint maxTextures = 0;
	glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &maxTextures);
	return m_setTextureCount + 1 < maxTextures;
}

void Material::FullRender(Mesh * mesh, const glm::mat4 & modelMatrix, const glm::mat4 & viewMatrix, const glm::mat4 & projectionMatrix, const glm::mat4 & viewProjectionMatrix)
{
	//Bind the shader
	m_shader.Bind();

	//Validate that the shader is still okay with the current context. This is only useful during development
#ifdef _DEBUG
	m_shader.Validate();
#endif

	//Update the MVP matrix properties in the material
	SetProperty(ShaderProperty("modelMatrix", modelMatrix));
	SetProperty(ShaderProperty("viewMatrix", viewMatrix));
	SetProperty(ShaderProperty("projectionMatrix", projectionMatrix));
	SetProperty(ShaderProperty("mvpMatrix", viewProjectionMatrix * modelMatrix));

	//Update the global light properties in the material
	const LightManager& lightManager = LightManager::Instance();
	SetProperty(ShaderProperty("globalAmbient", lightManager.GetGlobalAmbientColor()));
	SetProperty(ShaderProperty("fogColor", lightManager.GetFogColor()));
	SetProperty(ShaderProperty("fogDensity", lightManager.GetFogDensity()));
	SetProperty(ShaderProperty("fogStartDistance", lightManager.GetFogStartDistance()));

	//Pass the environment map to the material
	SetProperty(ShaderProperty("environmentMap", &LightManager::Instance().GetSkyBox()));

	//Pass the shadow map textures to the shader at the latest texture unit
	const std::vector<Light*> lights = LightManager::Instance().GetLights();
	for (size_t i = 0; i < LightManager::Instance().GetLightCount(); ++i)
	{
		SetProperty(ShaderProperty("shadowMaps[" + std::to_string(i) + "].shadowMap", &lights[i]->GetShadowMap()));
	}

	//Since the default sampler2D value is 0, start from 1, and make 0 represent a non existent texture
	GLuint currentTextureUnit = 1;

	//Pass all the properties to the shader
	for (const auto& propertyPair : m_shaderProperties)
	{
		//Retrieve a reference to the property
		const ShaderProperty& property = *propertyPair.second;

		//If the property is a texture, bind the texture
		if (property.type == PropertyType::Texture)
		{
			property.textureValue->Bind(currentTextureUnit);
			++currentTextureUnit;
		}

		//Send the property to the shader
		m_shader.SetProperty(property);
	}

	//Draw the mesh
	mesh->StreamToOpenGL
	(
		m_shader.GetAttribute("vertex"),
		m_shader.GetAttribute("normal"),
		m_shader.GetAttribute("uv"),
		m_shader.GetAttribute("tangents")
	);
	

	//Unbind any texture that may have been active
	currentTextureUnit = 1;
	for (const auto& propertyPair : m_shaderProperties)
	{
		const ShaderProperty& property = *propertyPair.second;

		if (property.type == PropertyType::Texture)
		{
			property.textureValue->Unbind(currentTextureUnit);
			++currentTextureUnit;
		}
	}

	//Unbind the shader
	m_shader.Unbind();
}

void Material::SimpleRender(Mesh * mesh, const glm::mat4 & modelMatrix, const glm::mat4 & viewMatrix, const glm::mat4 & projectionMatrix, const glm::mat4 & viewProjectionMatrix, bool castShadows)
{
	if (castShadows == false)
	{
		return;
	}

	//Load the simple shader
	if (s_simpleShader == nullptr)
	{
		s_simpleShader = Shader::Find("unlit/depth");
	}

	//Bind the simple shader
	s_simpleShader->Bind();

	//Pass in the mvpMatrix to the shader
	s_simpleShader->SetProperty(ShaderProperty("mvpMatrix", viewProjectionMatrix * modelMatrix));

	//Draw the mesh
	mesh->StreamToOpenGL
	(
		s_simpleShader->GetAttribute("vertex"),
		s_simpleShader->GetAttribute("normal"),
		s_simpleShader->GetAttribute("uv"),
		s_simpleShader->GetAttribute("tangents")
	);

	//Unbind the shader
	s_simpleShader->Unbind();
}

