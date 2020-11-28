#include "AbstractGame.hpp"
#include <Behaviours\Camera.hpp>
#include <Behaviours\MeshRenderer.hpp>
#include <Behaviours\PostProcessors\PostProcessor.hpp>

#include <Game\Behaviours\Player.hpp>

#include <Core\GameObject.hpp>
#include <Core\Time.hpp>
#include <Core\Scene.hpp>

#include <Input\Input.hpp>

#include <Renderers\Renderer.hpp>
#include <Renderers\UIRenderer.hpp>
#include <Renderers\PostProcessRenderer.hpp>

#include <Managers\ShaderManager.hpp>
#include <Managers\SceneManager.hpp>
#include <Managers\LightManager.hpp>

#include <Physics\Physics.hpp>

#include <Utils\Screen.hpp>
#include <Utils\Cursor.hpp>
#include <Utils\Profiler.hpp>

#include <sstream>
#include <iostream>

AbstractGame::AbstractGame() : m_debugHud("arial.ttf"), m_hierarchyDebugHud("arial.ttf") 
{
	InitializeWindow();
	InitializeHelperSingletons();

	m_debugHud.SetPositionOnScreen(10, 10); 
	m_debugHud.SetBackground("poison.png");
	m_hierarchyDebugHud.SetPositionOnScreen(300, 10);

#ifdef _DEBUG
	SetDebugHudEnabled(true);
#else
	SetDebugHudEnabled(false);
#endif
}

void AbstractGame::Initialize()
{
	std::cout << "Initializing engine..." << '\n' << '\n';
	PrintVersionInfo();
	InitializeGlew();
	InitializeShaders();
	InitializePhysics();
	InitializeLight();
	InitializeRenderer();
	InitializeRenderTexture();
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
	m_debugHud.SetVisible(enabled);
	m_hierarchyDebugHud.SetVisible(enabled);
}

void AbstractGame::OnInitialized() {}

void AbstractGame::InitializeWindow()
{
	std::cout << "Initializing window..." << '\n';
	m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(1280,720), "Mercurial", sf::Style::Fullscreen, sf::ContextSettings(24,8,0,3,3));
	std::cout << "Window initialized." << '\n' << '\n';
}

void AbstractGame::InitializeRenderTexture()
{
	std::cout << "Initialize screen render texture..." << '\n';
	m_renderTexture = std::make_unique<RenderTexture>(m_window->getSize().x, m_window->getSize().y);
	std::cout << "Render texture initialized." << '\n' << '\n';
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
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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
		//Make sure the Fps is locked to the limit set
		if (CheckFPSLimit(clock) == true)
		{
			Profiler::Instance().BeginSample("Events");
			//Process Events
			ProcessEvents();
			Profiler::Instance().EndSample();

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

			if (Input::IsKeyPressed(sf::Keyboard::F3))
			{
				SetDebugHudEnabled(!m_debugHudEnabled);
			}

			PostFrame();
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
	Profiler::Instance().BeginSample("Input Manager Reset");
	//Reset the input manager
	m_inputManager.Reset();
	Profiler::Instance().EndSample();

	sf::Event event;
	
	//Process all the accumulated events in the event queue
	while(m_window->pollEvent(event))
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
		//Debug Hud
		int totalVertexCount = 0;
		int totalTriangleCount = 0;
		MeshRenderer::GetTotalVertexTriangleCountInScene(&totalVertexCount, &totalTriangleCount);

		std::stringstream debugInfo;
		debugInfo << "FPS: " << (int)Time::s_frameRate << '\n';
		debugInfo << "Vertices: " << totalVertexCount << '\n';
		debugInfo << "Triangles: " << totalTriangleCount << '\n';
		debugInfo << Profiler::Instance().GetAllSampleDataAsString();

		m_debugHud.SetText(debugInfo.str());

		//Hierarchy
		debugInfo.str("");
		Scene* activeScene = SceneManager::Instance().GetActiveScene();
		debugInfo << "Scene: " << activeScene->GetName() << ", Root objects: " << activeScene->GetRootCount() << '\n';

		const auto& hierarchy = SceneManager::Instance().GetActiveScene()->GetRootGameObjects();
		for (const GameObject* object : hierarchy)
		{
			debugInfo << object->GetName() << ": ";
			debugInfo << object->GetTransform()->GetLocalPosition() << ", ";
			debugInfo << object->GetTransform()->GetLocalRotation().GetEulerAngles() << ", ";
			debugInfo << object->GetTransform()->GetLocalScale() << '\n';

			const auto& children = object->GetTransform()->GetAllChildrenRecursively();
			for (const Transform* child : children)
			{
				debugInfo << '\t' << child->GetGameObject()->GetName() << ": ";
				debugInfo << '\t' << child->GetLocalPosition() << ", ";
				debugInfo << '\t' << child->GetLocalRotation().GetEulerAngles() << ", ";
				debugInfo << '\t' << child->GetLocalScale() << '\n';
			}
		}
		m_hierarchyDebugHud.SetText(debugInfo.str());
	}
}

