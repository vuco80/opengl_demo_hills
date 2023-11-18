#include "World.h"

World* World::mInstance = nullptr;

World::World() {

}

World* World::instance() {
	if (mInstance == nullptr) mInstance = new World();
	return mInstance;
}

void World::setTerrain(Heightmap* terrain) {
	mTerrain = terrain;
}

const Heightmap* World::getTerrain() {
	return mTerrain;
}