#pragma once
#include "../core.h"

namespace guik {

class Pixels : public Control {
public:
	int getType();

	Pixels(int x, int y, int sizeX, int sizeY, Dword color=COLOR_BLACK);
	void SetPixelColor(int x, int y, Dword pxColor);

	void setX(int x);
	int getX();
	void setY(int y);
	int getY();

	void setSizeX(int sizeX);
	int getSizeX();
	void setSizeY(int sizeY);
	int getSizeY();

	int getPixelColor(int x, int y);

	void updateMap();

	virtual int getId();

	// функция 1 поставить точку
	void drawPixel(Dword x, Dword y, Dword color);

	void draw();

protected:
	Word x,y;
	Word sizeX, sizeY;
	Dword id;
	Dword color;
	Dword defColor;
	int** map;

	int type;
};

}