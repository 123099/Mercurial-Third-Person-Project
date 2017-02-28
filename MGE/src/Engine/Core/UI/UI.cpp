#include "UI.h"
#include <Renderers\UIRenderer.hpp>

UI::UI() : m_isVisible(true)
{
	UIRenderer::Instance().AddUIElement(this);
}

UI::~UI()
{
	UIRenderer::Instance().RemoveUIElement(this);
}

void UI::SetVisible(bool visible)
{
	m_isVisible = visible;
}

void UI::Draw(sf::RenderWindow & window)
{
	if (m_isVisible == true)
	{
		OnDraw(window);
	}
}
