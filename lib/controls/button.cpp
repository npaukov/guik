#include "button.h"
#include "../common.h"

int guik::Button::lastButtonCode = 0;

guik::Button::Button() {
    lastButtonCode = 0;
}

guik::Button::~Button() {

}

void guik::Button::init() {
	Control::init();
}

void guik::Button::destroy() {
	Control::destroy();
}

void guik::Button::draw(bool relative) {
	// Рисование кнопки
	if (this->visible) DefineButton(65536 * this->x + this->sizeX, 65536 * this->y + this->sizeY, this->id, this->backgroundColor.getHex());
	// Рисование дочерних элементов
	Control::draw(relative);
}

int guik::Button::getButtonCode() {
    lastButtonCode = get_os_button();
    return lastButtonCode;
}

int guik::Button::getLastButtonCode() {
    if (lastButtonCode == 0) lastButtonCode = get_os_button();

    return lastButtonCode;
}

void guik::Button::setLastButtonCode(int buttonCode) {
    lastButtonCode = buttonCode;
}

void guik::Button::onSysEvent(int event) {
    // Системное событие, клик по кнопке
    if (event == 3) {
        if (Button::getLastButtonCode() == this->id) this->callEvent(guik::Button::EVENT_CLICK);
    }
    else Control::onSysEvent(event);
}

void guik::Button::clearLastButtonCode() {
    lastButtonCode = 0;
}


