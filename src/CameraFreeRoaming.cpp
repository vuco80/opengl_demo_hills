#include "CameraFreeRoaming.h"
#include "World.h"
#include <SDL.h>
#include <ext/matrix_transform.hpp>

CameraFreeRoaming::CameraFreeRoaming(int id) : Camera(id), 
	mUnitsPerSecond(2.0f),
	mDegPerSecond(90.0f) {

}

CameraFreeRoaming::~CameraFreeRoaming() {

}

void CameraFreeRoaming::setSpeed(float unitsPerSecond) {
	mUnitsPerSecond = unitsPerSecond;
}

void CameraFreeRoaming::setRotationSpeed(float degreesPerSecond) {
	mDegPerSecond = degreesPerSecond;
}

void CameraFreeRoaming::update(float fps) {
	const Uint8* keys = SDL_GetKeyboardState(nullptr);
	float amount = mUnitsPerSecond / fps;
	float rotation = mDegPerSecond / fps;
	if (keys[SDL_SCANCODE_W]) move(amount);
	if (keys[SDL_SCANCODE_S]) move(-amount);
	if (keys[SDL_SCANCODE_D]) rotate(-rotation);
	if (keys[SDL_SCANCODE_A]) rotate(rotation);
}

void CameraFreeRoaming::move(float amount) {
	glm::vec3 direction = glm::normalize(mLookAt - mPosition);
	glm::vec3 movement = direction * amount;
	mPosition += movement;
	mLookAt += movement;

	float h = 0;
	if (World::instance()->getTerrain()->getHeightAt(mPosition.x, mPosition.z, &h)) {
		float newHeight = h + 4.0;
		float diff = newHeight - mPosition.y;
		if (amount < 0) amount *= -1;
		mPosition.y += diff * amount;
		mLookAt.y += diff * amount;
	}
}

void CameraFreeRoaming::rotate(float amount) {
	glm::mat4 rotation = glm::rotate(glm::mat4(1.0), glm::radians(amount), glm::vec3(0, 1, 0));
	glm::vec3 direction = glm::normalize(mLookAt - mPosition);
	glm::vec4 rotatedDirection = rotation * glm::vec4(direction, 0.0f);
	mLookAt = mPosition + glm::vec3(rotatedDirection.x, rotatedDirection.y, rotatedDirection.z);
}
