#pragma once

#include "Heightmap.h"

class World {
public:
	static World* instance();

	void setTerrain(Heightmap* terrain);
	const Heightmap* getTerrain();

private:
	World();
	static World* mInstance;
	Heightmap* mTerrain;
};