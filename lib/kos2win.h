#pragma once

namespace guik {

void BeginDraw();

void EndDraw();

void DrawWindow(int x, int y, int sizeX, int sizeY, char* header, int color, int style);

void draw_text_sys(char* text, int x, int y, int length, int color);

void DefineButton(int x, int y, int id, int color);

int get_os_event();

int get_os_button();

}