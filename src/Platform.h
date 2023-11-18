#pragma once

#include <SDL.h>

class App;

class Platform {
public:
	Platform();
	~Platform();

	void init();
	void run(App* app);
	void quit();

private:
	SDL_Window* mWindow;
};