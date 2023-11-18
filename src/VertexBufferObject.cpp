#include "VertexBufferObject.h"

VertexBufferObject::VertexBufferObject() : mId(0), mAttribIndex(0) {

}

VertexBufferObject::~VertexBufferObject() {

}

void VertexBufferObject::createAndBind() {
	glGenBuffers(1, &mId);
	bind();
}

void VertexBufferObject::bind() {
	glBindBuffer(GL_ARRAY_BUFFER, mId);
}

void VertexBufferObject::setData(glm::vec3* data, int verticesCount) {
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * verticesCount * 3, data, GL_STATIC_DRAW);
}

void VertexBufferObject::addAttributeVec3f(int stride, void* offset) {
	glEnableVertexAttribArray(mAttribIndex);
	glVertexAttribPointer(mAttribIndex, 3, GL_FLOAT, false, stride, offset);
	mAttribIndex++;
}

void VertexBufferObject::destroy() {
	glDeleteBuffers(1, &mId);
}