#include "Heightmap.h"
#include "ShaderProgram.h"
#include "Resources.h"
#include <SDL.h>

void multByStep(float step, float maxHeight, glm::vec3& v) {
	v.x *= step;
	v.y *= maxHeight;
	v.z *= step;
}

void findColor(const glm::vec3& vertex, std::vector<glm::vec3>& colors) {
	if (vertex.y < 0.015) colors.push_back(glm::vec3(0.93f, 0.69f, 0.52f));
	else if (vertex.y >= 0.015 && vertex.y <= 3.0f) colors.push_back(glm::vec3(0.75f, 0.73f, 0.3f));
	else colors.push_back(glm::vec3(0.35, 0.35, 0.35));
}

Uint32 getpixel(SDL_Surface* surface, int x, int y)
{
	int bpp = surface->format->BytesPerPixel;
	/* Here p is the address to the pixel we want to retrieve */
	Uint8* p = (Uint8*)surface->pixels + y * surface->pitch + x * bpp;

	switch (bpp)
	{
	case 1:
		return *p;
		break;

	case 2:
		return *(Uint16*)p;
		break;

	case 3:
		if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
			return p[0] << 16 | p[1] << 8 | p[2];
		else
			return p[0] | p[1] << 8 | p[2] << 16;
		break;

	case 4:
		return *(Uint32*)p;
		break;

	default:
		return 0;       /* shouldn't happen, but avoids warnings */
	}
}


SDL_Color getColor(SDL_Surface* surface, int x, int y) {
	SDL_Color rgb;
	Uint32 data = getpixel(surface, x, y);
	SDL_GetRGB(data, surface->format, &rgb.r, &rgb.g, &rgb.b);
	return rgb;
}

Heightmap::Heightmap() : mWidth(0), mDeep(0), mStep(1.0f), mMaxHeight(0.0f) {

}

Heightmap::~Heightmap() {

}

void Heightmap::load(const std::string& filename) {
	SDL_Surface* s = SDL_LoadBMP(filename.c_str());
	mWidth = s->w;
	mDeep = s->h;
	mHeights.reserve(mWidth * mDeep);

	Uint8* pixels = (Uint8*)s->pixels;
	for (int r = 0; r < s->h; ++r) {
		for (int c = 0; c < s->pitch; ++c) {
			SDL_Color col = getColor(s, c, r);
			//Uint8* p = pixels + r * s->pitch + c * s->format->BytesPerPixel;
			mHeights.push_back((float)(col.r / 255.0f));
		}
	}
 }

void Heightmap::init(float step, float maxHeight) {

	mStep = step;
	mMaxHeight = maxHeight;

	std::vector<glm::vec3> normals;
	std::vector<glm::vec3> colors;

	for (int r = 0; r < mDeep - 1; r++) {
		for (int c = 0; c < mWidth - 1; ++c) {
			int startIndex = mVertices.size();

			mVertices.push_back(glm::vec3(c + 0, mHeights[(mWidth * (r + 1)) + c + 0], r + 1));
			mVertices.push_back(glm::vec3(c + 0, mHeights[(mWidth * (r + 0)) + c + 0], r + 0));
			mVertices.push_back(glm::vec3(c + 1, mHeights[(mWidth * (r + 1)) + c + 1], r + 1));

			findColor(mVertices[startIndex], colors);
			findColor(mVertices[startIndex+1], colors);
			findColor(mVertices[startIndex+2], colors);

			multByStep(step, maxHeight, mVertices[startIndex]);
			multByStep(step, maxHeight, mVertices[startIndex+1]);
			multByStep(step, maxHeight, mVertices[startIndex+2]);

			{
				auto A = mVertices[startIndex + 1] - mVertices[startIndex];
				auto B = mVertices[startIndex] - mVertices[startIndex + 2];
				glm::vec3 normal = glm::normalize(glm::cross(A, B));
				normals.push_back(normal);
				normals.push_back(normal);
				normals.push_back(normal);
			}

			startIndex = mVertices.size();
			mVertices.push_back(glm::vec3(c + 0, mHeights[(mWidth * (r + 0)) + c + 0], r + 0));
			mVertices.push_back(glm::vec3(c + 1, mHeights[(mWidth * (r + 0)) + c + 1], r + 0));
			mVertices.push_back(glm::vec3(c + 1, mHeights[(mWidth * (r + 1)) + c + 1], r + 1));

			findColor(mVertices[startIndex], colors);
			findColor(mVertices[startIndex + 1], colors);
			findColor(mVertices[startIndex + 2], colors);

			multByStep(step, maxHeight, mVertices[startIndex]);
			multByStep(step, maxHeight, mVertices[startIndex + 1]);
			multByStep(step, maxHeight, mVertices[startIndex + 2]);

			{
				auto A = mVertices[startIndex + 1] - mVertices[startIndex];
				auto B = mVertices[startIndex] - mVertices[startIndex + 2];
				glm::vec3 normal = glm::normalize(glm::cross(A, B));
				normals.push_back(normal);
				normals.push_back(normal);
				normals.push_back(normal);
			}
		}
	}

	int vertexCount = mVertices.size();

	// color
	for (int i = 0; i < colors.size(); ++i) {
		mVertices.push_back(colors[i]);
	}

	// normals
	for(int i=0; i<normals.size(); ++i) {
		mVertices.push_back(normals[i]);
	}

	mVao.createAndBind();
	mVbo.createAndBind();
	mVbo.setData(mVertices.data(), vertexCount * 3);

	mVbo.addAttributeVec3f(0, 0);
	mVbo.addAttributeVec3f(0, (void*)(sizeof(glm::vec3) * vertexCount));
	mVbo.addAttributeVec3f(0, (void*)(sizeof(glm::vec3) * vertexCount * 2));
	mVao.unbind();

	mTrans.setTranslation(glm::vec3(0, 0, -5));
}

void Heightmap::update() {

}

void Heightmap::render() {
	ShaderProgram* p = Resources::instance()->getShaderProgram("standard");

	p->use();
	p->setUniformMat4("modelMat", mTrans.getMatrix());
	p->setUniformMat4("normalMat", mTrans.getMatrixNoTraslation());

	mVao.bind();
	OpenGL::drawArraysAsTriangles(0, mVertices.size() / 3);
	mVao.unbind();
}

void Heightmap::destroy() {
	mVbo.destroy();
	mVao.destroy();
}

bool Heightmap::getHeightAt(float x, float z, float* h) const {
	int realX = x / mStep;
	int realZ = z / mStep;

	if (realX < 0 || realX >= mWidth) return false;
	if (realZ < 0 || realZ >= mDeep) return false;

	*h = mHeights[(realZ * mWidth) + realX] * mMaxHeight;

	return true;
}