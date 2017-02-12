#pragma once
#include <Behaviours\AbstractBehaviour.hpp>
#include <Behaviours\BehaviourAttributes.hpp>
#include <LuaAPI\lua.hpp>

#include <Behaviours\Rigidbody.hpp>
#include <Behaviours\CapsuleCollider.hpp>

class Transform;
class Camera;

class Player final : public AbstractBehaviour//, public RequireBehaviours<CapsuleCollider, Rigidbody>
{
public:
	void Awake() override final;
	void FixedUpdate() override final;
	void Update() override final;

	int Carry(lua_State* luaState);

	static const luaL_Reg* GetFunctionList();
private:
	Camera* m_camera;
	Transform* m_carriedObject;

	void Move();
	void Look();
	void Interact();
};