#pragma once
#include "raylib.h"
class SoundFX
{
public:
	void playSound(Sound);
	void stopSound(Sound);
	void pauseSound(Sound);
	void resumeSound(Sound);
	void pauseSound(Sound);
	bool isSoundPlaying(Sound);
	void setSoundVolume(Sound, float); //Set the volume of a sound, loudest volume is 100.0f
	void setSoundPitch(Sound, float); //Set the pitch of a sound, highest pitch is 100.0f
	void setSoundPan(Sound, float); //Set the pan of a sound, left is 0.0f, right is 100.0f
	Sound loadSound(const char* fileName);

private:

protected:

};

