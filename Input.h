#pragma once
#include "raylib.h"

typedef enum {
    ENGINOALY_KEY_NULL = 0,        // Key: NULL, used for no key pressed
    // Alphanumeric keys
    ENGINOALY_KEY_APOSTROPHE = 39,       // Key: '
    ENGINOALY_KEY_COMMA = 44,       // Key: ,
    ENGINOALY_KEY_MINUS = 45,       // Key: -
    ENGINOALY_KEY_PERIOD = 46,       // Key: .
    ENGINOALY_KEY_SLASH = 47,       // Key: /
    ENGINOALY_KEY_ZERO = 48,       // Key: 0
    ENGINOALY_KEY_ONE = 49,       // Key: 1
    ENGINOALY_KEY_TWO = 50,       // Key: 2
    ENGINOALY_KEY_THREE = 51,       // Key: 3
    ENGINOALY_KEY_FOUR = 52,       // Key: 4
    ENGINOALY_KEY_FIVE = 53,       // Key: 5
    ENGINOALY_KEY_SIX = 54,       // Key: 6
    ENGINOALY_KEY_SEVEN = 55,       // Key: 7
    ENGINOALY_KEY_EIGHT = 56,       // Key: 8
    ENGINOALY_KEY_NINE = 57,       // Key: 9
    ENGINOALY_KEY_SEMICOLON = 59,       // Key: ;
    ENGINOALY_KEY_EQUAL = 61,       // Key: =
    ENGINOALY_KEY_A = 65,       // Key: A | a
    ENGINOALY_KEY_B = 66,       // Key: B | b
    ENGINOALY_KEY_C = 67,       // Key: C | c
    ENGINOALY_KEY_D = 68,       // Key: D | d
    ENGINOALY_KEY_E = 69,       // Key: E | e
    ENGINOALY_KEY_F = 70,       // Key: F | f
    ENGINOALY_KEY_G = 71,       // Key: G | g
    ENGINOALY_KEY_H = 72,       // Key: H | h
    ENGINOALY_KEY_I = 73,       // Key: I | i
    ENGINOALY_KEY_J = 74,       // Key: J | j
    ENGINOALY_KEY_K = 75,       // Key: K | k
    ENGINOALY_KEY_L = 76,       // Key: L | l
    ENGINOALY_KEY_M = 77,       // Key: M | m
    ENGINOALY_KEY_N = 78,       // Key: N | n
    ENGINOALY_KEY_O = 79,       // Key: O | o
    ENGINOALY_KEY_P = 80,       // Key: P | p
    ENGINOALY_KEY_Q = 81,       // Key: Q | q
    ENGINOALY_KEY_R = 82,       // Key: R | r
    ENGINOALY_KEY_S = 83,       // Key: S | s
    ENGINOALY_KEY_T = 84,       // Key: T | t
    ENGINOALY_KEY_U = 85,       // Key: U | u
    ENGINOALY_KEY_V = 86,       // Key: V | v
    ENGINOALY_KEY_W = 87,       // Key: W | w
    ENGINOALY_KEY_X = 88,       // Key: X | x
    ENGINOALY_KEY_Y = 89,       // Key: Y | y
    ENGINOALY_KEY_Z = 90,       // Key: Z | z
    ENGINOALY_KEY_LEFT_BRACKET = 91,       // Key: [
    ENGINOALY_KEY_BACKSLASH = 92,       // Key: '\'
    ENGINOALY_KEY_RIGHT_BRACKET = 93,       // Key: ]
    ENGINOALY_KEY_GRAVE = 96,       // Key: `
    // Function keys
    ENGINOALY_KEY_SPACE = 32,       // Key: Space
    ENGINOALY_KEY_ESCAPE = 256,      // Key: Esc
    ENGINOALY_KEY_ENTER = 257,      // Key: Enter
    ENGINOALY_KEY_TAB = 258,      // Key: Tab
    ENGINOALY_KEY_BACKSPACE = 259,      // Key: Backspace
    ENGINOALY_KEY_INSERT = 260,      // Key: Ins
    ENGINOALY_KEY_DELETE = 261,      // Key: Del
    ENGINOALY_KEY_RIGHT = 262,      // Key: Cursor right
    ENGINOALY_KEY_LEFT = 263,      // Key: Cursor left
    ENGINOALY_KEY_DOWN = 264,      // Key: Cursor down
    ENGINOALY_KEY_UP = 265,      // Key: Cursor up
    ENGINOALY_KEY_PAGE_UP = 266,      // Key: Page up
    ENGINOALY_KEY_PAGE_DOWN = 267,      // Key: Page down
    ENGINOALY_KEY_HOME = 268,      // Key: Home
    ENGINOALY_KEY_END = 269,      // Key: End
    ENGINOALY_KEY_CAPS_LOCK = 280,      // Key: Caps lock
    ENGINOALY_KEY_SCROLL_LOCK = 281,      // Key: Scroll down
    ENGINOALY_KEY_NUM_LOCK = 282,      // Key: Num lock
    ENGINOALY_KEY_PRINT_SCREEN = 283,      // Key: Print screen
    ENGINOALY_KEY_PAUSE = 284,      // Key: Pause
    ENGINOALY_KEY_F1 = 290,      // Key: F1
    ENGINOALY_KEY_F2 = 291,      // Key: F2
    ENGINOALY_KEY_F3 = 292,      // Key: F3
    ENGINOALY_KEY_F4 = 293,      // Key: F4
    ENGINOALY_KEY_F5 = 294,      // Key: F5
    ENGINOALY_KEY_F6 = 295,      // Key: F6
    ENGINOALY_KEY_F7 = 296,      // Key: F7
    ENGINOALY_KEY_F8 = 297,      // Key: F8
    ENGINOALY_KEY_F9 = 298,      // Key: F9
    ENGINOALY_KEY_F10 = 299,      // Key: F10
    ENGINOALY_KEY_F11 = 300,      // Key: F11
    ENGINOALY_KEY_F12 = 301,      // Key: F12
    ENGINOALY_KEY_LEFT_SHIFT = 340,      // Key: Shift left
    ENGINOALY_KEY_LEFT_CONTROL = 341,      // Key: Control left
    ENGINOALY_KEY_LEFT_ALT = 342,      // Key: Alt left
    ENGINOALY_KEY_LEFT_SUPER = 343,      // Key: Super left
    ENGINOALY_KEY_RIGHT_SHIFT = 344,      // Key: Shift right
    ENGINOALY_KEY_RIGHT_CONTROL = 345,      // Key: Control right
    ENGINOALY_KEY_RIGHT_ALT = 346,      // Key: Alt right
    ENGINOALY_KEY_RIGHT_SUPER = 347,      // Key: Super right
    ENGINOALY_KEY_KB_MENU = 348,      // Key: KB menu
    // Keypad keys
    ENGINOALY_KEY_KP_0 = 320,      // Key: Keypad 0
    ENGINOALY_KEY_KP_1 = 321,      // Key: Keypad 1
    ENGINOALY_KEY_KP_2 = 322,      // Key: Keypad 2
    ENGINOALY_KEY_KP_3 = 323,      // Key: Keypad 3
    ENGINOALY_KEY_KP_4 = 324,      // Key: Keypad 4
    ENGINOALY_KEY_KP_5 = 325,      // Key: Keypad 5
    ENGINOALY_KEY_KP_6 = 326,      // Key: Keypad 6
    ENGINOALY_KEY_KP_7 = 327,      // Key: Keypad 7
    ENGINOALY_KEY_KP_8 = 328,      // Key: Keypad 8
    ENGINOALY_KEY_KP_9 = 329,      // Key: Keypad 9
    ENGINOALY_KEY_KP_DECIMAL = 330,      // Key: Keypad .
    ENGINOALY_KEY_KP_DIVIDE = 331,      // Key: Keypad /
    ENGINOALY_KEY_KP_MULTIPLY = 332,      // Key: Keypad *
    ENGINOALY_KEY_KP_SUBTRACT = 333,      // Key: Keypad -
    ENGINOALY_KEY_KP_ADD = 334,      // Key: Keypad +
    ENGINOALY_KEY_KP_ENTER = 335,      // Key: Keypad Enter
    ENGINOALY_KEY_KP_EQUAL = 336,      // Key: Keypad =
    // Android key buttons
    ENGINOALY_KEY_BACK = 4,        // Key: Android back button
    ENGINOALY_KEY_MENU = 5,        // Key: Android menu button
    ENGINOALY_KEY_VOLUME_UP = 24,       // Key: Android volume up button
    ENGINOALY_KEY_VOLUME_DOWN = 25        // Key: Android volume down button
} EnginoalyKey;


