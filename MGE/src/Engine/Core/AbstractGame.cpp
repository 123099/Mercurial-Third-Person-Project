#include "AbstractGame.hpp"
#include <Behaviours\Camera.hpp>
#include <Behaviours\MeshRenderer.hpp>

#include <Core\GameObject.hpp>
#include <Core\Time.hpp>
#include <Core\Scene.hpp>

#include <Input\Input.hpp>

#include <Renderers\Renderer.hpp>
#include <Renderers\UIRenderer.hpp>

#include <Managers\ShaderManager.hpp>
#include <Managers\SceneManager.hpp>
#include <Managers\LightManager.hpp>

#include <Physics\Physics.hpp>

#include <Utils\Screen.hpp>
#include <Utils\Cursor.hpp>
#include <Utils\Profiler.hpp>

#include <sstream>
#include <iostream>

AbstractGame::AbstractGame() : m_debugHud("arial.ttf") { m_debugHud.SetPositionOnScreen(10, 10); }

void AbstractGame::Initialize()
{
	std::cout << "Initializing engine..." << '\n' << '\n';
	//TODO: InitializeConfig();
	//TODO: InitializeSkybox(); (Add RenderSettings)
	InitializeWindow();
	InitializeHelperSingletons();
	PrintVersionInfo();
	InitializeGlew();
	InitializeShaders();
	InitializePhysics();
	InitializeLight();
	InitializeRenderer();
	InitializeScene();
	PostInitializeScene();
	OnInitialized();
	std::cout << '\n' << "Engine initialized." << '\n' << '\n';
}

void AbstractGame::SetFPSLimit(float limit)
{
	m_fpsLimitTime = glm::clamp(limit, 0.0f, limit);
	if (m_fpsLimitTime != 0.0f)
	{
		m_fpsLimitTime = 1.0f / m_fpsLimitTime;
	}
}

void AbstractGame::SetDebugHudEnabled(bool enabled)
{
	m_debugHudEnabled = enabled;
}

void AbstractGame::OnInitialized() {}

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
    const GLint glewStatus = glewInit();
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
	Renderer::Instance().Initialize();
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

void AbstractGame::Run()
{
	//Initialize the engine
	Initialize();

	//Create a game clock
	sf::Clock clock;

	//Create an accumulator to determine how many times the fixed update should run to catch up with the FPS
	float accumulator = 0;

	//Update the cursor once before running to grab it, if necessary
	Cursor::Instance().Update();

	while (m_window->isOpen())
	{
		Profiler::Instance().BeginSample("Events");
		//Process Events
		ProcessEvents();
		Profiler::Instance().EndSample();

		//Make sure the Fps is locked to the limit set
		if (CheckFPSLimit(clock) == true)
		{
			//Calculate time per frame
			Time::s_deltaTime = clock.getElapsedTime().asSeconds() - Time::s_gameTime;

			//Update the frame rate
			Time::s_frameRate = 1.0f / Time::s_deltaTime;

			Profiler::Instance().BeginSample("FixedUpdate");
			accumulator = FixedUpdate(accumulator);
			Profiler::Instance().EndSample();

			//Bullet Physics Simulation
			Physics::Instance().StepSimulation();

			Profiler::Instance().BeginSample("Update");
			Update();
			Profiler::Instance().EndSample();

			//Render
			PreRender();

			Profiler::Instance().BeginSample("Render");
			Render();
			Profiler::Instance().EndSample();

			Profiler::Instance().BeginSample("PostRender");
			PostRender();
			Profiler::Instance().EndSample();

			//Update the game time
			Time::s_gameTime = clock.getElapsedTime().asSeconds();

			//Update frame count
			++Time::s_frameCount;

			PostFrame();

			//Display Hierarchy
			if (Input::IsKeyPressed(sf::Keyboard::H))
			{
				Scene* activeScene = SceneManager::Instance().GetActiveScene();
				std::cout << "Scene: " << activeScene->GetName() << ", Root objects: " << activeScene->GetRootCount() << '\n';

				const auto& hierarchy = SceneManager::Instance().GetActiveScene()->GetRootGameObjects();
				for (const auto& o : hierarchy)
				{
					std::cout << o->GetName() << '\n';
					std::cout << o->GetTransform()->GetLocalPosition() << '\n';
					std::cout << o->GetTransform()->GetLocalRotation().GetEulerAngles() << '\n';
					std::cout << o->GetTransform()->GetLocalScale() << '\n';
					const auto& children = o->GetTransform()->GetAllChildrenRecursively();
					for (const auto& c : children)
					{
						std::cout << '\t' << c->GetGameObject()->GetName() << '\n';
						std::cout << '\t' << c->GetLocalPosition() << '\n';
						std::cout << '\t' << c->GetLocalRotation().GetEulerAngles() << '\n';
						std::cout << '\t' << c->GetLocalScale() << '\n';
					}
				}
			}
		}
		
		//Clear the profiler data
		Profiler::Instance().Clear();
	}
}

