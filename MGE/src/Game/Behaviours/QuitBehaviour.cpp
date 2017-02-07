#include "QuitBehaviour.hpp"
#include <Input\Input.hpp>
#include <Game\Application.hpp>
#include <Behaviours\Camera.hpp>
void QuitBehaviour::Update()
{
	Ray ray = Camera::GetMainCamera()->ScreenPointToRay(Input::GetMousePosition());
	glm::vec3 closestPoint = ray.GetPointClosestTo(glm::vec3(0));
	if (glm::distance(glm::vec3(0), closestPoint) <= 3)
		std::cout << "On Sphere" << '\n';
	if (Input::GetAxis(InputAxes::s_quit))
	{
		Application::Instance().Quit();
	}
}
