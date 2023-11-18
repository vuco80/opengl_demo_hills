#include "Cube.h"
#include "OpenGL.h"
#include "Resources.h"
#include "Projections.h"
#include <iostream>
#include <glm.hpp>

Cube::Cube() {

}

Cube::~Cube() {

}

void Cube::init() {

	mVertices[0] = glm::vec3(-0.5, -0.5, 0.5);
	mVertices[1] = glm::vec3(-0.5, 0.5, 0.5);
	mVertices[2] = glm::vec3(0.5, -0.5, 0.5);
	mVertices[3] = glm::vec3(0.5, 0.5, 0.5);
	mVertices[4] = glm::vec3(0.5, -0.5, 0.5);
	mVertices[5] = glm::vec3(-0.5, 0.5, 0.5);
	mVertices[6] = glm::vec3(0.5, -0.5, 0.5);
	mVertices[7] = glm::vec3(0.5, 0.5, 0.5);
	mVertices[8] = glm::vec3(0.5, -0.5, -0.5);
	mVertices[9] = glm::vec3(0.5, -0.5, -0.5);
	mVertices[10] = glm::vec3(0.5, 0.5, 0.5);
	mVertices[11] = glm::vec3(0.5, 0.5, -0.5);
	mVertices[12] = glm::vec3(-0.5, -0.5, -0.5);
	mVertices[13] = glm::vec3(-0.5, 0.5, -0.5);
	mVertices[14] = glm::vec3(0.5, -0.5, -0.5);
	mVertices[15] = glm::vec3(0.5, 0.5, -0.5);
	mVertices[16] = glm::vec3(0.5, -0.5, -0.5);
	mVertices[17] = glm::vec3(-0.5, 0.5, -0.5);
	mVertices[18] = glm::vec3(-0.5, -0.5, 0.5);
	mVertices[19] = glm::vec3(-0.5, 0.5, 0.5);
	mVertices[20] = glm::vec3(-0.5, -0.5, -0.5);
	mVertices[21] = glm::vec3(-0.5, -0.5, -0.5);
	mVertices[22] = glm::vec3(-0.5, 0.5, 0.5);
	mVertices[23] = glm::vec3(-0.5, 0.5, -0.5);
	mVertices[24] = glm::vec3(-0.5, 0.5, 0.5);
	mVertices[25] = glm::vec3(-0.5, 0.5, -0.5);
	mVertices[26] = glm::vec3(0.5, 0.5, -0.5);
	mVertices[27] = glm::vec3(-0.5, 0.5, 0.5);
	mVertices[28] = glm::vec3(0.5, 0.5, -0.5);
	mVertices[29] = glm::vec3(0.5, 0.5, 0.5);
	mVertices[30] = glm::vec3(-0.5, -0.5, 0.5);
	mVertices[31] = glm::vec3(-0.5, -0.5, -0.5);
	mVertices[32] = glm::vec3(0.5, -0.5, -0.5);
	mVertices[33] = glm::vec3(-0.5, -0.5, 0.5);
	mVertices[34] = glm::vec3(0.5, -0.5, -0.5);
	mVertices[35] = glm::vec3(0.5, -0.5, 0.5);

	for (int i = 36; i < 72; ++i) mVertices[i] = glm::vec3(1.0f, 0.0f, 0.0f);

	/*mVertices[36] = glm::vec3(1.0f, 0, 0);
	mVertices[37] = glm::vec3(1.0f, 0, 0);
	mVertices[38] = glm::vec3(1.0f, 0, 0);
	mVertices[39] = glm::vec3(1.0f, 0, 0);
	mVertices[40] = glm::vec3(1.0f, 0, 0);
	mVertices[41] = glm::vec3(1.0f, 0, 0);
	mVertices[42] = glm::vec3(0.0f, 0.0f, 1);
	mVertices[43] = glm::vec3(0.0f, 0.0f, 1);
	mVertices[44] = glm::vec3(0.0f, 0.0f, 1);
	mVertices[45] = glm::vec3(0.0f, 0.0f, 1);
	mVertices[46] = glm::vec3(0.0f, 0.0f, 1);
	mVertices[47] = glm::vec3(0.0f, 0.0f, 1);
	mVertices[48] = glm::vec3(0.0f, 1.0f, 0);
	mVertices[49] = glm::vec3(0.0f, 1.0f, 0);
	mVertices[50] = glm::vec3(0.0f, 1.0f, 0);
	mVertices[51] = glm::vec3(0.0f, 1.0f, 0);
	mVertices[52] = glm::vec3(0.0f, 1.0f, 0);
	mVertices[53] = glm::vec3(0.0f, 1.0f, 0);
	mVertices[54] = glm::vec3(1.0f, 1.0f, 0);
	mVertices[55] = glm::vec3(1.0f, 1.0f, 0);
	mVertices[56] = glm::vec3(1.0f, 1.0f, 0);
	mVertices[57] = glm::vec3(1.0f, 1.0f, 0);
	mVertices[58] = glm::vec3(1.0f, 1.0f, 0);
	mVertices[59] = glm::vec3(1.0f, 1.0f, 0);
	mVertices[60] = glm::vec3(0.5f, 0.5f, 0.5f);
	mVertices[61] = glm::vec3(0.5f, 0.5f, 0.5f);
	mVertices[62] = glm::vec3(0.5f, 0.5f, 0.5f);
	mVertices[63] = glm::vec3(0.5f, 0.5f, 0.5f);
	mVertices[64] = glm::vec3(0.5f, 0.5f, 0.5f);
	mVertices[65] = glm::vec3(0.5f, 0.5f, 0.5f);
	mVertices[66] = glm::vec3(0.2f, 0.8f, 0.4f);
	mVertices[67] = glm::vec3(0.2f, 0.8f, 0.4f);
	mVertices[68] = glm::vec3(0.2f, 0.8f, 0.4f);
	mVertices[69] = glm::vec3(0.2f, 0.8f, 0.4f);
	mVertices[70] = glm::vec3(0.2f, 0.8f, 0.4f);
	mVertices[71] = glm::vec3(0.2f, 0.8f, 0.4f);*/

	// normals

	mVertices[72] = glm::vec3(0, 0, 1);
	mVertices[73] = glm::vec3(0, 0, 1);
	mVertices[74] = glm::vec3(0, 0, 1);
	mVertices[75] = glm::vec3(0, 0, 1);
	mVertices[76] = glm::vec3(0, 0, 1);
	mVertices[77] = glm::vec3(0, 0, 1);
	mVertices[78] = glm::vec3(1, 0, 0);
	mVertices[79] = glm::vec3(1, 0, 0);
	mVertices[80] = glm::vec3(1, 0, 0);
	mVertices[81] = glm::vec3(1, 0, 0);
	mVertices[82] = glm::vec3(1, 0, 0);
	mVertices[83] = glm::vec3(1, 0, 0);
	mVertices[84] = glm::vec3(0, 0, -1);
	mVertices[85] = glm::vec3(0, 0, -1);
	mVertices[86] = glm::vec3(0, 0, -1);
	mVertices[87] = glm::vec3(0, 0, -1);
	mVertices[88] = glm::vec3(0, 0, -1);
	mVertices[89] = glm::vec3(0, 0, -1);
	mVertices[90] = glm::vec3(-1, 0, 0);
	mVertices[91] = glm::vec3(-1, 0, 0);
	mVertices[92] = glm::vec3(-1, 0, 0);
	mVertices[93] = glm::vec3(-1, 0, 0);
	mVertices[94] = glm::vec3(-1, 0, 0);
	mVertices[95] = glm::vec3(-1, 0, 0);
	mVertices[96] = glm::vec3(0, 1, 0);
	mVertices[97] = glm::vec3(0, 1, 0);
	mVertices[98] = glm::vec3(0, 1, 0);
	mVertices[99] = glm::vec3(0, 1, 0);
	mVertices[100] = glm::vec3(0, 1, 0);
	mVertices[101] = glm::vec3(0, 1, 0);
	mVertices[102] = glm::vec3(0, -1, 0);
	mVertices[103] = glm::vec3(0, -1, 0);
	mVertices[104] = glm::vec3(0, -1, 0);
	mVertices[105] = glm::vec3(0, -1, 0);
	mVertices[106] = glm::vec3(0, -1, 0);
	mVertices[107] = glm::vec3(0, -1, 0);

	mVao.createAndBind();
	mVbo.createAndBind();
	mVbo.setData(mVertices, 108);

	mVbo.addAttributeVec3f(0, 0);
	mVbo.addAttributeVec3f(0, (void*)(sizeof(glm::vec3) * 36));
	mVbo.addAttributeVec3f(0, (void*)(sizeof(glm::vec3) * 72));
	mVao.unbind();	
}

void Cube::update() {
}

void Cube::render() {
	ShaderProgram* p = Resources::instance()->getShaderProgram("standard");

	p->use();
	p->setUniformMat4("modelMat", mTrans.getMatrix());
	p->setUniformMat4("normalMat", mTrans.getMatrixNoTraslation());

	mVao.bind();
	OpenGL::drawArraysAsTriangles(0, 36);
	mVao.unbind();
}

void Cube::destroy() {
	mVbo.destroy();
	mVao.destroy();
}