void AbstractGame::Quit()
{
	m_shouldQuit = true;
}

void AbstractGame::PostInitializeScene() 
{
	//Initialize all behaviours created during scene initialization
	SceneManager::Instance().GetActiveScene()->ProcessUninitializedObjects();
}

bool AbstractGame::CheckFPSLimit(const sf::Clock& gameClock)
{
	if (m_fpsLimitTime == 0.0f || Time::s_gameTime == 0)
	{
		return true;
	}
	
	return (gameClock.getElapsedTime().asSeconds() - Time::s_gameTime) >= m_fpsLimitTime;
}

void AbstractGame::ProcessEvents()
{
	sf::Event event;
	
	//Process all the accumulated events in the event queue
	Profiler::Instance().BeginSample("Poll Event");
	bool a = m_window->pollEvent(event);
	Profiler::Instance().EndSample();

	while( a ) 
	{

		Profiler::Instance().BeginSample("Input Manager Update");
		//Handle Input events by the Input Manager
		m_inputManager.Update(*m_window, event);
		Profiler::Instance().EndSample();
		Profiler::Instance().BeginSample("Misc Events");
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
        }
		Profiler::Instance().EndSample();
		a = m_window->pollEvent(event);
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
		for (GameObject* gameObject : rootGameObjects)
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
	for (size_t i = 0; i < rootGameObjects.size(); ++i)
	{
		rootGameObjects[i]->Update();
	}
}

void AbstractGame::UpdateDebugHud()
{
	if (m_debugHudEnabled == true)
	{
		int totalVertexCount = 0;
		int totalTriangleCount = 0;
		MeshRenderer::GetTotalVertexTriangleCountInScene(&totalVertexCount, &totalTriangleCount);

		std::stringstream debugInfo;
		debugInfo << "FPS: " << (int)Time::s_frameRate << '\n';
		debugInfo << "Vertices: " << totalVertexCount << '\n';
		debugInfo << "Triangles: " << totalTriangleCount << '\n';
		debugInfo << Profiler::Instance().GetAllSampleDataAsString();

		m_debugHud.SetText(debugInfo.str());
	}
}

void AbstractGame::PreRender()
{
	//Clear Screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Profiler::Instance().BeginSample("UpdateLight");
	//Update light UBO
	LightManager::Instance().UpdateLightData(Renderer::Instance().GetViewMatrix());
	Profiler::Instance().EndSample();
}

void AbstractGame::Render() 
{
	//Render 3D OpenGL
	Renderer::Instance().Render();

	//Render UI
	m_window->pushGLStates();
	UIRenderer::Instance().Render(*m_window);
	m_window->popGLStates();
}

void AbstractGame::PostRender() 
{
	//Swap the buffers
	m_window->display();
}

void AbstractGame::PostFrame()
{
	Profiler::Instance().BeginSample("Input Manager Reset");
	//Reset the input manager
	m_inputManager.Reset();
	Profiler::Instance().EndSample();

	//Update the cursor
	if (m_window->hasFocus() == true)
	{
		Cursor::Instance().Update();
	}

	//Process objects marked for destruction
	SceneManager::Instance().GetActiveScene()->ProcessObjectsToBeDestroyed();

	//Update the debug hud
	UpdateDebugHud();

	//Check whether the game should quit
	if (m_shouldQuit == true)
	{
		m_window->close();
	}
}

