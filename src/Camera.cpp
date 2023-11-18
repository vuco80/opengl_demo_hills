#include "Camera.h"
#include <ext/matrix_transform.hpp>

Camera::Camera(int id) : mId(id) {

}

Camera::~Camera() {

}

void Camera::set(const glm::vec3& position, const glm::vec3& lookAt, const glm::vec3& up) {
	mPosition = position;
	mLookAt = lookAt;
	mUp = up;
}

glm::mat4 Camera::getMatrix() const {
	return glm::lookAt(mPosition, mLookAt, mUp);
}