#include "functions.h"

#ifdef RUN_ON_WINDOWS
#include <iostream>
#endif

#include "../common.h"

guik::RGBColor::RGBColor() : r(0), g(0), b(0) {

}

guik::RGBColor::RGBColor(int r, int g, int b) : r(r), g(g), b(b) {

}

int guik::RGBColor::getHex() {
	return (r<<16) | (g<<8) | b;
}

void guik::RGBColor::setColor(int rc, int gc, int bc) {
	r = rc;
	g = gc;
	b = bc;
}

void guik::RGBColor::setColor(int color) {
	r = ((color >> 16) & 0xFF) / 255.0;
	g = ((color >> 8) & 0xFF) / 255.0;
	b = ((color) & 0xFF) / 255.0;
}

/**
* ¬ывод строки на доску отладки,
* если запускаетс€ под Windows,
* то выводитс€ в консоли
*/
void guik::debug(const char* message) {
#ifdef RUN_ON_WINDOWS
	std::cout << message << std::endl;
#else
	guik::BoardPuts(message);
#endif
}

/**
* ¬ывод строки на доску отладки,
* если запускаетс€ под Windows,
* то выводитс€ в консоли
*/
void guik::BoardPuts(const char *str) {
#ifndef RUN_ON_WINDOWS
	unsigned int i = 0;
	while(*(str + i)) {
		asm volatile ("int $0x40"::"a"(63), "b"(1), "c"(*(str + i)));
		i++;
	}
#else
	debug((char*)str);
#endif
}

/**
* ”становка маски дл€ получаемых событий,
* если запускаетс€ под Windows, то
* функци€ не выполн€ет никаких действий
*/
void guik::SetMaskForEvents(unsigned int mask) {
#ifndef RUN_ON_WINDOWS
	asm volatile ("int $0x40"::"a"(40), "b"(mask));
#endif
}

 char* guik::itoa(int number, char *destination, int base) {
    int count = 0;
    do {
        int digit = number % base;
        destination[count++] = (digit > 9) ? digit - 10 +'A' : digit + '0';
    } while ((number /= base) != 0);

    destination[count] = '\0';
    int i;

    for (i = 0; i < count / 2; ++i) {
        char symbol = destination[i];
        destination[i] = destination[count - i - 1];
        destination[count - i - 1] = symbol;
    }

    return destination;
}


char* guik::toString(int number, int base) {
    char* buffer;
    return guik::itoa(number, buffer, base);
}
