#pragma once
#include <Utils\Singleton.hpp>

class Mesh;

class MeshFactory final : public Singleton<MeshFactory>
{
friend Singleton<MeshFactory>;

public:
	Mesh* CreateQuad();
private:
	MeshFactory() = default;
};