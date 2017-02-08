#pragma once
#include <Utils\Singleton.hpp>
#include <Physics\Ray.hpp>
#include <Physics\RaycastHit.hpp>

class Physics final : public Singleton<Physics>
{
friend Singleton<Physics>;
public:
	bool Raycast(const Ray& ray);
	bool Raycast(const Ray& ray, float maxDistance);
	bool Raycast(const Ray& ray, RaycastHit& hitInfo, float maxDistance);
};