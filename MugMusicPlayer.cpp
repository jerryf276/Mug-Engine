#include "MugMusicPlayer.h"

void MugMusicPlayer::addMusic(char* fileName, std::string name, DoubleEndedStackAllocator* sAllocator)
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

	LoadMusicStream("Something has happened with the stack! Music not added!");
}

bool MugMusicPlayer::isMusicPlaying(Music music)
{
	if (isMusicPlaying(music)) {
		return true;
	}
	return false;
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

void MugMusicPlayer::pauseMusic(std::string music)
{
	for (int i = 0; i < musics.size(); ++i) {
		if (musics[i].name.compare(music)) {
			//Determining if the song exists (through the name it was defined as)
			//PlayMusicStream(musics[i].song);
			if (isMusicPlaying(musics[i].song)) {
				PauseMusicStream(musics[i].song);
			}
			else {
				std::cout << "Specified song isn't playing at the moment so it can't be paused!" << std::endl;
			}
		}
		else {
			//If song was typed in wrong or doesn't exist
			std::cout << "Invalid song name!" << std::endl;
		}
	}
}

void MugMusicPlayer::resumeMusic(std::string music)
{
	for (int i = 0; i < musics.size(); ++i) {
		if (musics[i].name.compare(music)) {
			//Determining if the song exists (through the name it was defined as)
			//PlayMusicStream(musics[i].song);
			if (!isMusicPlaying(musics[i].song)) {
				//PauseMusicStream(musics[i].song);
				ResumeMusicStream(musics[i].song);
			}
			else {
				std::cout << "Specified song isn't playing at the moment so it can't be paused!" << std::endl;
			}
		}
		else {
			//If song was typed in wrong or doesn't exist
			std::cout << "Invalid song name!" << std::endl;
		}
	}
}

void MugMusicPlayer::stopMusic(std::string music)
{
	for (int i = 0; i < musics.size(); ++i) {
		if (musics[i].name.compare(music)) {
			//Determining if the song exists (through the name it was defined as)
			//PlayMusicStream(musics[i].song);
			StopMusicStream(musics[i].song);
		}
		else {
			//If song was typed in wrong or doesn't exist
			std::cout << "Invalid song name!" << std::endl;
		}
	}
}

void MugMusicPlayer::setMusicVolume(std::string music, float volume)
{
	for (int i = 0; i < musics.size(); ++i) {
		if (musics[i].name.compare(music)) {
			//Determining if the song exists (through the name it was defined as)
			//PlayMusicStream(musics[i].song);
			SetMusicVolume(musics[i].song, volume / 100);
		}
		else {
			//If song was typed in wrong or doesn't exist
			std::cout << "Invalid song name!" << std::endl;
		}
	}
}

void MugMusicPlayer::setMusicPitch(std::string music, float volume)
{
	for (int i = 0; i < musics.size(); ++i) {
		if (musics[i].name.compare(music)) {
			//Determining if the song exists (through the name it was defined as)
			//PlayMusicStream(musics[i].song);
			SetMusicPitch(musics[i].song, volume / 100);
		}
		else {
			//If song was typed in wrong or doesn't exist
			std::cout << "Invalid song name!" << std::endl;
		}
	}
}

void MugMusicPlayer::setMusicPan(std::string music, float pan)
{
	for (int i = 0; i < musics.size(); ++i) {
		if (musics[i].name.compare(music)) {
			//Determining if the song exists (through the name it was defined as)
			//PlayMusicStream(musics[i].song);
			SetMusicPan(musics[i].song, pan / 100);
		}
		else {
			//If song was typed in wrong or doesn't exist
			std::cout << "Invalid song name!" << std::endl;
		}
	}
}

float MugMusicPlayer::getMusicTimeLength(std::string music)
{
	for (int i = 0; i < musics.size(); ++i) {
		if (musics[i].name.compare(music)) {
			//Determining if the song exists (through the name it was defined as)
			//PlayMusicStream(musics[i].song);
			//SetMusicPan(musics[i].song, pan / 100);
			return GetMusicTimeLength(musics[i].song);
		}
		else {
			//If song was typed in wrong or doesn't exist
			std::cout << "Invalid song name!" << std::endl;
		}
	}
	return 0.0f;
}

float MugMusicPlayer::getMusicTimePlayed(std::string music)
{
	for (int i = 0; i < musics.size(); ++i) {
		if (musics[i].name.compare(music)) {
			//Determining if the song exists (through the name it was defined as)
			//PlayMusicStream(musics[i].song);
			//SetMusicPan(musics[i].song, pan / 100);
			return GetMusicTimePlayed(musics[i].song);
		}
		else {
			//If song was typed in wrong or doesn't exist
			std::cout << "Invalid song name!" << std::endl;
		}
	}
	return 0.0f;
}

void MugMusicPlayer::updateMusicStream(std::string music)
{
	for (int i = 0; i < musics.size(); ++i) {
		if (musics[i].name.compare(music)) {
			//Determining if the song exists (through the name it was defined as)
		}
		else {
			//If song was typed in wrong or doesn't exist
			std::cout << "Invalid song name!" << std::endl;
		}
	}
}

//
//void MugMusicPlayer::setMusic(Music muse)
//{
//	music = muse;
//}
//
//Music MugMusicPlayer::getMusic()
//{
//	return music;
//}
