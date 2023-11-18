#include "Projections.h"
#include <ext/matrix_clip_space.hpp>

int Projections::mScreenWidth = 320;
int Projections::mScreenHeight = 240;

Projections::Projections() {
	
}

void Projections::setScreenSize(int screenWidth, int screenHeight) {
	mScreenWidth = screenWidth;
	mScreenHeight = screenHeight;
}

void Projections::buildProjection3d(float fov, float far) {
	mProj3d = glm::perspective(fov, (float)(mScreenWidth / mScreenHeight), 0.5f, far);
}