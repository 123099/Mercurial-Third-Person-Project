#include "Fog.hpp"
#include <Managers\LightManager.hpp>
#include <Behaviours\Camera.hpp>

Fog::Fog() : PostProcessor(*Shader::Find("post/fog")) {}

void Fog::ProcessTexture(RenderTexture & texture, RenderTexture& originalTexture)
{
	m_shader.Bind();

	//Pass the projection matrix to the shader
	m_shader.SetProperty(ShaderProperty("projectionMatrix", Camera::GetMainCamera()->GetProjectionMatrix()));

	//Pass the fog properties to the shader
	const LightManager& lightManager = LightManager::Instance();
	m_shader.SetProperty(ShaderProperty("fogColor", lightManager.GetFogColor()));
	m_shader.SetProperty(ShaderProperty("fogDensity", lightManager.GetFogDensity()));
	m_shader.SetProperty(ShaderProperty("fogStartDistance", lightManager.GetFogStartDistance()));

	//Pass color and depth textures to the shader
	texture.SetBindDepthTexture(false);
	texture.Bind(0);
	m_shader.SetProperty(ShaderProperty("colorTexture", &texture));

	originalTexture.SetBindDepthTexture(true);
	originalTexture.Bind(1);
	m_shader.SetProperty(ShaderProperty("depthTexture", &originalTexture));

	m_quad->StreamToOpenGL
	(
		m_shader.GetAttribute("vertex"),
		-1,
		m_shader.GetAttribute("uv"),
		-1
	);

	originalTexture.Unbind(1);
	texture.Unbind(0);

	m_shader.Unbind();
}
