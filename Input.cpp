#include "Input.h"

bool Input::isKeyDown(MugKey key)
{
    //Static cast to keyboardkey if doesn't work
    if (IsKeyDown(key)) {
        return true;
    }
}

bool Input::isKeyPressed(MugKey key)
{
    //Static cast to keyboardkey if doesn't work
    return IsKeyPressed(key);
}

bool Input::isKeyPressedAgain(MugKey key)
{
	if (isKeyPressedAgain(key)) {
		return true;
    }
    return false;
}

bool Input::isMousePressed(MugMouse button)
{
    if (IsMouseButtonPressed(static_cast<int>(button))) {
        return true;
    }
    return false;
}

bool Input::isMouseDown(MugMouse button)
{
    if (IsMouseButtonDown(static_cast<int>(button))) {
        return true;
    }
    return false;
}

bool Input::isMouseUp(MugMouse button)
{
    if (IsMouseButtonUp(static_cast<int>(button))) {
        return true;
    }
    return false;
}

bool Input::isMouseReleased(MugMouse button)
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


