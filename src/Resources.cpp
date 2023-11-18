#include "Resources.h"

Resources* Resources::mInstance = nullptr;

Resources::~Resources() {

}

Resources::Resources() {

}

Resources* Resources::instance() {
	if (mInstance == nullptr) mInstance = new Resources();
	return mInstance;
}

void Resources::addShaderProgram(ShaderProgram* p) {
	if (mShaders.find(p->name()) == mShaders.end()) {
		mShaders[p->name()] = p;
	}
}

ShaderProgram* Resources::getShaderProgram(const std::string& name) {
	return mShaders[name];
}
