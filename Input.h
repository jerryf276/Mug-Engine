#pragma once
#include "raylib.h"

typedef enum {
    MUG_KEY_NULL = 0,        // Key: NULL, used for no key pressed
    // Alphanumeric keys
    MUG_KEY_APOSTROPHE = 39,       // Key: '
    MUG_KEY_COMMA = 44,       // Key: ,
    MUG_KEY_MINUS = 45,       // Key: -
    MUG_KEY_PERIOD = 46,       // Key: .
    MUG_KEY_SLASH = 47,       // Key: /
    MUG_KEY_ZERO = 48,       // Key: 0
    MUG_KEY_ONE = 49,       // Key: 1
    MUG_KEY_TWO = 50,       // Key: 2
    MUG_KEY_THREE = 51,       // Key: 3
    MUG_KEY_FOUR = 52,       // Key: 4
    MUG_KEY_FIVE = 53,       // Key: 5
    MUG_KEY_SIX = 54,       // Key: 6
    MUG_KEY_SEVEN = 55,       // Key: 7
    MUG_KEY_EIGHT = 56,       // Key: 8
    MUG_KEY_NINE = 57,       // Key: 9
    MUG_KEY_SEMICOLON = 59,       // Key: ;
    MUG_KEY_EQUAL = 61,       // Key: =
    MUG_KEY_A = 65,       // Key: A | a
    MUG_KEY_B = 66,       // Key: B | b
    MUG_KEY_C = 67,       // Key: C | c
    MUG_KEY_D = 68,       // Key: D | d
    MUG_KEY_E = 69,       // Key: E | e
    MUG_KEY_F = 70,       // Key: F | f
    MUG_KEY_G = 71,       // Key: G | g
    MUG_KEY_H = 72,       // Key: H | h
    MUG_KEY_I = 73,       // Key: I | i
    MUG_KEY_J = 74,       // Key: J | j
    MUG_KEY_K = 75,       // Key: K | k
    MUG_KEY_L = 76,       // Key: L | l
    MUG_KEY_M = 77,       // Key: M | m
    MUG_KEY_N = 78,       // Key: N | n
    MUG_KEY_O = 79,       // Key: O | o
    MUG_KEY_P = 80,       // Key: P | p
    MUG_KEY_Q = 81,       // Key: Q | q
    MUG_KEY_R = 82,       // Key: R | r
    MUG_KEY_S = 83,       // Key: S | s
    MUG_KEY_T = 84,       // Key: T | t
    MUG_KEY_U = 85,       // Key: U | u
    MUG_KEY_V = 86,       // Key: V | v
    MUG_KEY_W = 87,       // Key: W | w
    MUG_KEY_X = 88,       // Key: X | x
    MUG_KEY_Y = 89,       // Key: Y | y
    MUG_KEY_Z = 90,       // Key: Z | z
    MUG_KEY_LEFT_BRACKET = 91,       // Key: [
    MUG_KEY_BACKSLASH = 92,       // Key: '\'
    MUG_KEY_RIGHT_BRACKET = 93,       // Key: ]
    MUG_KEY_GRAVE = 96,       // Key: `
    // Function keys
    MUG_KEY_SPACE = 32,       // Key: Space
    MUG_KEY_ESCAPE = 256,      // Key: Esc
    MUG_KEY_ENTER = 257,      // Key: Enter
    MUG_KEY_TAB = 258,      // Key: Tab
    MUG_KEY_BACKSPACE = 259,      // Key: Backspace
    MUG_KEY_INSERT = 260,      // Key: Ins
    MUG_KEY_DELETE = 261,      // Key: Del
    MUG_KEY_RIGHT = 262,      // Key: Cursor right
    MUG_KEY_LEFT = 263,      // Key: Cursor left
    MUG_KEY_DOWN = 264,      // Key: Cursor down
    MUG_KEY_UP = 265,      // Key: Cursor up
    MUG_KEY_PAGE_UP = 266,      // Key: Page up
    MUG_KEY_PAGE_DOWN = 267,      // Key: Page down
    MUG_KEY_HOME = 268,      // Key: Home
    MUG_KEY_END = 269,      // Key: End
    MUG_KEY_CAPS_LOCK = 280,      // Key: Caps lock
    MUG_KEY_SCROLL_LOCK = 281,      // Key: Scroll down
    MUG_KEY_NUM_LOCK = 282,      // Key: Num lock
    MUG_KEY_PRINT_SCREEN = 283,      // Key: Print screen
    MUG_KEY_PAUSE = 284,      // Key: Pause
    MUG_KEY_F1 = 290,      // Key: F1
    MUG_KEY_F2 = 291,      // Key: F2
    MUG_KEY_F3 = 292,      // Key: F3
    MUG_KEY_F4 = 293,      // Key: F4
    MUG_KEY_F5 = 294,      // Key: F5
    MUG_KEY_F6 = 295,      // Key: F6
    MUG_KEY_F7 = 296,      // Key: F7
    MUG_KEY_F8 = 297,      // Key: F8
    MUG_KEY_F9 = 298,      // Key: F9
    MUG_KEY_F10 = 299,      // Key: F10
    MUG_KEY_F11 = 300,      // Key: F11
    MUG_KEY_F12 = 301,      // Key: F12
    MUG_KEY_LEFT_SHIFT = 340,      // Key: Shift left
    MUG_KEY_LEFT_CONTROL = 341,      // Key: Control left
    MUG_KEY_LEFT_ALT = 342,      // Key: Alt left
    MUG_KEY_LEFT_SUPER = 343,      // Key: Super left
    MUG_KEY_RIGHT_SHIFT = 344,      // Key: Shift right
    MUG_KEY_RIGHT_CONTROL = 345,      // Key: Control right
    MUG_KEY_RIGHT_ALT = 346,      // Key: Alt right
    MUG_KEY_RIGHT_SUPER = 347,      // Key: Super right
    MUG_KEY_KB_MENU = 348,      // Key: KB menu
    // Keypad keys
    MUG_KEY_KP_0 = 320,      // Key: Keypad 0
    MUG_KEY_KP_1 = 321,      // Key: Keypad 1
    MUG_KEY_KP_2 = 322,      // Key: Keypad 2
    MUG_KEY_KP_3 = 323,      // Key: Keypad 3
    MUG_KEY_KP_4 = 324,      // Key: Keypad 4
    MUG_KEY_KP_5 = 325,      // Key: Keypad 5
    MUG_KEY_KP_6 = 326,      // Key: Keypad 6
    MUG_KEY_KP_7 = 327,      // Key: Keypad 7
    MUG_KEY_KP_8 = 328,      // Key: Keypad 8
    MUG_KEY_KP_9 = 329,      // Key: Keypad 9
    MUG_KEY_KP_DECIMAL = 330,      // Key: Keypad .
    MUG_KEY_KP_DIVIDE = 331,      // Key: Keypad /
    MUG_KEY_KP_MULTIPLY = 332,      // Key: Keypad *
    MUG_KEY_KP_SUBTRACT = 333,      // Key: Keypad -
    MUG_KEY_KP_ADD = 334,      // Key: Keypad +
    MUG_KEY_KP_ENTER = 335,      // Key: Keypad Enter
    MUG_KEY_KP_EQUAL = 336,      // Key: Keypad =
    // Android key buttons
    MUG_KEY_BACK = 4,        // Key: Android back button
    MUG_KEY_MENU = 5,        // Key: Android menu button
    MUG_KEY_VOLUME_UP = 24,       // Key: Android volume up button
    MUG_KEY_VOLUME_DOWN = 25        // Key: Android volume down button
} MugKey;


