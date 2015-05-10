#include "lib/guik.h"

using namespace guik;

int main() {
	Application* app = Application::getInstance();
	Window win;
	app->setWindow(&win);

	win.setPosition(20, 20);
	win.setSize(400, 200);
	win.setTitle("123");
	win.setStyle(3);
	win.color = Color(255, 255, 255);
	win.setName("MyWindow");
	win.setId(1);

	Label label;
	label.setPosition(10, 25);
	label.setText("Hello, world! Is is my first GUIK application!");
	label.textColor.setColor(100, 100, 0);

    win.addChild(&label);

    //int event;

    win.init();

    app->run();

	/**while (event = app->getSystemEventCode()) {
	    Button::clearLastButtonCode();
        Window::clearLastKeyCode();

        if (event == 3) {
            int key = Button::getButtonCode();
            if (key == 1) {
                win.destroy();
                return 0;
            }
        }
        else if (event == 2) {

        }

        app->routeEvent(event, 0);
        app->getWindow()->draw();
	}*/

	win.destroy();
	//app.run();

	return 0;
}
