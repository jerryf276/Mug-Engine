#pragma once
#include "Component.h"
#include <math.h>
class TransformComponent : public Component
{
public:
	TransformComponent(GameObject * owner);
	~TransformComponent();

	void start() override;
	void update(float dt) override;
	//void render() override;
	void initialise(Vector2 position, Vector2 size);
	void initialise(Vector2 position, Vector2 size, Vector2 origin);
	void fixedStart() override;

	void setPosition(Vector2 pos);
	Vector2 getPosition();

	void setSpeed(Vector2 vel);
	Vector2 getSpeed();

	Vector2 normalise(Vector2* vec);


private:
	Vector2 position;
	Vector2 size;
	Vector2 origin;
	Vector2 speed;


protected:

};

