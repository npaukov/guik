#pragma once

namespace guik {

struct EditBoxStruct {
Dword width, left, top, color, shift_color, focus_border_color, blur_border_color,
text_color, max, text, mouse_variable, flags, size, pos, offset, cl_curs_x, cl_curs_y, shift, shift_old;
};

class EditBox : public Control {
public:
	Dword id;
	Word x,y, width, left, top;
	Dword color, shift_color, focus_border_color, blur_border_color, text_color;
	Dword max;
	char* text;

	Dword mouse_variable;
	Dword flags;
	Dword size, pos, offset;
	Dword cl_curs_x, cl_curs_y;
	Dword shift, shift_old;

	bool hidden;

	EditBoxStruct component;

	int type;

	EditBox(int x, int y, int width);

	void updateStruct();

	int getType();
	void draw();

	virtual int getId();
	virtual void sysevent(int code);
};

}