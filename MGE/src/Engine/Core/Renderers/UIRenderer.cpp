#include "UIRenderer.hpp"
#include <algorithm>
#include <GL\glew.h>

void UIRenderer::Render(sf::RenderWindow & window)
{
	window.pushGLStates();
	for (size_t i = 0; i < m_UIElements.size(); ++i)
	{
		m_UIElements[i]->Draw(window);
	}
	window.popGLStates();
}

void UIRenderer::AddUIElement(UI * ui)
{
	m_UIElements.push_back(ui);
}

void UIRenderer::RemoveUIElement(UI * ui)
{
	m_UIElements.erase(std::remove(m_UIElements.begin(), m_UIElements.end(), ui));
}
