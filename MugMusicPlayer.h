#include "raylib.h"
#include "DoubleEndedStackAllocator.h"
#include <vector>
class MugMusicPlayer
{
public:
	//Music
	void playMusic(std::string);
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

	void addMusic(const char* fileName, std::string name, DoubleEndedStackAllocator* sAllocator);


private:
	//Music music;
	//MugMusicPlayer musicPlayer;
	//std::vector<Music> musics;\

	std::vector<Song> musics;
	//std::vector<std::string> musicNames;
	//Music:
	//Contains filename, name, and data
protected:

};

struct Song {
	Music song;
	std::string name;
	const char* fileName;
};
