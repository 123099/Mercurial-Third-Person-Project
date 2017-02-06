#include <Behaviours\Camera.hpp>
#include <iostream>

Camera* Camera::s_mainCamera;

Camera * Camera::GetMainCamera()
{
	return s_mainCamera;
}

Camera::Camera() :
	m_fieldOfView(60.0f),
	m_aspect(4.0f/3.0f),
	m_nearPlane(0.1f),
	m_farPlane(1000.0)
{
	ResetProjectionMatrix();

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

float Camera::GetFieldOfView()
{
	return m_fieldOfView;
}

float Camera::GetAspect()
{
	return m_aspect;
}

float Camera::GetNearPlane()
{
	return m_nearPlane;
}

float Camera::GetFarPlane()
{
	return m_farPlane;
}

void Camera::ResetProjectionMatrix()
{
	m_projection = glm::perspective(glm::radians(m_fieldOfView), m_aspect, m_nearPlane, m_farPlane);
}

const glm::mat4& Camera::GetProjectionMatrix() 
{
    return m_projection;
}

