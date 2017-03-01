#include "LevelImporter.hpp"
#include <Lua\Environment.hpp>
#include <Lua\Script.hpp>

#include <Core\GameObject.hpp>
#include <Core\config.hpp>

#include <Behaviours\Transform.hpp>
#include <Behaviours\Light.hpp>
#include <Behaviours\Camera.hpp>
#include <Behaviours\Terrain.hpp>
#include <Behaviours\FreeLookCamera.hpp>
#include <Behaviours\MeshRenderer.hpp>
#include <Behaviours\AudioSource.hpp>
#include <Behaviours\SphereCollider.hpp>
#include <Behaviours\BoxCollider.hpp>
#include <Behaviours\CapsuleCollider.hpp>
#include <Behaviours\ConvexMeshCollider.hpp>
#include <Behaviours\ConcaveMeshCollider.hpp>
#include <Behaviours\CharacterController.hpp>
#include <Behaviours\Rigidbody.hpp>
#include <Behaviours\AudioListener.hpp>

#include <Game\Behaviours\NPC.hpp>
#include <Game\Behaviours\RotatingBehaviour.hpp>
#include <Game\Behaviours\WobbleBehaviour.hpp>
#include <Game\Behaviours\Player.hpp>
#include <Game\Behaviours\TranslationAnimation.hpp>

#include <Importers\ObjImporter.hpp>
#include <Importers\MaterialImporter.hpp>

#include <Utils\Quaternion.hpp>
#include <Utils\StringUtils.hpp>
#include <iostream>
#include <cctype>

static std::vector<GameObject*> s_loadedObjects;

static GameObject* CreateGameObjectFromBaseData(lua_State* luaState)
{
	//Base data structure:
	//1 - Name
	//2 - Is Static?
	//3 - 5 - Position
	//6 - 9 - Rotation
	//10 - 12 - Scale

	//Retrieve name
	std::string name = lua_tostring(luaState, 1);

	//Retrieve whether the game object is static
	bool isStatic = (bool)lua_toboolean(luaState, 2);
	
	//Get the local position
	float positionValues[3];
	const int positionStartIndex = 3;
	for (int i = positionStartIndex; i < positionStartIndex + 3; ++i) positionValues[i - positionStartIndex] = (float)luaL_checknumber(luaState, i);

	//Get the local rotation
	float rotationValues[4];
	const int rotationStartIndex = 6;
	for (int i = rotationStartIndex; i < rotationStartIndex + 4; ++i) rotationValues[i - rotationStartIndex] = (float)luaL_checknumber(luaState, i);

	//Get the local scale
	float scaleValues[3];
	const int scaleStartIndex = 10;
	for (int i = scaleStartIndex; i < scaleStartIndex + 3; ++i) scaleValues[i - scaleStartIndex] = (float)luaL_checknumber(luaState, i);

	//Convert the float arrays to a glm structs
	const glm::vec3 position = glm::make_vec3(positionValues);
	const Quaternion rotation(rotationValues[0], rotationValues[1], rotationValues[2], rotationValues[3]);
	const glm::vec3 scale = glm::make_vec3(scaleValues);

	//Pop the used values from the stack
	for (int i = 0; i < 12; ++i)
		lua_remove(luaState, 1);
	
	//Create a game object
	GameObject* gameObject = SceneManager::Instance().GetActiveScene()->CreateGameObject(name);

	//Apply the local transformations
	gameObject->GetTransform()->SetLocalPosition(position);
	gameObject->GetTransform()->SetLocalRotation(rotation);
	gameObject->GetTransform()->SetLocalScale(scale);

	//Apply whether the object is static
	gameObject->GetTransform()->SetStatic(isStatic);

	//Return the game object
	return gameObject;
}

