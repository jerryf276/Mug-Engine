#pragma once
#include "Component.h"
class SpriteComponent : public Component
{
public:
	SpriteComponent(GameObject * owner);
	~SpriteComponent();

	void initialise(const char* fileName, std::string givenName, DoubleEndedStackAllocator * stack);
	void start() override;
	void update(float dt) override;
	void render();
	void fixedStart() override;

	Texture2D getSprite() { return sprite; }
	void setSprite(Texture2D sprite) { this->sprite = sprite; }
	//void setSpritePosition(Vector2 pos) { position = pos; }
	//Vector2 getSpritePosition() { return position; }


private:
	//Vector2 position;
	//Vector2 spriteSize;
	Texture2D sprite;
	const char* filename;
	Texture2D loadTexture(const char* filename, std::string givenName, DoubleEndedStackAllocator* stack);
protected:
};

