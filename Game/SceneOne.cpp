#include "SceneOne.h"

SceneOne::SceneOne(Input* input, RenderSystem* renderSys, GameState* state, SoundFX* snd, MusicPlayer* muse)
{
	
	this->input = input;
	this->renderer = renderSys;
	this->gameState = state;
	this->sound = snd;
	this->music = muse;


	sound->setSound(sound->loadSound("Game/Assets/Audio/coin.wav", "coin", stack));
	//stack->allocBottomStack("sound effect", sizeof(sound));
	//soundFX->loadSound("Game/Assets/Audio/coin.wav", "coin", stack);
	//musicPlayer->loadMusicStream("Game/Assets/Audio/cisco-default-hold-music-[hq-mono-audio]-opus-number-1-made-with-Voicemod.mp3", "music", stack);

	music->setMusic(music->loadMusicStream("Game/Assets/Audio/Cipher2.mp3", "music", stack));
	//stack->allocBottomStack("music", sizeof(music));


	player = new GameObject();
	//player->setTexture(renderer->loadTexture("Game/Assets/Textures/coin.png", "coin", stack));
	

	
}

void SceneOne::initialise()
{
	SpriteComponent* spriteComponent = player->AddComponent<SpriteComponent>();
	if (spriteComponent) {
		spriteComponent->initialise("Game/Assets/Images/Penguin-images-2/Animations/penguin_jump01.png", "Penguin Sprite", stack);
	}

	TransformComponent* transformComponent = player->AddComponent<TransformComponent>();
	if (transformComponent) {
		transformComponent->initialise({ 550, 340 }, { 100, 100 });
		transformComponent->setSpeed({ 120, 120 });
	}

	InputComponent* inputComponent = player->AddComponent<InputComponent>();
	if (inputComponent) {
		inputComponent->initialise(input);
	}


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

	player->update(dt);
}

void SceneOne::render()
{
	renderer->clearBackground({34, 214, 208, 255});

	if (keyHit == false) {
		if (input->isKeyPressed(MUG_KEY_G))
		{
			keyHit = true;
			//renderer->drawText("A is pressed", 10, 10, 20, BLACK);
		}
	}
	else {
		if (input->isKeyPressed(MUG_KEY_G))
		{
			keyHit = false;
		}
		
		else {
			renderer->drawText("G is pressed", 10, 10, 20, BLACK);
		}
	}
	/*player->render();*/
	renderer->render(player);
	debug();
}

void SceneOne::debug()
{
	//	//ImGui stuff goes here!
	rlImGuiBegin();
	ImGui::Begin("Debug", NULL);
	ImGui::Text("Hello, welcome to the debug menu!");
	ImGui::Text("FPS: %d", GetFPS());
	ImGui::End();
	rlImGuiEnd();
}
