#pragma once
#include "Component.h"
#include "TransformComponent.h"
#include "Input.h"
class InputComponent : public Component
{
public:
	void update(float dt) override;
	void start() override;
	void fixedStart() override;
	void initialise(Input* input);
	InputComponent(GameObject* owner);
	~InputComponent();

private:

protected:
	TransformComponent* transform;
	Input* input;
	//Vector2 velocity;
};

