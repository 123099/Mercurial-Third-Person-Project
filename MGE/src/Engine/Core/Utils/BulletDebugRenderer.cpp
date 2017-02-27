#include "BulletDebugRenderer.hpp"
#include <Behaviours\Camera.hpp>

BulletDebugRenderer::BulletDebugRenderer() : m_lineShader(Shader::Find("unlit/lineShader"))
{
	m_vertexAttrib = m_lineShader->GetAttribute("vertex");
	m_colorAttrib = m_lineShader->GetAttribute("color");
}

void BulletDebugRenderer::StartRender()
{
	m_lineShader->Bind();
	m_lineShader->SetProperty(ShaderProperty("view", Camera::GetMainCamera()->GetViewMatrix()));
	m_lineShader->SetProperty(ShaderProperty("projection", Camera::GetMainCamera()->GetProjectionMatrix()));
}

void BulletDebugRenderer::EndRender()
{
	m_lineShader->Unbind();
}

void BulletDebugRenderer::drawLine(const btVector3 & from, const btVector3 & to, const btVector3 & color)
{
	const GLfloat line[6]
	{
		from.x(), from.y(), from.z(),
		to.x(), to.y(), to.z()
	};

	const GLfloat lineColor[6]
	{
		color.x(), color.y(), color.z(),
		color.x(), color.y(), color.z(),
	};

	//Vertices
	glGenBuffers(1, &m_vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(line), &line, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &m_colorBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_colorBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(lineColor), &lineColor, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glEnableVertexAttribArray(m_vertexAttrib);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
	glVertexAttribPointer(m_vertexAttrib, 3, GL_FLOAT, GL_FALSE, 0, 0);
	
	glEnableVertexAttribArray(m_colorAttrib);
	glBindBuffer(GL_ARRAY_BUFFER, m_colorBuffer);
	glVertexAttribPointer(m_colorAttrib, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glDrawArrays(GL_LINES, 0, 2);

	glDisableVertexAttribArray(m_vertexAttrib);
	glDisableVertexAttribArray(m_colorAttrib);

	glDeleteBuffers(1, &m_vertexBuffer);
	glDeleteBuffers(1, &m_colorBuffer);
}
