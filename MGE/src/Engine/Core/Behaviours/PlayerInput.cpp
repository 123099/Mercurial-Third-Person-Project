#include <Behaviours\PlayerInput.hpp>
#include <Input\Input.hpp>

void PlayerInput::Awake()
{
	m_textLog = new TextLog();
	m_textLog->createLog();
}

void PlayerInput::Update()
{
	if (Input::IsKeyPressed(sf::Keyboard::A))
	{
		m_textLog->setLogInfo("A");
	}
}
