#pragma once

#include "OpenGL.h"
#include <string>

class Shader {
public:
	Shader();
	~Shader();

	bool loadFromFile(const std::string& filename, GLenum shaderType);

	GLuint getId() const;
	GLenum getType() const;

private:
	GLuint mId;
	GLuint mType;
};
