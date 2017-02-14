#include <Game\Behaviours\Player.hpp>
#include <Game\Behaviours\NPC.hpp>

#include <Behaviours\Lua\LuaEnvironment.hpp>
#include <Behaviours\SphereCollider.hpp>
#include <Behaviours\Transform.hpp>
#include <Behaviours\Camera.hpp>

#include <Input\Input.hpp>

#include <Core\GameObject.hpp>
#include <Core\Time.hpp>

#include <Physics\Physics.hpp>

#include <Utils\Screen.hpp>
#include <Utils\glm.hpp>

void Player::Awake()
{
	LuaEnvironment::GetLua()->RegisterType<Player>("Player");
	LuaEnvironment::GetLua()->BindObject<Player>(this, "Player", "player");

	m_camera = m_gameObject->GetBehavioursInChildren<Camera>()[0];
	m_characterController = m_gameObject->GetBehaviour<CharacterController>();
	m_characterController->SetWalkVelocity(5);
	m_characterController->SetStepHeight(0.35f);
	m_characterController->SetSlopeLimit(45);
}

void Player::FixedUpdate()
{
	const glm::vec2 mouseMovement = Input::GetMouseMovement();

	if (mouseMovement.x != 0)
	{
		m_characterController->SetAngularVelocity(glm::vec3(0, 0, Time::s_gameTime * 10));
	}
	Move();
}

void Player::Update()
{
	if (Input::GetAxis(InputAxes::s_jump))
	{
		m_characterController->Jump();
	}
	Look();
	Interact();
}

void Player::Move()
{
	const glm::vec3 movement(Input::GetAxis(InputAxes::s_horizontal), 0, -Input::GetAxis(InputAxes::s_vertical));
	const Quaternion cameraRotationExcludingX = Quaternion::EulerAngles(0.0f, m_camera->GetGameObject()->GetTransform()->GetEulerAngles().y, 0.0f);
	m_characterController->SetWalkDirection(cameraRotationExcludingX * movement);
}

void Player::Look()
{
	const glm::vec2 mouseMovement = Input::GetMouseMovement();

	if (mouseMovement.y != 0)
	{
		//Retrieve the camera's euler angles
		glm::vec3 cameraEuler = m_camera->GetGameObject()->GetTransform()->GetEulerAngles();

		//Rotate the camera around the x axis based on the vertical movement
		cameraEuler.x = glm::clamp(cameraEuler.x + mouseMovement.y * Time::s_deltaTime * 2, -90.0f, 90.0f);
		m_camera->GetGameObject()->GetTransform()->SetLocalRotation(Quaternion::EulerAngles(cameraEuler));
	}

}

void Player::Interact()
{
	//Check if the left click was pressed
	if (Input::GetButtonDown(InputAxes::s_interact))
	{
		//Create a ray from the center of the screen forward
		Ray ray = m_camera->ScreenPointToRay(Screen::Instance().GetWindowCenter());

		//Move the origin of the ray 2 units forward on the ray line to prevent intersection with the player
		ray.ChangeOrigin(2);

		//Cast the ray and see if we hit an interactble
		RaycastHit hitInfo;
		if (Physics::Instance().Raycast(ray, hitInfo, 4.0f) == true)
		{
			std::cout << "HIT " << hitInfo.GetCollider()->GetGameObject()->GetName() << " at " << hitInfo.GetPoint() << '\n';
			const Collider* collider = hitInfo.GetCollider();

			//Check if the collider is also an NPC
			NPC* npc = collider->GetGameObject()->GetBehaviour<NPC>();
			if (npc != nullptr)
			{
				//Execute the NPC script
				npc->StartInteraction();
			}
		}
	}
}

static const luaL_Reg functions[] = {
	{ "carry", lua_asmethod<Player, &Player::Carry> },
	{ NULL, NULL }
};

const luaL_Reg* Player::GetFunctionList()
{
	return functions;
}

int Player::Carry(lua_State * luaState)
{
	//Retrieve object to carry
	Transform* carriedObject = (Transform*)lua_touserdata(luaState, 1);

	//If the carried object is null, it means stop carrying what we are carrying
	if (carriedObject == nullptr)
	{
		if (m_carriedObject != nullptr)
		{
			m_carriedObject->SetParent(nullptr);
		}
	}
	else
	{
		//If we are currently carrying something, drop it
		if (m_carriedObject != nullptr)
		{
			m_carriedObject->SetParent(nullptr);
		}

		//Start carrying the new item
		carriedObject->SetParent(m_gameObject->GetTransform());
		m_carriedObject = carriedObject;
	}

	return 0;
}
