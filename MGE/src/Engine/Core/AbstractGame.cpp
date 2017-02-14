#include "AbstractGame.hpp"
#include <Behaviours\Camera.hpp>

#include <Core\GameObject.hpp>
#include <Core\Time.hpp>
#include <Core\Scene.hpp>

#include <Input\Input.hpp>

#include <Managers\Renderer.hpp>
#include <Managers\ShaderManager.hpp>
#include <Managers\SceneManager.hpp>
#include <Managers\LightManager.hpp>

#include <Physics\Physics.hpp>

#include <Utils\Screen.hpp>
#include <Utils\Cursor.hpp>
#include <Utils\Profiler.hpp>

#include <iostream>

void AbstractGame::Initialize() 
{
    std::cout << "Initializing engine..." << '\n' << '\n';
	//TODO: InitializeConfig();
	//TODO: InitializeSkybox(); (Add RenderSettings)
    InitializeWindow();
	InitializeHelperSingletons();
    PrintVersionInfo();
    InitializeGlew();
	InitializePhysics();
	InitializeShaders();
	InitializeLight();
    InitializeRenderer();
	InitializeInputManager();
    InitializeScene();
	PostInitializeScene();
	std::cout << '\n' << "Engine initialized." << '\n' << '\n';
}

void AbstractGame::SetVsync(bool enabled)
{
	m_vsyncEnabled = enabled;
	m_window->setVerticalSyncEnabled(enabled);
}

bool AbstractGame::IsVsyncEnabled()
{
	return m_vsyncEnabled;
}

void AbstractGame::InitializeWindow() 
{
	std::cout << "Initializing window..." << '\n';
	m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(800,600), "Mercurial", sf::Style::Default, sf::ContextSettings(24,8,0,3,3));
	std::cout << "Window initialized." << '\n' << '\n';
}

void AbstractGame::InitializeHelperSingletons()
{
	std::cout << "Initializing screen..." << '\n';
	Screen::Instance().SetWindow(m_window.get());
	std::cout << "Screen initialized" << '\n' << '\n';

	std::cout << "Initializing cursor..." << '\n';
	Cursor::Instance().SetWindow(m_window.get());
	std::cout << "Cursor initialized" << '\n' << '\n';
}

void AbstractGame::PrintVersionInfo() 
{
	std::cout << "Context info:" << '\n';
	std::cout << "----------------------------------" << '\n';

    const GLubyte *vendor = glGetString( GL_VENDOR );
    const GLubyte *renderer = glGetString( GL_RENDERER );
    const GLubyte *version = glGetString( GL_VERSION );
    const GLubyte *glslVersion = glGetString( GL_SHADING_LANGUAGE_VERSION );

    GLint major, minor;
    glGetIntegerv(GL_MAJOR_VERSION, &major);
    glGetIntegerv(GL_MINOR_VERSION, &minor);

    printf("GL Vendor : %s\n", vendor);
    printf("GL Renderer : %s\n", renderer);
    printf("GL Version (string) : %s\n", version);
    printf("GL Version (integer) : %d.%d\n", major, minor);
    printf("GLSL Version : %s\n", glslVersion);

	std::cout << "----------------------------------" << '\n' << '\n';
}

void AbstractGame::InitializeGlew() 
{
	std::cout << "Initializing GLEW..." << '\n';
    //initialize the opengl extension wrangler
    GLint glewStatus = glewInit();
	std::cout << "GLEW Status: " << (glewStatus == GLEW_OK ? "Initialized" : "Failed to Initialize") << '\n' << '\n';
}

void AbstractGame::InitializePhysics()
{
	std::cout << "Initialize Physics..." << '\n';
	Physics::Instance().Initialize();
	std::cout << "Physics Initialize" << '\n' << '\n';
}

void AbstractGame::InitializeRenderer() 
{
	std::cout << "Initializing renderer..." << '\n';
	Renderer::Instance();
    std::cout << "Renderer done." << '\n' << '\n';
}

void AbstractGame::InitializeShaders()
{
	std::cout << "Loading shaders..." << '\n';
	ShaderManager::LoadShaders();
	std::cout << "Shaders loaded." << '\n' << '\n';
}

void AbstractGame::InitializeLight()
{
	std::cout << "Initializing light manager..." << '\n';
	LightManager::Instance().LoadFromConfig();
	std::cout << "Light manager initialized." << '\n' << '\n';
}

void AbstractGame::InitializeInputManager()
{
	std::cout << "Initializing Input manager..." << '\n';
	m_inputManager = std::make_unique<InputManager>();
	std::cout << "Input manager initialized." << '\n' << '\n';
}

