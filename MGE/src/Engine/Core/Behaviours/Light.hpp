#pragma once
#include <Behaviours\AbstractBehaviour.hpp>
#include <Textures\RenderTexture.hpp>
#include <Utils\glm.hpp>
#include <string>

class Light final : public AbstractBehaviour
{
public:
	enum Type
	{
		Directional,
		Point,
		Spot
	};

	struct Data
	{
		glm::vec4 position;
		glm::vec4 direction;
		glm::vec4 ambientColor;
		glm::vec4 diffuseColor;
		glm::vec4 specularColor;
		glm::vec4 attenuation;
		float type;
		float intensity;
		float spotInnerAngleCos;
		float spotOuterAngleCos;
		glm::mat4 vpMatrix;
	};

	Light();
	~Light();

	void SetType(Type type);
	
	void SetColor(glm::vec4 color);
	void SetAmbientColor(glm::vec4 color);
	void SetDiffuseColor(glm::vec4 color);
	void SetSpecularColor(glm::vec4 color);

	void SetIntensity(float intensity);

	void SetAttenuation(float quadAttenuation);
	void SetAttenuation(glm::vec3 attenuation);

	void SetSpotInnerAngle(float spotAngle);
	void SetSpotOuterAngle(float spotAngle);

	Type GetType();

	RenderTexture& GetShadowMap();

	glm::vec4 GetAmbientColor();
	glm::vec4 GetDiffuseColor();
	glm::vec4 GetSpecularColor();

	float GetIntensity();
	float GetSpotInnerAngle();
	float GetSpotOuterAngle();

	glm::vec3 GetAttenuation();

	glm::mat4 GetViewMatrix();
	glm::mat4 GetProjectionMatrix();

	Data GetLightData();
private:
	Type m_type;

	RenderTexture m_shadowMap;

	glm::vec4 m_ambientColor;
	glm::vec4 m_diffuseColor;
	glm::vec4 m_specularColor;

	glm::vec3 m_attenuation;
	float m_intensity;

	float m_spotInnerAngle;
	float m_spotOuterAngle;
};

