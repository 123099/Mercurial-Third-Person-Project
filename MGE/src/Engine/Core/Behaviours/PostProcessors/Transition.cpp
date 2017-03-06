#include "Transition.hpp"
#include <Core\Time.hpp>

Transition::Transition() : PostProcessor(*Shader::Find("post/transition")){}

void Transition::ProcessTexture(RenderTexture & texture, RenderTexture & originalTexture)
{
	m_shader.Bind();
	m_shader.SetProperty(ShaderProperty("time", Time::s_gameTime));

	texture.SetBindDepthTexture(false);
	texture.Bind(0);
	m_shader.SetProperty(ShaderProperty("colorTexture", &texture));
	
	m_quad->StreamToOpenGL
	(
		m_shader.GetAttribute("vertex"),
		-1,
		m_shader.GetAttribute("uv"),
		-1
	);

	texture.Unbind(0);
	m_shader.Unbind();
}
