#pragma once
#include <Behaviours\AbstractBehaviour.hpp>

class AudioListener final : public AbstractBehaviour
{
public:
	static void SetGlobalVolume(float normalizedVolume);

	void Awake() override final;
	void Update() override final;
private:
	static int s_listenerCount;
};