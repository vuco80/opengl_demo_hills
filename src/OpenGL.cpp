#include "OpenGL.h"

void OpenGL::drawArraysAsTriangles(int firstVertexIndex, int verticesCount) {
	glDrawArrays(GL_TRIANGLES, firstVertexIndex, verticesCount);
}

void OpenGL::drawArraysAsTriangleStrip(int firstVertexIndex, int verticesCount) {
	glDrawArrays(GL_TRIANGLE_STRIP, firstVertexIndex, verticesCount);
}

GLuint OpenGL::createShader(GLenum shaderType) {
	return glCreateShader(shaderType);
}

void OpenGL::shaderSource(GLuint shader, GLsizei rowsCount, const char** data) {
	glShaderSource(shader, rowsCount, data, nullptr);
}

void OpenGL::compileShader(GLuint shader) {
	glCompileShader(shader);
}

void OpenGL::getShaderiv(GLuint shader, GLenum statusType, int* result) {
	glGetShaderiv(shader, statusType, result);
}

void OpenGL::deleteShader(GLuint shader) {
	glDeleteShader(shader);
}