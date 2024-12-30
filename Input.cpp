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
    return IsKeyPressedRepeat(key);
}

//bool Input::keyToggle(MugKey key)
//{
//    //if (isKeyPressedAgain(key) == false) {
//    //    if (isKeyPressed(key)) {
//    //      //  keyToggler = true;
//    //        return true;
//    //    }
//    //    else {
//    //        return false;
//    //    }
//    //}
//
//    //if (isKeyPressedAgain(key) == true) {
//    //    return false;
//    //}
//	
//	//if (isKeyPressed(key)) {
// //       if (keyToggler[key] == false) {
//	//		keyToggler[key] = true;
//	//		return true;
//	//	}
// //       else {
//	//		keyToggler[key] = false;
//	//		return false;
//	//	}
//	//}
//	//return false;
//
//
//    if (isKeyPressed(key) && !keyPressedLastFrame[key]) {
//        keyToggler[key] = !keyToggler[key];
//    }
//
//	keyPressedLastFrame[key] = isKeyPressed(key);
//
//
//	return keyToggler[key];
//}


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

Input::Input()
{
 //   constexpr int maxKeyValue = 348;
	//keyToggler.resize(maxKeyValue + 1, false);
	//keyPressedLastFrame.resize(maxKeyValue + 1, false);


}


