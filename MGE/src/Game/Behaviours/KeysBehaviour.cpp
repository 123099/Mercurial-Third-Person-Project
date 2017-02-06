#include <Game\Behaviours\KeysBehaviour.hpp>
#include <Core\GameObject.hpp>
#include <Behaviours\Transform.hpp>
#include <Input\Input.hpp>
#include <Core\Time.hpp>

void KeysBehaviour::Update()
{
	float moveSpeed = 0.0f;
	float turnSpeed = 0.0f;
	float riseSpeed = 0.0f;

	if ( Input::IsKeyHeld( sf::Keyboard::Up )) {
		moveSpeed = m_moveSpeed;
	}
	if (Input::IsKeyHeld( sf::Keyboard::Down )) {
		moveSpeed = -m_moveSpeed;
	}
	if (Input::IsKeyHeld( sf::Keyboard::Right )) {
		turnSpeed = -m_turnSpeed;
	}
	if (Input::IsKeyHeld(sf::Keyboard::Left)) {
		turnSpeed = +m_turnSpeed;
	}
	if (Input::IsKeyHeld( sf::Keyboard::RShift )) {
		riseSpeed = +10;
	}
	if (Input::IsKeyHeld(sf::Keyboard::RControl)) {
		riseSpeed = -10;
	}
	//translate the object in its own local space
	m_gameObject->GetTransform()->Translate( glm::vec3(0.0f, riseSpeed, -moveSpeed ) * Time::s_deltaTime ); //negative on the z since that is the forward in opengl

	//rotate the object in its own local space
	m_gameObject->GetTransform()->Rotate(glm::vec3(0, turnSpeed*Time::s_deltaTime, 0));
}

void KeysBehaviour::SetMoveSpeed(float moveSpeed)
{
	m_moveSpeed = moveSpeed;
}

void KeysBehaviour::SetTurnSpeed(float turnSpeed)
{
	m_turnSpeed = turnSpeed;
}
