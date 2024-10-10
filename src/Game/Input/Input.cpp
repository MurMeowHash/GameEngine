#include "Input.h"

std::array<int, KEY_COUNT> Input::keys;
int Input::currentState;
int Input::prevState;
GLFWwindow *Input::currentWindow{nullptr};
GLfloat Input::prevXPos;
GLfloat Input::prevYPos;
GLfloat Input::xOffset;
GLfloat Input::yOffset;
bool Input::firstMove{true};

void Input::setFocus(GLFWwindow *target) {
    currentWindow = target;
    keys.fill(GLFW_RELEASE);
}

int Input::detectKeyState(InputKey key) {
    return glfwGetKey(currentWindow, static_cast<int>(key));
}

void Input::updateStates(InputKey key) {
    currentState = detectKeyState(key);
    prevState = keys[static_cast<int>(key)];
    keys[static_cast<int>(key)] = currentState;
}

bool Input::getKeyDown(InputKey key) {
    updateStates(key);
    return currentState == GLFW_PRESS && prevState == GLFW_RELEASE;
}

bool Input::getKey(InputKey key) {
    updateStates(key);
    return currentState == GLFW_PRESS;
}

bool Input::getKeyUp(InputKey key) {
    updateStates(key);
    return currentState == GLFW_RELEASE && prevState == GLFW_PRESS;
}

void Input::mouse_callback(UNUSED GLFWwindow *window, GLdouble xPos, GLdouble yPos) {
    auto currentXPos = static_cast<GLfloat>(xPos);
    auto currentYPos = static_cast<GLfloat>(yPos);
    if(firstMove) {
        prevXPos = currentXPos;
        prevYPos = currentYPos;
        firstMove = false;
    }
    xOffset = currentXPos - prevXPos;
    yOffset = prevYPos - currentYPos;
}

GLfloat Input::getXOffset() {
    return xOffset;
}

GLfloat Input::getYOffset() {
    return yOffset;
}

void Input::reset() {
    xOffset = 0.f;
    yOffset = 0.f;
}