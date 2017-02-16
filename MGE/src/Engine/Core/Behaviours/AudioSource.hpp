#pragma once
#include <Behaviours\AbstractBehaviour.hpp>
#include <Audio\AudioClip.hpp>
#include <memory>

class AudioClip;

class AudioSource final : public AbstractBehaviour
{
public:
	enum Type
	{
		TwoD, ThreeD
	};

	AudioSource();
	~AudioSource();

	void SetAudioClip(AudioClip* audioClip);

	void SetPlayOnAwake(bool playOnAwake);
	void SetDestroyOnEnd(bool destroyOnEnd);

	void SetSpatialBlend(Type spatialBlendType);

	void Play();
	void Pause();
	void Stop();

	void PlayOneShot(AudioClip& audioClip);

	void SetLooping(bool loop);

	void SetAttenuation(float attenuation);
	void SetVolume(float volume);
	void SetPitch(float pitch);
	void Seek(float normalizedTime);

	void Awake() override final;
	void Update() override final;
private:
	AudioClip* m_clip;

	bool m_playOnAwake;
	bool m_destroyOnEnd;
	
	bool m_hasPlayedOnce;

	bool m_loop;

	float m_attenuation;
	float m_volume;
	float m_pitch;

	Type m_spatialType;
};