#pragma once
#include <Behaviours\PostProcessors\PostProcessor.hpp>
#include <Textures\RenderTexture.hpp>
#include <Utils\Singleton.hpp>
#include <vector>

class PostProcessRenderer final : public Singleton<PostProcessRenderer>
{
friend Singleton<PostProcessRenderer>;
friend PostProcessor;

public:
	void Render(RenderTexture& sceneTexture);
private:
	PostProcessRenderer();

	RenderTexture m_backbuffer;

	void AddPostProcessor(PostProcessor* processor);
	void RemovePostProcessor(PostProcessor* processor);

	std::vector<PostProcessor*> m_postProcessors;
};