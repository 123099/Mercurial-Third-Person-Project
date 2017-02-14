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
	glm::vec3 GetGravity();

	bool Raycast(const Ray& ray);
	bool Raycast(const Ray& ray, float maxDistance);
	bool Raycast(const Ray& ray, RaycastHit& hitInfo, float maxDistance);
	std::vector<RaycastHit> RaycastAll(const Ray& ray, float maxDistance);

	void AddCollisionObject(btCollisionObject* bulletCollisionObject);
	void RemoveCollisionObject(btCollisionObject* bulletCollisionObject);

	void AddAction(btActionInterface* bulletAction);
	void RemoveAction(btActionInterface* bulletAction);

	void StepSimulation();
private:
	std::unique_ptr<btDiscreteDynamicsWorld> m_physicsWorld;
	std::unique_ptr<btCollisionDispatcher> m_collisionDispatcher;
	std::unique_ptr<btDefaultCollisionConfiguration> m_collisionConfig;
	std::unique_ptr<btBroadphaseInterface> m_broadphaseInterface;
	std::unique_ptr<btSequentialImpulseConstraintSolver> m_constraintSolver;

	void AddRigidbody(btRigidBody& rigidbody);
	void RemoveRigidbody(btRigidBody& rigidbody);

	Rigidbody* BulletToMGERigidbody(const btCollisionObject* collisionObject);
};