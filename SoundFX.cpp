#include "SoundFX.h"

void SoundFX::playSound(Sound sound)
{
	PlaySound(sound);
}

void SoundFX::stopSound(Sound sound)
{
	StopSound(sound);
}

void SoundFX::pauseSound(Sound sound)
{
	PauseSound(sound);
}

bool SoundFX::isSoundPlaying(Sound sound)
{
	if (IsSoundPlaying(sound))
	{
		return true;
	}
	return false;
}

void SoundFX::setSoundVolume(Sound sound, float volume)
{
	SetSoundVolume(sound, volume / 100);
}

void SoundFX::setSoundPitch(Sound sound, float pitch)
{
	SetSoundPitch(sound, pitch / 100);
}

void SoundFX::setSoundPan(Sound sound, float pan)
{
	SetSoundPan(sound, pan / 100);
}

void SoundFX::resumeSound(Sound sound)
{
	ResumeSound(sound);
}
