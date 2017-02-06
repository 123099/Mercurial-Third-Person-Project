#ifndef CAMERA_H
#define CAMERA_H

#include <Behaviours\AbstractBehaviour.hpp>
#include <string>
#include <Utils\glm.hpp>

/**
 * Camera is just a Behaviour with an additional projection matrix.
 * The camera's own transform is used to generate a world to view matrix by taking the inverse of the camera transform
 * (see renderer).
 */
class Camera final : public AbstractBehaviour
{
public:
	static Camera* GetMainCamera();

	Camera();

	void SetFieldOfView(float fieldOfView);
	void SetAspect(float aspect);
	void SetAspect(float width, float height);
	void SetNearPlane(float nearPlane);
	void SetFarPlane(float farPlane);

	float GetFieldOfView();
	float GetAspect();
	float GetNearPlane();
	float GetFarPlane();

	void ResetProjectionMatrix();
    const glm::mat4& GetProjectionMatrix();
private:
	static Camera* s_mainCamera;

	glm::mat4 m_projection;

	float m_fieldOfView;
	float m_aspect;
	float m_nearPlane;
	float m_farPlane;

	bool m_hasChanged; //Tracks when a change has occured to require a recalculation of the projection matrix
};

#endif // CAMERA_H
