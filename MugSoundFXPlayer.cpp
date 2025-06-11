#include "MugSoundFXPlayer.h"

void MugSoundFXPlayer::addSound(char* fileName, std::string name, DoubleEndedStackAllocator* sAllocator)
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

void MugSoundFXPlayer::stopSound(std::string name)
{
	for (int i = 0; i < soundEffects.size(); ++i) {
		if (soundEffects[i].name.compare(name))
		{
			//PlaySound(soundEffects[i].soundEffect);
			StopSound(soundEffects[i].soundEffect);
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
			else {
				std::cout << "This sound can't be paused since it's not playing right now!";
			}
		}
		else {
			std::cout << "Sound effect name doesn't exist!" << std::endl;
		}
	}
}

void MugSoundFXPlayer::resumeSound(std::string name)
{
	for (int i = 0; i < soundEffects.size(); ++i) {
		if (soundEffects[i].name.compare(name))
		{
			//PlaySound(soundEffects[i].soundEffect);
			if (!isSoundPlaying(soundEffects[i].soundEffect)) {
				ResumeSound(soundEffects[i].soundEffect);
			}
			else {
				std::cout << "Can't resume a sound that is playing!";
			}
		}
		else {
			std::cout << "Sound effect name doesn't exist!" << std::endl;
		}
	}
}

void MugSoundFXPlayer::setSoundVolume(std::string name, float volumeCount)
{
	for (int i = 0; i < soundEffects.size(); ++i) {
		if (soundEffects[i].name.compare(name))
		{
			//PlaySound(soundEffects[i].soundEffect);
			//StopSound(soundEffects[i].soundEffect);
			SetSoundVolume(soundEffects[i].soundEffect, volumeCount / 100);
		}
		else {
			std::cout << "Sound effect name doesn't exist!" << std::endl;
		}
	}
}

void MugSoundFXPlayer::setSoundPitch(std::string name, float pitch)
{
	for (int i = 0; i < soundEffects.size(); ++i) {
		if (soundEffects[i].name.compare(name))
		{
			SetSoundPitch(soundEffects[i].soundEffect, pitch / 100);
		}
		else {
			std::cout << "Sound effect name doesn't exist!" << std::endl;
		}
	}
}

void MugSoundFXPlayer::setSoundPan(std::string name, float pan)
{
	for (int i = 0; i < soundEffects.size(); ++i) {
		if (soundEffects[i].name.compare(name))
		{
			SetSoundPan(soundEffects[i].soundEffect, pan / 100);
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
