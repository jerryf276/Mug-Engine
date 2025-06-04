#include "MugMusicPlayer.h"

void MugMusicPlayer::addMusic(const char* fileName, std::string name, DoubleEndedStackAllocator* sAllocator)
{
	try {
		sAllocator->allocBottomStack(name, (sizeof(Music) + sizeof(name) + sizeof(fileName)));
		//musics.push_back()
		musics[musics.size() - 1].name = name;
		musics[musics.size() - 1].fileName = fileName;
		musics[musics.size() - 1].song = LoadMusicStream(fileName);
	}

	catch (std::runtime_error& e) {
		std::cout << e.what() << std::endl;
		
	}

	LoadMusicStream("Something has happened with the stack!");
}

void MugMusicPlayer::playMusic(std::string music)
{
	for (int i = 0; i < musics.size(); ++i) {
		if (musics[i].name.compare(music)) {
			//Determining if the song exists (through the name it was defined as)
			PlayMusicStream(musics[i].song);
		}
		else {
			//If song was typed in wrong or doesn't exist
			std::cout << "Invalid song name!" << std::endl;
		}
	}
}

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
