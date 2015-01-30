#pragma once

namespace guik {
typedef unsigned __int32 Dword;
typedef unsigned __int16 Word;
typedef unsigned __int8 Byte;

#define NULL 0

void kos_WindowRedrawStatus(Dword status);

inline Dword kos_sysfunc2(void);
bool kos_GetButtonID(Dword &buttonID);
bool kos_GetKey(Byte &keyCode);

enum eNumberBase
{
	nbDecimal = 0,
	nbHex,
	nbBin
};

int strcmp(const char *s1, const char *s2);
void gstrcpy(char *str1, const char *str2);
char* gstrcat( char* dest, const char* src );
int gstrlen(const char* c_str);
}