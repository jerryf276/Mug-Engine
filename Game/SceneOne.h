#pragma once
#include "Game.h"
#include "InputComponent.h"
class SceneOne
{
public:
	SceneOne(Input* input, RenderSystem* renderSys, GameState * state, SoundFX * snd, MusicPlayer * muse);
	~SceneOne();

	void initialise();
	void update(float dt);
	void render();
	void debug();

private:
	DoubleEndedStackAllocator* stack = new DoubleEndedStackAllocator(size_t(10000));
	int test = 0;

	bool keyHit = false;
protected:

	Input* input;
	RenderSystem* renderer;
	GameState* gameState;
	SoundFX* sound;
	MusicPlayer* music;
	GameObject * player;
	Camera2D* camera;

};
