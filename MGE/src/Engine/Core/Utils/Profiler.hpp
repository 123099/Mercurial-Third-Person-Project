#pragma once
#include <string>
#include <sstream>
#include <unordered_map>
#include <SFML\System\Clock.hpp>
#include <Utils\Singleton.hpp>

struct Sample
{
public:
	Sample(const std::string& name) : m_name(name) {}
	float GetElapsedTime() const { return m_clock.getElapsedTime().asSeconds(); }
	std::string GetName() const { return m_name; }
private:
	std::string m_name;
	sf::Clock m_clock;
};

class Profiler : public Singleton<Profiler>
{
friend Singleton<Profiler>;

public:
	void BeginSample(const std::string& sampleName);
	void EndSample();

	void Clear();

	float GetSampleData(const std::string& sampleName);
	std::string GetAllSampleDataAsString();
private:
	std::unordered_map<std::string, float> m_sampleData;
	std::vector<Sample> m_sampleStack;

	std::stringstream m_sampleDataStringStream;

	const Sample& GetTopMostSample();

	Profiler() = default;
};