static int CreateGameObject(lua_State* luaState)
{
	//Command structure:
	//1 - model name (could be empty string)
	//2 - material name (could be empty string)

	//Create the base game object
	GameObject* gameObject = CreateGameObjectFromBaseData(luaState);

	//Retrieve the model name
	std::string modelName = lua_tostring(luaState, 1);

	//Retrieve the material name
	std::string materialName = lua_tostring(luaState, 2);

	if (modelName != "" || materialName != "")
	{
		//Add a Mesh renderer to the game object
		gameObject->AddBehaviour<MeshRenderer>();
	}

	//Load mesh based on file extension
	if (modelName != "")
	{
		//Split the name into name and extension
		std::vector<std::string> split = StringUtils::Split(modelName, '.');
		std::string name = split[0];
		std::string extension = split[1];
		
		//Use the appropriate importer based on the extension
		if (extension == "obj")
		{
			gameObject->GetBehaviour<MeshRenderer>()->SetSharedMesh(ObjImporter::LoadObj(name));
		}
	}

	//Load the material
	if (materialName != "")
	{
		gameObject->GetBehaviour<MeshRenderer>()->SetSharedMaterial(MaterialImporter::LoadMaterial(materialName));
	}

	//Add the object to the game object list. At this point the pointer ownership is transferred to whoever uses the list
	s_loadedObjects.push_back(gameObject);

	//Push the gameobject pointer as a light user data for further processing
	lua_pushlightuserdata(luaState, gameObject);

	return 1;
}

static int AddChild(lua_State* luaState)
{
	//Command structure:
	//1 - Parent game object
	//2 - Child game object
	//3 - Keep world position

	//Retrieve the parent game object
	GameObject* parent = (GameObject*)lua_touserdata(luaState, 1);

	//Retrieve the child game object
	GameObject* child = (GameObject*)lua_touserdata(luaState, 2);

	//Retrieve whether to keep world position
	bool worldPositionStays = (bool)lua_toboolean(luaState, 3);

	bool isChildStatic = child->GetTransform()->IsStatic();

	child->GetTransform()->SetStatic(false);

	//Add child to parent
	child->GetTransform()->SetParent(parent->GetTransform(), worldPositionStays);

	child->GetTransform()->SetStatic(isChildStatic);

	return 0;
}

#pragma region Behaviours

static int AddLight(GameObject* gameObject, lua_State* luaState)
{
	//Command structure:
	//1 - light type
	//2...5 - color
	//6 - intensity
	//7 - spot inner angle

	//Add a light component to the game object
	Light* light = gameObject->AddBehaviour<Light>();

	//Retrieve the light type
	std::string typeName = luaL_checkstring(luaState, 1);
	const Light::Type type =
		[&typeName]()
	{
		if (typeName == "directional") return Light::Type::Directional;
		else if (typeName == "point") return Light::Type::Point;
		else if (typeName == "spot") return Light::Type::Spot;

		return Light::Type::Directional;
	}();

	//Retrieve the color
	float colorValues[4];
	const int colorStartIndex = 2;
	for (int i = colorStartIndex; i < colorStartIndex + 4; ++i)
	{
		colorValues[i - colorStartIndex] = (float)luaL_checknumber(luaState, i);
	}

	//Convert the float array to a color
	glm::vec4 color = glm::make_vec4(colorValues);

	//Retrieve the intensity
	float intensity = (float)luaL_checknumber(luaState, 6);

	//Retrieve the spot inner angle
	float spotInnerAngle = (float)luaL_checknumber(luaState, 7);

	light->SetType(type);
	light->SetColor(color);
	light->SetIntensity(intensity);
	light->SetSpotInnerAngle(spotInnerAngle);

	return 0;
}

static int AddRotatingBehaviour(GameObject* gameObject, lua_State* luaState)
{
	//Command Structure:
	//1 - Speed

	//Retrieve the speed
	float speed = (float)luaL_checknumber(luaState, 1);

	//Add the behaviour
	gameObject->AddBehaviour<RotatingBehaviour>()->SetSpeed(speed);

	return 0;
}

