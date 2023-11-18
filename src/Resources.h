#pragma once

#include "ShaderProgram.h"
#include "CameraPool.h"
#include "Projections.h"
#include <string>
#include <map>

class Resources {
public:
	~Resources();
	static Resources* instance();
	void addShaderProgram(ShaderProgram* p);
	ShaderProgram* getShaderProgram(const std::string& name);
	CameraPool* getCameraPool() { return &mCameraPool; }
	Projections* getProjections() { return &mProjections; }

private:
	Resources();

	static Resources* mInstance;

	std::map<std::string, ShaderProgram*> mShaders;
	CameraPool mCameraPool;
	Projections mProjections;
};