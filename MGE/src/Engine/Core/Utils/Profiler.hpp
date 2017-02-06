#pragma once
#include <string>
#include <unordered_map>
#include <SFML\System\Clock.hpp>

class Profiler
{
public:
	static void BeginSample(const std::string& sampleName);
	static void EndSample();

	static float GetSampleData(const std::string& sampleName);
private:
	using sampleMap = std::unordered_map<std::string, float>;
	static sampleMap s_samples;

	static std::string s_currentSample;
	static sf::Clock s_sampleClock;

	Profiler() {}
	~Profiler() {}
};

