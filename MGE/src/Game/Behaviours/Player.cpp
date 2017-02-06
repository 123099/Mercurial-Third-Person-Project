#include <Game\Behaviours\Player.hpp>
#include <Behaviours\Lua\LuaEnvironment.hpp>
#include <GameObject.hpp>
#include <Behaviours\Transform.hpp>
#include <Utils\glm.hpp>

void Player::Awake()
{
	LuaEnvironment::GetLua()->RegisterType<Player>("Player");
	LuaEnvironment::GetLua()->BindObject<Player>(this, "Player", "player");
}

void Player::SetHasKeyCode(bool hasKeyCode)
{
	m_hasKeyCode = hasKeyCode;
}

bool Player::HasKeyCode()
{
	return m_hasKeyCode;
}

void Player::SetHasDragon(bool hasDragon)
{
	m_hasDragon = hasDragon;
}

bool Player::HasDragon()
{
	return m_hasDragon;
}

void Player::Teleport(float x, float y, float z)
{
	m_gameObject->GetTransform()->SetWorldPosition(glm::vec3(x, y, z));
}

int Player::SetHasKeyCode(lua_State * luaState)
{
	SetHasKeyCode((bool)lua_toboolean(luaState, 1));

	return 0;
}

int Player::HasKeyCode(lua_State * luaState)
{
	lua_pushboolean(luaState, m_hasKeyCode);

	return 1;
}

int Player::SetHasDragon(lua_State * luaState)
{
	SetHasDragon((bool)lua_toboolean(luaState, 1));

	return 0;
}

int Player::HasDragon(lua_State * luaState)
{
	lua_pushboolean(luaState, m_hasDragon);

	return 1;
}

int Player::Teleport(lua_State * luaState)
{
	float x = (float)luaL_checknumber(luaState, 1);
	float y = (float)luaL_checknumber(luaState, 2);
	float z = (float)luaL_checknumber(luaState, 3);
	Teleport(x, y, z);

	return 0;
}

static const luaL_Reg functions[] = {
	{ "sethaskeycode", lua_asmethod<Player, &Player::SetHasKeyCode> },
	{ "haskeycode", lua_asmethod<Player, &Player::HasKeyCode> },
	{ "sethasdragon", lua_asmethod<Player, &Player::SetHasDragon> },
	{ "hasdragon", lua_asmethod<Player, &Player::HasDragon> },
	{ "teleport", lua_asmethod<Player, &Player::Teleport> },
	{ NULL, NULL }
};

const luaL_Reg* Player::GetFunctionList()
{
	return functions;
}