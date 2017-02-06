#pragma once
#include <Behaviours\AbstractBehaviour.hpp>
#include <Behaviours\BehaviourAttributes.hpp>
#include <Behaviours\MeshRenderer.hpp>

class WobbleBehaviour final : public AbstractBehaviour, public RequireBehaviours<MeshRenderer>
{
public:
	void Update() override final;
};


