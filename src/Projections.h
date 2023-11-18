#pragma once
#include <glm.hpp>

class Projections {
public:
	Projections();

	static void setScreenSize(int screenWidth, int screenHeight);
	
	void buildProjection3d(float fov = 45.0f, float far = 1000.0f);
	glm::mat4 getProjection3d() const { return mProj3d; }

private:
	static int mScreenWidth;
	static int mScreenHeight;

	glm::mat4 mProj3d;
};