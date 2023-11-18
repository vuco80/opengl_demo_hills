#include "CameraPool.h"

CameraPool::CameraPool() : mActiveIndex(-1) {

}

CameraPool::~CameraPool() {
	while (!mPool.empty()) {
		delete mPool.back();
		mPool.pop_back();
	}
}

void CameraPool::add(Camera* camera, bool active) {
	mPool.push_back(camera);
	if (active) mActiveIndex = mPool.size() - 1;
}

Camera* CameraPool::getActiveCamera() {
	if (mActiveIndex > -1) return mPool[mActiveIndex];
	return nullptr;
}

void CameraPool::setActive(int cameraId) {
	for (int i = 0; i < mPool.size(); ++i) {
		if (mPool[i]->id() == cameraId) {
			mActiveIndex = i;
			break;
		}
	}
}