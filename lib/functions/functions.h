#pragma once

namespace guik {

// Структура для управления цветом
struct RGBColor {
	int r, g, b;
	RGBColor();
	RGBColor(int r, int g, int b);

	void setColor(int color);
	void setColor(int rc, int gc, int bc);

	int getHex();

	operator int() const {
		return (r<<16) | (g<<8) | b;
	}

	static const int RED = 0xFF0000;
	static const int GREEN = 0x00FF00;
	static const int BLUE = 0x0000FF;
	static const int WHITE = 0xFFFFFF;
	static const int BLACK = 0x000000;
};

typedef RGBColor Color;

// Вывод сообщения на доску отладки
void debug(const char* message);

// Вывод сообщения на доску отладки
void BoardPuts(const char *str);

// Установка маски для событий
void SetMaskForEvents(unsigned int mask);

// Преобразование числа в строку
char* itoa(int number, char *destination, int base);

char* toString(int number, int base = 10);
}
