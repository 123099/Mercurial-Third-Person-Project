#pragma once
#include <Textures\Texture.hpp>

class RenderTexture : public Texture
{
public:
  	RenderTexture(int width, int height);
	virtual ~RenderTexture();

    void Activate();
    void Deactivate();

	void SetBindDepthTexture(bool bindDepthTexture);

	void Bind(GLuint textureUnit = 0) override final;
protected:
	GLuint m_fboHandle;
	GLuint m_depthTextureID;

	bool m_bindDepthTexture;
};
