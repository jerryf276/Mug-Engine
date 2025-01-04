#include "TransformComponent.h"

TransformComponent::TransformComponent(GameObject * owner) : Component(owner)
{
	position.x = 0;
	position.y = 0;
	origin.x = 0;
	origin.y = 0;
	size.x = 0;
	size.y = 0;

}

TransformComponent::~TransformComponent()
{
}

Vector2 TransformComponent::normalise(Vector2* vec)
{
	float length = sqrt((vec->x * vec->x) + (vec->y * vec->y));
	vec->x = vec->x / length;
	vec->y = vec->y / length;
	return {vec->x, vec->y};
}

void TransformComponent::start()
{

}

void TransformComponent::update(float dt)
{
	//this->position.x += velocity.x * dt;
	//this->position.y += velocity.y * dt;

}

void TransformComponent::initialise(Vector2 position, Vector2 size)
{
	this->position = position;
	this->size = size;
	this->origin = { 0,0 };


}

void TransformComponent::initialise(Vector2 position, Vector2 size, Vector2 origin)
{
	this->position = position;
	this->size = size;
	this->origin = origin;
}

void TransformComponent::fixedStart()
{

}

void TransformComponent::setPosition(Vector2 pos)
{
	position = pos;
}

Vector2 TransformComponent::getPosition()
{
	return position;
}

void TransformComponent::setSpeed(Vector2 spd)
{
	speed = spd;
}

Vector2 TransformComponent::getSpeed()
{
	return speed;
}
