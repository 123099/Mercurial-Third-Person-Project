#include "PostProcessRenderer.hpp"
#include <Core\GameObject.hpp>
#include <Behaviours\PostProcessors\PostProcessor.hpp>
#include <Utils\Screen.hpp>
#include <algorithm>

PostProcessRenderer::PostProcessRenderer() : m_backbuffer(Screen::Instance().GetWidth(), Screen::Instance().GetHeight(), false) {}

void PostProcessRenderer::Render(RenderTexture & sceneTexture)
{
	glDisable(GL_DEPTH_TEST);

	RenderTexture* sourceTexture = &sceneTexture;
	RenderTexture* destinationTexture = &m_backbuffer;

	const size_t count = m_postProcessors.size();
	for (size_t i = 0; i < count; ++i)
	{
		destinationTexture->Activate(false);
			m_postProcessors[i]->ProcessTexture(*sourceTexture, sceneTexture);
		destinationTexture->Deactivate();

		RenderTexture* temp = destinationTexture;
		destinationTexture = i < count - 1 ? sourceTexture : &sceneTexture;
		sourceTexture = temp;
	}

	glEnable(GL_DEPTH_TEST);
}

void PostProcessRenderer::AddPostProcessor(PostProcessor * processor)
{
	m_postProcessors.push_back(processor);
}

void PostProcessRenderer::RemovePostProcessor(PostProcessor * processor)
{
	m_postProcessors.erase(std::remove(m_postProcessors.begin(), m_postProcessors.end(), processor));
}
