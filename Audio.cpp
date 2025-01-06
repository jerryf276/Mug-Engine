#include "Audio.h"

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

Sound SoundFX::loadSound(const char* fileName, const std::string& givenName, DoubleEndedStackAllocator* sAllocator)
{
	try {
		sAllocator->allocBottomStack(givenName, sizeof(Sound));
		return LoadSound(fileName);
	}
	catch (std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}
	return LoadSound("There is issues with the stack!");
}

void SoundFX::unloadSound(Sound sound)
{
	UnloadSound(sound);

}

Sound SoundFX::getSound()
{
	return sound;
}

void SoundFX::setSound(Sound sound)
{
	this->sound = sound;
}

//void SoundFX::setSound(Sound snd)
//{
//	sound = snd;
//}



void MusicPlayer::playMusic(Music music)
{
	PlayMusicStream(music);
}

void MusicPlayer::stopMusic(Music music)
{
	StopMusicStream(music);
}

void MusicPlayer::pauseMusic(Music music)
{
	PauseMusicStream(music);
}

void MusicPlayer::resumeMusic(Music music)
{
	ResumeMusicStream(music);
}

bool MusicPlayer::isMusicPlaying(Music music)
{
	return IsMusicStreamPlaying(music);
}

void MusicPlayer::setMusicVolume(Music music, float volume)
{
	SetMusicVolume(music, volume / 100);
}

void MusicPlayer::setMusicPitch(Music music, float volume)
{
	SetMusicPitch(music, volume / 100);
}

void MusicPlayer::setMusicPan(Music music, float pan)
{
	SetMusicPan(music, pan / 100);
}

Music MusicPlayer::loadMusicStream(const char* fileName, const std::string& givenName, DoubleEndedStackAllocator* sAllocator)
{
	try {
		sAllocator->allocBottomStack(givenName, sizeof(Music));
		return LoadMusicStream(fileName);
	}
	catch (std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}
	return LoadMusicStream("Something has happened with the stack!");
}

void MusicPlayer::unloadMusicStream(Music music)
{
	UnloadMusicStream(music);
}

float MusicPlayer::getMusicTimeLength(Music music)
{
	return GetMusicTimeLength(music);
}

float MusicPlayer::getMusicTimePlayed(Music music)
{
	return GetMusicTimePlayed(music);
}

void MusicPlayer::updateMusicStream(Music music)
{
	UpdateMusicStream(music);
}

void MusicPlayer::setMusic(Music muse)
{
	music = muse;
}

Music MusicPlayer::getMusic()
{
	return music;
}

void SoundFX::resumeSound(Sound sound)
{
	ResumeSound(sound);
}
