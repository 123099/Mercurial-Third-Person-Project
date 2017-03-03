#define MAX_LIGHTS 20

#include <Managers\LightManager.hpp>
#include <Behaviours\Light.hpp>
#include <Core\GameObject.hpp>
#include <Behaviours\Transform.hpp>
#include <Behaviours\Camera.hpp>
#include <Managers\ShaderManager.hpp>
#include <Renderers\Renderer.hpp>
#include <Utils\Profiler.hpp>
#include <Core\config.hpp>
#include <fstream>
#include <memory>

LightManager::LightManager() : 
	m_lightBufferID(InitializeLightBuffer()),
	m_globalAmbient(glm::vec4(0.2, 0.2, 0.15, 1)),
	m_fogColor(glm::vec4(1.0)),
	m_fogDensity(0.03f),
	m_fogStartDistance(10.0f) 
{
	//Load a default skybox
	m_skybox.SetCubeFaces(config::MGE_TEXTURES_PATH + "skybox/Sunset/", ".png");
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

size_t LightManager::GetLightCount() const
{
	return m_lights.size();
}

void LightManager::SetSkyBox(CubeMap skybox)
{
	m_skybox = skybox;
}

void LightManager::SetGlobalAmbientColor(glm::vec4 color)
{
	m_globalAmbient = color;
}

void LightManager::SetFogColor(glm::vec4 color)
{
	m_fogColor = color;
}

void LightManager::SetFogDensity(float density)
{
	m_fogDensity = density;
}

void LightManager::SetFogStartDistance(float distance)
{
	m_fogStartDistance = distance;
}

CubeMap& LightManager::GetSkyBox()
{
	return m_skybox;
}

glm::vec4 LightManager::GetGlobalAmbientColor() const
{
	return m_globalAmbient;
}

glm::vec4 LightManager::GetFogColor() const
{
	return m_fogColor;
}

float LightManager::GetFogDensity() const
{
	return m_fogDensity;
}

float LightManager::GetFogStartDistance() const
{
	return m_fogStartDistance;
}

GLuint LightManager::InitializeLightBuffer()
{
	GLuint bufferID = 0;

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
		if (shaderPair.second->HasLightBuffer() == true)
		{
			glShaderStorageBlockBinding(shaderPair.second->GetProgramID(), shaderPair.second->GetLightBufferBlockIndex(), bindingPoint);
		}
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
#include <Input\Input.hpp>
bool enabled = true;
void LightManager::RenderShadowMaps()
{
	glCullFace(GL_FRONT);
	if (Input::IsKeyPressed(sf::Keyboard::F1))
		enabled = !enabled;
	for (size_t i = 0; i < GetLightCount(); ++i)
	{
		//Get the light
		Light* light = m_lights[i];

		//Activate the shadow map render texture
		light->GetShadowMap().Activate();

		//Render the scene to the texture
		Renderer::Instance().Render(light->GetViewMatrix(), light->GetProjectionMatrix());

		//Finish with the render texture
		light->GetShadowMap().Deactivate();
	}

	if (enabled)
	{
		glDisable(GL_CULL_FACE);
		glEnable(GL_TEXTURE_2D);
		for (size_t i = 0; i < GetLightCount(); ++i)
		{
			m_lights[i]->GetShadowMap().Bind();
			glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0);
			glVertex3f(-1.0f + i * 1.0f, -1, 0.0);
			glTexCoord2f(1.0, 0.0);
			glVertex3f(0.0f + i * 1.0f, -1, 0.0);
			glTexCoord2f(1.0, 1.0);
			glVertex3f(0.0f + i * 1.0f, 0.0f, 0.0);
			glTexCoord2f(0.0, 1.0);
			glVertex3f(-1.0f + i * 1.0f, 0.0f, 0.0);
			glEnd();
			m_lights[i]->GetShadowMap().Unbind();
		}
		glEnable(GL_CULL_FACE);
	}
	glCullFace(GL_BACK);
}

std::vector<Light*> LightManager::GetLights()
{
	return m_lights;
}

void LightManager::LoadFromConfig()
{
	const std::string fullPath = config::MGE_CONFIG_PATH + "lightManager.cfg";

	//Open the file
	std::ifstream file(fullPath);

	//Make sure we opened the file
	if (file.is_open())
	{
		//Start reading the file line by line
		std::string propertyName;
		while (file >> propertyName)
		{
			bool success = true;

			if (propertyName == "globalAmbient")
			{
				if (!(file >> m_globalAmbient.x >> m_globalAmbient.y >> m_globalAmbient.z >> m_globalAmbient.w))
				{
					success = false;
				}
			}
			else if (propertyName == "fogColor")
			{
				if (!(file >> m_fogColor.x >> m_fogColor.y >> m_fogColor.z >> m_fogColor.w))
				{
					success = false;
				}
			}
			else if (propertyName == "fogDensity")
			{
				if (!(file >> m_fogDensity))
				{
					success = false;
				}
			}
			else if (propertyName == "fogStartDistance")
			{
				if (!(file >> m_fogStartDistance))
				{
					success = false;
				}
			}

			if (success == false)
			{
				std::cerr << "[Error] Reading light manager config property " << propertyName << "!\n";
			}
		}
	}
	else
	{
		std::cerr << "Failed to open the config file for the light manager at " << fullPath << "!\n";
	}
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
