#include "Profiler.hpp"
#include <iostream>

Profiler::sampleMap Profiler::s_samples;

std::string Profiler::s_currentSample;
sf::Clock Profiler::s_sampleClock;

void Profiler::BeginSample(const std::string & sampleName)
{
	if (sampleName != "")
	{
		s_currentSample = sampleName;
		s_sampleClock.restart();
	}
	else
	{
		std::cerr << "Profiler Error: Sample name cannot be an empty string!" << '\n';
	}
}

void Profiler::EndSample()
{
	if (s_currentSample != "")
	{
		s_samples[s_currentSample] = s_sampleClock.getElapsedTime().asSeconds();
		s_currentSample = "";
	}
}

float Profiler::GetSampleData(const std::string & sampleName)
{
	Profiler::sampleMap::iterator sample = s_samples.find(sampleName);

	if (sample != s_samples.end())
	{
		return sample->second;
	}
	else
	{
		return 0.0f;
	}
}
