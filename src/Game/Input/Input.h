#pragma once

#include "InputKey.h"
#include "../../utils/utils.h"
#include <array>
#include <vector>

class Input {
private:
    static std::array<int, KEY_COUNT> keys;
    static int currentState;
    static int prevState;
    static GLFWwindow *currentWindow;
    static GLfloat prevXPos;
    static GLfloat prevYPos;
    static GLfloat xOffset;
    static GLfloat yOffset;
    static bool firstMove;
    static int detectKeyState(InputKey key);
    static void updateStates(InputKey key);
public:
    static void initialize();
    NODISCARD static bool getKeyDown(InputKey key);
    NODISCARD static bool getKey(InputKey key);
    NODISCARD static bool getKeyUp(InputKey key);
    NODISCARD static GLfloat getXOffset();
    NODISCARD static GLfloat getYOffset();
    static void reset();
    static void mouse_callback(UNUSED GLFWwindow *window, GLdouble xPos, GLdouble yPos);
};