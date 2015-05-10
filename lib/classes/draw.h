#pragma once
#include "../core.h"

namespace guik {

class Draw {
public:
	static void number(Dword value,Dword digitsNum,Word x,Word y,Dword colour,eNumberBase nBase = nbDecimal,bool valueIsPointer=false);
	static void offcut(int startX, int startY, int endX, int endY, int color=COLOR_BLACK, bool inverse=false);
	static void pixel(Dword x, Dword y, Dword pxColor);

	static void window(int x, int y, int sizeX, int sizeY, int mainAreaType, int mainAreaColour, int headerType, int headerColor, int borderColour);
	static void button(int x, int y, int sizeX, int sizeY, int buttonID, int color);
	static void label(int x, int y, int fontType, int color, const char *text, int textLen);
};

}