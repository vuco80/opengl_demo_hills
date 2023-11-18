#pragma once

class App {
public:
	App() {}
	virtual ~App() {}

	virtual void init() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void quit() = 0;
};