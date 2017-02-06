#pragma once
#include <SFML\Graphics.hpp>

class InputAxes
{
public:
	InputAxes() = delete;

	union ButtonUnion
	{
		sf::Keyboard::Key m_keyboardKey;
		sf::Mouse::Button m_mouseButton;
	};

	enum struct ButtonType {
		Keyboard, Mouse
	};

	struct Button {
		ButtonType m_type;
		ButtonUnion m_button;

		Button(sf::Keyboard::Key l_key) { m_button.m_keyboardKey = l_key; m_type = ButtonType::Keyboard; }
		Button(sf::Mouse::Button l_mouseButton) { m_button.m_mouseButton = l_mouseButton; m_type = ButtonType::Mouse; }
	};

    struct Axis
    {
        std::string m_name;
        Button m_positiveButton;
        Button m_negativeButton;
        Button m_altPositiveButton;
        Button m_altNegativeButton;
    };

public:
    static Axis s_fire;
    static Axis s_horizontal;
    static Axis s_vertical;
	static Axis s_quit;
};

