#pragma once
#include <Core\AbstractGame.hpp>
#include <Utils\Singleton.hpp>

class LuaGame final : public AbstractGame, public Singleton<LuaGame>
{
friend Singleton<LuaGame>;

public:
	void InitializeScene() override final;
private:
	LuaGame() = default;
};