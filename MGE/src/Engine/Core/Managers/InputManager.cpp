#include <Managers\InputManager.hpp>
#include <Utils\Cursor.hpp>
#include <Utils\glm.hpp>
#include <Core\Time.hpp>

int InputManager::s_mouseWheelDelta = 0;
glm::vec2 InputManager::s_mousePosition;
glm::vec2 InputManager::s_mouseDelta;

char InputManager::s_textInputCharacter = '\0';

bool InputManager::s_anyKey = false;
bool InputManager::s_anyKeyUp = false;

bool InputManager::s_keysPressed[sf::Keyboard::KeyCount];
bool InputManager::s_keysHeld[sf::Keyboard::KeyCount];
bool InputManager::s_keysReleased[sf::Keyboard::KeyCount];

bool InputManager::s_mouseButtonsPressed[sf::Mouse::ButtonCount];
bool InputManager::s_mouseButtonsHeld[sf::Mouse::ButtonCount];
bool InputManager::s_mouseButtonsReleased[sf::Mouse::ButtonCount];

InputManager::InputManager()
{
    Reset(true);
}

void InputManager::Reset(bool l_fullReset)
{
	resetArray(s_keysPressed, sizeof s_keysPressed);
	resetArray(s_keysReleased, sizeof s_keysReleased);

	resetArray(s_mouseButtonsPressed, sizeof s_mouseButtonsPressed);
	resetArray(s_mouseButtonsReleased, sizeof s_mouseButtonsReleased);

    this->s_anyKeyUp = false;
	this->s_textInputCharacter = '\0';

	if (l_fullReset)
	{
		resetArray(s_keysHeld, sizeof s_keysHeld);
		resetArray(s_mouseButtonsHeld, sizeof s_mouseButtonsHeld);

		this->s_anyKey = false;
	}
}

void InputManager::Update(const sf::RenderWindow& window, const sf::Event & event)
{
	if (window.hasFocus())
	{
		//Update the static arrays based on the event data//
			//**Keyboard**//
		if (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased)
		{
			//Check that the key code is known
			if (event.key.code != sf::Keyboard::Unknown)
			{
				if (event.type == sf::Event::KeyPressed)
				{
					//Mark key as pressed (this is only valid for this frame, since it will be reset in the next call to update)//
					this->s_keysPressed[event.key.code] = true;
					//Mark key as held. This is valid until the key is released//
					this->s_keysHeld[event.key.code] = true;
					//Mark any key held as true
					this->s_anyKey = true;
				}
				else if (event.type == sf::Event::KeyReleased)
				{
					//Mark key as released. This is valid until next frame//
					this->s_keysReleased[event.key.code] = true;
					//Mark held key as no longer held//
					this->s_keysHeld[event.key.code] = false;
					//Mark any key released as true
					this->s_anyKeyUp = true;
					//Mark any key held as false
					this->s_anyKey = false;
				}
			}
		}
		else if (event.type == sf::Event::TextEntered)
		{
			//Make sure input is within the ASCII range and is not backspace
			if (event.text.unicode < 128 && event.text.unicode != 8)
			{
				//Convert carriage return (\r) into a new line (\n)
				if (event.text.unicode == 13)
				{
					s_textInputCharacter = '\n';
				}
				else
				{
					s_textInputCharacter = static_cast<char>(event.text.unicode);
				}
			}
		}
		//**Mouse**//
		else if (event.type == sf::Event::MouseButtonPressed || event.type == sf::Event::MouseButtonReleased)
		{
			if (event.type == sf::Event::MouseButtonPressed)
			{
				//Mark mouse button as pressed (this is only valid for this frame, since it will be reset in the next call to update)//
				this->s_mouseButtonsPressed[event.mouseButton.button] = true;
				//Mark mouse button as held. This is valid until the mouse button is released//
				this->s_mouseButtonsHeld[event.mouseButton.button] = true;
				//Mark any key held as true
				this->s_anyKey = true;
			}
			else if (event.type == sf::Event::MouseButtonReleased)
			{
				//Mark mouse button as released. This is valid until next frame//
				this->s_mouseButtonsReleased[event.mouseButton.button] = true;
				//Mark held mouse button as no longer held//
				this->s_mouseButtonsHeld[event.mouseButton.button] = false;
				//Mark any key released as true
				this->s_anyKeyUp = true;
				//Mark any key held as false
				this->s_anyKey = false;
			}
		}
		else if (event.type == sf::Event::MouseMoved)
		{
			//On mouse move, calculate the delta of the mouse
			//If the cursor is centered, calculate relative to center,
			//else, calculate relative to previous pos
			const glm::vec2 anchorPoint = [&]()
			{
				if (Cursor::Instance().GetCursorMode() == Cursor::Mode::LockedAndCentered)
				{
					return glm::vec2(window.getSize().x * 0.5f, window.getSize().y * 0.5f);
				}
				else
				{
					return this->s_mousePosition;
				}
			}();

			this->s_mousePosition = glm::vec2(event.mouseMove.x, window.getSize().y - event.mouseMove.y);
			this->s_mouseDelta = this->s_mousePosition - anchorPoint;
		}
		else if (event.type == sf::Event::MouseWheelMoved)
		{
			this->s_mouseWheelDelta += event.mouseWheel.delta;
		}
	}
}

glm::vec2 InputManager::convertSFtoGLM(const sf::RenderWindow& window, const sf::Vector2i& vec)
{
	return glm::vec2(vec.x, window.getSize().y - vec.y);
}

void InputManager::resetArray(bool* l_array, int arraySize)
{
	//Calculate array length
	int arrayLength = arraySize / sizeof(l_array[0]);
	for (int i = 0; i < arrayLength; ++i)
	{
		l_array[i] = false;
	}
}

