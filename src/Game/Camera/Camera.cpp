#include "Camera.h"
#include "../Screen/Screen.h"

Camera::Camera(const glm::vec3 &up, GLfloat fov, GLfloat nearClip, GLfloat farClip, const glm::vec3 &position,
               const glm::vec3 &rotation) :
               upDirection{up}, nearClip{nearClip}, farClip{farClip}, GameObject(position, rotation) {
    setFov(fov);
}

void Camera::updateTransform() {
    GameObject::updateTransform();
    forwardDirection.x = glm::sin(rotation.y) * glm::cos(rotation.x);
    forwardDirection.y = glm::sin(rotation.x);
    forwardDirection.z = glm::cos(rotation.y) * glm::cos(rotation.x);
    forwardDirection = glm::normalize(forwardDirection);
    view = glm::lookAt(position, forwardDirection, upDirection);
    projection = glm::perspective(fov, Screen::getAspectRatio(), nearClip, farClip);
}

void Camera::setFov(GLfloat targetFov) {
    fov = glm::radians(targetFov);
}

glm::mat4 Camera::getViewTransform() const {
    return view;
}

glm::mat4 Camera::getProjectionTransform() const {
    return projection;
}
