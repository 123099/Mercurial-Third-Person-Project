#pragma once
#include "SFML\Graphics.hpp"
#include <Core\Input\InputAxes.hpp>

class InputManager
{
friend class Input;

public:
	InputManager();

	void Reset(bool l_fullReset = false);
	void Update(sf::Event& event);

private:
	void resetArray(bool* l_array, int arraySize);

	static int s_mouseWheelDelta;
	static sf::Vector2i s_mousePosition;

    static bool s_anyKey;
    static bool s_anyKeyUp;

	static bool s_keysPressed[sf::Keyboard::KeyCount];
	static bool s_keysHeld[sf::Keyboard::KeyCount];
	static bool s_keysReleased[sf::Keyboard::KeyCount];

	static bool s_mouseButtonsPressed[sf::Mouse::ButtonCount];
	static bool s_mouseButtonsHeld[sf::Mouse::ButtonCount];
	static bool s_mouseButtonsReleased[sf::Mouse::ButtonCount];

	static int GetMouseWheelDelta();
	static sf::Vector2i GetMousePosition();

    static bool IsAnyKeyHeld();
    static bool IsAnyKeyUp();

	static bool IsKeyPressed(sf::Keyboard::Key l_key);
	static bool IsKeyHeld(sf::Keyboard::Key l_key);
	static bool IsKeyReleased(sf::Keyboard::Key l_key);

    static int GetAxis(InputAxes::Axis l_axis);

    static bool GetButton(InputAxes::Axis l_axis);
    static bool GetButtonDown(InputAxes::Axis l_axis);
    static bool GetButtonUp(InputAxes::Axis l_axis);

	static bool GetMouseButton(sf::Mouse::Button l_button);
	static bool GetMouseButtonDown(sf::Mouse::Button l_button);
	static bool GetMouseButtonUp(sf::Mouse::Button l_button);

	static int GetAxisButtonValue(InputAxes::Button l_button);
};

