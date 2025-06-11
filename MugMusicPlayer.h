#include "raylib.h"
#include "DoubleEndedStackAllocator.h"
#include <vector>

struct Song {
	Music song;
	std::string name;
	char* fileName;
};

class MugMusicPlayer
{
public:
	//Music
	void playMusic(std::string);
	void pauseMusic(std::string);
	void resumeMusic(std::string);
	void stopMusic(std::string);
	void setMusicVolume(std::string, float);
	void setMusicPitch(std::string, float);
	void setMusicPan(std::string, float);

	float getMusicTimeLength(std::string);
	float getMusicTimePlayed(std::string);

	void updateMusicStream(std::string);
	//void setMusic(Music);
	//Music getMusic();

	void addMusic(char* fileName, std::string name, DoubleEndedStackAllocator* sAllocator);


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
