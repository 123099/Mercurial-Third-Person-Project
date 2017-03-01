#include "LuaUtils.hpp"
#include <Time.hpp>
#include <string>

#include <Core\GameObject.hpp>
#include <Core\Scene.hpp>

#include <Managers\SceneManager.hpp>

#include <Behaviours\Light.hpp>
#include <Behaviours\AudioSource.hpp>
#include <Game\Behaviours\LightIdentifier.hpp>

#include <Audio\AudioClip.hpp>

#pragma region Public members

void LuaUtils::CheckParameterCount(lua_State* l_luaState, int expectedCount)
{
	//Get the current amount of parameters from the provided state
	int parameterCount = lua_gettop(l_luaState);

	//Make sure there are enough parameters
	if (parameterCount < expectedCount)
	{
		DisplayError(l_luaState, "Wrong parameter count! Expected " + std::to_string(expectedCount) + ", got " + std::to_string(parameterCount));
	}
}

void LuaUtils::DisplayError(lua_State* l_luaState, const std::string & errorMessage)
{
	//Push the error message to the stack
	lua_pushstring(l_luaState, errorMessage.c_str());

	//Tell lua to display the error
	lua_error(l_luaState);
}

void LuaUtils::StepCoroutines(lua_State* l_resumingState) 
{
	//Go through all the coroutines being tracked and resume them
	for (auto itr = m_coroutines.begin(), end = m_coroutines.end(); itr != end; ++itr)
	{
		//Resume the coroutine
		int executionResult = lua_resume(*itr, l_resumingState, 0);

		//If the coroutine finished its execution and is no longer in a yielded state, remove it from the vector
		if (executionResult == LUA_OK)
		{
			m_coroutines.erase(itr);

			//Decrement the iterator to prevent skipping an element
			--itr;
		}
	}
}
#pragma endregion

#pragma region Lua Function Wrappers
static const luaL_Reg functions[]
{
	{"startcoroutine", lua_asmethod<LuaUtils, &LuaUtils::AddCoroutine>},
	{"getgametime", lua_asmethod<LuaUtils, &LuaUtils::GetGameTime>},
	{"playsound", lua_asmethod<LuaUtils, &LuaUtils::PlayAudioSource>},
	{"togglelight", lua_asmethod<LuaUtils, &LuaUtils::ToggleLight>},
	{nullptr, nullptr}
};

const luaL_Reg * LuaUtils::GetFunctionList()
{
	return functions;
}

int LuaUtils::AddCoroutine(lua_State * l_luaState)
{
	//Check the parameter count
	CheckParameterCount(l_luaState, 1);

	//Make sure the parameter is a function
	if (lua_isfunction(l_luaState, -1) == false)
	{
		DisplayError(l_luaState, "Wrong parameter type! Expected function.");
	}

	//Create a new coroutine
	lua_State* coroutine = lua_newthread(l_luaState);

	//Push the function to the top of the state stack
	lua_pushvalue(l_luaState, -2);

	//Transfer the function from the top of the state stack to the top of the coroutine stack
	lua_xmove(l_luaState, coroutine, 1);

	//Start the coroutine
	int executionResult = lua_resume(coroutine, l_luaState, 0);

	//If the coroutine is in a yielded state, add it to the coroutine list to resume it on update
	if (executionResult == LUA_YIELD)
	{
		m_coroutines.push_back(coroutine);
	}

	//Return the lua_State coroutine to lua
	return 1;
}

int LuaUtils::GetGameTime(lua_State * l_luaState)
{
	//Push the game time to lua
	lua_pushnumber(l_luaState, Time::s_gameTime);

	return 1;
}

int LuaUtils::PlayAudioSource(lua_State * l_luaState)
{
	//Get the sound file name
	const std::string fileName = luaL_checkstring(l_luaState, 1);

	//Get the location at which to play the sound
	const float x = (float)luaL_checknumber(l_luaState, 2);
	const float y = (float)luaL_checknumber(l_luaState, 3);
	const float z = (float)luaL_checknumber(l_luaState, 4);

	//Get whether to loop the sound or not
	const bool loop = (bool)lua_toboolean(l_luaState, 5);

	//Get the volume
	const float volume = (float)luaL_checknumber(l_luaState, 6);

	GameObject* gameObject = SceneManager::Instance().GetActiveScene()->CreateGameObject("Sound");
	gameObject->GetTransform()->SetWorldPosition(glm::vec3(x, y, z));

	AudioClip* audioClip = AudioClip::Load(fileName, false, true);
	AudioSource* audioSource = gameObject->AddBehaviour<AudioSource>();
	
	audioSource->SetAudioClip(audioClip);
	audioSource->SetLooping(loop);
	audioSource->SetVolume(volume);
	audioSource->SetDestroyOnEnd(true);

	audioSource->Play();

	return 0;
}
int LuaUtils::ToggleLight(lua_State * l_luaState)
{
	//Command structure:
	//1 - light ID
	//2 - on or off

	int ID = (int)luaL_checknumber(l_luaState, 1);
	bool enabled = (bool)lua_toboolean(l_luaState, 2);

	const std::vector<LightIdentifier*> lightIdentifiers = GameObject::FindObjectsOfType<LightIdentifier>();
	const size_t size = lightIdentifiers.size();
	for (size_t i = 0; i < size; ++i)
	{
		if (lightIdentifiers[i]->GetID() == ID)
		{
			Light* light = lightIdentifiers[i]->GetGameObject()->GetBehaviour<Light>();
			if (light != nullptr)
			{
				light->SetIntensity((float)enabled);
			}
		}
	}

	return 0;
}
#pragma endregion