// Add backwards compatibility support for deprecated names
#define MOUSE_LEFT_BUTTON   ENGINOALY_MOUSE_BUTTON_LEFT
#define MOUSE_RIGHT_BUTTON  ENGINOALY_MOUSE_BUTTON_RIGHT
#define MOUSE_MIDDLE_BUTTON ENGINOALY_MOUSE_BUTTON_MIDDLE

// Mouse buttons
typedef enum {
    ENGINOALY_MOUSE_BUTTON_LEFT    = 0,       // Mouse button left
    ENGINOALY_MOUSE_BUTTON_RIGHT   = 1,       // Mouse button right
    ENGINOALY_MOUSE_BUTTON_MIDDLE  = 2,       // Mouse button middle (pressed wheel)
    ENGINOALY_MOUSE_BUTTON_SIDE    = 3,       // Mouse button side (advanced mouse device)
    ENGINOALY_MOUSE_BUTTON_EXTRA   = 4,       // Mouse button extra (advanced mouse device)
    ENGINOALY_MOUSE_BUTTON_FORWARD = 5,       // Mouse button forward (advanced mouse device)
    ENGINOALY_MOUSE_BUTTON_BACK    = 6,       // Mouse button back (advanced mouse device)
} EnginoalyMouse;


class Input
{
public:
	bool isKeyDown(EnginoalyKey key);
	bool isKeyPressed(EnginoalyKey key);

    bool isMousePressed(EnginoalyMouse button);
    bool isMouseDown(EnginoalyMouse button);
    bool isMouseUp(EnginoalyMouse button);
    bool isMouseReleased(EnginoalyMouse button);

    Vector2 getMousePosition();
    int getMouseX();
    int getMouseY();

    void setMousePosition(int x, int y);

    Vector2 getMouseWheelMoveVector();
    int getMouseWheelMove();

	//void setKeyUp(int key);
	//void setKeyDown(int key);

private:
	//bool keys[256]; //Array for storing key states
	//bool keyStillHeld[256];

        
protected:

};

