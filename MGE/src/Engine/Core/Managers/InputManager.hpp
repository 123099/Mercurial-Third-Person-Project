#pragma once
#include "SFML\Graphics.hpp"
#include <Core\Input\InputAxes.hpp>
#include <Utils\glm.hpp>

class InputManager
{
friend class Input;

public:
	InputManager();

	void Reset(bool l_fullReset = false);
	void Update(const sf::RenderWindow& window, const sf::Event& event);
private:
	glm::vec2 convertSFtoGLM(const sf::RenderWindow& window, const sf::Vector2i& vec);
	void resetArray(bool* l_array, int arraySize);

	static int s_mouseWheelDelta;
	static glm::vec2 s_mousePosition;
	static glm::vec2 s_mouseDelta;

	static char s_textInputCharacter;

    static bool s_anyKey;
    static bool s_anyKeyUp;

	static bool s_keysPressed[sf::Keyboard::KeyCount];
	static bool s_keysHeld[sf::Keyboard::KeyCount];
	static bool s_keysReleased[sf::Keyboard::KeyCount];

	static bool s_mouseButtonsPressed[sf::Mouse::ButtonCount];
	static bool s_mouseButtonsHeld[sf::Mouse::ButtonCount];
	static bool s_mouseButtonsReleased[sf::Mouse::ButtonCount];

	static int GetMouseWheelDelta();
	static glm::vec2 GetMousePosition();
	static glm::vec2 GetMouseMovement();

	static char GetCharacterTyped();

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

