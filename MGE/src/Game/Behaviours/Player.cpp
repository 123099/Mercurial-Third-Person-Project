#include <Game\Behaviours\Player.hpp>
#include <Game\Behaviours\NPC.hpp>

#include <Behaviours\Lua\LuaEnvironment.hpp>
#include <Behaviours\CharacterController.hpp>
#include <Behaviours\Transform.hpp>
#include <Behaviours\Camera.hpp>

#include <Input\Input.hpp>

#include <Core\GameObject.hpp>
#include <Core\Time.hpp>

#include <Physics\Physics.hpp>

#include <Utils\Screen.hpp>

Player::Player() : m_textLog("arial.ttf"), m_crosshair("crosshair.png")
{
	m_textLog.SetPositionOnScreen(10, 400);
	m_textLog.SetFontColor(sf::Color::Red);
	m_crosshair.SetPositionOnScreen(Screen::Instance().GetWidth() * 0.5f - 16, Screen::Instance().GetHeight() * 0.5f - 16);
}

void Player::SetWalkVelocity(float velocity)
{
	m_walkVelocity = velocity;
}

void Player::Awake()
{
	LuaEnvironment::GetLua()->RegisterType<Player>("Player");
	LuaEnvironment::GetLua()->BindObject<Player>(this, "Player", "player");

	m_camera = m_gameObject->GetBehavioursInChildren<Camera>()[0];
	glm::vec3 cameraEulers = m_camera->GetGameObject()->GetTransform()->GetLocalRotation().GetEulerAngles();
	m_accumulatedCameraRotation = glm::vec2(cameraEulers.y, cameraEulers.x);

	m_characterController = m_gameObject->GetBehaviour<CharacterController>();
	m_characterController->SetWalkVelocity(m_walkVelocity);
	m_characterController->SetStepHeight(0.35f);
	m_characterController->SetSlopeLimit(45);
}

void Player::FixedUpdate()
{
	Move();
}

void Player::Update()
{
	Look();
	Interact();

	if (Input::GetMouseButtonDown(sf::Mouse::Button::Right))
	{
		DropCarriedObject();
	}

	if (m_carriedObject != nullptr)
	{
		m_carriedObject->SetWorldPosition(m_camera->GetGameObject()->GetTransform()->GetWorldPosition() + 1.0f * m_camera->GetGameObject()->GetTransform()->GetForwardVector());
	}
}

void Player::Move()
{
	const glm::vec3 movement(Input::GetAxis(InputAxes::s_horizontal), 0, -Input::GetAxis(InputAxes::s_vertical));
	const Quaternion forwardRotation = Quaternion::EulerAngles(0.0f, m_accumulatedCameraRotation.y, 0.0f);
	m_characterController->SetWalkDirection(forwardRotation * movement);

	if (Input::GetAxis(InputAxes::s_jump))
	{
		m_characterController->Jump(8);
	}
}

void Player::Look()
{
	const glm::vec2 mouseMovement = Input::GetMouseMovement();

	if (mouseMovement != glm::vec2(0.0f))
	{
		m_accumulatedCameraRotation.x = glm::clamp(m_accumulatedCameraRotation.x + mouseMovement.y * Time::s_deltaTime * 2, -90.0f, 90.0f);
		m_accumulatedCameraRotation.y -= mouseMovement.x * Time::s_deltaTime * 2;
		m_camera->GetGameObject()->GetTransform()->SetLocalRotation(Quaternion::EulerAngles(m_accumulatedCameraRotation.x, m_accumulatedCameraRotation.y, 0.0f));
	}
}

void Player::Interact()
{
	//Check if the left click was pressed
	if (Input::GetButtonDown(InputAxes::s_interact))
	{
		//Create a ray from the center of the screen forward
		Ray ray = m_camera->ScreenPointToRay(Screen::Instance().GetWindowCenter());

		//Move the origin of the ray 1 unit forward on the ray line to prevent intersection with the player
		ray.ChangeOrigin(0.6f);

		//Cast the ray and see if we hit an interactble
		RaycastHit hitInfo;
		if (Physics::Instance().Raycast(ray, hitInfo, 5.0f) == true)
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

void Player::DropCarriedObject()
{
	if (m_carriedObject != nullptr)
	{
		m_carriedObject->SetParent(nullptr);

		Rigidbody* carriedObjectRigidbody = m_carriedObject->GetGameObject()->GetBehaviour<Rigidbody>();
		if (carriedObjectRigidbody != nullptr)
		{
			carriedObjectRigidbody->SetKinematic(false);
		}

		m_carriedObject = nullptr;
	}
}

static const luaL_Reg functions[] = {
	{"carry", lua_asmethod<Player, &Player::Carry>},
	{"iscarrying", lua_asmethod<Player, &Player::IsCarrying>},
	{"log", lua_asmethod<Player, &Player::Log>},
	{ NULL, NULL }
};

const luaL_Reg* Player::GetFunctionList()
{
	return functions;
}

int Player::Carry(lua_State * luaState)
{
	//Retrieve object to carry
	NPC* objectToCarry = lua_checkType<NPC>(luaState, 1);

	//If the carried object is null, it means stop carrying what we are carrying
	if (objectToCarry == nullptr)
	{
		DropCarriedObject();
	}
	else if(objectToCarry->GetGameObject()->GetTransform() != m_carriedObject)
	{
		DropCarriedObject();

		//Start carrying the new item
		m_carriedObject = objectToCarry->GetGameObject()->GetTransform();
		m_carriedObject->SetParent(GetGameObject()->GetTransform());

		Rigidbody* carriedObjectRigidbody = m_carriedObject->GetGameObject()->GetBehaviour<Rigidbody>();
		if (carriedObjectRigidbody != nullptr)
		{
			carriedObjectRigidbody->SetKinematic(true);
		}
	}

	return 0;
}

int Player::IsCarrying(lua_State * luaState)
{
	lua_pushboolean(luaState, m_carriedObject != nullptr);

	return 1;
}

int Player::Log(lua_State* luaState)
{
	const std::string textToLog(luaL_checkstring(luaState, 1));
	m_textLog.AddText(textToLog + "\n");

	return 0;
}
