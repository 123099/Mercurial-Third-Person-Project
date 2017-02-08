#pragma once
#include <SFML\Graphics\RenderWindow.hpp>
#include <Utils\Singleton.hpp>

class Cursor final : public Singleton<Cursor>
{
friend Singleton<Cursor>;

public:
	enum Mode
	{
		Unlocked,
		Locked,
		LockedAndCentered
	};

	void SetWindow(sf::RenderWindow* window);

	void SetCursorVisible(bool visible);
	void SetCursorMode(Mode cursorMode);

	Mode GetCursorMode() const;

	void Update();
private:
	sf::RenderWindow* m_window;
	Mode m_cursorMode;

	Cursor() = default;
};
