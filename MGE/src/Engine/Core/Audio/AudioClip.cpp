#include "AudioClip.hpp"
#include <SFML\System\Time.hpp>
#include <config.hpp>
#include <iostream>

InstanceCache<AudioClip> AudioClip::s_cache;

AudioClip * AudioClip::Load(const std::string & fileName, bool stream, bool cache)
{
	//Check if an audio clip with the provided file name is already cached
	if (cache == false || s_cache.HasValue(fileName) == false)
	{
		//Create a new Audio Clip
		AudioClip* audioClip = new AudioClip(fileName, stream);

		const std::string fullPath = config::MGE_AUDIO_PATH + fileName;

		if (stream == true)
		{
			if (audioClip->m_music.openFromFile(fullPath) == false)
			{
				std::cerr << "Couldn't open music file " << fullPath << "!\n";
			}
		}
		else
		{
			if (audioClip->m_soundBuffer.loadFromFile(fullPath) == false)
			{
				std::cerr << "Couldn't load sound file " << fullPath << "!\n";
			}
			else
			{
				audioClip->m_sound.setBuffer(audioClip->m_soundBuffer);
			}
		}

		if (cache == true)
		{
			//Cache the audio clip
			s_cache.AddValue(audioClip);
		}

		return audioClip;
	}
	else
	{
		//Retrieve the cached value and return it
		return s_cache.GetValue(fileName);
	}
}

AudioClip::AudioClip(const std::string& name, bool stream) : m_stream(stream)
{
	m_name = name;
}

void AudioClip::Play()
{
	if (m_stream == true)
	{
		m_music.play();
	}
	else
	{
		m_sound.play();
	}
}

void AudioClip::Pause()
{
	if (m_stream == true)
	{
		m_music.pause();
	}
	else
	{
		m_sound.pause();
	}
}

void AudioClip::Stop()
{
	if (m_stream == true)
	{
		m_music.stop();
	}
	else
	{
		m_sound.stop();
	}
}

void AudioClip::SetLooping(bool loop)
{
	if (m_stream == true)
	{
		m_music.setLoop(loop);
	}
	else
	{
		m_sound.setLoop(loop);
	}
}

void AudioClip::SetMinimumDistance(float distance)
{
	if (m_stream == true)
	{
		m_music.setMinDistance(distance);
	}
	else
	{
		m_sound.setMinDistance(distance);
	}
}

void AudioClip::SetAttenuation(float attenuation)
{
	if (m_stream == true)
	{
		m_music.setAttenuation(attenuation);
	}
	else
	{
		m_sound.setAttenuation(attenuation);
	}
}

void AudioClip::SetVolume(float volume)
{
	if (m_stream == true)
	{
		m_music.setVolume(volume * 100.0f);
	}
	else
	{
		m_sound.setVolume(volume * 100.0f);
	}
}

void AudioClip::SetPitch(float pitch)
{
	if (m_stream == true)
	{
		m_music.setPitch(pitch);
	}
	else
	{
		m_sound.setPitch(pitch);
	}
}

void AudioClip::Seek(float normalizedTime)
{
	//Retrieve the duration of the clip
	const sf::Time duration = [&](){return m_stream == true ? m_music.getDuration() : m_soundBuffer.getDuration(); }();

	//Calculate new duration time based on the normalized time
	const sf::Time newDuration = sf::seconds(duration.asSeconds() * normalizedTime);

	if (m_stream == true)
	{
		m_music.setPlayingOffset(newDuration);
	}
	else
	{
		m_sound.setPlayingOffset(newDuration);
	}
}

bool AudioClip::IsPlaying()
{
	if (m_stream == true)
	{
		return m_music.getStatus() == sf::SoundSource::Playing;
	}
	else
	{
		return m_sound.getStatus() == sf::SoundSource::Playing;
	}
}

void AudioClip::UseRelativePosition(bool relativePosition)
{
	if (m_stream == true)
	{
		m_music.setRelativeToListener(relativePosition);
	}
	else
	{
		m_sound.setRelativeToListener(relativePosition);
	}
}

void AudioClip::SetWorldPosition(const glm::vec3& position)
{
	if (m_stream == true)
	{
		m_music.setPosition(position.x, position.y, position.z);
	}
	else
	{
		m_sound.setPosition(position.x, position.y, position.z);
	}
}