int InputManager::GetMouseWheelDelta()
{
	return s_mouseWheelDelta;
}

glm::vec2 InputManager::GetMousePosition()
{
	return s_mousePosition;
}

glm::vec2 InputManager::GetMouseMovement()
{
	return s_mouseDelta;
}

char InputManager::GetCharacterTyped()
{
	return s_textInputCharacter;
}

bool InputManager::IsAnyKeyHeld()
{
    return s_anyKey;
}

bool InputManager::IsAnyKeyUp()
{
    return s_anyKeyUp;
}

bool InputManager::IsKeyPressed(sf::Keyboard::Key l_key)
{
    if (l_key == sf::Keyboard::Key::Unknown)
        return false;
	return s_keysPressed[l_key];
}

bool InputManager::IsKeyHeld(sf::Keyboard::Key l_key)
{
    if (l_key == sf::Keyboard::Key::Unknown)
        return false;
	return s_keysHeld[l_key];
}

bool InputManager::IsKeyReleased(sf::Keyboard::Key l_key)
{
    if (l_key == sf::Keyboard::Key::Unknown)
        return false;
	return s_keysReleased[l_key];
}

int InputManager::GetAxisButtonValue(InputAxes::Button l_button)
{
	int value = 0;

	if (l_button.m_type == InputAxes::ButtonType::Keyboard)
		value = IsKeyHeld(l_button.m_button.m_keyboardKey);
	else if (l_button.m_type == InputAxes::ButtonType::Mouse)
		value = GetMouseButton(l_button.m_button.m_mouseButton);

	return value;
}

int InputManager::GetAxis(InputAxes::Axis l_axis)
{
    int l_axisValue = 0;

	//Get the value for the positive button
	l_axisValue += GetAxisButtonValue(l_axis.m_positiveButton);

	//Get the value for the alternative positive button
	l_axisValue += GetAxisButtonValue(l_axis.m_altPositiveButton);

	//Get the value for the negative button
	l_axisValue -= GetAxisButtonValue(l_axis.m_negativeButton);

	//Get the value for the alternative negative button
	l_axisValue -= GetAxisButtonValue(l_axis.m_altNegativeButton);

	//Make sure the value doesn't exceed the -1 to 1 range, in case 2 positive or 2 negative buttons are pressed at the same time
    l_axisValue = glm::clamp(l_axisValue, -1, 1);

    return l_axisValue;
}

bool InputManager::GetButton(InputAxes::Axis l_axis)
{
	bool positiveIsHeld = 
		(l_axis.m_positiveButton.m_type == InputAxes::ButtonType::Keyboard && IsKeyHeld(l_axis.m_positiveButton.m_button.m_keyboardKey)) ||
		(l_axis.m_positiveButton.m_type == InputAxes::ButtonType::Mouse && GetMouseButton(l_axis.m_positiveButton.m_button.m_mouseButton));

	bool altPositiveIsHeld =
		(l_axis.m_altPositiveButton.m_type == InputAxes::ButtonType::Keyboard && IsKeyHeld(l_axis.m_altPositiveButton.m_button.m_keyboardKey)) ||
		(l_axis.m_altPositiveButton.m_type == InputAxes::ButtonType::Mouse && GetMouseButton(l_axis.m_altPositiveButton.m_button.m_mouseButton));

    return positiveIsHeld || altPositiveIsHeld;
}

bool InputManager::GetButtonDown(InputAxes::Axis l_axis)
{
	bool positiveIsPressed =
		(l_axis.m_positiveButton.m_type == InputAxes::ButtonType::Keyboard && IsKeyPressed(l_axis.m_positiveButton.m_button.m_keyboardKey)) ||
		(l_axis.m_positiveButton.m_type == InputAxes::ButtonType::Mouse && GetMouseButtonDown(l_axis.m_positiveButton.m_button.m_mouseButton));

	bool altPositiveIsPressed =
		(l_axis.m_altPositiveButton.m_type == InputAxes::ButtonType::Keyboard && IsKeyPressed(l_axis.m_altPositiveButton.m_button.m_keyboardKey)) ||
		(l_axis.m_altPositiveButton.m_type == InputAxes::ButtonType::Mouse && GetMouseButtonDown(l_axis.m_altPositiveButton.m_button.m_mouseButton));

	return positiveIsPressed || altPositiveIsPressed;
}

bool InputManager::GetButtonUp(InputAxes::Axis l_axis)
{
	bool positiveIsReleased =
		(l_axis.m_positiveButton.m_type == InputAxes::ButtonType::Keyboard && IsKeyReleased(l_axis.m_positiveButton.m_button.m_keyboardKey)) ||
		(l_axis.m_positiveButton.m_type == InputAxes::ButtonType::Mouse && GetMouseButtonUp(l_axis.m_positiveButton.m_button.m_mouseButton));

	bool altPositiveIsReleased =
		(l_axis.m_altPositiveButton.m_type == InputAxes::ButtonType::Keyboard && IsKeyReleased(l_axis.m_altPositiveButton.m_button.m_keyboardKey)) ||
		(l_axis.m_altPositiveButton.m_type == InputAxes::ButtonType::Mouse && GetMouseButtonUp(l_axis.m_altPositiveButton.m_button.m_mouseButton));

	return positiveIsReleased || altPositiveIsReleased;
}

bool InputManager::GetMouseButton(sf::Mouse::Button l_button)
{
	return s_mouseButtonsHeld[l_button];
}

bool InputManager::GetMouseButtonDown(sf::Mouse::Button l_button)
{
	return s_mouseButtonsPressed[l_button];
}

bool InputManager::GetMouseButtonUp(sf::Mouse::Button l_button)
{
	return s_mouseButtonsReleased[l_button];
}


