#include "AudioSource.hpp"
#include <Audio\AudioClip.hpp>
#include <Core\GameObject.hpp>
#include <Behaviours\Transform.hpp>

AudioSource::AudioSource() :
	m_loop(false),
	m_attenuation(1.0f),
	m_minDistance(1.0f),
	m_volume(1.0f),
	m_pitch(1.0f) {}

void AudioSource::SetAudioClip(AudioClip * audioClip)
{
	//Stop the previou clip
	if (m_clip != nullptr)
	{
		m_clip->Stop();
	}

	//Swap to the new clip
	m_clip = audioClip;
}

void AudioSource::SetPlayOnAwake(bool playOnAwake)
{
	m_playOnAwake = playOnAwake;
}

void AudioSource::SetSpatialBlend(float spatialBlend)
{
	//Clamp the blend value between 0 and 1
	spatialBlend = glm::clamp(spatialBlend, 0.0f, 1.0f);

	//Calculate the minimum sound loudness distance based on the spatial blend.
	//As the value decreases, the min distance increases and the sound is more 2D and vice-a-versa
	m_minDistance = 1.0f + (1.0f - spatialBlend) * 1000.0f;

	if (m_clip != nullptr)
	{
		m_clip->SetMinimumDistance(m_minDistance);
	}
}

void AudioSource::Play()
{
	if (m_clip != nullptr)
	{
		//Apply source volume, pitch and loop values
		m_clip->SetAttenuation(m_attenuation);
		m_clip->SetMinimumDistance(m_minDistance);
		m_clip->SetVolume(m_volume);
		m_clip->SetPitch(m_pitch);
		m_clip->SetLooping(m_loop);

		//Play the clip
		m_clip->Play();
	}
}

void AudioSource::Pause()
{
	if (m_clip != nullptr)
	{
		m_clip->Pause();
	}
}

void AudioSource::Stop()
{
	if (m_clip != nullptr)
	{
		m_clip->Stop();
	}
}

void AudioSource::PlayOneShot(AudioClip& audioClip)
{
	audioClip.SetLooping(false);
	audioClip.SetVolume(m_volume);
	audioClip.SetPitch(m_pitch);
	audioClip.SetAttenuation(m_attenuation);
	audioClip.SetMinimumDistance(m_minDistance);
	audioClip.SetWorldPosition(m_gameObject->GetTransform()->GetWorldPosition());
	audioClip.Play();
}

void AudioSource::SetLooping(bool loop)
{
	m_loop = loop;

	if (m_clip != nullptr)
	{
		m_clip->SetLooping(loop);
	}
}

void AudioSource::SetAttenuation(float attenuation)
{
	m_attenuation = attenuation;

	if (m_clip != nullptr)
	{
		m_clip->SetAttenuation(attenuation);
	}
}

void AudioSource::SetVolume(float volume)
{
	m_volume = volume;

	if (m_clip != nullptr)
	{
		m_clip->SetVolume(volume);
	}
}

void AudioSource::SetPitch(float pitch)
{
	m_pitch = pitch;

	if (m_clip != nullptr)
	{
		m_clip->SetPitch(pitch);
	}
}

void AudioSource::Seek(float normalizedTime)
{
	if (m_clip != nullptr)
	{
		m_clip->Seek(normalizedTime);
	}
}

void AudioSource::Awake()
{
	if (m_playOnAwake == true)
	{
		Play();
	}
}

void AudioSource::Update()
{
	if (m_clip != nullptr)
	{
		m_clip->SetWorldPosition(m_gameObject->GetTransform()->GetWorldPosition());
	}
}
