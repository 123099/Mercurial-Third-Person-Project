#pragma once
#include <Behaviours\AbstractBehaviour.hpp>
#include <Behaviours\Light.hpp>

class Flashlight final : public AbstractBehaviour
{
public:
	void Awake() override final;
	void Update() override final;
private:
	Light* m_spotlight;

	float m_defaultIntensity;
	bool m_isOn;
};
