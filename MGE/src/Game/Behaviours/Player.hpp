#pragma once
#include <Behaviours\AbstractBehaviour.hpp>
#include <LuaAPI\lua.hpp>

class Camera;

class Player final : public AbstractBehaviour
{
public:
	void Awake() override final;
	void FixedUpdate() override final;
	void Update() override final;

	static const luaL_Reg* GetFunctionList();
private:
	Camera* m_camera;

	void Move();
	void Look();
	void Interact();
};