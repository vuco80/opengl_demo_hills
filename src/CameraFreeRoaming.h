#pragma once
#include "Camera.h"

class CameraFreeRoaming : public Camera {
public:
	CameraFreeRoaming(int id);
	~CameraFreeRoaming();

	void setSpeed(float unitsPerSecond);
	void setRotationSpeed(float degreesPerSecond);

	void update(float fps) override;

private:
	float mUnitsPerSecond;
	float mDegPerSecond;

	void move(float amount);
	void rotate(float amount);
};