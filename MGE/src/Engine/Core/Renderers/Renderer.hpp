#pragma once

#include <Utils\glm.hpp>
#include <Utils\Singleton.hpp>
#include <vector>

class GameObject;
class Camera;
class MeshRenderer;

class Renderer final : public Singleton<Renderer>
{
friend Singleton<Renderer>;
friend MeshRenderer;

public:
	void Initialize();

    void SetClearColor (float r, float g, float b);

    void Render (const glm::mat4& viewMatrix, const glm::mat4& projectionMatrix, bool simpleRender = false);
private:
	Renderer() = default;
	std::vector<MeshRenderer*> m_renderables;

	void AddRenderable(MeshRenderer* meshRenderer);
	void RemoveRenderable(MeshRenderer* meshRenderer);
};
