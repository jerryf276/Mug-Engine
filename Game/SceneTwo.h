#pragma once
#include "Game.h"
class SceneTwo
{
public:
	SceneTwo(Input* input, RenderSystem* renderSys, GameState* state, SoundFX* snd, MusicPlayer* muse);
	~SceneTwo();

	void update(float dt);
	void render();
	void debug();

private:

protected:
	Input* input;
	RenderSystem* renderer;
	GameState* gameState;
	SoundFX* sound;
	MusicPlayer* music;

};

