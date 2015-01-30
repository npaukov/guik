#include "../core.h"
#include "../modules/pixels.h"

namespace guik {

Pixels::Pixels(int x, int y, int sizeX, int sizeY, Dword color) : x(x), y(y), sizeX(sizeX), sizeY(sizeY), color(color), defColor(color) {
	this->map = new int*[sizeY];

	int i,j;
	for (i=0;i<sizeY;i++) {
		this->map[i] = new int[sizeX];
		for (j=0;j<sizeX;j++) {
			this->map[i][j] = color;
		}
	}
}


void Pixels::setX(int x) {
	this->x = x;
}

int Pixels::getX() {
	return this->x;
}

void Pixels::setY(int y) {
	this->y = y;
}

int Pixels::getY() {
	return this->y;
}

void Pixels::setSizeX(int sizeX) {
	this->sizeX = sizeX;
}

int Pixels::getSizeX() {
	return this->sizeX;
}

void Pixels::setSizeY(int sizeY) {
	this->sizeY = sizeY;
}

int Pixels::getSizeY() {
	return this->sizeY;
}


int Pixels::getPixelColor(int x, int y) {
	if (x >=sizeX || y >= sizeY) return false;
	return this->map[y][x];
}

void Pixels::draw() {
	this->call(EVENT_DRAW);
	int y,x, pxColor;

	for (y=0;y<sizeY;y++) {
		for (x=0;x<sizeX;x++) {
			pxColor = this->map[y][x];
			this->drawPixel(x,y,(Dword)pxColor);
		}
	}
}

void Pixels::updateMap() {
	int y,x;

	delete[] this->map;
	this->map = new int*[this->sizeY];

	for (y=0;y<sizeY;y++) {
		this->map[y] = new int[sizeX];
		for (x=0;x<sizeX;x++) {
			this->map[y][x] = this->color;
		}
	}

	this->defColor = this->color;
}

void Pixels::SetPixelColor(int x, int y, Dword pxColor) {
	this->map[y][x] = pxColor;
}

int Pixels::getType() {
	return CONTROL_PIXELS;
}

int Pixels::getId() {
	return this->id;
}

// функция 1 поставить точку
void Pixels::drawPixel(Dword x, Dword y, Dword pxColor) {
	x += this->x;
	y += this->y;

	//Dword pxColor = (Dword)this->color;

	__asm{
		push 1
		pop eax
		mov ebx, x
		mov ecx, y
		mov edx, pxColor
		int 0x40
	}
}

}