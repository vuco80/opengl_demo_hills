#include "Platform.h"
#include "HillsApp.h"

int main(int argc, char** argv) {
	Platform platform;
	App* hills = new HillsApp();

	platform.init();
	platform.run(hills);
	hills->quit();
	platform.quit();

	return 0;
}