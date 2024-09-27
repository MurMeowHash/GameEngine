#include "utils.h"

glm::vec3 rgb_to_normalized(const glm::vec3 &rgbColor) {
    return rgbColor / RGB_CONVERSION_FACTOR;
}