#pragma once
#include <Behaviours\AbstractBehaviour.hpp>

#include <bullet\btBulletDynamicsCommon.h>
#include <memory>

class Collider : public AbstractBehaviour
{
public:
	~Collider() = 0;

	btCollisionShape* GetBulletCollisionShape();
protected:
	std::unique_ptr<btCollisionShape> m_collisionShape;

	virtual void SetupCollisionShape() = 0;
};