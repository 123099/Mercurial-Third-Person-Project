#pragma once
#include <UI\UI.h>
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Texture.hpp>
#include <Utils\glm.hpp>
#include <string>


class Crosshair : public UI
{
public:
	Crosshair(const std::string& crosshhairFileName);

	void SetPositionOnScreen(float x, float y);

	void OnDraw(sf::RenderWindow& window) override;
private:
	sf::Sprite m_crosshairSprite;
	sf::Texture m_crosshairTexture;
};