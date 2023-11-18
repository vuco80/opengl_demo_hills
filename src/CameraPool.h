#pragma once
#include "Camera.h"
#include <vector>

class CameraPool {
public:
	CameraPool();
	~CameraPool();

	void add(Camera* camera, bool active = true);
	Camera* getActiveCamera();
	void setActive(int cameraId);

private:
	std::vector<Camera*> mPool;
	int mActiveIndex;
};
