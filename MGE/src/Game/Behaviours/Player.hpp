#pragma once
#include <Behaviours\AbstractBehaviour.hpp>
#include <LuaAPI\lua.hpp>

class Transform;
class Camera;

class Player final : public AbstractBehaviour
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