#include <kosSyst.h>
#include <kosFile.h>

#include "mylib/core.h"

#include "mylib/modules/offcut.h"
#include "mylib/modules/pixels.h"
#include "mylib/modules/numberLabel.h"

class ApplicationWindow : public guik::Window {
public:
	class Minus : public guik::Button {
	public:
		Minus() : Button(6, 10, 10, 50, 10, COLOR_RED) {
			
		};

		void onClick() {
			//Button* btn = ApplicationWindow::getWindow()->btn;
			//btn->text->setPaddingLeft(btn->text->getPaddingLeft()-1);
			//btn->text->setPaddingTop(btn->text->getPaddingTop()-1);
			ApplicationWindow::getWindow()->update();
		};
	};

	class Plus : public guik::Button {
	public:
		Plus() : Button(7, 80, 10, 50, 10, COLOR_GREEN) {
			
		};

		void onClick() {
			//Button* btn = ApplicationWindow::getWindow()->btn;
			//btn->text->setPaddingLeft(btn->text->getPaddingLeft()+1);
			//btn->text->setPaddingTop(btn->text->getPaddingTop()+1);
			ApplicationWindow::getWindow()->update();
		};
	};

	guik::Button* btn;

	Minus* minus;
	Plus* plus;

	void start() {
		class hello {

		};
		btn = new guik::Button(5, 100, 100);
		//btn->setText("Hello, button!");

		minus = new Minus();
		plus = new Plus();

		this->addControl(btn);
		this->addControl(plus);
		this->addControl(minus);
	};

	static ApplicationWindow* getWindow() {
		static ApplicationWindow* object;
		if (!object) object = new ApplicationWindow();
		return object;
	};

private:
	
	ApplicationWindow() : Window("Hello, C++") {
	};
};

void kos_Main() {
	using guik::Application;
	kos_GetSystemClock();


	ApplicationWindow* win = ApplicationWindow::getWindow();
	win->start();

	Application::setWindow(win);
	Application::run();
}