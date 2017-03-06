#pragma once
#include <Behaviours\PostProcessors\PostProcessor.hpp>

class Fog final : public PostProcessor
{
public:
	Fog();

	void ProcessTexture(RenderTexture& texture, RenderTexture& originalTexture) override final;
};