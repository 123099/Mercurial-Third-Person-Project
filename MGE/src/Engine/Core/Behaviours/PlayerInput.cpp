#include <Behaviours\PlayerInput.hpp>
#include <Input\Input.hpp>

PlayerInput::PlayerInput() : m_textLog("arial.ttf") {}

void PlayerInput::Update()
{
	char lastCharInput = Input::GetCharacterTyped();
	if (lastCharInput != '\0')
	{
		m_textLog.AddText(std::string(&lastCharInput, 1));
	}
}
