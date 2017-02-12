#pragma once
#include <Textures\Texture.hpp>
#include <GL\glew.h>
#include <Utils\Screen.hpp>

class RenderTexture final : public Texture
{
public:
	RenderTexture();
	//void Bind(GLuint textureUnit) override;
	//void Unbind(GLuint textureUnit) override;
private:
	GLuint m_frameBuffer;
	GLuint m_depthRenderBuffer;
};