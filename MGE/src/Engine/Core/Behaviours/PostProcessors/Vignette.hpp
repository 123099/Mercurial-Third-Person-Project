#pragma once
#include <Behaviours\PostProcessors\PostProcessor.hpp>

class Vignette final : public PostProcessor
{
public:
	Vignette();

	void ProcessTexture(RenderTexture& texture, RenderTexture& originalTexture) override final;
};