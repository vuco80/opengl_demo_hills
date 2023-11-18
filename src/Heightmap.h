#pragma once
#include <glm.hpp>
#include <vector>
#include <string>
#include "VertexArrayObject.h"
#include "VertexBufferObject.h"
#include "Transformation.h"

class Heightmap {
public:
	Heightmap();
	~Heightmap();

	void init(float step, float maxHeight);
	void load(const std::string& filename);
	void update();
	void render();
	void destroy();

	bool getHeightAt(float x, float z, float* h) const;

private:
	int mWidth, mDeep;
	float mStep, mMaxHeight;
	std::vector<float> mHeights;
	std::vector<glm::vec3> mVertices;
	VertexArrayObject mVao;
	VertexBufferObject mVbo;
	Transformation mTrans;
};