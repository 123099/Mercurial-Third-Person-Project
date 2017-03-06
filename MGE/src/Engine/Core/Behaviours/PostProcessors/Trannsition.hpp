#pragma once
#include <Behaviours\PostProcessors\PostProcessor.hpp>

class Transition final : public PostProcessor
{
public:
	Transition();
	void ProcessTexture(RenderTexture& texture, RenderTexture& originalTexture) override final;
};