#pragma once
#include <SFML\Audio\Music.hpp>
#include <SFML\Audio\Sound.hpp>
#include <SFML\Audio\SoundBuffer.hpp>
#include <Utils\InstanceCache.hpp>
#include <Utils\glm.hpp>
#include <string>

class AudioClip final : public ICacheable
{
public:
	static AudioClip* Load(const std::string& fileName, bool stream, bool cache);

	void Play();
	void Pause();
	void Stop();

	void SetLooping(bool loop);

	void SetMinimumDistance(float distance);
	void SetAttenuation(float attenuation);
	void SetVolume(float volume);
	void SetPitch(float pitch);
	void Seek(float normalizedTime);

	bool IsPlaying();

	void UseRelativePosition(bool relativePosition);
	void SetWorldPosition(const glm::vec3& position);
private:
	AudioClip(const std::string& name, bool stream);

	sf::SoundBuffer m_soundBuffer;
	sf::Music m_music;
	sf::Sound m_sound;

	const bool m_stream;

	static InstanceCache<AudioClip> s_cache;
};
