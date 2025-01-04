#include "SpriteComponent.h"

SpriteComponent::SpriteComponent(GameObject* owner) : Component(owner), filename { " " }
{
	std::cout << "SpriteComponent created" << std::endl;
	if (!owner) {
		std::cout << "owner is null!" << std::endl;
	}
}

SpriteComponent::~SpriteComponent()
{

}

void SpriteComponent::initialise(const char * filename, std::string givenName, DoubleEndedStackAllocator* stack)
{
	sprite = loadTexture(filename, givenName, stack);
//	try {

//	}
//	this->filename = filename;
//	sprite = LoadTexture(this->filename);


}

void SpriteComponent::start()
{

}

void SpriteComponent::update(float dt)
{

}

void SpriteComponent::render()
{

}


void SpriteComponent::fixedStart()
{

}

Texture2D SpriteComponent::loadTexture(const char* filename, std::string givenName, DoubleEndedStackAllocator* stack)
{
	try {
		stack->allocTopStack(givenName, sizeof(Texture2D));
		return LoadTexture(filename);
	}
	catch (std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}
	return LoadTexture("There is issues with the stack!");
}
