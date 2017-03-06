#include "Contrast.hpp"

Contrast::Contrast() : PostProcessor(*Shader::Find("post/contrast")) {}

void Contrast::SetContrast(float contrast)
{
	m_contrast = contrast;
}

void Contrast::ProcessTexture(RenderTexture & texture, RenderTexture& originalTexture)
{
	m_shader.Bind();

	m_shader.SetProperty(ShaderProperty("contrast", m_contrast));

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
