#pragma once

#include <Behaviours\AbstractBehaviour.hpp>
#include <Physics\Ray.hpp>
#include <Utils\glm.hpp>
#include <string>

class Camera final : public AbstractBehaviour
{
public:
	static Camera* GetMainCamera();
	static void SetMainCamera(Camera * camera);

	Camera();

	void SetFieldOfView(float fieldOfView);
	void SetAspect(float aspect);
	void SetAspect(float width, float height);
	void SetNearPlane(float nearPlane);
	void SetFarPlane(float farPlane);

	float GetFieldOfView() const;
	float GetAspect() const;
	float GetNearPlane() const;
	float GetFarPlane() const;

	void ResetProjectionMatrix();

	glm::mat4 GetViewMatrix() const;
    const glm::mat4& GetProjectionMatrix() const;

	Ray ScreenPointToRay(glm::vec2 point);
private:
	static Camera* s_mainCamera;

	glm::mat4 m_projection;

	float m_fieldOfView;
	float m_aspect;
	float m_nearPlane;
	float m_farPlane;
};
