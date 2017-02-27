#ifndef ABSTRACTGAME_H
#define ABSTRACTGAME_H

#include <GL/glew.h>
#include <string>
#include <memory>
#include <Managers\InputManager.hpp>
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Graphics\RenderTexture.hpp>

class AbstractGame
{
public:
    virtual void Initialize();

	void SetFPSLimit(float limit);

    void Run();
	void Quit();
protected:
    AbstractGame() = default;
    virtual ~AbstractGame() = default;

    //Initialize the actual scene
    virtual void InitializeScene() = 0;

	//Render all game objects in the display root
	virtual void Render();
	sf::RenderTexture renderT;
	std::unique_ptr<sf::RenderWindow> m_window;		//SFML window to render into
	std::unique_ptr<InputManager> m_inputManager;	//Manages Input events and provides the data to all classes in the project

	float m_fpsLimitTime;
	bool m_shouldQuit;
private:
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

	//Initialize the input manager instance
	void InitializeInputManager();

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

	//Sets everything up for rendering, e.g. binding light buffers
	void PreRender();

	//Cleans after itself after rendering, e.g. unbind light buffers
	void PostRender();

	//Processing needed to be done after the frame ends, such as destroying objects marked as destroyed during the frame
	void PostFrame();

    AbstractGame(const AbstractGame&) = delete;
    AbstractGame& operator=(const AbstractGame&) = delete;
};

#endif // ABSTRACTGAME_H
