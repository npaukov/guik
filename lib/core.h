#pragma once

#include "components/sys.h"

#include "functions/string.h"
#include "components/string.h"

namespace guik {

#define COLOR_RED 0xFF0000
#define COLOR_GREEN 0x008000
#define COLOR_BLUE 0x0000FF

#define COLOR_AQUA 0x00FFFF
#define COLOR_BLACK 0x000000
#define COLOR_FUCHSIA 0xFF00FF
#define COLOR_GRAY 0x808080
#define COLOR_LIME 0x00FF00
#define COLOR_MAROON 0x800000
#define COLOR_NAVY 0x000080
#define COLOR_OLIVE 0x808000
#define COLOR_PURPLE 0x800080
#define COLOR_SILVER 0xC0C0C0
#define COLOR_TEAL 0x008080
#define COLOR_WHITE 0xFFFFFF
#define COLOR_YELLOW 0xFFFF00

void draw_rectangle(int x, int y, int sizex, int sizey, int color);
void draw_offcut();

#ifndef MAX_FORM_CONTROLS
	#define MAX_FORM_CONTROLS 75
#endif

#define CONTROL_UNKNOWN 0
#define CONTROL_BUTTON 1
#define CONTROL_LABEL 2
#define CONTROL_PIXELS 3
#define CONTROL_NUMBER_LABEL 4
#define CONTROL_OFFCUT 5
#define CONTROL_RECTANGLE 6
#define CONTROL_PIXEL 7
// BoxLib
#define CONTROL_EDIT_BOX 8


#define EVENT_DRAW 0
#define EVENT_BUTTON_CLICK 1
#define EVENT_KEY_PRESS 2
#define EVENT_WINDOW_CLOSE 3
}

#include "classes/events.h"
#include "classes/stack.h"

#include "modules/control.h"
#include "modules/button.h"
#include "modules/label.h"
#include "modules/window.h"

#include "classes/application.h"