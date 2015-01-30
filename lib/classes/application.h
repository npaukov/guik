#pragma once
#include "../core.h"

namespace guik {

class Application {
public:
	static Window* win;
	static void setWindow(Window* win);
	static Window* getWindow();
	static void run();
	//static void start();

	static void exit();
	static void Release();
protected:
	static int waitForEvents();
	static void eventsHandler();
};

}