#pragma once

#include "../core.h"
#include "../classes/draw.h"

namespace guik {

void Draw::number(Dword value,Dword digitsNum,Word x,Word y,Dword colour,eNumberBase nBase, bool valueIsPointer) {
	Dword arg1, arg2;

	//
	arg1 = ( valueIsPointer ? 1 : 0 ) |
		( ((Byte)nBase) << 8 ) |
		( ( digitsNum & 0x1F ) << 16 );
	arg2 = ( x << 16 ) | y;
	//
	__asm{
		push 47
		pop eax
		mov ebx, arg1
		mov ecx, value
		mov edx, arg2
		mov esi, colour
		int 0x40
	}
}

// Нарисовать отрезок
void Draw::offcut(int startX, int startY, int endX, int endY, int color, bool inverse) {
	int x,y;
	x = startX*65536 + endX;
	y = startY*65536 + endY;

	color = (!inverse) ? color : 0x01000000;

	__asm{
		push 38
		pop eax
		mov ebx, x
		mov ecx, y
		mov edx, color
		int 0x40
	}
}

// Поставить пиксель
void Draw::pixel(Dword x, Dword y, Dword pxColor) {
	__asm{
		push 1
		pop eax
		mov ebx, x
		mov ecx, y
		mov edx, pxColor
		int 0x40
	}
}

void Draw::label(int x, int y, int fontType, int color, const char *text, int textLen) {
	int arg1, arg2;

	arg1 = ( x << 16 ) | y;
	arg2 = ( fontType << 24 ) | color;

	__asm{
		push 4
		pop eax
		mov ebx, arg1
		mov ecx, arg2
		mov edx, text
		mov esi, textLen
		int 0x40
	}
}

void Draw::window(int x, int y, int sizeX, int sizeY, int mainAreaType, int mainAreaColour, int headerType, int headerColor, int borderColour) {
	Dword arg1, arg2, arg3, arg4;

	//
	arg1 = ( x << 16 ) + sizeX;
	arg2 = ( y << 16 ) + sizeY;
	arg3 = ( mainAreaType << 24 ) | mainAreaColour;
	arg4 = ( headerType << 24 ) | headerColor;
	//

	__asm{
		push 0
		pop eax
		mov ebx, arg1
		mov ecx, arg2
		mov edx, arg3
		mov esi, arg4
		mov edi, borderColour
		int 0x40
	}
}

void Draw::button(int x, int y, int sizeX, int sizeY, int buttonID, int color) {
	int arg1, arg2;

	//
	arg1 = ( x << 16 ) | sizeX;
	arg2 = ( y << 16 ) | sizeY;
	//
	__asm{
		push 8
		pop eax
		mov ebx, arg1
		mov ecx, arg2
		mov edx, buttonID
		mov esi, color
		int 0x40
	}
}

}