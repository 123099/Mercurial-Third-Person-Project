#include <Managers\Renderer.hpp>
#include <Core\GameObject.hpp>
#include <Behaviours\Camera.hpp>
#include <Core\Mesh.hpp>
#include <Core\Material.hpp>
#include <Utils\Profiler.hpp>
#include <Behaviours\MeshRenderer.hpp>
#include <Behaviours\Transform.hpp>
#include <Core\Scene.hpp>
#include <GL/glew.h>
#include <iostream>
#include <algorithm>

Renderer::Renderer()
{
	glEnable(GL_TEXTURE_CUBE_MAP_SEAMLESS);
	glEnable( GL_DEPTH_TEST );
	glEnable( GL_CULL_FACE ); // default GL_BACK
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	SetClearColor(0.0f, 0.0f, 0.0f);
}

void Renderer::SetClearColor(float r, float g, float b)
{
    glClearColor(r, g, b, 1.0f );
}

glm::mat4 Renderer::GetViewMatrix() const
{
	return Camera::GetMainCamera()->GetViewMatrix();
}

glm::mat4 Renderer::GetProjectionMatrix() const
{
	return Camera::GetMainCamera()->GetProjectionMatrix();
}

void Renderer::Render ()
{
	//Get the matrices common to all game objects for this frame
	const glm::mat4 viewMatrix = GetViewMatrix();
	const glm::mat4 projectionMatrix = GetProjectionMatrix();
	const glm::mat4 viewProjectionMatrix = projectionMatrix * viewMatrix;

	//Render all the renderables that are part of the currently active scene
	//TODO: UNORDERED MAP WITH KEY = SCENE
	const size_t renderablesCount = m_renderables.size();
	for (size_t i = 0; i < renderablesCount; ++i)
	{
		m_renderables[i]->Render(viewMatrix, projectionMatrix, viewProjectionMatrix);
	}
}

void Renderer::AddRenderable(MeshRenderer * meshRenderer)
{
	m_renderables.push_back(meshRenderer);
}

void Renderer::RemoveRenderable(MeshRenderer * meshRenderer)
{
	m_renderables.erase(std::remove(m_renderables.begin(), m_renderables.end(), meshRenderer));
}

