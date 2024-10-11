#include "utils.h"

glm::vec3 rgb_to_normalized(const glm::vec3 &rgbColor) {
    glm::vec3 outColor = rgbColor / RGB_CONVERSION_FACTOR;
    return glm::clamp(outColor, MIN_RGB_COLOR, MAX_RGB_COLOR);
}