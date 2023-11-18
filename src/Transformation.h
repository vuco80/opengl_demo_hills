#pragma once

#include <glm.hpp>

class Transformation {
public:
	Transformation();
	~Transformation();

	glm::mat4 getMatrix();
	glm::mat4 getMatrixNoTraslation();

	void setTranslation(const glm::vec3& translation);
	void addTranslation(const glm::vec3& translation);
	void setRotation(float angle, const glm::vec3& axes);
	void setScale(const glm::vec3 scale);

private:
	glm::vec3 mTranslation;
	float mRotationAngle;
	glm::vec3 mRotationAxes;
	glm::vec3 mScale;
};