#include "../core.h"
#include "../classes/events.h"

#include "../modules/button.h"

#include "../classes/draw.h"

namespace guik {

void ButtonLabel::setPaddingLeft(int padding) {
	this->paddingLeft = padding;
}

int ButtonLabel::getPaddingLeft() {
	return this->paddingLeft;
}

void ButtonLabel::setPaddingRight(int padding) {
	this->paddingRight = padding;
}

int ButtonLabel::getPaddingRight() {
	return this->paddingRight;
}

void ButtonLabel::setPaddingTop(int padding) {
	this->paddingTop = padding;
}

int ButtonLabel::getPaddingTop() {
	return this->paddingTop;
}

void ButtonLabel::setPaddingBottom(int padding) {
	this->paddingBottom = padding;
}

int ButtonLabel::getPaddingBottom() {
	return this->paddingBottom;
}

int Button::getId() {
	return this->id;
}

void Button::setX(int x) {
	this->x = x;
}

int Button::getX() {
	return this->x;
}

void Button::setY(int y) {
	this->y = y;
}

int Button::getY() {
	return this->y;
}

void Button::setSizeX(int sizeX) {
	this->sizeX = sizeX;
}

int Button::getSizeX() {
	return this->sizeX;
}

void Button::setSizeY(int sizeY) {
	this->sizeY = sizeY;
}

int Button::getSizeY() {
	return this->sizeY;
}

void Button::setText(char* text) {
	this->enableLabel = true;
	this->text->setText(text);
}

char* Button::getText() {
	return this->text->getText();
}

void Button::setColor(int color) {
	this->color = color;
}

int Button::getColor() {
	return this->color;
}

void Button::setHiddenState(bool hidden) {
	this->hidden = hidden;
}

bool Button::isHidden() {
	return this->hidden;
}

Button::Button(int id, int x, int y, int sizeX, int sizeY, int color) : id(id), x(x),y(y), sizeX(sizeX), sizeY(sizeY), 
				color(color), hidden(false), enableLabel(false), type(CONTROL_BUTTON)
{
	this->text = new ButtonLabel("Hello");
}

void Button::draw() {
	if (!hidden) {
		if (this->enableLabel) {
			// Ширина кнопки
			// Отступ слева
			this->sizeX = this->text->getPaddingLeft() + gstrlen(this->text->getText())*6 + this->text->getPaddingRight();

			// Высота кнопки
			// Отступ сверху
			this->sizeY = this->text->getPaddingTop() + 5 + this->text->getPaddingRight();

			this->text->setX(x+this->text->getPaddingLeft());
			this->text->setY(y+this->text->getPaddingTop());

			Draw::button(x, y, sizeX, sizeY, id, color );
			this->text->draw();
		}
		else {
			Draw::button(x, y, sizeX, sizeY, id, color );
		}
	}
	this->call(EVENT_DRAW);
}

Button::~Button() {
	delete this->text;
}

int Button::getType() {
	return CONTROL_BUTTON;
}

}