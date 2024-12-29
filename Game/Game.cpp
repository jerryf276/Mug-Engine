#include "Game.h"
#include "RenderSystem.h"
#include <iostream>

mug::Application* mug::createApp()
{
	return new Game();
}


Game::Game()
{
	//renderer = new RenderSystem();
	
//	renderSystem->setTargetFPS(60);
}

Game::~Game()
{
	delete renderer;
}


void Game::update(float deltaTime)
{
	return;
}

void Game::render(RenderSystem * renderSys)
{
	renderer = renderSys;
	renderer->clearBackground(RED);

	//std::cout << renderSystem->getFPS() << std::endl;
	//s/td::cout << "Hello, world!" << std::endl;

	//int x = renderer->getFPS();
//	std::cout << x << std::endl;

	debug();
	
}

void Game::debug()
{
	//ImGui stuff goes here!
	rlImGuiBegin();
	ImGui::Begin("Debug", NULL);
	ImGui::Text("Hello, world!");
	ImGui::Text("FPS: %d", renderer->getFPS());
	ImGui::End();
	rlImGuiEnd();

}


