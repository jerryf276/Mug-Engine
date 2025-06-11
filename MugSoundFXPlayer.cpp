#include "MugSoundFXPlayer.h"

void MugSoundFXPlayer::addMusic(char* fileName, std::string name, DoubleEndedStackAllocator* sAllocator)
{
	try {
		sAllocator->allocBottomStack(name, sizeof(Sound) + sizeof(name) + sizeof(fileName));
		soundEffects[soundEffects.size() - 1].name = name;
		soundEffects[soundEffects.size() - 1].fileName = fileName;
		soundEffects[soundEffects.size() - 1].soundEffect = LoadSound(fileName);
	}

	catch (std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}

	LoadMusicStream("Something has happened with the stack! Music not added!");
}

void MugSoundFXPlayer::playSound(std::string name)
{
	for (int i = 0; i < soundEffects.size(); ++i) {
		if (soundEffects[i].name.compare(name)) 
		{
			PlaySound(soundEffects[i].soundEffect);
		}
		else {
			std::cout << "Sound effect name doesn't exist!" << std::endl;
		}
	}
}

void MugSoundFXPlayer::pauseSound(std::string name)
{
	for (int i = 0; i < soundEffects.size(); ++i) {
		if (soundEffects[i].name.compare(name))
		{
			//PlaySound(soundEffects[i].soundEffect);
			if (isSoundPlaying(soundEffects[i].soundEffect)) {
				PauseSound(soundEffects[i].soundEffect);
			}
		}
		else {
			std::cout << "Sound effect name doesn't exist!" << std::endl;
		}
	}
}

bool MugSoundFXPlayer::isSoundPlaying(Sound sound)
{
	if (IsSoundPlaying(sound))
	{
		return true;
	}
	return false;
}
