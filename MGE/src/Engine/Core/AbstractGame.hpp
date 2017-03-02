#pragma once
#include <Managers\InputManager.hpp>
#include <SFML\Graphics\RenderWindow.hpp>
#include <Textures\RenderTexture.hpp>
#include <UI\TextLog.hpp>
#include <GL\glew.h>
#include <memory>
#include <string>

class AbstractGame
{
public:
	void SetFPSLimit(float limit);
	void SetDebugHudEnabled(bool enabled);

    void Run();
	void Quit();
protected:
	AbstractGame();
    virtual ~AbstractGame() = default;

	float m_fpsLimitTime;
	bool m_shouldQuit;

	bool m_debugHudEnabled;

	std::unique_ptr<sf::RenderWindow> m_window;
	std::unique_ptr<RenderTexture> m_renderTexture;
	InputManager m_inputManager;

	TextLog m_debugHud;
	TextLog m_hierarchyDebugHud;

	virtual void OnInitialized();
    virtual void InitializeScene() = 0;
private:
	//Begins initializing the engine
	void Initialize();

	//Initialize SFML rendering context
	void InitializeWindow();

	//Initialize the helper singleton instances, such as Screen and Cursor
	void InitializeHelperSingletons();

	//Print info about the current driver version etc
	void PrintVersionInfo();

	//Initialize the extension wrangler
	void InitializeGlew();

	//Initialize bullet physics
	void InitializePhysics();

	//Create our own custom renderer instance
	void InitializeRenderer();

	//Load all the shaders in the shaders folder
	void InitializeShaders();

	//Load the light buffer
	void InitializeLight();

	//Initialize all the components, etc.
	void PostInitializeScene();

	//Check whether enough time has passed to coincide with the fps limit set
	bool CheckFPSLimit(const sf::Clock& gameClock);

	//Process any sfml window events (see SystemEventDispatcher/Listener)
	void ProcessEvents();

	//Call FixedUpdate on all the components until the loop catches up with the FPS
	float FixedUpdate(float accumulator);

	//Call update on all game objects in the display root
	void Update();

	//Updated the information on the debug hud
	void UpdateDebugHud();

	//Sets everything up for rendering, e.g. binding light buffers
	void PreRender();

	//Renders the Scene and the UI
	void Render();

	//Cleans after itself after rendering, e.g. unbind light buffers
	void PostRender();

	//Processing needed to be done after the frame ends, such as destroying objects marked as destroyed during the frame
	void PostFrame();

    AbstractGame(const AbstractGame&) = delete;
    AbstractGame& operator=(const AbstractGame&) = delete;
};