#pragma once
#include <Textures\RenderTexture.hpp>
#include <Utils\Singleton.hpp>

class PostProcessRenderer final : public Singleton<PostProcessRenderer>
{
friend Singleton<PostProcessRenderer>;

public:
	void Render(RenderTexture& sceneTexture);
private:
	PostProcessRenderer() = default;
};