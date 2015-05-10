#include "core.h"

namespace guik {


// Нарисовать прямоугольник
void draw_rectangle(int x, int y, int sizex, int sizey, int color) {
	x = x*65536+sizex;
	y = y*65536+sizey;
	__asm{
		push 13
		pop eax
		mov ebx, x
		mov ecx, y
		mov edx, color
		int 0x40
	}
}

}