#include <Game\Behaviours\Player.hpp>
#include <Behaviours\Lua\LuaEnvironment.hpp>
#include <Behaviours\Transform.hpp>
#include <Behaviours\Camera.hpp>
#include <Core\GameObject.hpp>
#include <Input\Input.hpp>
#include <Core\Time.hpp>
#include <Utils\glm.hpp>

void Player::Awake()
{
	LuaEnvironment::GetLua()->RegisterType<Player>("Player");
	LuaEnvironment::GetLua()->BindObject<Player>(this, "Player", "player");

	m_camera = m_gameObject->GetBehavioursInChildren<Camera>()[0];
}

void Player::FixedUpdate()
{
	Move();
}

void Player::Update()
{
	Look();
	Interact();
}

static const luaL_Reg functions[] = {
	{ NULL, NULL }
};

const luaL_Reg* Player::GetFunctionList()
{
	return functions;
}

void Player::Move()
{
	const glm::vec3 movement(Input::GetAxis(InputAxes::s_horizontal), 0, -Input::GetAxis(InputAxes::s_vertical));
	m_gameObject->GetTransform()->Translate(movement * Time::s_deltaTime);
}

void Player::Look()
{
	const glm::vec2 mouseMovement = Input::GetMouseMovement();
	if (mouseMovement.x != 0)
	{
		//Rotate the player around the y axis based on the horizontal movement
		m_gameObject->GetTransform()->Rotate(glm::vec3(0.0f, -mouseMovement.x * Time::s_deltaTime * 50, 0.0f));
	}

	if (mouseMovement.y != 0)
	{
		//Retrieve the camera's euler angles
		glm::vec3 cameraEuler = m_camera->GetGameObject()->GetTransform()->GetEulerAngles();

		//Rotate the camera around the x axis based on the vertical movement
		cameraEuler.x = glm::clamp(cameraEuler.x + mouseMovement.y * Time::s_deltaTime * 50, -90.0f, 90.0f);
		m_camera->GetGameObject()->GetTransform()->SetLocalRotation(Quaternion::EulerAngles(cameraEuler));
	}
}

void Player::Interact()
{
}
