#pragma once
#include <Behaviours\AbstractBehaviour.hpp>
#include <Behaviours\BehaviourAttributes.hpp>
#include <Behaviours\MeshRenderer.hpp>
#include <Utils\glm.hpp>
#include <memory>

class Camera;
class CubeMap;

class Skybox final : public AbstractBehaviour, public RequireBehaviours<MeshRenderer>
{
public:
	Skybox();

	void Awake() override final;

	void SetCamera(Camera* camera);
	void SetTintColor(glm::vec4 tintColor);
	void SetExposure(float exposure);
	void SetSkyboxCubeMap(CubeMap* skyboxCubeMap);

	void Update() override final;
private:
	Camera* m_camera;
	MeshRenderer* m_meshRenderer;

	CubeMap* m_skyboxCubeMap;
	glm::vec4 m_tintColor;
	float m_exposure;
};

