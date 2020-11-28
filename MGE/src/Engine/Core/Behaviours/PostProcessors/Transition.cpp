#include "Transition.hpp"
#include <Core\Time.hpp>

Transition::Transition() : PostProcessor(*Shader::Find("post/transition")){}

void Transition::Awake()
{
	m_startTime = Time::s_gameTime;
}

void Transition::Play()
{
	m_startTime = Time::s_gameTime;
	m_isPlaying = true;
}

void Transition::SetColor(glm::vec3 color)
{
	m_color = glm::vec4(color, 1.0f);
}

void Transition::SetDirection(int direction)
{
	m_direction = direction;
}

void Transition::ProcessTexture(RenderTexture & texture, RenderTexture & originalTexture)
{
	m_shader.Bind();
	m_shader.SetProperty(ShaderProperty("time", Time::s_gameTime - m_startTime));
	m_shader.SetProperty(ShaderProperty("color", m_color));
	m_shader.SetProperty(ShaderProperty("direction", m_direction));
	m_shader.SetProperty(ShaderProperty("isPlaying", (int)m_isPlaying));

	texture.SetBindDepthTexture(false);
	texture.Bind(0);
	m_shader.SetProperty(ShaderProperty("colorTexture", &texture));
	
	DrawToTexture();

	texture.Unbind(0);
	m_shader.Unbind();
}
