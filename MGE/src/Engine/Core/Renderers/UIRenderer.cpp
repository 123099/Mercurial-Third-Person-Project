#include "UIRenderer.hpp"
#include <algorithm>

void UIRenderer::Render(sf::RenderWindow & window)
{
	for (size_t i = 0; i < m_UIElements.size(); ++i)
	{
		m_UIElements[i]->Draw(window);
	}
}

void UIRenderer::AddUIElement(UI * ui)
{
	m_UIElements.push_back(ui);
}

void UIRenderer::RemoveUIElement(UI * ui)
{
	m_UIElements.erase(std::remove(m_UIElements.begin(), m_UIElements.end(), ui));
}
