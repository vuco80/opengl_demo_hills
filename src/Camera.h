#pragma once

#include <glm.hpp>

class Camera {
public:
	Camera(int id);
	virtual ~Camera();

	void set(const glm::vec3& position, const glm::vec3& lookAt, const glm::vec3& up = { 0.0f, 1.0f, 0.0f });
	glm::mat4 getMatrix() const;
	int id() const { return mId; }
	virtual void update(float fps) {}

private:
	int mId;

protected:
	glm::vec3 mPosition;
	glm::vec3 mLookAt;
	glm::vec3 mUp;
};