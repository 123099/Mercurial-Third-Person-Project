#pragma once
#include <Physics\Ray.hpp>
#include <Physics\RaycastHit.hpp>

#include <Behaviours\Rigidbody.hpp>
#include <bullet\btBulletDynamicsCommon.h>

#include <Utils\Singleton.hpp>
#include <Utils\glm.hpp>

#include <memory>

class Physics final : public Singleton<Physics>
{
friend Singleton<Physics>;
friend Rigidbody;

public:
	void Initialize();
	void SetGravity(glm::vec3 gravity);

	bool Raycast(const Ray& ray);
	bool Raycast(const Ray& ray, float maxDistance);
	bool Raycast(const Ray& ray, RaycastHit& hitInfo, float maxDistance);

	void StepSimulation();
private:
	std::unique_ptr<btDiscreteDynamicsWorld> m_physicsWorld;
	std::unique_ptr<btCollisionDispatcher> m_collisionDispatcher;
	std::unique_ptr<btDefaultCollisionConfiguration> m_collisionConfig;
	std::unique_ptr<btBroadphaseInterface> m_broadphaseInterface;
	std::unique_ptr<btSequentialImpulseConstraintSolver> m_constraintSolver;

	void AddRigidbody(btRigidBody& rigidbody);
	void RemoveRigidbody(btRigidBody& rigidbody);
};