#pragma once
#include "../../core.h"
#include "../../components/dll.h"

namespace guik {

class BoxLib{
public:
	static dll* lib;
	static dword_func* edit_box_draw;
	static dword_func* edit_box_key;
	static dword_func* edit_box_mouse;
	static dword_func* edit_box_set_text;

	static void init();
	static void initEditBox();
};

#include "editbox.h"

}