static int AddTerrain(GameObject* gameObject, lua_State* luaState)
{
	//Command Structure:
	//1 - width
	//2 - height
	//3 - depth

	//Retrieve the size of the terrain
	int width = (int)luaL_checknumber(luaState, 1);
	int height = (int)luaL_checknumber(luaState, 2);
	int depth = (int)luaL_checknumber(luaState, 3);

	//Add the behaviour
	Terrain* terrain = gameObject->AddBehaviour<Terrain>();

	//Setup the terrain
	terrain->SetSize(width, depth);
	terrain->SetHeight(height);

	return 0;
}

static int AddWobbleBehaviour(GameObject* gameObject, lua_State* luaState)
{
	gameObject->AddBehaviour<WobbleBehaviour>();

	return 0;
}

static int AddCamera(GameObject* gameObject, lua_State* luaState)
{
	//Command Structure:
	//1 - FoV
	//2 - Near Plane
	//3 - Far Plane

	//Retrieve FoV
	float fieldOfView = (float)luaL_checknumber(luaState, 1);

	//Retrieve near and far planes
	float nearPlane = (float)luaL_checknumber(luaState, 2);
	float farPlane = (float)luaL_checknumber(luaState, 3);

	//Add camera to gameobject
	Camera* camera = gameObject->AddBehaviour<Camera>();

	//Apply properties
	camera->SetFieldOfView(fieldOfView);
	camera->SetNearPlane(nearPlane);
	camera->SetFarPlane(farPlane);

	return 0;
}

static int AddFreeLookCamera(GameObject* gameObject, lua_State* luaState)
{
	//Command Structure:
	//1 - Move speed
	//2 - Rotation speed

	//Retrieve speeds
	float moveSpeed = (float)luaL_checknumber(luaState, 1);
	float rotationSpeed = (float)luaL_checknumber(luaState, 2);

	FreeLookCamera* flc = gameObject->AddBehaviour<FreeLookCamera>();
	flc->SetMoveSpeed(moveSpeed);
	flc->SetRotationSpeed(rotationSpeed);

	return 0;
}

static int AddNPC(GameObject* gameObject, lua_State* luaState)
{
	//Command Structure:
	//1 - NPC ID
	//2 - Is interactble
	//3 - Run every frame?

	//Retrieve ID
	const int ID = (int)luaL_checkinteger(luaState, 1);

	//Retrieve whether interactble
	const bool isInteractble = (bool)lua_toboolean(luaState, 2);

	//Retrieve whether to run every frame
	const bool runEveryFrame = (bool)lua_toboolean(luaState, 3);

	//Add NPC to object
	NPC* npc = gameObject->AddBehaviour<NPC>();
	npc->SetID(ID);
	npc->SetInteractble(isInteractble);
	npc->SetRunEveryFrame(runEveryFrame);

	return 0;
}

static int AddPlayer(GameObject* gameObject, lua_State* luaState)
{
	gameObject->AddBehaviour<Player>();

	return 0;
}

static int AddAudioSource(GameObject* gameObject, lua_State* luaState)
{
	//Command Structure:
	//1 - file name
	//2 - stream clip
	//3 - cache clip
	//4 - play on awake
	//5 - loop
	//6 - pitch
	//7 - volume
	//8 - is 2D?

	//Retrieve file name
	const std::string fileName = luaL_checkstring(luaState, 1);

	//Retrieve whether to stream
	const bool streamClip = (bool)lua_toboolean(luaState, 2);

	//Retrieve whether to cache
	const bool cacheClip = (bool)lua_toboolean(luaState, 3);

	//Retrieve whether to play on awake
	const bool playOnAwake = (bool)lua_toboolean(luaState, 4);

	//Retrieve whether to loop
	const bool loop = (bool)lua_toboolean(luaState, 5);

	//Retrieve the pitch
	const float pitch = (float)luaL_checknumber(luaState, 6);

	//Retrieve the volume
	const float volume = (float)luaL_checknumber(luaState, 7);

	//Retrieve whether the sound is 2D or 3D
	const bool is2D = (bool)lua_toboolean(luaState, 8);

	//Add the behaviour
	AudioSource* audioSource = gameObject->AddBehaviour<AudioSource>();

	//Apply values
	audioSource->SetAudioClip(AudioClip::Load(fileName, streamClip, cacheClip));
	audioSource->SetPlayOnAwake(playOnAwake);
	audioSource->SetLooping(loop);
	audioSource->SetPitch(pitch);
	audioSource->SetVolume(volume);
	audioSource->SetSpatialBlend(is2D ? AudioSource::Type::TwoD : AudioSource::Type::ThreeD);
	
	return 0;
}

