#include "InputComponent.h"

void InputComponent::update(float dt)
{
	Vector2 vec;
	Vector2 velocity;
	if (input->isKeyDown(MUG_KEY_A)) {
		vec.x = -1;
	}
	else if (input->isKeyDown(MUG_KEY_D)) {
		vec.x = 1;
	}
	else {
		vec.x = 0;
	}

	if (input->isKeyDown(MUG_KEY_W)) {
		vec.y = -1;
	}
	else if (input->isKeyDown(MUG_KEY_S)) {
		vec.y = 1;
	}
	else {
		vec.y = 0;
	}

	if (vec.x != 0 || vec.y != 0) {
		Vector2 direction = transform->normalise(&vec);
		velocity = { direction.x * transform->getSpeed().x, direction.y * transform->getSpeed().y };


	//	transform->setVelocity(vec);
	}
	else {
		velocity = { 0,0 };
	}

	transform->setPosition({ transform->getPosition().x + (velocity.x * dt), transform->getPosition().y + (velocity.y * dt) });
	
}

void InputComponent::start()
{

}

void InputComponent::fixedStart()
{

}

void InputComponent::initialise(Input * input)
{
	transform = mugGameObject->GetComponent<TransformComponent>();
	this->input = input;

}

InputComponent::InputComponent(GameObject* owner) : Component(owner)
{

}

InputComponent::~InputComponent()
{

}

