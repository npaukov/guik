#include "../../core.h"
#include "../../classes/events.h"

#include "init.h"
#include "editbox.h"

namespace guik {
/**guik::EditBox::EditBox(int x, int y, int size) {
	this->x = x;
	this->y = y;
	this->width = size;
	this->size = size;

	this->color = COLOR_RED;
	this->text_color = COLOR_BLACK;

	this->max = 255;

	this->text = "Hello, world!";

	this->updateStruct();
}

void guik::EditBox::updateStruct() {
	component.blur_border_color = this->blur_border_color;
	component.cl_curs_x = this->cl_curs_x;
	component.cl_curs_y = this->cl_curs_y;
	component.color = this->color;
	component.flags = this->flags;
	component.focus_border_color = this->focus_border_color;
	component.left = this->x;
	component.max = this->max;
	component.mouse_variable = (Dword)&this->mouse_variable;
	component.offset = this->offset;
	component.pos = this->pos;
	component.shift = this->shift;
	component.shift_color = this->shift_color;
	component.shift_old = this->shift_old;
	component.size = this->size;
	component.text = (Dword)this->text;
	component.text_color = this->text_color;
	component.top = this->y;
	component.width = this->width;
}*/

/**void guik::EditBox::draw() {
	if (!hidden) {
		BoxLib::edit_box_draw((Dword)&this->component);
	}
		//Dword mouse_dd;
		//char fname[256];
		//EditBoxStruct file_box = {200,100, 45, 0xffffff,0x6a9480, COLOR_RED, COLOR_YELLOW, 0x808080,255,(Dword)&fname,(Dword)&mouse_dd};
/**Dword width, left, top, color, shift_color, focus_border_color, blur_border_color,
text_color, max, text, mouse_variable*
		//BoxLib::edit_box_draw((Dword)&file_box);
	this->call(EVENT_DRAW);
}

void guik::EditBox::sysevent(int code) {
	switch (code) {
		case EVENT_KEY_PRESS:
			Byte keyCode;
			kos_GetKey(keyCode);


			__asm
			{
			mov ah, keyCode
			}

			this->component.text = (Dword)"Test!";

			//BoxLib::edit_box_key((Dword)&this->component);
		break;
	}

	BoxLib::edit_box_mouse((Dword)&this->component);
}

int guik::EditBox::getType() {
	return CONTROL_EDIT_BOX;
}

int guik::EditBox::getId() {
	return this->id;
}
*/
}