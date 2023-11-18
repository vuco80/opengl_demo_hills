#pragma once

#include <GL\glew.h>
#include <glm.hpp>

class VertexBufferObject {
public:
	VertexBufferObject();
	~VertexBufferObject();

	void createAndBind();
	void bind();
	void setData(glm::vec3* data, int verticesCount);
	void addAttributeVec3f(int stride, void* offset);
	void destroy();

private:
	GLuint mId;
	int mAttribIndex;
};