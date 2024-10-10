#pragma once

#include "../../Shader/Shader.h"
#include "../../Shader/ShaderType.h"
#include "../../utils/utils.h"

class BasicMaterial {
private:
    bool initialized;
    void initShader(ShaderType type, const char *shaderName);
protected:
    Shader *shader;
public:
    BasicMaterial(ShaderType type, const char *shaderName);
    NODISCARD bool good() const;
    virtual bool apply() = 0;
    virtual ~BasicMaterial() = default;
    explicit operator bool() const;
    bool operator!() const;
};