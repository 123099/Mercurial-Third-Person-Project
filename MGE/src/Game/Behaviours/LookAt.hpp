#pragma once
#include <Behaviours\AbstractBehaviour.hpp>

class LookAt final : public AbstractBehaviour
{
public:
	void SetTarget(GameObject* target);
    void Update() override final;
private:
    GameObject * m_target;
};
