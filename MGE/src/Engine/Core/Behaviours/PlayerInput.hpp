#pragma once
#include<Behaviours\AbstractBehaviour.hpp>
#include<UI\TextLog.hpp>

class PlayerInput final : public AbstractBehaviour
{
public:
	void Awake() override final;
	void Update() override final;
	
private:
	TextLog* m_textLog;
};
