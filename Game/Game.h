#pragma once


#include "Mug.h"

class Game : public mug::Application
{
public:
	void update(float dt) override final;
	void render() override final;

	void debug();

	Game(RenderSystem * renderSys, Input * input);
	~Game();

private:
	DoubleEndedStackAllocator* stack = new DoubleEndedStackAllocator(size_t(1000000));
	int test = 0;
	//RenderSystem* renderer = new RenderSystem();
	bool keyHit = false;
	
	MusicPlayer* musicPlayer;
	SoundFX* soundFX;


//	void run() override final;
};