static int AddSphereCollider(GameObject* gameObject, lua_State* luaState)
{
	//Command Structure:
	//1 - radius

	//Get radius
	const float radius = (float)luaL_checknumber(luaState, 1);

	gameObject->AddBehaviour<SphereCollider>()->SetRadius(radius);

	return 0;
}

static int AddBoxCollider(GameObject* gameObject, lua_State* luaState)
{
	//Command Structure:
	//1..3 - half extents

	//Get extents
	float halfExtentsValues[3];
	for (int i = 1; i < 4; ++i)
	{
		halfExtentsValues[i - 1] = (float)luaL_checknumber(luaState, i);
	}
	const glm::vec3 halfExtents = glm::make_vec3(halfExtentsValues);

	gameObject->AddBehaviour<BoxCollider>()->SetHalfExtents(halfExtents);

	return 0;
}

static int AddCapsuleCollider(GameObject* gameObject, lua_State* luaState)
{
	//Command Structure:
	//1 - radius
	//2 - height

	//Get radius
	const float radius = (float)luaL_checknumber(luaState, 1);

	//Get height
	const float height = (float)luaL_checknumber(luaState, 2);

	CapsuleCollider* capsuleCollider = gameObject->AddBehaviour<CapsuleCollider>();
	capsuleCollider->SetRadius(radius);
	capsuleCollider->SetHeight(height);

	return 0;
}

static int AddMeshCollider(GameObject* gameObject, lua_State* luaState)
{
	//Command structure:
	//1 - Is Convex?

	//Retrieve whether the mesh collider is convex or not
	const bool isConvex = (bool)lua_toboolean(luaState, 1);

	if (isConvex == true)
	{
		gameObject->AddBehaviour<ConvexMeshCollider>();
	}
	else
	{
		gameObject->AddBehaviour<ConcaveMeshCollider>();
	}

	return 0;
}

static int AddRigidbody(GameObject* gameObject, lua_State* luaState)
{
	//Command Structure:
	//1 - mass
	//2 - is kinematic?
	//3 - freeze x position
	//4 - freeze y position
	//5 - freeze z position
	//6 - freeze x rotation
	//7 - freeze y rotation
	//8 - freeze z rotation

	//Get mass
	const float mass = (float)luaL_checknumber(luaState, 1);

	//Get kinematic state
	const bool isKinematic = (bool)lua_toboolean(luaState, 2);

	//Get Freeze Position axes
	const bool freezeXPos = (bool)lua_toboolean(luaState, 3);
	const bool freezeYPos = (bool)lua_toboolean(luaState, 4);
	const bool freezeZPos = (bool)lua_toboolean(luaState, 5);

	//Get Freeze Rotation axes
	const bool freezeXRot = (bool)lua_toboolean(luaState, 6);
	const bool freezeYRot = (bool)lua_toboolean(luaState, 7);
	const bool freezeZRot = (bool)lua_toboolean(luaState, 8);

	Rigidbody* rigidbody = gameObject->AddBehaviour<Rigidbody>();
	rigidbody->SetMass(mass);
	rigidbody->SetKinematic(isKinematic);
	rigidbody->FreezePosition(freezeXPos, freezeYPos, freezeZPos);
	rigidbody->FreezeRotation(freezeXRot, freezeYRot, freezeZRot);

	return 0;
}

