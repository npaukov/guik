#pragma once
#include "label.h"
#include "../components/string.h"

namespace guik {
	
class ButtonLabel : public Label {
public:
	ButtonLabel(char* text) : Label(text), paddingLeft(4), paddingRight(4), paddingTop(4), paddingBottom(4) {

	};

	void setPaddingLeft(int padding);
	int getPaddingLeft();

	void setPaddingRight(int padding);
	int getPaddingRight();

	void setPaddingTop(int padding);
	int getPaddingTop();

	void setPaddingBottom(int padding);
	int getPaddingBottom();
protected:
	int paddingLeft, paddingRight;
	int paddingTop, paddingBottom;
};

class Button : public Control {
public:
	Button(int id, int x=0, int y=0, int sizeX=30, int sizeY=10, int color=COLOR_BLUE);
	~Button();

	virtual void onClick(){};

	void on();

	int getType();
	void draw();

	int getId();
	void setX(int x);
	int getX();
	void setY(int y);
	int getY();

	void setSizeX(int sizeX);
	int getSizeX();
	void setSizeY(int sizeY);
	int getSizeY();

	void setColor(int color);
	int getColor();

	void setText(char* text);
	char* getText();

	void setHiddenState(bool hidden);
	bool isHidden();

	ButtonLabel* text;

protected:
	Word x,y,sizeX,sizeY;
	Dword id;
	Dword color;
	bool hidden;

	bool enableLabel;

	int type;
};

}