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

	void SetGlobalAmbientColor(glm::vec4 globalAmbientColor);
	glm::vec4 GetGlobalAmbientColor() const;

	void UpdateLightData(glm::mat4 viewMatrix);
private:
	std::vector<Light*> m_lights;

	glm::vec4 m_globalAmbient;

	GLuint m_lightBufferID;

	GLuint InitializeLightBuffer();

	const size_t BindLightBuffer(GLuint bufferID, bool useMaxSize = false);
	void UnbindLightBuffer();

	void AddLight(Light* light);
	void RemoveLight(Light* light);
	bool HasLight(Light* light);

	LightManager();
};

