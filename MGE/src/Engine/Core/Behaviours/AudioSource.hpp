#pragma once
#include <Behaviours\AbstractBehaviour.hpp>
#include <Audio\AudioClip.hpp>
#include <memory>

class AudioClip;

class AudioSource final : public AbstractBehaviour
{
public:
	AudioSource();

	void SetAudioClip(AudioClip* audioClip);

	void SetPlayOnAwake(bool playOnAwake);

	void SetSpatialBlend(float spatialBlend);

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
	bool m_loop;

	float m_attenuation;
	float m_volume;
	float m_pitch;

	float m_minDistance;
};