#include "../common.h"
#include "label.h"

guik::Label::Label() {

}

guik::Label::~Label() {

}

void guik::Label::init() {
	Control::init();
}

void guik::Label::destroy() {
	Control::destroy();
}

void guik::Label::draw(bool relative) {
	// Рисование налписи
    if (this->visible) draw_text_sys(this->text.getString(), this->x, this->y, this->text.getSize(), this->textColor.getHex());
	// Рисование дочерних элементов
	Control::draw(relative);
}

const char* guik::Label::getText() {
    return this->text.getString();
}

void guik::Label::setText(const char* text) {
    this->text = text;
}
