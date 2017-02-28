#pragma once
#include <Core\AbstractGame.hpp>
#include <Utils\Singleton.hpp>

class Application final : public AbstractGame, public Singleton<Application>
{
friend Singleton<Application>;

protected:
	void OnInitialized() override final;
    void InitializeScene() override final;
private:
	Application() = default;
    Application(const Application&) = delete;
    Application& operator=(const Application&) = delete;
};
