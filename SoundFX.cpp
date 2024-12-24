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

Sound SoundFX::loadSound(const char* fileName)
{
	return LoadSound(fileName);
}

void SoundFX::playMusic(Music music)
{
	PlayMusicStream(music);
}

void SoundFX::stopMusic(Music music)
{
	StopMusicStream(music);
}

void SoundFX::pauseMusic(Music music)
{
	PauseMusicStream(music);
}

void SoundFX::resumeMusic(Music music)
{
	ResumeMusicStream(music);
}

bool SoundFX::isMusicPlaying(Music music)
{
	return isMusicPlaying(music);
}

void SoundFX::setMusicVolume(Music music, float volume)
{
	SetMusicVolume(music, volume / 100);
}

void SoundFX::setMusicPitch(Music music, float volume)
{
	SetMusicPitch(music, volume / 100);
}

void SoundFX::setMusicPan(Music music, float pan)
{
	SetMusicPan(music, pan / 100);
}

Music SoundFX::loadMusicStream(const char* fileName)
{
	return LoadMusicStream(fileName);
}

void SoundFX::unloadMusicStream(Music music)
{
	UnloadMusicStream(music);
}

float SoundFX::getMusicTimeLength(Music music)
{
	return GetMusicTimeLength(music);
}

float SoundFX::getMusicTimePlayed(Music music)
{
	return GetMusicTimePlayed(music);
}

void SoundFX::resumeSound(Sound sound)
{
	ResumeSound(sound);
}
