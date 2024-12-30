#include "Game.h"
#include "RenderSystem.h"
#include <iostream>

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
	soundFX->setSound(soundFX->loadSound("Game/Assets/Audio/coin.wav", "coin", stack));
	//soundFX->loadSound("Game/Assets/Audio/coin.wav", "coin", stack);
	//musicPlayer->loadMusicStream("Game/Assets/Audio/cisco-default-hold-music-[hq-mono-audio]-opus-number-1-made-with-Voicemod.mp3", "music", stack);

	musicPlayer->setMusic(musicPlayer->loadMusicStream("Game/Assets/Audio/cisco-default-hold-music-[hq-mono-audio]-opus-number-1-made-with-Voicemod.mp3", "music", stack));

	
	//musicPlayer->loadMusicStream("Assets/Audio/cisco-default-hold-music-[hq-mono-audio]-opus-number-1-made-with-Voicemod.mp3", "music", stack);

	
//	renderSystem->setTargetFPS(60);
}

Game::~Game()
{
	delete renderer;
}


void Game::update(float deltaTime)
{
	musicPlayer->updateMusicStream(musicPlayer->getMusic());
	if (input->isKeyPressed(MUG_KEY_B))
	{
		soundFX->playSound(soundFX->getSound());
	}

	if (!musicPlayer->isMusicPlaying(musicPlayer->getMusic())) {
		musicPlayer->playMusic(musicPlayer->getMusic());
	}
}

void Game::render()
{
	//renderer = renderSys;
	renderer->clearBackground(RED);

	if (keyHit == false) {
		if (input->isKeyPressed(MUG_KEY_A))
		{
			keyHit = true;
			//renderer->drawText("A is pressed", 10, 10, 20, BLACK);
		}
	}
	else {
		if (input->isKeyPressed(MUG_KEY_A))
		{
			keyHit = false;
		}
		
		else {
			renderer->drawText("A is pressed", 10, 10, 20, BLACK);
		}
	}

	//if (input->isKeyPressed(MUG_KEY_B))
	//{
	//	soundFX->playSound(soundFX->getSound());
	//}	

	//if (!musicPlayer->isMusicPlaying(musicPlayer->getMusic())) {
	//	musicPlayer->playMusic(musicPlayer->getMusic());
	//}
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


