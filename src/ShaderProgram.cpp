#include "ShaderProgram.h"

ShaderProgram::ShaderProgram(const std::string& name) : mName(name), mId(0), mLinked(false) {

}

ShaderProgram::~ShaderProgram() {
	glDeleteProgram(mId);
}

void ShaderProgram::create() {
	mId = glCreateProgram();
}

void ShaderProgram::addShader(Shader* s) {
	glAttachShader(mId, s->getId());
}

bool ShaderProgram::link() {
	if (mLinked) return true;

	mLinked = true;
	glLinkProgram(mId);
	int result;
	glGetProgramiv(mId, GL_LINK_STATUS, &result);
	return result == GL_TRUE;
}

void ShaderProgram::use() {
	glUseProgram(mId);
}

const std::string& ShaderProgram::name() const {
	return mName;
}

void ShaderProgram::setUniformMat4(const std::string& name, const glm::mat4& matrix) {
	GLint loc = glGetUniformLocation(mId, name.c_str());
	glProgramUniformMatrix4fv(mId, loc, 1, GL_FALSE, &matrix[0][0]);
}

void ShaderProgram::setUniformVec3(const std::string& name, const glm::vec3& vector) {
	GLint loc = glGetUniformLocation(mId, name.c_str());
	glProgramUniform3fv(mId, loc, 1, &vector[0]);
}