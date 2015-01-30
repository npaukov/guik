#include "init.h"

namespace guik {

dll* BoxLib::lib;
dword_func* BoxLib::edit_box_draw;
dword_func* BoxLib::edit_box_key;
dword_func* BoxLib::edit_box_mouse;
dword_func* BoxLib::edit_box_set_text;

void BoxLib::init() {
	lib = new dll("/sys/lib/box_lib.obj");
	lib->exitOnError = false;
	lib->load();
}

void BoxLib::initEditBox() {
	edit_box_draw = (dword_func*)lib->loadFunction("edit_box");
	edit_box_mouse = (dword_func*)lib->loadFunction("edit_box_mouse");
	edit_box_key = (dword_func*)lib->loadFunction("edit_box_key");
	edit_box_set_text = (dword_func*)lib->loadFunction("edit_box_set_text");
}

}