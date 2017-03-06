#include <Behaviours\Camera.hpp>
#include <Core\GameObject.hpp>
#include <Utils\Screen.hpp>
#include <gl\glew.h>

Camera* Camera::s_mainCamera;

Camera * Camera::GetMainCamera()
{
	return s_mainCamera;
}

Camera::Camera() :
	m_fieldOfView(60.0f),
	m_nearPlane(0.1f),
	m_farPlane(1000.0)
{
	ResetProjectionMatrix();
	SetAspect((float)Screen::Instance().GetWidth(), (float)Screen::Instance().GetHeight());

	if (s_mainCamera == nullptr)
	{
		s_mainCamera = this;
	}
}

void Camera::SetFieldOfView(float fieldOfView)
{
	m_fieldOfView = fieldOfView;
	ResetProjectionMatrix();
}

void Camera::SetAspect(float aspect)
{
	m_aspect = aspect;
	ResetProjectionMatrix();
}

void Camera::SetAspect(float width, float height)
{
	SetAspect(width / height);
}

void Camera::SetNearPlane(float nearPlane)
{
	m_nearPlane = nearPlane;
	ResetProjectionMatrix();
}

void Camera::SetFarPlane(float farPlane)
{
	m_farPlane = farPlane;
	ResetProjectionMatrix();
}

float Camera::GetFieldOfView() const
{
	return m_fieldOfView;
}

float Camera::GetAspect() const
{
	return m_aspect;
}

float Camera::GetNearPlane() const
{
	return m_nearPlane;
}

float Camera::GetFarPlane() const
{
	return m_farPlane;
}

void Camera::ResetProjectionMatrix()
{
	m_projection = glm::perspective(glm::radians(m_fieldOfView), m_aspect, m_nearPlane, m_farPlane);
}

glm::mat4 Camera::GetViewMatrix() const
{
	return glm::inverse(m_gameObject->GetTransform()->GetModelMatrix());
}

const glm::mat4& Camera::GetProjectionMatrix() const
{
    return m_projection;
}

Ray Camera::ScreenPointToRay(glm::vec2 point)
{
	GLint viewPort[4];
	glGetIntegerv(GL_VIEWPORT, &viewPort[0]);
	const glm::vec4 rayDirection_cameraSpace = glm::vec4(glm::unProject(glm::vec3(point, 0.0f), glm::mat4(), m_projection, glm::make_vec4(&viewPort[0])), 0.0f);
	return Ray(m_gameObject->GetTransform()->GetWorldPosition(), glm::normalize(m_gameObject->GetTransform()->GetModelMatrix() * rayDirection_cameraSpace));
}

