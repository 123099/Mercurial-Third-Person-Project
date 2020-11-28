#pragma once
#include <Behaviours\AbstractBehaviour.hpp>
#include <Behaviours\BehaviourAttributes.hpp>
#include <Behaviours\MeshRenderer.hpp>

class Sun final : public AbstractBehaviour, public RequireBehaviours<MeshRenderer>
{
public:
	void Awake() override final;
	void Update() override final;
	void SetTimeToLose(float time);
	float GetPassedTime();

private:
	MeshRenderer* m_meshRenderer;

	float m_timeToLoseGame;
	float m_timeWhenGameStarted;
	float passedTime;

	bool m_lost;
};