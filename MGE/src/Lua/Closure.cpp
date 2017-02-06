#include <Lua\Closure.hpp>

void Closure::Call()
{
	m_ownerEnvironment.ExecuteFunction(this);
}

Closure::Closure(Environment & environment) : m_ownerEnvironment(environment) {}
