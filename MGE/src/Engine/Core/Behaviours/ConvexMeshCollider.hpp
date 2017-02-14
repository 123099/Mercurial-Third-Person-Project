#pragma once
#include <Behaviours\Collider.hpp>
#include <Behaviours\BehaviourAttributes.hpp>
#include <Behaviours\MeshRenderer.hpp>

class ConvexMeshCollider final : public Collider, public RequireBehaviours<MeshRenderer>
{
public:
	void Start() override final;

	void SetupCollisionShape() override final;
};