void AbstractGame::Run()
{
	//Create a game clock
	sf::Clock clock;

	//Create an accumulator to determine how many times the fixed update should run to catch up with the FPS
	float accumulator = 0;

	//Initialize all behaviours created until now
	SceneManager::Instance().GetActiveScene()->ProcessUninitializedObjects();

	while (m_window->isOpen())
	{
		//Update the game time
		Time::s_gameTime = clock.getElapsedTime().asSeconds();

		Profiler::BeginSample("Events");
		//Process Events
		ProcessEvents();
		Profiler::EndSample();

		if (m_window->isOpen() == false) break;

		//Fixed Update
		Profiler::BeginSample("FixedUpdate");
		accumulator = FixedUpdate(accumulator);
		Profiler::EndSample();

		//Bullet Physics Simulation
		Physics::Instance().StepSimulation();

		Profiler::BeginSample("Update");
		//Update 
		Update();		
		Profiler::EndSample();

		if (m_window->isOpen() == false) break;

		//Render
		PreRender();

		Profiler::BeginSample("Render");
		Render();
		Profiler::EndSample();

		Profiler::BeginSample("PostRender");
		PostRender();
		Profiler::EndSample();

		//Calculate time per frame
		Time::s_deltaTime = clock.getElapsedTime().asSeconds() - Time::s_gameTime;

		//Update the frame rate
		Time::s_frameRate = 1.0f / Time::s_deltaTime;

		//Update the cursor
		if (m_window->hasFocus() == true)
		{
			Cursor::Instance().Update();
		}

		//Reset the mouse values of the input manager
		//m_inputManager->ResetMouse(*m_window);

		//Update frame count
		++Time::s_frameCount;

		//Display Hierarchy
		if (Input::IsKeyPressed(sf::Keyboard::H))
		{
			const auto hierarchy = SceneManager::Instance().GetActiveScene()->GetRootGameObjects();
			for (auto o : hierarchy)
			{
				std::cout << o->GetName() << '\n';
				std::cout << o->GetTransform()->GetLocalPosition() << '\n';
				std::cout << o->GetTransform()->GetLocalRotation().GetEulerAngles() << '\n';
				std::cout << o->GetTransform()->GetLocalScale() << '\n';
				auto children = o->GetTransform()->GetAllChildrenRecursively();
				for (auto c : children)
				{
					std::cout << '\t' << c->GetGameObject()->GetName() << '\n';
					std::cout << '\t' << c->GetLocalPosition() << '\n';
					std::cout << '\t' << c->GetLocalRotation().GetEulerAngles() << '\n';
					std::cout << '\t' << c->GetLocalScale() << '\n';
				}
			}
		}
	}
}

void AbstractGame::Quit()
{
	m_window->close();
}

void AbstractGame::PostInitializeScene() {}

void AbstractGame::ProcessEvents()
{
	sf::Event event;

	//Reset the input manager
	m_inputManager->Reset();

	//Process all the accumulated events in the event queue
	while( m_window->pollEvent( event ) ) 
	{
		//Handle Input events by the Input Manager
		m_inputManager->Update(*m_window, event);

		//Handle other types of misc. events
        switch (event.type) 
		{
		case sf::Event::Closed:
			Quit();
			break;
        case sf::Event::Resized:
            //would be better to move this to the renderer
            //this version implements nonconstrained match viewport scaling
            glViewport(0, 0, event.size.width, event.size.height);
			Camera::GetMainCamera()->SetAspect((float) event.size.width, (float) event.size.height);
            break;
		default:
			break;
        }
	}
}

float AbstractGame::FixedUpdate(float accumulator)
{
	//Store the current delta time
	const float currentDeltaTime = Time::s_deltaTime;

	//Set the delta time to the fixed delta time to allow users to use Time::s_deltaTime in FixedUpdate
	Time::s_deltaTime = Time::s_fixedDeltaTime;

	//Increment the accumulator by the time it took to process the last frame
	accumulator += currentDeltaTime;

	//Limit the accumulator to the maximum time step
	accumulator = glm::clamp(accumulator, accumulator, Time::s_maxTimeStep);

	//As long as the accumulated time is above the allowed time per fixed update, keep running
	while (accumulator >= Time::s_fixedDeltaTime)
	{
		accumulator -= Time::s_fixedDeltaTime;

		//Retrieve the root game objects in the scene
		//This is done every call to FixedUpdate in case the scene graph has changed
		const auto& rootGameObjects = SceneManager::Instance().GetActiveScene()->GetRootGameObjects();

		for (const auto& gameObject : rootGameObjects)
		{
			gameObject->FixedUpdate();
		}
	}

	//Reset the delta time
	Time::s_deltaTime = currentDeltaTime;

	//Return the accumulated amount left
	return accumulator;
}

void AbstractGame::Update() 
{
	Scene* activeScene = SceneManager::Instance().GetActiveScene();
	activeScene->ProcessUninitializedObjects();

	const auto& rootGameObjects = activeScene->GetRootGameObjects();
	for (const auto& gameObject : rootGameObjects)
	{
		gameObject->Update();
	}
}

void AbstractGame::PreRender()
{
	//Clear Screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Profiler::BeginSample("UpdateLight");
	//Update light UBO
	LightManager::Instance().UpdateLightData(Renderer::Instance().GetViewMatrix());
	Profiler::EndSample();
}

void AbstractGame::Render() 
{
	const Scene* activeScene = SceneManager::Instance().GetActiveScene();
	if(activeScene != nullptr)
		Renderer::Instance().Render(*activeScene);
}

void AbstractGame::PostRender() 
{
	//Swap the buffers
	m_window->display();
}

