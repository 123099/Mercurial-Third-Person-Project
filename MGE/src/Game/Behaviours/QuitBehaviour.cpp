#include "QuitBehaviour.hpp"
#include <Input\Input.hpp>
#include <Game\Application.hpp>
#include <Behaviours\Camera.hpp>
#include <Physics\Physics.hpp>
void QuitBehaviour::Update()
{
	Ray ray = Camera::GetMainCamera()->ScreenPointToRay(Input::GetMousePosition());
	if(Physics::Instance().RayCast(ray))
		std::cout << "On Sphere" << '\n';
	if (Input::GetAxis(InputAxes::s_quit))
	{
		Application::Instance().Quit();
	}
}
