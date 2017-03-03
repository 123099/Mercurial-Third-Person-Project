#pragma once
#include <GL\glew.h>
#include <Utils\Singleton.hpp>
#include <Utils\glm.hpp>
#include <Utils\Singleton.hpp>
#include <vector>

class Light;

class LightManager final : public Singleton<LightManager>
{
friend Singleton<LightManager>;
friend Light;

public:
	size_t GetLightCount() const;

	void SetGlobalAmbientColor(glm::vec4 color);
	void SetFogColor(glm::vec4 color);
	void SetFogDensity(float density);
	void SetFogStartDistance(float distance);

	glm::vec4 GetGlobalAmbientColor() const;
	glm::vec4 GetFogColor() const;
	float GetFogDensity() const;
	float GetFogStartDistance() const;

	void UpdateLightData(glm::mat4 viewMatrix);
	void RenderShadowMaps();

	std::vector<Light*> GetLights();
	
	void LoadFromConfig();
private:
	std::vector<Light*> m_lights;

	glm::vec4 m_globalAmbient;
	glm::vec4 m_fogColor;
	float m_fogDensity;
	float m_fogStartDistance;

	GLuint m_lightBufferID;

	GLuint InitializeLightBuffer();

	const size_t BindLightBuffer(GLuint bufferID, bool useMaxSize = false);
	void UnbindLightBuffer();

	void AddLight(Light* light);
	void RemoveLight(Light* light);
	bool HasLight(Light* light);

	LightManager();
};

