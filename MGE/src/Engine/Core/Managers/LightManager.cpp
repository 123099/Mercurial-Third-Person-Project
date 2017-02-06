#define MAX_LIGHTS 20

#include "LightManager.hpp"
#include <memory>
#include <Behaviours\Light.hpp>
#include <Managers\ShaderManager.hpp>
#include <Utils\Profiler.hpp>

LightManager::LightManager() : 
	m_lightBufferID(InitializeLightBuffer()),
	m_globalAmbient(glm::vec4(0.2, 0.2, 0.15, 1)) {}

LightManager & LightManager::Instance()
{
	static LightManager instance;
	return instance;
}

void LightManager::AddLight(Light * light)
{
	if (m_lights.size() < MAX_LIGHTS && HasLight(light) == false)
	{
		m_lights.push_back(light);
	}
}

void LightManager::RemoveLight(Light * light)
{
	m_lights.erase(std::remove(m_lights.begin(), m_lights.end(), light));
}

bool LightManager::HasLight(Light * light)
{
	return std::find(m_lights.begin(), m_lights.end(), light) != m_lights.end();
}

int LightManager::GetLightCount() const
{
	return m_lights.size();
}

void LightManager::SetGlobalAmbientColor(glm::vec4 globalAmbientColor)
{
	m_globalAmbient = globalAmbientColor;
}

glm::vec4 LightManager::GetGlobalAmbientColor() const
{
	return m_globalAmbient;
}

GLuint LightManager::InitializeLightBuffer()
{
	GLuint bufferID = -1;

	//Generate a buffer for the light uniform
	glGenBuffers(1, &bufferID);

	//Bind the light buffer with maximum size
	const size_t lightBufferSize = BindLightBuffer(bufferID, true);

	//Allocate and provide the default light data to the buffer
	const Light::Data data[MAX_LIGHTS];
	glBufferData(GL_SHADER_STORAGE_BUFFER, lightBufferSize, &data, GL_DYNAMIC_DRAW);

	//Set the binding point of the buffer
	constexpr int bindingPoint = 0;

	//Bind the buffer to the binding point
	glBindBufferBase(GL_SHADER_STORAGE_BUFFER, bindingPoint, bufferID);

	//For every shader, bind the light data uniform block to the binding point
	const auto& shaders = ShaderManager::GetShaders().GetCache();

	for (const auto& shaderPair : shaders)
	{
		glShaderStorageBlockBinding(shaderPair.second->GetProgramID(), shaderPair.second->GetLightBufferBlockIndex(), bindingPoint);
	}

	UnbindLightBuffer();

	return bufferID;
}

void LightManager::UpdateLightData(glm::mat4 viewMatrix)
{
	//Create an array of light data the size as the amount of lights
	const std::unique_ptr<Light::Data[]> data = std::make_unique<Light::Data[]>(m_lights.size());
	
	//Fill in the data from all the lights
	const size_t lightCount = m_lights.size();
	for (size_t i = 0; i < lightCount; ++i)
	{
		//Retrieve the data of the 'i'th light
		data[i] = m_lights[i]->GetLightData();

		//Transform the light position and direction vectors to camera space
		if (data[i].position != glm::vec4(0.0f)) data[i].position = viewMatrix * data[i].position;
		if (data[i].direction != glm::vec4(0.0f)) data[i].direction = viewMatrix * data[i].direction;
	}

	//Bind the light buffer with size equal the amount of lights
	const size_t lightBufferSize = BindLightBuffer(m_lightBufferID);

	//Retrieve the pointer to the UBO
	GLvoid* bufferPointer = //glMapBuffer(GL_UNIFORM_BUFFER, GL_WRITE_ONLY);
		glMapBufferRange(GL_SHADER_STORAGE_BUFFER, 0, lightBufferSize, GL_MAP_WRITE_BIT | GL_MAP_UNSYNCHRONIZED_BIT | GL_MAP_INVALIDATE_BUFFER_BIT);
	
	//Copy the data to the UBO
	std::memcpy(bufferPointer, data.get(), lightBufferSize);

	//Finalize
	glUnmapBuffer(GL_SHADER_STORAGE_BUFFER);
	UnbindLightBuffer();
}

const size_t LightManager::BindLightBuffer(GLuint bufferID, bool useMaxSize)
{
	//Calculate the light buffer size to bind
	const size_t lightBufferSize = sizeof(Light::Data) * (useMaxSize ? MAX_LIGHTS : m_lights.size());

	//Bind the required range of the entire buffer
	glBindBufferRange(GL_SHADER_STORAGE_BUFFER, 0, bufferID, 0, lightBufferSize);

	//Return the size bound
	return lightBufferSize;
}

void LightManager::UnbindLightBuffer()
{
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
}
