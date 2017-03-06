#include "RenderTexture.hpp"
#include <SFML/Graphics.hpp>

RenderTexture::RenderTexture(int width, int height) : Texture("RenderTexture"), m_fboHandle(0), m_width(width), m_height(height)
{
    //Create the Frame Buffer
    glGenFramebuffers(1, &m_fboHandle);
    glBindFramebuffer(GL_FRAMEBUFFER, m_fboHandle);

	//Setup Color texture
    glBindTexture(GL_TEXTURE_2D, m_ID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	//Setup depth texture
	glGenTextures(1, &m_depthTextureID);
	glBindTexture(GL_TEXTURE_2D, m_depthTextureID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT24, width, height, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);

    //generate a depth buffer
    glGenRenderbuffers(1, &m_depthRenderBuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, m_depthRenderBuffer);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, width, height);

    // Bind the depth buffer to the FBO
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, m_depthRenderBuffer);

	//Bind the textures to the frame buffer
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_ID, 0);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, m_depthTextureID, 0);

    //set the target for the fragment shader outputs
    GLenum drawBufs[] = {GL_COLOR_ATTACHMENT0};
    glDrawBuffers(1, drawBufs);

    // Unbind the framebuffer, and revert to default framebuffer
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

RenderTexture::~RenderTexture()
{
	glDeleteTextures(1, &m_depthTextureID);
	glDeleteRenderbuffers(1, &m_depthRenderBuffer);
    glDeleteFramebuffers(1, &m_fboHandle);
	Deactivate();
}

void RenderTexture::Activate(bool clear) 
{
    glBindFramebuffer(GL_FRAMEBUFFER, m_fboHandle);

	if (clear == true)
	{
		glClearColor(0, 0, 0, 0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	glGetIntegerv(GL_VIEWPORT, &m_previousViewport[0]);
	glViewport(0, 0, m_width, m_height);
}

void RenderTexture::Deactivate() 
{
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glViewport(m_previousViewport[0], m_previousViewport[1], m_previousViewport[2], m_previousViewport[3]);
}

int RenderTexture::GetWidth()
{
	return m_width;
}

int RenderTexture::GetHeight()
{
	return m_height;
}

void RenderTexture::SetBindDepthTexture(bool bindDepthTexture)
{
	m_bindDepthTexture = bindDepthTexture;
}

void RenderTexture::Bind(GLuint textureUnit)
{
	glActiveTexture(GL_TEXTURE0 + textureUnit);
	if (m_bindDepthTexture == true)
	{
		glBindTexture(GL_TEXTURE_2D, m_depthTextureID);
	}
	else
	{
		glBindTexture(GL_TEXTURE_2D, m_ID);
	}
}


