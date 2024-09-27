#pragma once

#include "Shader.h"

struct ShaderHash {
    size_t operator()(const Shader &shader) const;
};