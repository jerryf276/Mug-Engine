#include "Game.h"
#include "RenderSystem.h"
#include <iostream>
#include "SceneOne.h"
#include "SceneTwo.h"

mug::Application* mug::createApp(RenderSystem* renderSys, Input* input)
{
	return new Game(renderSys, input);
}


Game::Game(RenderSystem* renderSys, Input * ipt)
{
	renderer = renderSys;
	input = ipt;


	InitAudioDevice();
	musicPlayer = new MusicPlayer();
	soundFX = new SoundFX();
	gameState = new GameState();


	sceneOne = new SceneOne(input, renderer, gameState, soundFX, musicPlayer);
	sceneTwo = new SceneTwo(input, renderer, gameState, soundFX, musicPlayer);

	
	

	
	//musicPlayer->loadMusicStream("Assets/Audio/cisco-default-hold-music-[hq-mono-audio]-opus-number-1-made-with-Voicemod.mp3", "music", stack);

	gameState->setCurrentState(State::SCENE_ONE);
//	renderSystem->setTargetFPS(60);
}

Game::~Game()
{
	delete renderer;
}


void Game::initialise()
{
	//Feel free to change your window icon here!
	SetWindowIcon(LoadImage("Game/Assets/Images/logo.png"));

	sceneOne->initialise();
	sceneTwo->initialise();
}


void Game::update(float deltaTime)
{

	if (gameState->getCurrentState() == State::SCENE_ONE) {
		sceneOne->update(deltaTime);
	}
	else if (gameState->getCurrentState() == State::SCENE_TWO) {
		sceneTwo->update(deltaTime);
	}

	
}

void Game::render()
{

	if (gameState->getCurrentState() == State::SCENE_ONE) {
		sceneOne->render();
	}
	else if (gameState->getCurrentState() == State::SCENE_TWO) {
		sceneTwo->render();
	}
	else if (gameState->getCurrentState() == State::EXIT) {
		renderer->closeWindow();
	}
}



