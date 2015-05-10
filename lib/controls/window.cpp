#include "window.h"
#include "../common.h"
#include "../controls/button.h"

oskey_t guik::Window::lastKey;

guik::Window::Window() {

}

guik::Window::~Window() {

}

void guik::Window::init() {
	Control::init();
}

void guik::Window::destroy() {
	Control::destroy();
}

void guik::Window::draw(bool relative) {
	BeginDraw();

	// Рисование самого окна
	if (this->visible) DrawWindow(this->x, this->y, this->sizeX, this->sizeY, this->title.getString(), this->color.getHex(), this->style);
	// Рисование всех дочерних объектов
	Control::draw(false);

	EndDraw();
}

void guik::Window::setStyle(int style) {
	this->style = style;
}

int guik::Window::getStyle() {
	return this->style;
}

void guik::Window::setTitle(const char* Title) {
	this->title = Title;
}

const char* guik::Window::getTitle() {
	return this->title.getString();
}


int guik::Window::getKeyCode() {
    lastKey = get_key();
    return lastKey.code;
}

int guik::Window::getLastKeyCode() {
    if (lastKey.code == 0) lastKey = get_key();

    return lastKey.code;
}

void guik::Window::setLastKeyCode(int keyCode) {
    lastKey.code = keyCode;
}

void guik::Window::onSysEvent(int event) {
    // Системное событие, клик по кнопке
    if (event == 2) {
        this->callEvent(guik::Window::EVENT_KEY);
    }

    Control::onSysEvent(event);
}

void guik::Window::clearLastKeyCode() {
    lastKey.code = 0;
}
