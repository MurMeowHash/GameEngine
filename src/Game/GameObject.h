#pragma once

#include "IUpdatable.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include "../utils/utils.h"

class GameObject : public IUpdatable {
private:
    glm::mat4 model;
    GameObject *parent;
    std::vector<GameObject *> children;
protected:
    static constexpr glm::vec3 X_AXIS{1.0f, 0.0f, 0.0f};
    static constexpr glm::vec3 Y_AXIS{0.0f, 1.0f, 0.0f};
    static constexpr glm::vec3 Z_AXIS{0.0f, 0.0f, 1.0f};
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;
    glm::mat3 rotationOperand;
    virtual void updateTransform();
public:
    static constexpr glm::vec3 DEFAULT_POS{0.0f};
    static constexpr glm::vec3 DEFAULT_ROT{0.0f};
    static constexpr glm::vec3 DEFAULT_SCALE{1.0f};
    explicit GameObject(const glm::vec3 &position = DEFAULT_POS, const glm::vec3 &rotation = DEFAULT_ROT,
               const glm::vec3 &scale = DEFAULT_SCALE);
    void setPos(const glm::vec3 &pos);
    void setRot(const glm::vec3 &rot);
    void setScale(const glm::vec3 &scaleFactor);
    void setParent(GameObject *targetParent);
    NODISCARD glm::vec3 getPos() const;
    NODISCARD glm::vec3 getRot() const;
    NODISCARD glm::vec3 getScale() const;
    void addChild(GameObject *child);
    NODISCARD glm::mat4 getModelTransform() const;
    void update() override;
};