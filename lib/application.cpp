#include "application.h"
#include "kos32sys.h"


using namespace guik;

guik::Application* guik::Application::Instance = 0;

bool guik::Application::run() {
	int eventCode;

	while (eventCode = get_os_event()) {
        switch (eventCode) {
            case 1:
                this->window->draw();
            break;

            case 3:
                int buttonKey = get_os_button();
                if (buttonKey == 1) {
                    this->window->destroy();
                    return false;
                }
            break;
        }
    }

	return true;
}

guik::Application* guik::Application::getInstance() {
    if(!Instance)
        Instance = new Application();
    return Instance;
}

void guik::Application::setWindow(guik::Window* window) {
	this->window = window;
}

guik::Window* guik::Application::getWindow() {
	return (Window*)this->window;
}

int guik::Application::getSystemEventCode() {
    return get_os_event();
}

void guik::Application::routeEvent(int event, bool mode=0) {
    // MODE - режим передачи событий (не используется)
    this->window->callSysEvent(event);
}
