#include "QuitBehaviour.hpp"
#include <Input\Input.hpp>
#include <Game\Application.hpp>

void QuitBehaviour::Update()
{
	if (Input::GetAxis(InputAxes::s_quit))
	{
		Application::Instance().Quit();
	}
}
