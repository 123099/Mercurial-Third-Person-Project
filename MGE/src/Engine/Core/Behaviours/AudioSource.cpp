#include "AudioSource.hpp"
#include <Core\Scene.hpp>
#include <Core\GameObject.hpp>
#include <Behaviours\Transform.hpp>
#include <Managers\SceneManager.hpp>

AudioSource::AudioSource() :
	m_loop(false),
	m_attenuation(0.8f),
	m_volume(1.0f),
	m_pitch(1.0f),
	m_spatialType(Type::ThreeD) {}

AudioSource::~AudioSource()
{
	delete m_clip;
}

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

void AudioSource::SetDestroyOnEnd(bool destroyOnEnd)
{
	m_destroyOnEnd = destroyOnEnd;
}

void AudioSource::SetSpatialBlend(Type spatialBlendType)
{
	//Cache the value for ourselves to use in the Update method
	m_spatialType = spatialBlendType;

	//Disable or enable spatialization based on the sound type
	switch (spatialBlendType)
	{
	case TwoD:
		m_clip->UseRelativePosition(true);
		m_clip->SetWorldPosition(glm::vec3(0.0));
		break;
	case ThreeD:
		m_clip->UseRelativePosition(false);
		break;
	}
}

void AudioSource::Play()
{
	if (m_clip != nullptr)
	{
		//Apply source volume, pitch and loop values
		m_clip->SetAttenuation(m_attenuation);
		m_clip->SetVolume(m_volume);
		m_clip->SetPitch(m_pitch);
		m_clip->SetLooping(m_loop);

		//Play the clip
		m_clip->Play();

		m_hasPlayedOnce = true;
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
		if (m_spatialType != Type::TwoD)
		{
			m_clip->SetWorldPosition(m_gameObject->GetTransform()->GetWorldPosition());
		}

		if (m_destroyOnEnd == true && m_hasPlayedOnce == true && m_clip->IsPlaying() == false)
		{
			SceneManager::Instance().GetActiveScene()->DestroyGameObject(m_gameObject);
		}
	}
}
