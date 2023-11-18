#pragma once
#include "Shader.h"
#include <string>
#include <glm.hpp>

class ShaderProgram {
public:
	ShaderProgram(const std::string& name);
	~ShaderProgram();

	void create();
	void addShader(Shader* s);
	bool link();
	void use();
	const std::string& name() const;

	void setUniformMat4(const std::string& name, const glm::mat4& matrix);
	void setUniformVec3(const std::string& name, const glm::vec3& vector);

private:
	GLuint mId;
	bool mLinked;
	std::string mName;
};