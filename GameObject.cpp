#include "GameObject.h"
#include "Component.h"

GameObject::GameObject() : name{ "Game Object" }
{
	
}

GameObject::GameObject(std::string name) : name{ name }
{
	std::cout << "Made a game object with name: " << name << std::endl;
}

GameObject::GameObject(GameObject& toCopy) noexcept
{
	//gameID = toCopy.gameID;
	//name = toCopy.name;
	//game_Components = toCopy.game_Components;
}

GameObject::GameObject(GameObject&& toMove) noexcept : game_Components{ std::move(toMove.game_Components) }
{
	//gameID = toMove.gameID;
//	name = toMove.name;
	//game_Components = toMove.game_Components;
}

void GameObject::update(float dt)
{
	for (auto& c : game_Components) {
		c->update(dt);
	}

	
}

//void GameObject::render()
//{
//	for (auto& c : game_Components) {
//		c->render();
//	}
//
//}

void GameObject::start() {
	for (auto& c : game_Components) {
		c->start();
	}
}

//void GameObject::setGameID(int id)
//{
//	gameID = id;
//}
