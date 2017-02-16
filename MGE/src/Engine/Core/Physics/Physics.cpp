#include "Physics.hpp"
#include <Core\GameObject.hpp>
#include <Core\Time.hpp>

#include <Behaviours\Transform.hpp>
#include <Behaviours\Collider.hpp>
#include <Behaviours\Rigidbody.hpp>

#include <bullet\BulletCollision\CollisionDispatch\btGhostObject.h>

#include <vector>

void Physics::Initialize()
{
	//Collision dispatcher configuration
	m_collisionConfig = std::make_unique<btDefaultCollisionConfiguration>();
	m_collisionDispatcher = std::make_unique<btCollisionDispatcher>(m_collisionConfig.get());

	//Collision test
	m_broadphaseInterface = std::make_unique<btDbvtBroadphase>(); //AABB

	//Ghost objects
	m_broadphaseInterface->getOverlappingPairCache()->setInternalGhostPairCallback(new btGhostPairCallback());

	//Constraint solver
	m_constraintSolver = std::make_unique<btSequentialImpulseConstraintSolver>();

	//Dynamics World
	m_physicsWorld = std::make_unique<btDiscreteDynamicsWorld>(m_collisionDispatcher.get(), m_broadphaseInterface.get(), m_constraintSolver.get(), m_collisionConfig.get());
}

void Physics::SetGravity(glm::vec3 gravity)
{
	m_physicsWorld->setGravity(btVector3(gravity.x, gravity.y, gravity.z));
}

glm::vec3 Physics::GetGravity()
{
	return glm::vec3(m_physicsWorld->getGravity().getX(), m_physicsWorld->getGravity().getY(), m_physicsWorld->getGravity().getZ());
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
	//Do a ray cast using bullet
	const btVector3 Start(ray.GetOrigin().x, ray.GetOrigin().y, ray.GetOrigin().z);
	const glm::vec3 endGLM = ray.GetPoint(maxDistance <= 0 ? 99999 : maxDistance);
	const btVector3 End(endGLM.x, endGLM.y, endGLM.z);

	btCollisionWorld::ClosestRayResultCallback bulletHitInfo(Start, End);
	m_physicsWorld->rayTest(Start, End, bulletHitInfo);

	if (bulletHitInfo.hasHit())
	{
		//Set data to the ray cast hit info
		hitInfo.SetPoint(glm::vec3(bulletHitInfo.m_hitPointWorld.getX(), bulletHitInfo.m_hitPointWorld.getY(), bulletHitInfo.m_hitPointWorld.getZ()));
		hitInfo.SetNormal(glm::vec3(bulletHitInfo.m_hitNormalWorld.getX(), bulletHitInfo.m_hitNormalWorld.getY(), bulletHitInfo.m_hitNormalWorld.getZ()));

		//Find the rigidbody that was hit
		const btCollisionObject* collisionObject = bulletHitInfo.m_collisionObject;
		const Rigidbody* rigidbody = BulletToMGERigidbody(collisionObject);

		if (rigidbody != nullptr)
		{
			hitInfo.SetCollider(rigidbody->GetGameObject()->GetBehaviour<Collider>());
		}

		return true;
	}

	return false;
}

std::vector<RaycastHit> Physics::RaycastAll(const Ray & ray, float maxDistance)
{
	//Do a ray cast using bullet
	const btVector3 Start(ray.GetOrigin().x, ray.GetOrigin().y, ray.GetOrigin().z);
	const glm::vec3 endGLM = ray.GetPoint(maxDistance < 0 ? 0 : maxDistance);
	const btVector3 End(endGLM.x, endGLM.y, endGLM.z);

	btCollisionWorld::AllHitsRayResultCallback bulletHitInfo(Start, End);
	m_physicsWorld->rayTest(Start, End, bulletHitInfo);

	std::vector<RaycastHit> hitInfoVector;

	if (bulletHitInfo.hasHit())
	{
		const int hitObjectCount = bulletHitInfo.m_collisionObjects.size();

		for (int i = 0; i < hitObjectCount; ++i)
		{
			RaycastHit hitInfo;

			//Set data to the ray cast hit info
			hitInfo.SetPoint(glm::vec3(bulletHitInfo.m_hitPointWorld[i].getX(), bulletHitInfo.m_hitPointWorld[i].getY(), bulletHitInfo.m_hitPointWorld[i].getZ()));
			hitInfo.SetNormal(glm::vec3(bulletHitInfo.m_hitNormalWorld[i].getX(), bulletHitInfo.m_hitNormalWorld[i].getY(), bulletHitInfo.m_hitNormalWorld[i].getZ()));

			//Find the rigidbody that was hit
			const btCollisionObject* collisionObject = bulletHitInfo.m_collisionObjects[i];
			const Rigidbody* rigidbody = BulletToMGERigidbody(collisionObject);

			if (rigidbody != nullptr)
			{
				hitInfo.SetCollider(rigidbody->GetGameObject()->GetBehaviour<Collider>());
			}

			hitInfoVector.push_back(hitInfo);
		}
	}

	return hitInfoVector;
}

void Physics::AddCollisionObject(btCollisionObject * bulletCollisionObject)
{
	m_physicsWorld->addCollisionObject(bulletCollisionObject, btBroadphaseProxy::AllFilter, btBroadphaseProxy::StaticFilter);
}

void Physics::RemoveCollisionObject(btCollisionObject * bulletCollisionObject)
{
	m_physicsWorld->removeCollisionObject(bulletCollisionObject);
}

void Physics::AddAction(btActionInterface * bulletAction)
{
	m_physicsWorld->addAction(bulletAction);
}

void Physics::RemoveAction(btActionInterface * bulletAction)
{
	m_physicsWorld->removeAction(bulletAction);
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

Rigidbody * Physics::BulletToMGERigidbody(const btCollisionObject * collisionObject)
{
	std::vector<Rigidbody*> rigidbodies = GameObject::FindObjectsOfType<Rigidbody>();
	for (const auto& rigidbody : rigidbodies)
	{
		if (rigidbody->GetBulletRigidbody() == collisionObject)
		{
			return rigidbody;
		}
	}

	return nullptr;
}
