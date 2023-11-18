#include "HillsApp.h"
#include "ShaderProgram.h"
#include "Projections.h"
#include "Resources.h"
#include "Header.h"
#include "CameraFreeRoaming.h"
#include "World.h"
#include <iostream>

HillsApp::HillsApp() {

}

HillsApp::~HillsApp() {

}

void HillsApp::init() {
	ShaderProgram* program = new ShaderProgram("standard");
	Shader vs, fs;
	if (!vs.loadFromFile("vertexShader.glsl", GL_VERTEX_SHADER)) {
		std::cerr << "error compiling vertex shader" << std::endl;
	}
	if (!fs.loadFromFile("fragmentShader.glsl", GL_FRAGMENT_SHADER)) {
		std::cerr << "error compiling fragment shader" << std::endl;
	}
	program->create();
	program->addShader(&vs);
	program->addShader(&fs);
	if (!program->link()) {
		std::cerr << "error linking shader program" << std::endl;
	}
	program->use();
	Resources::instance()->addShaderProgram(program);
	Camera* cam1 = new Camera(CAMERA_ID_1);
	cam1->set({ 0, 0, 3 }, { 0, 0, -3 });
	Resources::instance()->getCameraPool()->add(cam1);
	CameraFreeRoaming* cam2 = new CameraFreeRoaming(CAMERA_ID_FREE_ROAMING);
	cam2->set({ 128, 22.0, 1 }, { 128, 22.0, 5 });
	cam2->setSpeed(10.0f);
	cam2->setRotationSpeed(45.0f);
	Resources::instance()->getCameraPool()->add(cam2);
	Resources::instance()->getProjections()->buildProjection3d();

	mTerrain.load("hill3.bmp");
	mTerrain.init(2.0f, 30.0f);

	World::instance()->setTerrain(&mTerrain);
}

void HillsApp::update() {
	Resources::instance()->getCameraPool()->getActiveCamera()->update(60.0f);
}

void HillsApp::render() {
	ShaderProgram* p = Resources::instance()->getShaderProgram("standard");
	Camera* cam = Resources::instance()->getCameraPool()->getActiveCamera();
	const Projections* proj = Resources::instance()->getProjections();

	p->use();
	p->setUniformMat4("projectionMat", proj->getProjection3d());
	p->setUniformMat4("viewMat", cam->getMatrix());
	p->setUniformVec3("ambientLight", { 0.2f, 0.2f, 0.2f });

	mTerrain.render();
}

void HillsApp::quit() {
	mTerrain.destroy();
}