#include "Transformation.h"
#include <ext/matrix_transform.hpp>

Transformation::Transformation() : mTranslation(0, 0, 0), mRotationAngle(0), mRotationAxes(1, 0, 0), mScale(1, 1, 1) {

}

Transformation::~Transformation() {

}

glm::mat4 Transformation::getMatrix() {
	glm::mat4 mat(1.0);

	mat = glm::translate(mat, mTranslation);
	mat = glm::rotate(mat, glm::radians(mRotationAngle), mRotationAxes);	
	mat = glm::scale(mat, mScale);

	return mat;
}

glm::mat4 Transformation::getMatrixNoTraslation() {
	glm::mat4 mat(1.0);

	mat = glm::rotate(mat, glm::radians(mRotationAngle), mRotationAxes);
	mat = glm::scale(mat, mScale);

	return mat;
}

void Transformation::setTranslation(const glm::vec3& translation) {
	mTranslation = translation;
}

void Transformation::addTranslation(const glm::vec3& translation) {
	mTranslation += translation;
}

void Transformation::setRotation(float angle, const glm::vec3& axes) {
	mRotationAngle = angle;
	mRotationAxes = axes;
}

void Transformation::setScale(const glm::vec3 scale) {
	mScale = scale;
}