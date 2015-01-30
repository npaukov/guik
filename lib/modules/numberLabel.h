#pragma once
#include "../core.h"

namespace guik {

class NumberLabel : public Control {
public:
	int getType();

	NumberLabel(int number, int x=10, int y=10, int color=COLOR_BLACK,int digits=2);

	void draw();

	int getId();
	void setX(int x);
	int getX();
	void setY(int y);
	int getY();

	void setColor(int color);
	int getColor();

	void setNumber(int number);
	int getNumber();

	void setDigits(int digits);
	int getDigits();

protected:
	Word x,y;
	Dword id;
	Dword color;
	Dword digits, num;
	eNumberBase nBase;
	int type;
};

}