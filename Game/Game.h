#pragma once


#include "Mug.h"

class Game : public mug::Application
{
public:
	void update(float dt) override final;
	void render(RenderSystem * renderSys) override final;

	void debug();

	Game();
	~Game();

private:
	int test = 0;
	RenderSystem* renderer = new RenderSystem();

//	void run() override final;
};

