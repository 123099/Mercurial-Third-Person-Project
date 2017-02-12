#include <Behaviours\Rigidbody.hpp>
#include <Physics\Physics.hpp>
#include <Core\GameObject.hpp>
#include <Behaviours\Transform.hpp>

Rigidbody::Rigidbody() : m_mass(1.0f) {}

void Rigidbody::Awake()
{
	//Cache the collider on the game object
	m_collider = m_gameObject->GetBehaviour<Collider>();

	//Create a motion state starting out at the transform's location and orientation
	const glm::vec3 transformWorldPosition = m_gameObject->GetTransform()->GetWorldPosition();
	const btTransform startTransform(m_gameObject->GetTransform()->GetWorldRotation(), btVector3(transformWorldPosition.x, transformWorldPosition.y, transformWorldPosition.z));
	m_rigidbodyMotion = std::make_unique<btDefaultMotionState>(startTransform);

	//Retrieve the collision shape
	btCollisionShape* collisionShape = m_collider->GetBulletCollisionShape();

	//Calculate inertia for the provided mass
	btVector3 inertia;
	collisionShape->calculateLocalInertia(m_mass, inertia);

	//Create the Rigid body
	const btRigidBody::btRigidBodyConstructionInfo rigidbodyInfo(m_mass, m_rigidbodyMotion.get(), collisionShape, inertia);
	m_rigidbody = std::make_unique<btRigidBody>(rigidbodyInfo);

	Physics::Instance().AddRigidbody(*m_rigidbody);
}

void Rigidbody::Update()
{
	//Get the transform of the rigidbody simulation
	btTransform rbTransform;
	m_rigidbodyMotion->getWorldTransform(rbTransform);

	//Update the game object's transform based on the transform of the rigid body
	m_gameObject->GetTransform()->SetWorldPosition(glm::vec3(rbTransform.getOrigin().getX(), rbTransform.getOrigin().getY(), rbTransform.getOrigin().getZ()));
	m_gameObject->GetTransform()->SetWorldRotation(rbTransform.getRotation());
}

void Rigidbody::SetMass(float mass)
{
	m_mass = mass;

	if (m_rigidbody != nullptr)
	{
		//Remove the rigidbody from the world
		Physics::Instance().RemoveRigidbody(*m_rigidbody);

		//Change the mass
		btVector3 inertia;
		m_collider->GetBulletCollisionShape()->calculateLocalInertia(mass, inertia);
		m_rigidbody->setMassProps(mass, inertia);

		//Add the rigidbody back to the world
		Physics::Instance().AddRigidbody(*m_rigidbody);
	}
}
