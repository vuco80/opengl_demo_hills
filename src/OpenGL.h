#pragma once

#include <GL\glew.h>

class OpenGL {
public:
	static void drawArraysAsTriangles(int firstVertexIndex, int verticesCount);
	static void drawArraysAsTriangleStrip(int firstVertexIndex, int verticesCount);
	static GLuint createShader(GLenum shaderType);
	static void shaderSource(GLuint shader, GLsizei rowsCount, const char** data);
	static void compileShader(GLuint shader);
	static void getShaderiv(GLuint shader, GLenum statusType, int* result);
	static void deleteShader(GLuint shader);
};