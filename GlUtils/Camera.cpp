//
// Created by opot on 10.04.17.
//

#include "Camera.h"

namespace fjfj {

    Camera::Camera(int width, int height, glm::vec3 position, glm::vec3 up) : Front(
            glm::vec3(0.0f, 0.0f, -1.0f)) {
        this->Position = position;
        this->WorldUp = up;
        this->aspect = (float) width / height;
        this->update();
        this->updatePerspective();
    }

    glm::mat4 Camera::GetViewMatrix() {
        return glm::lookAt(this->Position, this->Position + this->Front, this->Up);
    }

    void Camera::lookAt(glm::vec3 target) {
        this->Front = glm::normalize(target - this->Position);
        this->Right = glm::normalize(glm::cross(this->Front, this->WorldUp));
        this->Up = glm::normalize(glm::cross(this->Right, this->Front));
    }

    void Camera::update() {
        this->Right = glm::normalize(glm::cross(this->Front, this->WorldUp));
        this->Up = glm::normalize(glm::cross(this->Right, this->Front));
    }

    void Camera::updatePerspective() {
        this->perspective = glm::perspective(fov, aspect, near, far);
    }

}