#include "Input.h"

bool Input::isKeyDown(EnginoalyKey key)
{
    //Static cast to keyboardkey if doesn't work
    if (IsKeyDown(key)) {
        return true;
    }
}

bool Input::isKeyPressed(EnginoalyKey key)
{
    //Static cast to keyboardkey if doesn't work
    return IsKeyPressed(key);
}

bool Input::isKeyPressedAgain(EnginoalyKey key)
{
	if (isKeyPressedAgain(key)) {
		return true;
    }
    return false;
}

bool Input::isMousePressed(EnginoalyMouse button)
{
    if (IsMouseButtonPressed(static_cast<int>(button))) {
        return true;
    }
    return false;
}

bool Input::isMouseDown(EnginoalyMouse button)
{
    if (IsMouseButtonDown(static_cast<int>(button))) {
        return true;
    }
    return false;
}

bool Input::isMouseUp(EnginoalyMouse button)
{
    if (IsMouseButtonUp(static_cast<int>(button))) {
        return true;
    }
    return false;
}

bool Input::isMouseReleased(EnginoalyMouse button)
{
    if (IsMouseButtonReleased(static_cast<int>(button))) {
        return true;
    }
    return false;
}

Vector2 Input::getMousePosition()
{
    return GetMousePosition();
}

int Input::getMouseX()
{
    return GetMouseX();
}

int Input::getMouseY()
{
    return GetMouseY();
}

void Input::setMousePosition(int x, int y)
{
    SetMousePosition(x, y);
}

Vector2 Input::getMouseWheelMoveVector()
{
    return GetMouseWheelMoveV();
}

int Input::getMouseWheelMove()
{
    return GetMouseWheelMove();
}


