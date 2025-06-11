#pragma once
#include "raylib.h"
#include "DoubleEndedStackAllocator.h"
#include <vector>

struct soundFX {
	Sound soundEffect;
	std::string name;
	char* fileName;
};


class MugSoundFXPlayer
{
public:
	//Sound
	void playSound(std::string);
	void stopSound(std::string);
	void pauseSound(std::string);
	void resumeSound(std::string);
	void playSound(Sound);
	void stopSound(Sound);
	void pauseSound(Sound);
	void resumeSound(Sound);
	bool isSoundPlaying(Sound);
	void setSoundVolume(Sound, float); //Set the volume of a sound, loudest volume is 100.0f
	void setSoundPitch(Sound, float); //Set the pitch of a sound, highest pitch is 100.0f
	void setSoundPan(Sound, float); //Set the pan of a sound, left is 0.0f, right is 100.0f
	//Sound loadSound(const char* fileName, const std::string& givenName, DoubleEndedStackAllocator* sAllocator);
	void unloadSound(Sound);

	//Sound getSound();
	void setSound(Sound sound);

	void addMusic(char* fileName, std::string name, DoubleEndedStackAllocator* sAllocator);
private:
	std::vector<soundFX> soundEffects;
protected:

};

