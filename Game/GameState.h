#pragma once

//Possible game states, if you wish to add more states, add them here to this enum class!
enum class State {
	MAIN_MENU,
	SCENE_ONE,
	SCENE_TWO,
	PAUSE,
	EXIT
};
class GameState
{
public:
	//Sets the current game state
	void setCurrentState(State state) {
		currentState = state;
	}
	//Returns the current game state
	State getCurrentState() {
		return currentState;
	}
private:
	State currentState;
};

