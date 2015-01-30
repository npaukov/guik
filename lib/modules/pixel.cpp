#include "../core.h"
#include "pixel.h"
#include "../classes/draw.h"
namespace guik {

Pixel::Pixel(int x, int y, Dword color) : x(x), y(y), color(color) {

}

void Pixel::setX(int x) {
	this->x = x;
}

int Pixel::getX() {
	return this->x;
}

void Pixel::setY(int y) {
	this->y = y;
}

int Pixel::getY() {
	return this->y;
}

void Pixel::setColor(int color) {
	this->color = color;
}

int Pixel::getColor() {
	return this->color;
}

void Pixel::draw() {
	this->call(EVENT_DRAW);
	Draw::pixel(this->x, this->y, this->color);
}

int Pixel::getType() {
	return CONTROL_PIXEL;
}

int Pixel::getId() {
	return this->id;
}

}