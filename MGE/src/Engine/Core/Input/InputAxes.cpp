#include <Input\InputAxes.hpp>
#include <string>

InputAxes::Axis InputAxes::s_fire = {
    "Fire",
    sf::Keyboard::LControl,
    sf::Keyboard::Unknown,
    sf::Keyboard::RControl,
    sf::Keyboard::Unknown
};

InputAxes::Axis InputAxes::s_horizontal =
{
    "Horizontal",
    sf::Keyboard::Right,
    sf::Keyboard::Left,
    sf::Keyboard::D,
    sf::Keyboard::A
};

InputAxes::Axis InputAxes::s_vertical =
{
    "Vertical",
    sf::Keyboard::Up,
    sf::Keyboard::Down,
    sf::Keyboard::W,
    sf::Keyboard::S
};

InputAxes::Axis InputAxes::s_jump = 
{
	"Jump",
	sf::Keyboard::Space,
	sf::Keyboard::Unknown,
	sf::Keyboard::Unknown,
	sf::Keyboard::Unknown
};

InputAxes::Axis InputAxes::s_quit =
{
	"Quit",
	sf::Keyboard::Escape,
	sf::Keyboard::Unknown,
	sf::Keyboard::Unknown,
	sf::Keyboard::Unknown
};

InputAxes::Axis InputAxes::s_interact =
{
	"Interact",
	sf::Mouse::Button::Left,
	sf::Keyboard::Unknown,
	sf::Keyboard::F,
	sf::Keyboard::Unknown
};

