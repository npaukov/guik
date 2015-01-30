#pragma once

namespace guik {

struct dll_import {
	char *name;
	void *data;
};

typedef Dword __stdcall dword_func(Dword);

class dll {
public:
	char* path;
	bool status;
	dll_import* table;

	bool exitOnError;

	dll(char* path);
	
	dll_import* load();
	void* loadFunction(dll_import* lib, char* function);
	void* loadFunction(char* function);
};

}