#pragma once


#include "Mug.h"

class Game : public mug::Application
{
public:
	void update(float dt) override final;
	void render() override final;

	void debug();

private:
	int test = 0;
//	void run() override final;
};

