#pragma once

#include "App.h"
#include "Cube.h"
#include <vector>
#include "Heightmap.h"

class HillsApp : public App {
public:
	HillsApp();
	~HillsApp();

	void init() override;
	void update() override;
	void render() override;
	void quit() override;

private:
	std::vector<Cube> mCubes;
	Heightmap mTerrain;
};