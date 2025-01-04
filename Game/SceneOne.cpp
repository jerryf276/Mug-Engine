#include "SceneOne.h"

SceneOne::SceneOne(Input* input, RenderSystem* renderSys, GameState* state, SoundFX* snd, MusicPlayer* muse)
{
	
	this->input = input;
	this->renderer = renderSys;
	this->gameState = state;
	this->sound = snd;
	this->music = muse;


	sound->setSound(sound->loadSound("Game/Assets/Audio/coin.wav", "coin", stack));
	//soundFX->loadSound("Game/Assets/Audio/coin.wav", "coin", stack);
	//musicPlayer->loadMusicStream("Game/Assets/Audio/cisco-default-hold-music-[hq-mono-audio]-opus-number-1-made-with-Voicemod.mp3", "music", stack);

	music->setMusic(music->loadMusicStream("Game/Assets/Audio/cisco-default-hold-music-[hq-mono-audio]-opus-number-1-made-with-Voicemod.mp3", "music", stack));

}

SceneOne::~SceneOne()
{

}

void SceneOne::update(float dt)
{
	if (input->isKeyPressed(MUG_KEY_P))
	{
		gameState->setCurrentState(State::SCENE_TWO);
	}
	else if (input->isKeyPressed(MUG_KEY_ESCAPE)) {
		gameState->setCurrentState(State::EXIT);
	}

	music->updateMusicStream(music->getMusic());

	if (input->isKeyPressed(MUG_KEY_B))
	{
		sound->playSound(sound->getSound());
	}

	if (!music->isMusicPlaying(music->getMusic())) {
		music->playMusic(music->getMusic());
	}
}

void SceneOne::render()
{
	renderer->clearBackground(BLUE);

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

	debug();
}

void SceneOne::debug()
{
	//	//ImGui stuff goes here!
	rlImGuiBegin();
	ImGui::Begin("Debug", NULL);
	ImGui::End();
	rlImGuiEnd();
}
