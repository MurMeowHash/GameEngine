#include "Screen.h"
#include "../../Error/Error.h"
#include "../../utils/utils.h"
#include "../../Debug/Debug.h"

GLint Screen::screenWidth{UNINITIALIZED_SCREEN_SIZE};
GLint Screen::screenHeight{UNINITIALIZED_SCREEN_SIZE};
glm::vec4 Screen::clearColor;

void Screen::update(GLint scrWidth, GLint scrHeight, const glm::vec3 &background) {
    if(scrWidth <= 0 || scrHeight <= 0) {
        Error::fallWithMessage("SCREEN", "WIDTH_HEIGHT_ARE_LESS_THAN_ZERO");
    }
    screenWidth = scrWidth;
    screenHeight = scrHeight;
    setBackgroundColor(background);
}

void Screen::setBackgroundColor(const glm::vec3 &background) {
    clearColor = glm::vec4(rgb_to_normalized(background), 1.0f);
}

void Screen::clear() {
    glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);
    glClear(GL_COLOR_BUFFER_BIT);
}

GLfloat Screen::getAspectRatio() {
    if(screenWidth == UNINITIALIZED_SCREEN_SIZE
    || screenHeight == UNINITIALIZED_SCREEN_SIZE) {
        Debug::logError("SCREEN", "UNINITIALIZED_SIZE");
    }
    return static_cast<GLfloat>(screenWidth) / static_cast<GLfloat>(screenHeight);
}