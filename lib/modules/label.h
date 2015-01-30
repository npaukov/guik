#pragma once

namespace guik {

class Label : public Control {
public:
	int getType();

	Label(char* text, int x=0, int y=0, int color=COLOR_BLACK);
	~Label();

	virtual int getId();

	void on();
	void draw();
	
	void setX(int x);
	int getX();
	void setY(int y);
	int getY();

	void setColor(int color);
	int getColor();

	void setHiddenState(bool hidden);
	bool isHidden();

	void setFontType(int fontType);
	int getFontType();

	void setText(char* text);
	void setText(mstring text);
	char* getText();
	mstring getTextString();
	int getLength();

protected:
	void Release();
	Word x,y;
	Dword id;
	Dword color;
	bool hidden;
	Byte fontType;
	mstring text;
	int type;
private:

};

}