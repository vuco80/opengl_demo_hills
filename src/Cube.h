#pragma once

#include <glm.hpp>
#include "VertexArrayObject.h"
#include "VertexBufferObject.h"
#include "Transformation.h"

class Cube {
public:
	Cube();
	~Cube();

	void init();
	void update();
	void render();
	void destroy();

	Transformation* transform() { return &mTrans; }

private:
	glm::vec3 mVertices[108];
	VertexArrayObject mVao;
	VertexBufferObject mVbo;
	Transformation mTrans;
};