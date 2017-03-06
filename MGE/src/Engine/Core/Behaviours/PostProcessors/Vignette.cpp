#include "Vignette.hpp"

Vignette::Vignette() : PostProcessor(*Shader::Find("post/vignette")) {}

void Vignette::ProcessTexture(RenderTexture & texture, RenderTexture& originalTexture)
{
	m_shader.Bind();

	//Pass the screen's resolution to the shader
	m_shader.SetProperty(ShaderProperty("screenSize", glm::vec4(texture.GetWidth(), texture.GetHeight(), 0.0f, 0.0f)));

	//Pass the color texture of the scene
	texture.SetBindDepthTexture(false);
	texture.Bind(0);
	m_shader.SetProperty(ShaderProperty("colorTexture", &texture));

	//Draw the mesh
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
