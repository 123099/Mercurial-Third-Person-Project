#include <Renderers\Renderer.hpp>
#include <Core\GameObject.hpp>
#include <Core\Mesh.hpp>
#include <Core\Material.hpp>

#include <Behaviours\Camera.hpp>
#include <Behaviours\MeshRenderer.hpp>

#include <GL/glew.h>
#include <algorithm>

void Renderer::Initialize()
{
	glEnable(GL_TEXTURE_CUBE_MAP_SEAMLESS);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE); // default GL_BACK
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	SetClearColor(0.0f, 0.0f, 0.0f);
}

void Renderer::SetClearColor(float r, float g, float b)
{
    glClearColor(r, g, b, 1.0f );
}

void Renderer::Render (const glm::mat4& viewMatrix, const glm::mat4& projectionMatrix)
{
	//Get the matrices common to all game objects for this frame
	const glm::mat4 viewProjectionMatrix = projectionMatrix * viewMatrix;

	//Render all the renderables that are registered
	const size_t renderablesCount = m_renderables.size();
	for (size_t i = 0; i < renderablesCount; ++i)
	{
		m_renderables[i]->Render(viewMatrix, projectionMatrix, viewProjectionMatrix);
	}

	//Set the active texture back to texture unit 0, which is the default mode for SFML
	glActiveTexture(GL_TEXTURE0);
}

void Renderer::AddRenderable(MeshRenderer * meshRenderer)
{
	m_renderables.push_back(meshRenderer);
}

void Renderer::RemoveRenderable(MeshRenderer * meshRenderer)
{
	m_renderables.erase(std::remove(m_renderables.begin(), m_renderables.end(), meshRenderer));
}

