#pragma once

#include <glm/glm.hpp>
#include <glad/glad.h>

#define NODISCARD [[nodiscard]]
#define UNUSED [[maybe_unused]]

static constexpr GLfloat RGB_CONVERSION_FACTOR{255.0f};

NODISCARD glm::vec3 rgb_to_normalized(const glm::vec3 &rgbColor);