#pragma once

#include <Utils\glm.hpp>
#include <Utils\Singleton.hpp>
#include <vector>

class GameObject;
class Camera;
class MeshRenderer;

/**
 * Renderer implements a default single pass forward renderer.
 */
class Renderer final : public Singleton<Renderer>
{
friend Singleton<Renderer>;
friend MeshRenderer;

public:
    void SetClearColor (float r, float g, float b);

	glm::mat4 GetViewMatrix() const;
	glm::mat4 GetProjectionMatrix() const;

    void Render ();
private:
	Renderer();
	std::vector<MeshRenderer*> m_renderables;

	void AddRenderable(MeshRenderer* meshRenderer);
	void RemoveRenderable(MeshRenderer* meshRenderer);
};