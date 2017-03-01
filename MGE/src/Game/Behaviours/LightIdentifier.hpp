#pragma once
#include <Behaviours\AbstractBehaviour.hpp>

class LightIdentifier final : public AbstractBehaviour
{
public:
	void SetID(int ID);
	int GetID();
private:
	int m_ID;
};