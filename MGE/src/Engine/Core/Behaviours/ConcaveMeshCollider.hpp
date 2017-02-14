#pragma once
#include <Behaviours\Collider.hpp>
#include <bullet\btBulletCollisionCommon.h>
#include <Behaviours\MeshRenderer.hpp>
#include <Behaviours\BehaviourAttributes.hpp>
#include <memory>

class ConcaveMeshCollider final : public Collider, public RequireBehaviours<MeshRenderer>
{
public:
	void SetupCollisionShape() override final;
private:
	std::unique_ptr<btTriangleMesh> m_triangleMesh;
};