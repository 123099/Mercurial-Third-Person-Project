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

	DrawToTexture();

	texture.Unbind(0);

	m_shader.Unbind();
}
