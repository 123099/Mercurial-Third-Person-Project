#pragma once
#include <Managers\InputManager.hpp>

class Input
{
public:
	static int GetMouseWheelDelta();
	static glm::vec2 GetMousePosition();
	static glm::vec2 GetMouseMovement();

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
};

