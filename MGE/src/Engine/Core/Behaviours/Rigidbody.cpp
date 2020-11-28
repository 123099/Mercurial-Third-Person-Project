#include <Behaviours\Rigidbody.hpp>
#include <Physics\Physics.hpp>
#include <Core\GameObject.hpp>
#include <Behaviours\Transform.hpp>

Rigidbody::Rigidbody() : m_mass(1.0f), m_friction(0.5f) {}

Rigidbody::~Rigidbody()
{
	Physics::Instance().RemoveRigidbody(*m_rigidbody);
}

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
	btVector3 inertia(0.0f, 0.0f, 0.0f);
	if (m_mass != 0.0f)
	{
		collisionShape->calculateLocalInertia(m_mass, inertia);
	}

	//Create the Rigidbody
	const btRigidBody::btRigidBodyConstructionInfo rigidbodyInfo(m_mass, m_rigidbodyMotion.get(), collisionShape, inertia);
	m_rigidbody = std::make_unique<btRigidBody>(rigidbodyInfo);

	SetAlwaysActive(m_isAlwaysActive);

	//Set friction
	SetFriction(m_friction);

	//Set static
	if (m_gameObject->GetTransform()->IsStatic() == true)
	{
		m_rigidbody->setCollisionFlags(m_rigidbody->getCollisionFlags() | btRigidBody::CollisionFlags::CF_STATIC_OBJECT);
	}

	SetKinematic(m_isKinematic);

	FreezePosition(m_freezePositionX, m_freezePositionY, m_freezePositionZ);
	FreezeRotation(m_freezeRotationX, m_freezeRotationY, m_freezeRotationZ);

	Physics::Instance().AddRigidbody(*m_rigidbody);
}

void Rigidbody::Update()
{
	if (m_gameObject->GetTransform()->IsStatic() == true)
	{
		return;
	}

	//Based on whether the rigidbody is kinematic or not, either update the engine's transform or the rigidbody's transform
	if (m_isKinematic == false)
	{
		//Get the transform of the rigidbody simulation
		btTransform rbTransform;
		m_rigidbodyMotion->getWorldTransform(rbTransform);
		
		//Update the game object's transform based on the transform of the rigid body
		const btVector3 origin = rbTransform.getOrigin();
		m_gameObject->GetTransform()->SetWorldPosition(glm::vec3(origin.getX(), origin.getY(), origin.getZ()));
		m_gameObject->GetTransform()->SetWorldRotation(rbTransform.getRotation());
	}
	else
	{
		const glm::vec3 worldPos = m_gameObject->GetTransform()->GetWorldPosition();

		btTransform rbTransform;
		rbTransform.setOrigin(btVector3(worldPos.x, worldPos.y, worldPos.z));
		rbTransform.setRotation(m_gameObject->GetTransform()->GetWorldRotation());
		m_rigidbodyMotion->setWorldTransform(rbTransform);
		m_rigidbody->proceedToTransform(rbTransform);
	}
}

void Rigidbody::SetMass(float mass)
{
	m_mass = mass;

	if (m_rigidbody != nullptr)
	{
		//Remove the rigidbody from the world
		Physics::Instance().RemoveRigidbody(*m_rigidbody);

		//Change the mass
		btVector3 inertia(0.0f, 0.0f, 0.0f);
		if (m_mass != 0.0f)
		{
			m_collider->GetBulletCollisionShape()->calculateLocalInertia(mass, inertia);
		}
		m_rigidbody->setMassProps(mass, inertia);

		//Add the rigidbody back to the world
		Physics::Instance().AddRigidbody(*m_rigidbody);
	}
}

void Rigidbody::SetFriction(float friction)
{
	m_friction = friction;

	if (m_rigidbody != nullptr)
	{
		m_rigidbody->setFriction(friction);
	}
}

void Rigidbody::SetKinematic(bool kinematic)
{
	m_isKinematic = kinematic;

	if (m_rigidbody != nullptr)
	{
		if (kinematic == true)
		{
			m_rigidbody->setCollisionFlags(btRigidBody::CollisionFlags::CF_KINEMATIC_OBJECT | m_rigidbody->getCollisionFlags()); //Add kinematic flag
		}
		else
		{
			//If the rigid body has the kinematic flag, then remove it
			if ((m_rigidbody->getCollisionFlags() & btRigidBody::CollisionFlags::CF_KINEMATIC_OBJECT) == btRigidBody::CollisionFlags::CF_KINEMATIC_OBJECT)
			{
				m_rigidbody->setCollisionFlags(btRigidBody::CollisionFlags::CF_KINEMATIC_OBJECT ^ m_rigidbody->getCollisionFlags()); //Remove kinematic flag
				SetMass(m_mass);
			}
		}
	}
}

void Rigidbody::SetAlwaysActive(bool alwaysActive)
{
	m_isAlwaysActive = alwaysActive;

	if (m_rigidbody != nullptr)
	{
		m_rigidbody->setActivationState(DISABLE_DEACTIVATION);
	}
}

void Rigidbody::AddForce(const glm::vec3 & force)
{
	//Activate the rigidbody
	m_rigidbody->activate(true);

	//Apply the force
	m_rigidbody->applyCentralForce(btVector3(force.x, force.y, force.z));

	//Set angular velocity to 0 to not affect rotation with the force
	m_rigidbody->setAngularVelocity(btVector3(0,0,0));
}

void Rigidbody::AddRelativeForce(const glm::vec3 & force)
{
	AddForce(m_gameObject->GetTransform()->GetWorldRotation() * force);
}

void Rigidbody::FreezePosition(bool xAxis, bool yAxis, bool zAxis)
{
	m_freezePositionX = xAxis;
	m_freezePositionY = yAxis;
	m_freezePositionZ = zAxis;

	if (m_rigidbody != nullptr)
	{
		m_rigidbody->setLinearFactor(btVector3(float(!xAxis), float(!yAxis), float(!zAxis)));
	}
}

void Rigidbody::FreezeRotation(bool xAxis, bool yAxis, bool zAxis)
{
	m_freezeRotationX = xAxis;
	m_freezeRotationY = yAxis;
	m_freezeRotationZ = zAxis;

	if (m_rigidbody != nullptr)
	{
		m_rigidbody->setAngularFactor(btVector3(float(!xAxis), float(!yAxis), float(!zAxis)));
	}
}

void Rigidbody::Translate(const glm::vec3 & translation)
{
	btTransform transform;
	m_rigidbodyMotion->getWorldTransform(transform);
	const btVector3 worldPosition(translation.x + transform.getOrigin().getX(),
								  translation.y + transform.getOrigin().getY(),
								  translation.z + transform.getOrigin().getY());
	transform.setOrigin(worldPosition);
	m_rigidbody->proceedToTransform(transform);
	m_rigidbodyMotion->setWorldTransform(transform);
}

void Rigidbody::SetRotation(Quaternion & rotation)
{
	if (m_rigidbody != nullptr)
	{
		btTransform transform;
		m_rigidbodyMotion->getWorldTransform(transform);
		transform.setRotation(rotation);
		m_rigidbody->proceedToTransform(transform);
	}
}

btRigidBody * Rigidbody::GetBulletRigidbody()
{
	return m_rigidbody.get();
}
