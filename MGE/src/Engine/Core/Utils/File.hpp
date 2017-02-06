#pragma once
#include <string>

class File
{
public:
	static std::string GetContents(const std::string& fileName);

	File() = delete;
};

