#pragma once
#include <vector>
#include <string>

class GameObject;

class LevelImporter
{
public:
	static std::vector<GameObject*> LoadLevel(const std::string& levelName);
	LevelImporter() = delete;
};

