#pragma once

namespace guik {

// ��������� ��� ���������� ������
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

// ����� ��������� �� ����� �������
void debug(const char* message);

// ����� ��������� �� ����� �������
void BoardPuts(const char *str);

// ��������� ����� ��� �������
void SetMaskForEvents(unsigned int mask);

// �������������� ����� � ������
char* itoa(int number, char *destination, int base);

char* toString(int number, int base = 10);
}
