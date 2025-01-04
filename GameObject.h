#pragma once
#include <vector>
#include <utility>
#include <memory>
#include <iostream>
#include "UniquePointer.h"
#include "Input.h"
class Component;

class GameObject
{
public:
	GameObject();
	GameObject(std::string name);
	GameObject(GameObject& toCopy) noexcept;
	GameObject(GameObject&& toMove) noexcept;
	void update(float dt);
	//void render();

	void start();

	//Used for adding the input component to the game object

	template <class T>
	T* AddComponent() {
		T* component = new T(this);
		const type_info& tInfo = typeid(*component);
		for (int i = 0; i < game_Components.size(); ++i) {
			//Loops through every component already added to the game object
			const type_info& cInfo = typeid(*game_Components[i]);
			if (tInfo == cInfo) {
				//If the component was added already, return a nullptr.
				std::cout << "Error! Component has been added in twice!" << std::endl;
				return nullptr;
			}

		}

		//If the component has not been added, add it to the game object.
		game_Components.push_back(component);
		return(component);
	}

	template <class T>
	T* GetComponent() {
		const type_info& tInfo = typeid(T);
		for (auto& c : game_Components) {
			const type_info& cInfo = typeid(*c);
			if (cInfo == tInfo) {
				return static_cast<T*>(c);
			}
		}
		return nullptr;
	}
	template <class T>

	T* DeleteComponent() {
		const type_info& tInfo = typeid(T);
		for (auto& c : game_Components) {
			if (c) {
				const type_info& cInfo = typeid(*c);
				if (cInfo == tInfo) {
					c = nullptr;
					std::cout << "Component deleted!" << std::endl;
				}
			}
		}
		return nullptr;
	}

	//void setGameID(int);

	bool isAlive() {
		return alive;
	}
	void setAlive(bool a) {
		alive = a;
	}

private:
	//SmartPointer<Component> rawPointer;
	UniquePointer<Component> rawPointer;
	std::vector<Component*> game_Components;
	bool alive;
	std::string name;

//	int gameID;
protected:

};

