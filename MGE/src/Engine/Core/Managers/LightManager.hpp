#pragma once
#include <GL\glew.h>
#include <Utils\glm.hpp>
#include <vector>

class Light;

class LightManager
{
friend Light;

public:
	static LightManager& Instance();

	int GetLightCount() const;

	void SetGlobalAmbientColor(glm::vec4 color);
	void SetFogColor(glm::vec4 color);
	void SetFogDensity(float density);
	void SetFogStartDistance(float distance);

	glm::vec4 GetGlobalAmbientColor() const;
	glm::vec4 GetFogColor() const;
	float GetFogDensity() const;
	float GetFogStartDistance() const;

	void UpdateLightData(glm::mat4 viewMatrix);
	
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

