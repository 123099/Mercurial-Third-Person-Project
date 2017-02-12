#include "Physics.hpp"
#include <Core\GameObject.hpp>

#include <Behaviours\Transform.hpp>
#include <Behaviours\SphereCollider.hpp>

#include <Core\Time.hpp>

#include <vector>

void Physics::Initialize()
{
	//Collision dispatcher configuration
	m_collisionConfig = std::make_unique<btDefaultCollisionConfiguration>();
	m_collisionDispatcher = std::make_unique<btCollisionDispatcher>(m_collisionConfig.get());

	//Collision test
	m_broadphaseInterface = std::make_unique<btDbvtBroadphase>(); //AABB

	//Constraint solver
	m_constraintSolver = std::make_unique<btSequentialImpulseConstraintSolver>();

	//Dynamics World
	m_physicsWorld = std::make_unique<btDiscreteDynamicsWorld>(m_collisionDispatcher.get(), m_broadphaseInterface.get(), m_constraintSolver.get(), m_collisionConfig.get());
}

void Physics::SetGravity(glm::vec3 gravity)
{
	m_physicsWorld->setGravity(btVector3(gravity.x, gravity.y, gravity.z));
}

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
	for (const auto& collider : colliders)
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

void Physics::StepSimulation()
{
	m_physicsWorld->stepSimulation(Time::s_fixedDeltaTime, 10, Time::s_fixedDeltaTime);
}

void Physics::AddRigidbody(btRigidBody & rigidbody)
{
	m_physicsWorld->addRigidBody(&rigidbody);
}

void Physics::RemoveRigidbody(btRigidBody & rigidbody)
{
	m_physicsWorld->removeRigidBody(&rigidbody);
}
