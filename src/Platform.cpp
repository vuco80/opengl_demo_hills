#include "Platform.h"
#include <GL\glew.h>
#include "App.h"
#include "Projections.h"

Platform::Platform() : mWindow(nullptr) {

}

Platform::~Platform() {

}

void Platform::init() {
	const int width = 1920;
	const int height = 1080;
	//const int width = 800;
	//const int height = 600;

	SDL_Init(SDL_INIT_VIDEO);
	mWindow = SDL_CreateWindow("Hills", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL /* | SDL_WINDOW_FULLSCREEN*/);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	SDL_GL_CreateContext(mWindow);
	glewExperimental = true;
	glewInit();
	SDL_GL_SetSwapInterval(1);
	//glClearColor(0.15f, 0.1f, 0.1f, 1.0f);
	glClearColor(0.67f, 0.86f, 1.0f, 1.0f);
	glViewport(0, 0, width, height);
	Projections::setScreenSize(width, height);

	glEnable(GL_DEPTH_TEST);
	glFrontFace(GL_CW);
	glCullFace(GL_BACK);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void Platform::run(App* app) {
	bool run = true;

	app->init();

	Uint32 frametime = SDL_GetTicks();
	Uint32 framestep = 16;
	Uint32 frameaccum = 0;

	while (run) {
		Uint32 now = SDL_GetTicks();
		Uint32 elapsed = now - frametime;
		frametime = now;
		frameaccum += elapsed;

		SDL_Event evt;
		while (SDL_PollEvent(&evt)) {
			switch (evt.type) {
			case SDL_QUIT:
				run = false;
				break;
			}
		}

		while (frameaccum >= framestep) {
			frameaccum -= framestep;
			app->update();
		}

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		app->render();
		SDL_GL_SwapWindow(mWindow);
	}
	
}

void Platform::quit() {
	SDL_DestroyWindow(mWindow);
	SDL_Quit();
}