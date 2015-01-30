#include "../core.h"
#include "dll.h"

#include "../functions/string.h"
namespace guik {

dll::dll(char* path) {
	this->path = path;
	exitOnError = false;
}

dll_import* dll::load() {
	dll_import* res;
	char* path = this->path;
	__asm{
		mov eax, 68
		mov ebx, 19
		mov ecx, path
		int 0x40
		mov res, eax
	}

	if (!res && this->exitOnError == true) Application::exit();

	this->table = res;
	if (!res) this->status = false;
	return res;
}

void* dll::loadFunction(dll_import* lib, char* function) {
	int i;
	for (i=0;;i++) {
		if (((lib+i) -> name) == NULL) {
			break;
		}

		if (strcmp(function, (lib+i)->name) == 0) {
			return (lib+i)->data;
		}
	}

	if (this->exitOnError == true) Application::exit();
	this->status = false;
	return NULL;
}

void* dll::loadFunction(char* function) {
	return this->loadFunction(this->table, function);
}

}