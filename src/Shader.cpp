#include "Shader.h"
#include <fstream>
#include <vector>
#include <iostream>

Shader::Shader() : mId(0), mType(0) {

}

Shader::~Shader() {
	OpenGL::deleteShader(mId);
}

bool Shader::loadFromFile(const std::string& filename, GLenum shaderType) {
	std::ifstream file;
	file.open(filename.c_str());
	if (!file.good()) return false;

	std::vector<std::string> content;
	for (std::string line; std::getline(file, line); ) {
		line += '\n';
		content.push_back(line.c_str());
	}

	file.close();

	std::vector<const char*> source;
	for (const auto& line : content) {
		source.push_back(line.c_str());
	}

	mId = OpenGL::createShader(shaderType);
	OpenGL::shaderSource(mId, static_cast<GLsizei>(content.size()), source.data());
	OpenGL::compileShader(mId);

	int compileStatus;
	OpenGL::getShaderiv(mId, GL_COMPILE_STATUS, &compileStatus);
	if (compileStatus == GL_FALSE) {
		char infoLog[1000];
		int loglen = 0;
		glGetShaderInfoLog(mId, 1000, &loglen, infoLog);
		std::cerr << "error: " << infoLog << std::endl;
		return false;
	}

	mType = shaderType;

	return true;
}

GLuint Shader::getId() const {
	return mId;
}

GLenum Shader::getType() const {
	return mType;
}