// Add backwards compatibility support for deprecated names
#define MOUSE_LEFT_BUTTON   MUG_MOUSE_BUTTON_LEFT
#define MOUSE_RIGHT_BUTTON  MUG_MOUSE_BUTTON_RIGHT
#define MOUSE_MIDDLE_BUTTON MUG_MOUSE_BUTTON_MIDDLE

// Mouse buttons
typedef enum {
    MUG_MOUSE_BUTTON_LEFT    = 0,       // Mouse button left
    MUG_MOUSE_BUTTON_RIGHT   = 1,       // Mouse button right
    MUG_MOUSE_BUTTON_MIDDLE  = 2,       // Mouse button middle (pressed wheel)
    MUG_MOUSE_BUTTON_SIDE    = 3,       // Mouse button side (advanced mouse device)
    MUG_MOUSE_BUTTON_EXTRA   = 4,       // Mouse button extra (advanced mouse device)
    MUG_MOUSE_BUTTON_FORWARD = 5,       // Mouse button forward (advanced mouse device)
    MUG_MOUSE_BUTTON_BACK    = 6,       // Mouse button back (advanced mouse device)
} MugMouse;


class Input
{
public:
	bool isKeyDown(MugKey key);
	bool isKeyPressed(MugKey key);
	bool isKeyPressedAgain(MugKey key);

    bool isMousePressed(MugMouse button);
    bool isMouseDown(MugMouse button);
    bool isMouseUp(MugMouse button);
    bool isMouseReleased(MugMouse button);

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

