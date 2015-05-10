#include "../core.h"
#include "../classes/events.h"

#include "../modules/label.h"
#include "../classes/draw.h"

namespace guik {

Label::Label(char* text, int x, int y, int color) : x(x),y(x),id(0),color(color),hidden(false),fontType(0x80),text(text) {
	
}

void Label::draw() {
	if (!hidden) Draw::label(x, y, fontType, color, text, 0);
	this->call(EVENT_DRAW);
}

void Label::setX(int x) {
	this->x = x;	
}

int Label::getX() {
	return this->x;
}

void Label::setY(int y) {
	this->y = y;
}

int Label::getY() {
	return this->y;
}

void Label::setColor(int color) {
	this->color = color;
}

int Label::getColor() {
	return this->color;
}

void Label::setHiddenState(bool hidden) {
	this->hidden = hidden;
}

bool Label::isHidden() {
	return this->hidden;
}

void Label::setFontType(int fontType) {
	this->fontType = fontType;
}

int Label::getFontType() {
	return this->fontType;
}

void Label::setText(char* text) {
	this->text = text;
}

void Label::setText(mstring text) {
	this->text = text;
}

char* Label::getText() {
	return (char*)this->text.getString();
}

mstring Label::getTextString() {
	return this->text;
}

int Label::getLength() {
	return this->text.getLength();
}

int Label::getType() {
	return CONTROL_LABEL;
}

void Label::Release() {
	
}

Label::~Label() {
	this->Release();	
}

int Label::getId() {
	return this->id;
}

}