void AbstractGame::PreRender()
{
	//Clear Screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Profiler::Instance().BeginSample("UpdateLight");
	//Update light UBO
	LightManager::Instance().UpdateLightData(Camera::GetMainCamera()->GetViewMatrix());
	Profiler::Instance().EndSample();

	Profiler::Instance().BeginSample("Render Shadow Maps");
	LightManager::Instance().RenderShadowMaps();
	Profiler::Instance().EndSample();
}

void AbstractGame::Render() 
{
#ifdef _DEBUG
	Camera::GetMainCamera()->SetAspect((float)m_window->getSize().x / 2.0f, (float)m_window->getSize().y);

	//Render pass
	m_renderTexture->Activate();
		Renderer::Instance().Render(Camera::GetMainCamera()->GetViewMatrix(), Camera::GetMainCamera()->GetProjectionMatrix());
	m_renderTexture->Deactivate();

	//Pre-post processing
	glViewport(0, 0, m_window->getSize().x / 2, m_window->getSize().y);
	RenderTextureToScreen();

	Profiler::Instance().BeginSample("Post Process");
	PostProcessRenderer::Instance().Render(*m_renderTexture.get());
	Profiler::Instance().EndSample();

	//Post-post processing
	glViewport(m_window->getSize().x / 2, 0, m_window->getSize().x / 2, m_window->getSize().y);
	RenderTextureToScreen();

	Camera::GetMainCamera()->SetAspect((float)m_window->getSize().x, (float)m_window->getSize().y);
	glViewport(0, 0, m_window->getSize().x, m_window->getSize().y);
#else
	//Render pass
	m_renderTexture->Activate();
		Renderer::Instance().Render(Camera::GetMainCamera()->GetViewMatrix(), Camera::GetMainCamera()->GetProjectionMatrix());
	m_renderTexture->Deactivate();

	PostProcessRenderer::Instance().Render(*m_renderTexture.get());
	RenderTextureToScreen();
#endif
	//Render UI
	UIRenderer::Instance().Render(*m_window);
}

void AbstractGame::RenderTextureToScreen()
{
	//Draw rendered texture to the screen
	glDisable(GL_CULL_FACE);
	glEnable(GL_TEXTURE_2D);
	m_renderTexture->SetBindDepthTexture(false);
	m_renderTexture->Bind();

	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f);
		glVertex2f(-1.0, -1.0f);

		glTexCoord2f(1.0f, 0.0f);
		glVertex2f(1.0, -1.0f);

		glTexCoord2f(1.0f, 1.0f);
		glVertex2f(1.0, 1.0f);

		glTexCoord2f(0.0f, 1.0f);
		glVertex2f(-1.0, 1.0f);
	glEnd();

	m_renderTexture->Unbind();
	glEnable(GL_CULL_FACE);

}

void AbstractGame::PostRender() 
{
	m_window->display();
}

void AbstractGame::PostFrame()
{
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

