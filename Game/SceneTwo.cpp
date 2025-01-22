#include "SceneTwo.h"

SceneTwo::SceneTwo(Input* input, RenderSystem* renderSys, GameState* state, SoundFX* snd, MusicPlayer* muse)
{
	this->input = input;
	this->renderer = renderSys;
	this->gameState = state;
	this->sound = snd;
	this->music = muse;
}

SceneTwo::~SceneTwo()
{
	delete input;
	delete renderer;
	delete gameState;
	delete sound;
	delete music;
}

void SceneTwo::initialise()
{

}

void SceneTwo::update(float dt)
{
	if (input->isKeyPressed(MUG_KEY_O)) {
		gameState->setCurrentState(State::SCENE_ONE);
	}
	else if (input->isKeyPressed(MUG_KEY_ESCAPE)) {
		gameState->setCurrentState(State::EXIT);
	}
}

void SceneTwo::render()
{
	renderer->clearBackground(RED);
	renderer->drawText("Welcome to scene two! ", 300, 300, 20, BLACK);
//	renderer->drawText("Press O to switch back to scene one!", 300, 600, 40, BLACK);
	debug();
}

void SceneTwo::debug()
{
	rlImGuiBegin();
	ImGui::Begin("Debug", NULL);
	ImGui::Text("FPS: %d", GetFPS());
	ImGui::End();
	rlImGuiEnd();
}
