#include "sys.h"

namespace guik {

inline Dword kos_sysfunc2(void)
{
	__asm push 2
	__asm pop eax
	__asm int 0x40
}

// функция 2 получить код нажатой клавиши
bool kos_GetKey( Byte &keyCode )
{
	Dword result = kos_sysfunc2();
	//
	keyCode = result >> 8;
	//
	return ( result & 0xFF ) == 0;
}

// функция 12
void kos_WindowRedrawStatus( Dword status )
{
	__asm{
		push 12
		pop eax
		mov ebx, status
		int 0x40
	}
}

// функция 17
bool kos_GetButtonID( Dword &buttonID )
{
	Dword result;

	//
	__asm{
		push 17
		pop eax
		int 0x40
		mov result, eax
	}
	//
	buttonID = result >> 8;
	//
	return (result & 0xFF) == 0;
}

int strcmp(const char *s1, const char *s2) {
	int i;
 
	if (s1 == NULL) {
		if (s2 == NULL)
			return 0;
		else
			return 1;
	}
	else {
		if (s2 == NULL) return 1;
 
		for (i = 0;;i++) {
			if (s1[i] == '\0') {
				if (s2[i] == '\0')
					return 0;
				else
					return 1;
			}
			else {
				if (s2[i] == '\0')
					return 1;
				else {
					if (s1[i] != s2[i]) return 1;
				}
			}
        }
        return 0;
	}
}

void gstrcpy(char *str1, const char *str2)
{
    while(*str2) *str1++=*str2++;
    *str1=0;
}

 char* gstrcat( char* dest, const char* src )
 {
      while (*dest) dest++;
      while (*dest++ = *src++);
      return --dest;
 }

int gstrlen(const char* c_str)
{
    int count=0;
    while(*c_str++) ++count;
    return count;
}

}