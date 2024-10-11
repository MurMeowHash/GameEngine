#include "GameObject.h"
#include <algorithm>

GameObject::GameObject(const glm::vec3 &position, const glm::vec3 &rotation, const glm::vec3 &scale)
: position{position}, rotation{rotation}, scale{scale}, parent{nullptr} {

}

void GameObject::setPos(const glm::vec3 &pos) {
    position = pos;
}

void GameObject::setRot(const glm::vec3 &rot) {
    rotation = rot;
}

void GameObject::setScale(const glm::vec3 &scaleFactor) {
    scale = scaleFactor;
}

void GameObject::setParent(GameObject *targetParent) {
    parent = targetParent;
}

glm::vec3 GameObject::getPos() const {
    return position;
}

glm::vec3 GameObject::getRot() const {
    return rotation;
}

glm::vec3 GameObject::getScale() const {
    return scale;
}

void GameObject::addChild(GameObject *child) {
    auto targetChild = std::find(children.begin(), children.end(), child);
    if(targetChild == children.end()) {
        child->setParent(this);
        children.push_back(child);
    }
}

void GameObject::updateTransform() {
    model = glm::mat4{1.0f};
    model = glm::translate(model, position);
    model = glm::rotate(model, glm::radians(rotation.x), X_AXIS);
    model = glm::rotate(model, glm::radians(rotation.y), Y_AXIS);
    model = glm::rotate(model, glm::radians(rotation.z), Z_AXIS);
    model = glm::scale(model, scale);
    rotationOperand = glm::mat3(model);
}

glm::mat4 GameObject::getModelTransform() const {
    return model;
}

void GameObject::update() {
    updateTransform();
    if(parent != nullptr) {
        model = parent->getModelTransform() * model;
    }
    for(GameObject *child : children) {
        child->update();
    }
}
