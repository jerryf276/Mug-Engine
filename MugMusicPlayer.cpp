#include "MugMusicPlayer.h"

void MugMusicPlayer::playMusic(Music music)
{
	PlayMusicStream(music);
}

void MugMusicPlayer::stopMusic(Music music)
{
	StopMusicStream(music);
}

void MugMusicPlayer::pauseMusic(Music music)
{
	PauseMusicStream(music);
}

void MugMusicPlayer::resumeMusic(Music music)
{
	ResumeMusicStream(music);
}

bool MugMusicPlayer::isMusicPlaying(Music music)
{
	return IsMusicStreamPlaying(music);
}

void MugMusicPlayer::setMusicVolume(Music music, float volume)
{
	SetMusicVolume(music, volume / 100);
}

void MugMusicPlayer::setMusicPitch(Music music, float volume)
{
	SetMusicPitch(music, volume / 100);
}

void MugMusicPlayer::setMusicPan(Music music, float pan)
{
	SetMusicPan(music, pan / 100);
}

Music MugMusicPlayer::loadMusicStream(const char* fileName, const std::string& givenName, DoubleEndedStackAllocator* sAllocator)
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

void MugMusicPlayer::unloadMusicStream(Music music)
{
	UnloadMusicStream(music);
}

float MugMusicPlayer::getMusicTimeLength(Music music)
{
	return GetMusicTimeLength(music);
}

float MugMusicPlayer::getMusicTimePlayed(Music music)
{
	return GetMusicTimePlayed(music);
}

void MugMusicPlayer::updateMusicStream(Music music)
{
	UpdateMusicStream(music);
}

void MugMusicPlayer::setMusic(Music muse)
{
	music = muse;
}

Music MugMusicPlayer::getMusic()
{
	return music;
}

void MugMusicPlayer::addMusic(const char* fileName, std::string name)
{

}
