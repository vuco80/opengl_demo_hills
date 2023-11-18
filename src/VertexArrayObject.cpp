#include "VertexArrayObject.h"

VertexArrayObject::VertexArrayObject() : mId(0) {

}

VertexArrayObject::~VertexArrayObject() {

}

void VertexArrayObject::createAndBind() {
	glGenVertexArrays(1, &mId);
	bind();
}

void VertexArrayObject::bind() {
	glBindVertexArray(mId);
}

void VertexArrayObject::unbind() {
	glBindVertexArray(0);
}

void VertexArrayObject::destroy() {
	glDeleteVertexArrays(1, &mId);
}