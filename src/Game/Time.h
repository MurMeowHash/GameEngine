#pragma once

#include <glad/glad.h>
#include "../utils/utils.h"

class Time {
private:
    static GLfloat lastTime;
    static GLfloat deltaTime;
public:
    static void calculateDeltaTime();
    NODISCARD static GLfloat getDeltaTime();
};