#pragma once

#include "../core.h"
#include "numberLabel.h"
#include "../classes/draw.h"

namespace guik {

void NumberLabel::setX(int x) {
	this->x = x;
}

int NumberLabel::getX() {
	return this->x;
}

void NumberLabel::setY(int y) {
	this->y = y;
}

int NumberLabel::getY() {
	return this->y;
}

void NumberLabel::setColor(int color) {
	this->color = color;
}

int NumberLabel::getColor() {
	return this->color;
}

void NumberLabel::setNumber(int number) {
	this->num = number;
}

int NumberLabel::getNumber() {
	return this->num;
}

void NumberLabel::setDigits(int digits) {
	this->digits = digits;
}

int NumberLabel::getDigits() {
	return this->digits;
}

NumberLabel::NumberLabel(int number, int x, int y, int color,int digits) : x(x), y(y), num(number), digits(digits), color(color) {

}

int NumberLabel::getType() {
	return CONTROL_NUMBER_LABEL;
}

int NumberLabel::getId() {
	return this->id;
}

// функция 1 поставить точку
void NumberLabel::draw() {
	this->call(EVENT_DRAW);
	Draw::number(this->num, this->digits, this->x, this->y, this->color);
}

}