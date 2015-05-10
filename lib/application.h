#pragma once
#include "common.h"
#include "controls/window.h"

namespace guik {

class Application {
public:
    virtual ~Application() {
		if (window) {
			//delete window;
		}
	};
	virtual void init() {};

	virtual void setWindow(Window* window);
	virtual Window* getWindow();

    virtual bool run();

	static Application* getInstance();

    virtual void routeEvent(int event, bool mode);
    virtual int getSystemEventCode();

    //int test; // Использовалось для тестирования Singleton
protected:
	static Application* Instance;
	Window* window;

    Application() {
		window = 0;
		//test = 15;
	};
};

}
