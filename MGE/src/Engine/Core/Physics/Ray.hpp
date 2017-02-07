#pragma once
#include <Utils\glm.hpp>

class Ray final
{
public:
	Ray(const glm::vec3& origin, const glm::vec3& direction);

	glm::vec3 GetOrigin();
	glm::vec3 GetDirection();

	glm::vec3 GetPoint(float distanceAlong);
	glm::vec3 GetPointClosestTo(const glm::vec3& point);
private:
	glm::vec3 m_origin;
	glm::vec3 m_direction;
};