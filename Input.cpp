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
