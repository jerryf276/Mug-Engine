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
	void setSoundVolume(std::string, float);
	void setSoundPitch(std::string, float);
	void setSoundPan(std::string, float);


	//Is this function needed?
	void unloadSound(std::string);

	void addSound(char* fileName, std::string name, DoubleEndedStackAllocator* sAllocator);
private:
	std::vector<soundFX> soundEffects;
protected:

};

