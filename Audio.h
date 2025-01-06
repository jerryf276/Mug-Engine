#pragma once
#include "raylib.h"
#include "DoubleEndedStackAllocator.h"
#include <string>
#include <stdexcept>
#include <vector>
class SoundFX
{
public:

	//Sound
	void playSound(Sound);
	void stopSound(Sound);
	void pauseSound(Sound);
	void resumeSound(Sound);
	bool isSoundPlaying(Sound);
	void setSoundVolume(Sound, float); //Set the volume of a sound, loudest volume is 100.0f
	void setSoundPitch(Sound, float); //Set the pitch of a sound, highest pitch is 100.0f
	void setSoundPan(Sound, float); //Set the pan of a sound, left is 0.0f, right is 100.0f
	Sound loadSound(const char* fileName, const std::string & givenName, DoubleEndedStackAllocator* sAllocator);
	void unloadSound(Sound);

	Sound getSound();
	void setSound(Sound sound);

private:
	Sound sound;
//	std::vector<Sound> sounds;

protected:

};

class MusicPlayer
{
public:
	//Music
	void playMusic(Music);
	void stopMusic(Music);
	void pauseMusic(Music);
	void resumeMusic(Music);
	bool isMusicPlaying(Music);
	void setMusicVolume(Music, float); //Set the volume of a music, loudest volume is 100.0f
	void setMusicPitch(Music, float); //Set the pitch of a music, highest pitch is 100.0f
	//	void setMusicLoopCount(Music, int); //Set the loop count of a music, -1 is infinite
	void setMusicPan(Music, float); //Set the pan of a music, left is 0.0f, right is 100.0f
	Music loadMusicStream(const char* fileName, const std::string& givenName, DoubleEndedStackAllocator* sAllocator);
	void unloadMusicStream(Music);
	float getMusicTimeLength(Music music);
	float getMusicTimePlayed(Music music);
	void updateMusicStream(Music music);

	void setMusic(Music);
	Music getMusic();
private:
	Music music;
	std::vector<Music> musics;
protected:

};
