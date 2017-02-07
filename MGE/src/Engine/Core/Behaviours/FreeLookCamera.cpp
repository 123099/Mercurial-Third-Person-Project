#include "FreeLookCamera.hpp"
#include <Input\Input.hpp>
#include <Core\GameObject.hpp>
#include <Behaviours\Transform.hpp>
#include <Core\Time.hpp>
#include <Utils\glm.hpp>

void FreeLookCamera::SetMoveSpeed(float speed)
{
	m_moveSpeed = speed;
}

void FreeLookCamera::SetRotationSpeed(float speed)
{
	m_rotationSpeed = speed;
}

void FreeLookCamera::Awake()
{
	glm::vec3 eulerAngles = m_gameObject->GetTransform()->GetEulerAngles();
	m_accumulatedXRotation = eulerAngles.x;
	m_accumulatedYRotation = eulerAngles.y;
}

void FreeLookCamera::Update()
{
	Rotate();
	Move();
}

void FreeLookCamera::Rotate()
{
	//Once the mouse button is pressed, update the previous mouse position
	if (Input::GetMouseButtonDown(sf::Mouse::Button::Right))
	{
		m_previousMousePos = Input::GetMousePosition();
	}

	//Only move the camera if the right mouse button is held
	if (Input::GetMouseButton(sf::Mouse::Button::Right))
	{
		//Calculate the delta mouse movement
		glm::vec2 deltaMousePosition = Input::GetMousePosition() - m_previousMousePos;

		//Update the previous position
		m_previousMousePos = Input::GetMousePosition();

		//Convert sf vector to glm vector for math operations
		deltaMousePosition *= m_rotationSpeed;

		//Calculate the new rotation angles
		m_accumulatedXRotation += deltaMousePosition.y;
		m_accumulatedYRotation -= deltaMousePosition.x;

		//Apply rotation
		m_gameObject->GetTransform()->SetLocalRotation(glm::quat(glm::vec3(m_accumulatedXRotation, m_accumulatedYRotation, 0)));
	}
}

void FreeLookCamera::Move()
{
	glm::vec3 movement = glm::vec3(Input::GetAxis(InputAxes::s_horizontal), 0, -Input::GetAxis(InputAxes::s_vertical));

	if (Input::IsKeyHeld(sf::Keyboard::Q))
	{
		movement.y = -1;
	}
	else if (Input::IsKeyHeld(sf::Keyboard::E))
	{
		movement.y = 1;
	}

	//If no movement input is given, reset the acceleration clock and do nothing
	if (glm::dot(movement, movement) == 0.0)
	{
		m_accelerationClock.restart();
		return;
	}
	m_gameObject->GetTransform()->Translate(
		movement * (m_moveSpeed + m_accelerationClock.getElapsedTime().asSeconds() * 5.0f) * Time::s_deltaTime
	);
}
