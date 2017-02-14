#include "Ray.hpp"

Ray::Ray(const glm::vec3 & origin, const glm::vec3 & direction) :
	m_origin(origin),
	m_direction(glm::normalize(direction)) {}

void Ray::ChangeOrigin(float distanceAlongRayToNewOrigin)
{
	m_origin = GetPoint(distanceAlongRayToNewOrigin);
}

glm::vec3 Ray::GetOrigin() const
{
	return m_origin;
}

glm::vec3 Ray::GetDirection() const
{
	return m_direction;
}

glm::vec3 Ray::GetPoint(float distanceAlong) const
{
	return m_origin + distanceAlong * m_direction;
}

glm::vec3 Ray::GetPointClosestTo(const glm::vec3 & point) const
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

float Ray::GetDistanceToPointOnRay(const glm::vec3 & point) const
{
	return (point.x - m_origin.x) / m_direction.x; //X = A + tB -> t = (X-A)/B. x,y,z should all equal t, when X is on ray and B is no zero
}
