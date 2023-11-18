#pragma once

#include <GL\glew.h>

class VertexArrayObject {
public:
	VertexArrayObject();
	~VertexArrayObject();

	void createAndBind();
	void bind();
	void unbind();
	void destroy();

private:
	GLuint mId;
};