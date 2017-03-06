#pragma once
#include <Behaviours\AbstractBehaviour.hpp>
#include <Behaviours\BehaviourAttributes.hpp>
#include <Game\Behaviours\TextLogBehaviour.hpp>
#include <Utils\glm.hpp>
#include <LuaAPI\lua.hpp>
#include <UI\TextLog.hpp>
#include <UI\Crosshair.hpp>

class CharacterController;
class Transform;
class Camera;

class Player final : public AbstractBehaviour, public RequireBehaviours<TextLogBehaviour>
{
public:
	Player();

	void SetWalkVelocity(float velocity);

	void Awake() override final;
	void FixedUpdate() override final;
	void Update() override final;

	int Carry(lua_State* luaState);
	int IsCarrying(lua_State* luaState);

	int Log(lua_State * luaState);

	static const luaL_Reg* GetFunctionList();
private:
	Camera* m_camera;
	Transform* m_carriedObject;
	CharacterController* m_characterController;

	glm::vec2 m_accumulatedCameraRotation;

	float m_walkVelocity;

	TextLogBehaviour* m_textLogBehaviour;
	Crosshair m_crosshair;

	void Move();
	void Look();
	void Interact();

	void DropCarriedObject(float throwForce = 200.0f);
};