#pragma once
#include "raylib.h"
#include "DoubleEndedStackAllocator.h"
#include <iostream>
#include "GameObject.h"
class Component

{
public:
//	Component() = default;
	Component(GameObject* gameObject) : mugGameObject(gameObject) {}
	//Component(const Component& copy);
//	Component(Component&& move) noexcept;
	virtual ~Component() {}
	//virtual void initialise() = 0;
	virtual void start() = 0;
	virtual void update(float dt) = 0;
//	virtual void render() = 0;
	virtual void fixedStart() = 0;
private:
	//	GameObject* const m_GameObject;
protected:
	GameObject* mugGameObject;
};

