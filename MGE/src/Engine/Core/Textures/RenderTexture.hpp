#pragma once
#include <Textures\Texture.hpp>

class RenderTexture : public Texture
{
public:
  	RenderTexture(int width, int height, bool depth = true);
	~RenderTexture();

    void Activate(bool clear = true);
    void Deactivate();

	int GetWidth();
	int GetHeight();

	void SetBindDepthTexture(bool bindDepthTexture);

	void Bind(GLuint textureUnit = 0) override final;
protected:
	GLuint m_fboHandle;
	GLuint m_depthRenderBuffer;
	GLuint m_depthTextureID;

	bool m_bindDepthTexture;
	bool m_hasDepth;

	int m_width;
	int m_height;
	GLint m_previousViewport[4];
};
