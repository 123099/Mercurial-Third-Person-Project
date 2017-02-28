#include <UI\Crosshair.hpp>
#include <Core\config.hpp>

Crosshair::Crosshair(const std::string& crosshairFileName)
{
	m_crosshairTexture.loadFromFile(config::MGE_SPRITES_PATH + crosshairFileName);
	m_crosshairSprite.setTexture(m_crosshairTexture);
}

void Crosshair::SetPositionOnScreen(float x, float y)
{
	m_crosshairSprite.setPosition(x, y);
}

void Crosshair::OnDraw(sf::RenderWindow& window)
{
	window.draw(m_crosshairSprite);
}