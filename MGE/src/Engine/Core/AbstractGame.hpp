#ifndef ABSTRACTGAME_H
#define ABSTRACTGAME_H

#include <GL/glew.h>
#include <string>
#include <memory>
#include <Managers\InputManager.hpp>
#include <SFML\Graphics\RenderWindow.hpp>

class AbstractGame
{
public:
    //Creates a window, initializes glew,a world instance, a renderer and the input and shader managers
    virtual void Initialize();

	//Enabled or disables VSync, including the update loop
	void SetVsync(bool enabled);

	//Returns whether the game window has vertical sync enabled or not
	bool IsVsyncEnabled();

    //Starts the game loop - process events, update the behaviours and render
    void Run();
	void Quit();
protected:
    AbstractGame() = default;
    virtual ~AbstractGame() = default;

    //Initialize the actual scene
    virtual void InitializeScene() = 0;

	//Render all game objects in the display root
	virtual void Render();

	std::unique_ptr<sf::RenderWindow> m_window;		//SFML window to render into
	std::unique_ptr<InputManager> m_inputManager;	//Manages Input events and provides the data to all classes in the project

	bool m_vsyncEnabled;			//Keeps track of whether vsync was enabled or disabled

private:
	//Initialize SFML rendering context
	void InitializeWindow();

	//Initialize the Screen instance
	void InitializeScreen();

	//Print info about the current driver version etc
	void PrintVersionInfo();

	//Initialize the extension wrangler
	void InitializeGlew();

	//Create our own custom renderer instance
	void InitializeRenderer();

	//Load all the shaders in the shaders folder
	void InitializeShaders();

	//Load the light buffer
	void InitializeLight();

	//Initialize the input manager instance
	void InitializeInputManager();

	//Initialize all the components, etc.
	void PostInitializeScene();

	//Process any sfml window events (see SystemEventDispatcher/Listener)
	void ProcessEvents();

	//Call FixedUpdate on all the components until the loop catches up with the FPS
	float FixedUpdate(float accumulator);

	//Call update on all game objects in the display root
	void Update();

	//Sets everything up for rendering, e.g. binding light buffers
	void PreRender();

	//Cleans after itself after rendering, e.g. unbind light buffers
	void PostRender();

    AbstractGame(const AbstractGame&) = delete;
    AbstractGame& operator=(const AbstractGame&) = delete;
};

#endif // ABSTRACTGAME_H
