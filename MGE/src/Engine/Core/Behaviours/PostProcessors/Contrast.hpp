#pragma once
#include <Behaviours\PostProcessors\PostProcessor.hpp>

class Contrast final : public PostProcessor
{
public:
	Contrast();

	void SetContrast(float contrast);

	void ProcessTexture(RenderTexture& texture, RenderTexture& originalTexture) override final;
private:
	float m_contrast;
};