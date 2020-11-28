#pragma once
#include <Behaviours\PostProcessors\PostProcessor.hpp>

class Transition final : public PostProcessor
{
public:
	Transition();

	void Awake() override final;

	void Play();

	void SetColor(glm::vec3 color);
	void SetDirection(int direction);

	void ProcessTexture(RenderTexture& texture, RenderTexture& originalTexture) override final;
private:
	float m_startTime;
	bool m_isPlaying;

	int m_direction;
	glm::vec4 m_color;
};