int AddCharacterController(GameObject* gameObject, lua_State* luaState)
{
	//Command Structure:
	//1 - Slope limit
	//2 - Step height
	//3 - radius
	//4 - height

	const float slopeLimit = (float)luaL_checknumber(luaState, 1);
	const float stepHeight = (float)luaL_checknumber(luaState, 2);
	const float radius = (float)luaL_checknumber(luaState, 3);
	const float height = (float)luaL_checknumber(luaState, 4);

	CharacterController* controller = gameObject->AddBehaviour<CharacterController>();
	controller->SetSlopeLimit(slopeLimit);
	controller->SetStepHeight(stepHeight);
	controller->SetRadius(radius);
	controller->SetHeight(height);

	return 0;
}

int AddTranslationAnimation(GameObject* gameObject, lua_State* luaState)
{
	gameObject->AddBehaviour<TranslationAnimation>();

	return 0;
}

int AddAudioListener(GameObject* gameObject, lua_State* luaState)
{
	gameObject->AddBehaviour<AudioListener>();

	return 0;
}

using func = std::add_pointer_t<int(GameObject*, lua_State*)>;
static const std::unordered_map<std::string, func> creationFunctions
{
	std::make_pair("light", AddLight),
	std::make_pair("rotatingbehaviour", AddRotatingBehaviour),
	std::make_pair("terrain", AddTerrain),
	std::make_pair("wobblebehaviour", AddWobbleBehaviour),
	std::make_pair("camera", AddCamera),
	std::make_pair("freelookcamera", AddFreeLookCamera),
	std::make_pair("npc", AddNPC),
	std::make_pair("player", AddPlayer),
	std::make_pair("audiosource", AddAudioSource),
	std::make_pair("spherecollider", AddSphereCollider),
	std::make_pair("boxcollider", AddBoxCollider),
	std::make_pair("capsulecollider", AddCapsuleCollider),
	std::make_pair("meshcollider", AddMeshCollider),
	std::make_pair("rigidbody", AddRigidbody),
	std::make_pair("charactercontroller", AddCharacterController),
	std::make_pair("translationanimation", AddTranslationAnimation),
	std::make_pair("audiolistener", AddAudioListener),
};

static int AddBehaviour(lua_State* luaState)
{
	//Command structure:
	//1 - Game object
	//2 - Behaviour name

	//Retrieve the game object
	GameObject* gameObject = (GameObject*)lua_touserdata(luaState, 1);

	//Retrieve the behaviour name
	std::string behaviour = luaL_checkstring(luaState, 2);

	//Convert the behaviour to lower case for consistency
	std::transform(behaviour.begin(), behaviour.end(), behaviour.begin(), std::tolower);

	//Remove the values from the stack
	lua_remove(luaState, 1);
	lua_remove(luaState, 1);

	//Call the proper function based on the behaviour name
	auto found = creationFunctions.find(behaviour);
	if (found != creationFunctions.end())
	{
		return found->second(gameObject, luaState);
	}

	return 0;
}

#pragma endregion

std::vector<GameObject*> LevelImporter::LoadLevel(const std::string & levelName)
{
	std::cout << "[Loading level " << levelName << "...]" << '\n';

	//Clear the loaded objects list
	s_loadedObjects.clear();

	//Create an environment in which to load a lua script
	Environment environment;

	//Register the creation functions
	environment.RegisterFunction(CreateGameObject, "creategameobject");
	environment.RegisterFunction(AddChild, "addchild");
	environment.RegisterFunction(AddBehaviour, "addbehaviour");

	//Load the level script
	Script script(environment, config::MGE_LEVELS_PATH + levelName);

	//Execute the loading script
	script.Execute();

	std::cout << "[Level loaded successfully!]\n\n";

	//Return the loaded objects list
	return s_loadedObjects;
}
