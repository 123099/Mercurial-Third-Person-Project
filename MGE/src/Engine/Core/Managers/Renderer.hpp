#pragma once
#ifndef RENDERER_H
#define RENDERER_H

#include <Utils\glm.hpp>
#include <vector>

class Scene;
class GameObject;
class Camera;
class MeshRenderer;

/**
 * Renderer implements a default single pass forward renderer.
 */
class Renderer final
{
friend MeshRenderer;

public:
	static Renderer& Instance();

    void SetClearColor (float r, float g, float b);

	glm::mat4 GetViewMatrix() const;
	glm::mat4 GetProjectionMatrix() const;

    void Render (const Scene& scene);
private:
	Renderer();
	std::vector<MeshRenderer*> m_renderables;

	void AddRenderable(MeshRenderer* meshRenderer);
	void RemoveRenderable(MeshRenderer* meshRenderer);
};

#endif // RENDERER_H
