#include "ShadowBox.hpp"
#include <Core\GameObject.hpp>
#include <Behaviours\Transform.hpp>

ShadowBox::ShadowBox(Camera & camera, float distance, float offset) : m_camera(camera), m_shadowDistance(distance), m_boxOffset(offset)
{
	//Calculate the size of the near and far planes
	m_nearPlaneSize.x = m_camera.GetNearPlane() * glm::tan(glm::radians(m_camera.GetFieldOfView()));
	m_nearPlaneSize.y = m_nearPlaneSize.x / m_camera.GetAspect();

	m_farPlaneSize.x = m_shadowDistance * glm::tan(glm::radians(m_camera.GetFieldOfView()));
	m_farPlaneSize.y = m_farPlaneSize.x / m_camera.GetAspect();
}

void ShadowBox::Calculate(const glm::mat4 & lightViewMatrix)
{
	glm::vec3 cameraPosition = m_camera.GetGameObject()->GetTransform()->GetWorldPosition();
	glm::vec3 cameraForward = m_camera.GetGameObject()->GetTransform()->GetForwardVector();

	glm::vec3 nearPlaneCenter = cameraPosition + cameraForward * m_shadowDistance;
	glm::vec3 farPlaneCenter = cameraPosition + cameraForward * m_camera.GetNearPlane();

	std::vector<glm::vec3> frustumVertices = GetFrustumVertices(lightViewMatrix, farPlaneCenter, nearPlaneCenter);

	m_minX = m_maxX = frustumVertices[0].x;
	m_minY = m_maxY = frustumVertices[0].y;
	m_minZ = m_maxZ = frustumVertices[0].z;

	for (size_t i = 1; i < frustumVertices.size(); ++i)
	{
		glm::vec3& point = frustumVertices[i];
		
		if (point.x > m_maxX)
		{
			m_maxX = point.x;
		}
		else if (point.x < m_minX)
		{
			m_minX = point.x;
		}

		if (point.y > m_maxY)
		{
			m_maxY = point.y;
		}
		else if (point.y < m_minY)
		{
			m_minY = point.y;
		}

		if (point.z > m_maxZ)
		{
			m_maxZ = point.z;
		}
		else if (point.z < m_minZ)
		{
			m_minZ = point.z;
		}
	}

	m_maxZ += m_boxOffset;
}

glm::vec3 ShadowBox::GetCenter(const glm::mat4& lightViewMatrix)
{
	float x = (m_minX + m_maxX) * 0.5f;
	float y = (m_minX + m_maxX) * 0.5f;
	float z = (m_minX + m_maxX) * 0.5f;

	return glm::vec3(glm::inverse(lightViewMatrix) * glm::vec4(x, y, z, 1.0f));
}

glm::mat4 ShadowBox::GetViewMatrix(const glm::mat4& lightViewMatrix, glm::vec3 lightDirection)
{
	return glm::lookAt(lightDirection, GetCenter(lightViewMatrix), glm::vec3(0.0f, 1.0f, 0.0f));
}

glm::mat4 ShadowBox::GetProjectionMatrix()
{
	float w = GetWidth();
	float h = GetHeight();
	float z = GetDepth();
	return glm::ortho(-w, w, -h, h, -z, z);
}

std::vector<glm::vec3> ShadowBox::GetFrustumVertices(const glm::mat4& lightViewMatrix, const glm::vec3& farPlaneCenter, const glm::vec3& nearPlaneCenter)
{
	std::vector<glm::vec3> vertices;

	//Calculate the 8 vertices of the camera frustum in light space
	glm::vec3 cameraUp = m_camera.GetGameObject()->GetTransform()->GetUpVector();
	glm::vec3 cameraDown = -cameraUp;
	glm::vec3 cameraRight = m_camera.GetGameObject()->GetTransform()->GetRightVector();
	glm::vec3 cameraLeft = -cameraRight;

	glm::vec3 farPlaneTop = farPlaneCenter + cameraUp * m_farPlaneSize.y;
	glm::vec3 farPlaneBottom = farPlaneCenter + cameraDown * m_farPlaneSize.y;
	glm::vec3 nearPlaneTop = nearPlaneCenter + cameraUp * m_nearPlaneSize.y;
	glm::vec3 nearPlaneBottom = nearPlaneCenter + cameraDown * m_nearPlaneSize.y;

	vertices.push_back(GetLightSpaceFrustumVertex(lightViewMatrix, farPlaneTop, cameraRight, m_farPlaneSize.x));
	vertices.push_back(GetLightSpaceFrustumVertex(lightViewMatrix, farPlaneTop, cameraLeft, m_farPlaneSize.x));
	vertices.push_back(GetLightSpaceFrustumVertex(lightViewMatrix, farPlaneBottom, cameraRight, m_farPlaneSize.x));
	vertices.push_back(GetLightSpaceFrustumVertex(lightViewMatrix, farPlaneBottom, cameraLeft, m_farPlaneSize.x));

	vertices.push_back(GetLightSpaceFrustumVertex(lightViewMatrix, nearPlaneTop, cameraRight, m_nearPlaneSize.x));
	vertices.push_back(GetLightSpaceFrustumVertex(lightViewMatrix, nearPlaneTop, cameraLeft, m_nearPlaneSize.x));
	vertices.push_back(GetLightSpaceFrustumVertex(lightViewMatrix, nearPlaneBottom, cameraRight, m_nearPlaneSize.x));
	vertices.push_back(GetLightSpaceFrustumVertex(lightViewMatrix, nearPlaneBottom, cameraLeft, m_nearPlaneSize.x));

	return vertices;
}

glm::vec3 ShadowBox::GetLightSpaceFrustumVertex(const glm::mat4 & lightViewMatrix, const glm::vec3& start, const glm::vec3& direction, float width)
{
	glm::vec4 point = glm::vec4(start + direction * width, 1.0f);

	return glm::vec3(lightViewMatrix * point);
}

float ShadowBox::GetWidth()
{
	return m_maxX - m_minX;
}

float ShadowBox::GetHeight()
{
	return m_maxY - m_minY;
}

float ShadowBox::GetDepth()
{
	return  m_maxZ - m_minZ;
}
