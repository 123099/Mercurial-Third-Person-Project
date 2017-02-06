#pragma once
#include <Core\Material.hpp>
#include <string>

class MaterialImporter
{
public:
	static Material* LoadMaterial(const std::string & materialName);
private:
	MaterialImporter() = default;
};

