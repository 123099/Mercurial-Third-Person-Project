#pragma once
#include <Utils\Singleton.hpp>
#include <Physics\Ray.hpp>

class Physics final : public Singleton<Physics>
{
friend Singleton<Physics>;
public:
	bool RayCast(const Ray& ray);
};