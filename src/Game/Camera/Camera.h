#pragma once

#include "../GameObject.h"

class Camera : public GameObject {
private:
    static constexpr glm::vec3 WORLD_UP{0.0f, 1.0f, 0.0f};
    static constexpr GLfloat DEFAULT_FOV{45.0f};
    static constexpr GLfloat DEFAULT_NEAR_CLIP{0.1f};
    static constexpr GLfloat DEFAULT_FAR_CLIP{100.0f};
    glm::vec3 forwardDirection;
    glm::vec3 upDirection;
    GLfloat fov;
    GLfloat nearClip;
    GLfloat farClip;
    glm::mat4 view;
    glm::mat4 projection;
protected:
    void updateTransform() override;
public:
    explicit Camera(const glm::vec3 &up = WORLD_UP, GLfloat fov = DEFAULT_FOV, GLfloat nearClip = DEFAULT_NEAR_CLIP,
                    GLfloat farClip = DEFAULT_FAR_CLIP, const glm::vec3 &position = DEFAULT_POS,
                    const glm::vec3 &rotation = DEFAULT_ROT);
    void setFov(GLfloat targetFov);
    NODISCARD glm::mat4 getViewTransform() const;
    NODISCARD glm::mat4 getProjectionTransform() const;
};