#include "WobbleBehaviour.hpp"
#include <Core\Material.hpp>
#include <Core\GameObject.hpp>
#include <Core\Time.hpp>

void WobbleBehaviour::Update()
{
	m_gameObject->GetBehaviour<MeshRenderer>()->GetMaterial()->SetFloat("time", Time::s_gameTime);
}
