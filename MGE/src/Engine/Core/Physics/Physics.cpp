#include "Physics.hpp"
#include <Core\GameObject.hpp>
#include <Behaviours\Transform.hpp>
#include <Behaviours\SphereCollider.hpp>
#include <vector>

bool Physics::Raycast(const Ray & ray)
{
	return Raycast(ray, 0.0f);
}

bool Physics::Raycast(const Ray & ray, float maxDistance)
{
	RaycastHit hitInfo;
	return Raycast(ray, hitInfo, maxDistance);
}

bool Physics::Raycast(const Ray & ray, RaycastHit& hitInfo, float maxDistance)
{
	//Retrieve all the colliders in the scene
	const std::vector<SphereCollider*> colliders = GameObject::FindObjectsOfType<SphereCollider>();

	//For each collider, check if the ray collides with it
	for (const auto collider : colliders)
	{
		const glm::vec3 sphereCenter = collider->GetGameObject()->GetTransform()->GetWorldPosition();
		const glm::vec3 closestPointOnRayToSphere = ray.GetPointClosestTo(sphereCenter);
		const float distanceToPointOnRay = ray.GetDistanceToPointOnRay(closestPointOnRayToSphere);

		if (maxDistance <= 0.0f || distanceToPointOnRay <= maxDistance)
		{
			const glm::vec3 closestPointToSphereCenter = sphereCenter - closestPointOnRayToSphere;
			const float distanceSquared = glm::dot(closestPointToSphereCenter, closestPointToSphereCenter);
			if (distanceSquared <= collider->GetRadius() * collider->GetRadius())
			{
				hitInfo.SetPoint(closestPointOnRayToSphere);
				hitInfo.SetCollider(collider);
				return true;
			}
		}
	}

	return false;
}
