#pragma once
#include <GL\glew.h>
#include <Utils\glm.hpp>
#include <Core\Shader.hpp>
#include <bullet\LinearMath\btIDebugDraw.h>

class BulletDebugRenderer : public btIDebugDraw 
{
public:
	BulletDebugRenderer();

	void StartRender();
	void EndRender();

	void drawLine(const btVector3& from, const btVector3& to, const btVector3& color) override;
	void drawContactPoint(const btVector3 &, const btVector3 &, btScalar, int, const btVector3 &) override {}
	void reportErrorWarning(const char *) override {}
	void draw3dText(const btVector3 &, const char *) override {}
	void setDebugMode(int p) override {}
	int getDebugMode(void) const override { return btIDebugDraw::DBG_DrawWireframe; }
private:
	GLuint m_vertexBuffer;
	GLuint m_colorBuffer;

	GLuint m_vertexAttrib;
	GLuint m_colorAttrib;

	Shader* m_lineShader;
};