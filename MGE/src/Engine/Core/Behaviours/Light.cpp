#include "Light.hpp"
#include <Core\GameObject.hpp>
#include <Behaviours\Transform.hpp>
#include <Managers\LightManager.hpp>

Light::Light() :
	m_type(Light::Type::Directional),
	m_ambientColor(glm::vec4(0)),
	m_diffuseColor(glm::vec4(0)),
	m_specularColor(glm::vec4(0)),
	m_intensity(0),
	m_attenuation(0,1,0),
	m_spotInnerAngle(0),
	m_spotOuterAngle(90) 
{
	LightManager::Instance().AddLight(this);
}

Light::~Light()
{
	LightManager::Instance().RemoveLight(this);
}

void Light::SetType(Type type)
{
	this->m_type = type;
}

void Light::SetColor(glm::vec4 color)
{
	SetAmbientColor(color);
	SetDiffuseColor(color);
	SetSpecularColor(color);
}

void Light::SetAmbientColor(glm::vec4 color)
{
	this->m_ambientColor = color;
}

void Light::SetDiffuseColor(glm::vec4 color)
{
	this->m_diffuseColor = color;
}

void Light::SetSpecularColor(glm::vec4 color)
{
	this->m_specularColor = color;
}

void Light::SetIntensity(float intensity)
{
	this->m_intensity = intensity;
}

void Light::SetAttenuation(float quadAttenuation)
{
	SetAttenuation(glm::vec3(0, 0, quadAttenuation));
}

void Light::SetAttenuation(glm::vec3 attenuation)
{
	if (attenuation.x == 0) attenuation.x = 1;
	this->m_attenuation = attenuation;
}

void Light::SetSpotInnerAngle(float spotAngle)
{
	m_spotInnerAngle = spotAngle;
}

void Light::SetSpotOuterAngle(float spotAngle)
{
	m_spotOuterAngle = spotAngle;
}

glm::vec4 Light::GetAmbientColor()
{
	return m_ambientColor;
}

glm::vec4 Light::GetDiffuseColor()
{
	return m_diffuseColor;
}

glm::vec4 Light::GetSpecularColor()
{
	return m_specularColor;
}

float Light::GetIntensity()
{
	return m_intensity;
}

float Light::GetSpotInnerAngle()
{
	return m_spotInnerAngle;
}

float Light::GetSpotOuterAngle()
{
	return m_spotOuterAngle;
}

glm::vec3 Light::GetAttenuation()
{
	return m_attenuation;
}

Light::Data Light::GetLightData()
{
	//Make sure we are attached to the scene to have an effect
	if (m_gameObject == nullptr)
	{
		return Light::Data();
	}
	else
	{
		glm::vec4 position = glm::vec4(0.0f);

		//Decide whether to use the light's position
		if (m_type == Light::Type::Point || m_type == Light::Type::Spot)
		{
			position = glm::vec4(m_gameObject->GetTransform()->GetWorldPosition(), 1);
		}

		glm::vec4 direction = glm::vec4(0.0f);

		//Decide whether to use the light's direction
		if (m_type == Light::Type::Directional || m_type == Light::Type::Spot)
		{
			direction = m_gameObject->GetTransform()->GetModelMatrix() * glm::vec4(0.0f, 0.0f, -1.0f, 0.0f);
		}

		return
		{
			position,
			direction,
			m_ambientColor,
			m_diffuseColor,
			m_specularColor,
			m_type == Light::Type::Directional ? glm::vec4(0.0f) : glm::vec4(m_attenuation, 0.0f),
			float(m_type),
			m_intensity,
			m_type == Light::Type::Spot ? glm::cos(glm::radians(m_spotInnerAngle * 0.5f)) : -1.0f, //-1 = cos(180)
			m_type == Light::Type::Spot ? glm::cos(glm::radians(m_spotOuterAngle * 0.5f)) : -1.0f //-1 = cos(180). Faster to check type and send -1 instead of calculating cos
		};
	}
}
