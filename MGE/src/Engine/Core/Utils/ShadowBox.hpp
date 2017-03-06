#pragma once
#include <Behaviours\Camera.hpp>
#include <vector>

class ShadowBox final
{
public:
	ShadowBox(Camera& camera, float distance, float offset);

	void Calculate(const glm::mat4& lightViewMatrix);

	glm::vec3 GetCenter(const glm::mat4& lightViewMatrix);

	glm::mat4 GetViewMatrix(const glm::mat4& lightViewMatrix, glm::vec3 lightDirection);
	glm::mat4 GetProjectionMatrix();
private:
	Camera& m_camera;
	float m_shadowDistance;
	float m_boxOffset;

	float m_minX, m_maxX;
	float m_minY, m_maxY;
	float m_minZ, m_maxZ; 

	glm::vec2 m_nearPlaneSize;
	glm::vec2 m_farPlaneSize;

	std::vector<glm::vec3> GetFrustumVertices(const glm::mat4& lightViewMatrix, const glm::vec3& farPlaneCenter, const glm::vec3& nearPlaneCenter);
	glm::vec3 GetLightSpaceFrustumVertex(const glm::mat4& lightViewMatrix, const glm::vec3& start, const glm::vec3& direction, float width);

	float GetWidth();
	float GetHeight();
	float GetDepth();
};
