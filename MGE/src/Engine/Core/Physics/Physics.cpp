#include "Physics.hpp"
#include <Core\GameObject.hpp>
#include <Behaviours\Transform.hpp>
#include <Behaviours\SphereCollider.hpp>
#include <vector>

bool Physics::RayCast(const Ray & ray)
{
	//Retrieve all the colliders in the scene
	const std::vector<SphereCollider*> colliders = GameObject::FindObjectsOfType<SphereCollider>();
	
	//For each collider, check if the ray collides with it
	for (const auto collider : colliders)
	{
		const glm::vec3 sphereCenter = collider->GetGameObject()->GetTransform()->GetWorldPosition();
		const glm::vec3 closestPointOnRayToSphere = ray.GetPointClosestTo(sphereCenter);
		const glm::vec3 closestPointToSphereCenter = sphereCenter - closestPointOnRayToSphere;
		const float distanceSquared = glm::dot(closestPointToSphereCenter, closestPointToSphereCenter);
		if (distanceSquared <= collider->GetRadius() * collider->GetRadius())
		{
			return true;
		}
	}

	return false;
}
