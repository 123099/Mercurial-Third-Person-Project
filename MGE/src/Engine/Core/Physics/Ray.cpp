#include "Ray.hpp"

Ray::Ray(const glm::vec3 & origin, const glm::vec3 & direction) :
	m_origin(origin),
	m_direction(glm::normalize(direction)) {}

glm::vec3 Ray::GetOrigin()
{
	return m_origin;
}

glm::vec3 Ray::GetDirection()
{
	return m_direction;
}

glm::vec3 Ray::GetPoint(float distanceAlong)
{
	return m_origin + distanceAlong * m_direction;
}

glm::vec3 Ray::GetPointClosestTo(const glm::vec3 & point)
{
	const glm::vec3 originToPoint = point - m_origin;
	const glm::vec3 parallelToRay = glm::proj(originToPoint, m_direction);

	//Make sure that the point is in front of the ray, otherwise, the closest point is the origin
	if (glm::dot(glm::normalize(parallelToRay), m_direction) < 0)
	{
		return m_origin;
	}
	else
	{
		const glm::vec3 perpendicularToRay = originToPoint - parallelToRay;
		return point - perpendicularToRay;
	}
}
