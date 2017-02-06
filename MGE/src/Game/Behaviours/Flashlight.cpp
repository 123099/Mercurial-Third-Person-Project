#include <Game\Behaviours\Flashlight.hpp>
#include <Core\GameObject.hpp>
#include <Input\Input.hpp>
#include <Core\Time.hpp>
#include <Behaviours\Transform.hpp>

void Flashlight::Awake()
{
	m_spotlight = m_gameObject->GetBehaviour<Light>();
	m_defaultIntensity = m_spotlight->GetIntensity();
	m_isOn = true;
}

void Flashlight::Update()
{
	if (Input::IsKeyPressed(sf::Keyboard::F))
	{
		m_isOn = !m_isOn;
		m_spotlight->SetIntensity((float)m_isOn * m_defaultIntensity);
	}

	m_gameObject->GetTransform()->Rotate(glm::vec3(0, Time::s_deltaTime * -30, 0));
}
