#include <Input\Input.hpp>

int Input::GetMouseWheelDelta()
{
	return InputManager::GetMouseWheelDelta();
}

glm::vec2 Input::GetMousePosition()
{
	return InputManager::GetMousePosition();
}

glm::vec2 Input::GetMouseMovement()
{
	return InputManager::GetMouseMovement();
}

char Input::GetCharacterTyped()
{
	return InputManager::GetCharacterTyped();
}

bool Input::IsAnyKeyHeld()
{
    return InputManager::IsAnyKeyHeld();
}

bool Input::IsAnyKeyUp()
{
    return InputManager::IsAnyKeyUp();
}

bool Input::IsKeyPressed(sf::Keyboard::Key l_key)
{
	return InputManager::IsKeyPressed(l_key);
}

bool Input::IsKeyHeld(sf::Keyboard::Key l_key)
{
	return InputManager::IsKeyHeld(l_key);
}

bool Input::IsKeyReleased(sf::Keyboard::Key l_key)
{
	return InputManager::IsKeyReleased(l_key);
}

int Input::GetAxis(InputAxes::Axis l_axis)
{
    return InputManager::GetAxis(l_axis);
}

bool Input::GetButton(InputAxes::Axis l_axis)
{
    return InputManager::GetButton(l_axis);
}

bool Input::GetButtonDown(InputAxes::Axis l_axis)
{
    return InputManager::GetButtonDown(l_axis);
}

bool Input::GetButtonUp(InputAxes::Axis l_axis)
{
    return InputManager::GetButtonUp(l_axis);
}

bool Input::GetMouseButton(sf::Mouse::Button l_button)
{
	return InputManager::GetMouseButton(l_button);
}

bool Input::GetMouseButtonDown(sf::Mouse::Button l_button)
{
	return InputManager::GetMouseButtonDown(l_button);
}

bool Input::GetMouseButtonUp(sf::Mouse::Button l_button)
{
	return InputManager::GetMouseButtonUp(l_button);
}
