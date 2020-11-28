#pragma once
#include <Behaviours\AbstractBehaviour.hpp>
#include <Behaviours\BehaviourAttributes.hpp>
#include <Behaviours\MeshRenderer.hpp>
#include <Behaviours\Camera.hpp>
#include <Textures\RenderTexture.hpp>

class TV final : public AbstractBehaviour, public RequireBehaviours<MeshRenderer>
{
public:
	TV();

	void Awake() override final;
	void Update() override final;
private:
	RenderTexture m_texture;
	MeshRenderer* m_meshRenderer;
	Camera* m_camera;
};