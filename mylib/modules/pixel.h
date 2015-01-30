#pragma once
#include "../core.h"

namespace guik {

class Pixel : public Control {
public:
	Pixel(int x, int y, Dword color=COLOR_BLACK);
	void update();

	void setX(int x);
	int getX();
	void setY(int y);
	int getY();
	void setColor(int color);
	int getColor();

	virtual int getId();
	int getType();

	void draw();
protected:
	Word x,y;
	Dword id;
	Dword color;

	int type;
};

}