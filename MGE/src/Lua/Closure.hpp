#pragma once
#include <Lua\Environment.hpp>

class Closure 
{
friend Environment;

public:
	void Call();
private:
	Closure(Environment& environment);

	Environment& m_ownerEnvironment;
};