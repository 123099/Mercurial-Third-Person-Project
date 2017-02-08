#pragma once
#include <Core\AbstractGame.hpp>
#include <Utils\Singleton.hpp>

class DebugHud;

class Application final : public AbstractGame, public Singleton<Application>
{
friend Singleton<Application>;

public:
    void Initialize() override final;
protected:
    void InitializeScene() override final;

	void Render() override final;
private:
	DebugHud* m_hud;

	void InitSceneLighting();
    void UpdateHud();

	Application() = default;
    Application(const Application&) = delete;
    Application& operator=(const Application&) = delete;
};
