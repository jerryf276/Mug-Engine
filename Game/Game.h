#pragma once


#include "Mug.h"
#include "GameState.h"
class SceneOne;
class SceneTwo;


class Game : public mug::Application
{
public:
	void update(float dt) override final;
	void render() override final;
	void initialise() override final;

	//void debug();

	Game(RenderSystem * renderSys, Input * input);
	~Game();

private:
	DoubleEndedStackAllocator* stack = new DoubleEndedStackAllocator(size_t(10000));
	int test = 0;
	//RenderSystem* renderer = new RenderSystem();
	bool keyHit = false;
	
	MusicPlayer* musicPlayer;
	SoundFX* soundFX;

	SceneOne* sceneOne;
	SceneTwo* sceneTwo;
	GameState* gameState;


//	void run() override final;
};

