#pragma once
#include <UI\UI.h>
#include <Utils\Singleton.hpp>
#include <SFML\Graphics\RenderWindow.hpp>
#include <vector>

class UIRenderer final : public Singleton<UIRenderer>
{
friend Singleton<UIRenderer>;
friend UI;

public:
	void Render(sf::RenderWindow& window);
private:
	std::vector<UI*> m_UIElements;

	void AddUIElement(UI* ui);
	void RemoveUIElement(UI* ui);
};