#include <Game\Behaviours\CameraOrbit.hpp>
#include <Core\GameObject.hpp>
#include <Core\Material.hpp>
#include <Input\Input.hpp>
#include <Core\Time.hpp>
#include <Behaviours\Transform.hpp>

CameraOrbit::CameraOrbit() :
	m_accumulatedYRotation(0),
	m_accumulatedXRotation(0),
	m_previousMousePos(Input::GetMousePosition()) {}

void CameraOrbit::SetTarget(GameObject * l_target)
{
	this->m_target = l_target;
}

void CameraOrbit::SetDistance(float distance)
{
	m_distance = distance;
}

void CameraOrbit::SetMinTiltAngle(float angle)
{
	m_minTiltAngle = angle;
}

void CameraOrbit::SetMaxTiltAngle(float angle)
{
	m_maxTiltAngle = angle;
}

void CameraOrbit::SetRotationSpeed(float rotationSpeed)
{
	m_rotationSpeed = rotationSpeed;
}

void CameraOrbit::Update()
{
	//Get the current mouse position
	glm::vec2 mousePos = Input::GetMousePosition();

	//Calculate the displacement of the mouse
	glm::vec2 mouseDisplacement = mousePos - m_previousMousePos;

	//Store the current mouse position
	m_previousMousePos = mousePos;

	//Update the rotation based on the displacement of the mouse
	m_accumulatedYRotation -= mouseDisplacement.x * m_rotationSpeed;
	m_accumulatedXRotation -= mouseDisplacement.y * m_rotationSpeed;

	//Clamp the X rotation
	m_accumulatedXRotation = glm::clamp(m_accumulatedXRotation, m_minTiltAngle, m_maxTiltAngle);
	
	//Create a rotation matrix using the current rotation values around x and y axes
	glm::mat4 rotation = glm::rotate(glm::radians(m_accumulatedYRotation), glm::vec3(0, 1, 0)) * glm::rotate(glm::radians(m_accumulatedXRotation), glm::vec3(1, 0, 0));

	//Create a translation of distance backwards from the origin matrix
	glm::mat4 translation = glm::translate(glm::vec3(0, 0, glm::clamp(m_distance - Input::GetMouseWheelDelta(), 1.0f, 5000.0f)));

	//Translate and rotate the camera by the translation and rotation matrices and translate the camera to the target
	m_gameObject->GetTransform()->SetModelMatrix(glm::translate(m_target->GetTransform()->GetWorldPosition()) * rotation * translation);
}
