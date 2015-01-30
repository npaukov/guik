#pragma once
#include "../core.h"

namespace guik {

class Offcut : public Control {
public:
	int getType();

	Offcut(int startX, int startY, int endX, int endY);

	virtual int getId();
	void draw();

	void setStartX(int x);
	int getStartX();
	void setStartY(int y);
	int getStartY();
	void setEndX(int x);
	int getEndX();
	void setEndY(int y);
	int getEndY();

	void setColor(int color);
	int getColor();

	void setInverse(bool inverse);
	bool isInverse();

protected:
	int startX,startY;
	int endX, endY;
	int id;
	int type;
	Dword color;
	bool inverse;
};

struct OffcutVertex {
	int x,y;
};

struct OffcutTriangle {
	OffcutVertex v1;
	OffcutVertex v2;
	OffcutVertex v3;

	Offcut* o1;
	Offcut* o2;
	Offcut* o3;
};

struct OffcutRectangle {
	OffcutVertex v1;
	OffcutVertex v2;
	OffcutVertex v3;
	OffcutVertex v4;

	Offcut* o1;
	Offcut* o2;
	Offcut* o3;
	Offcut* o4;
};

class OffcutPolygon {
public:
	OffcutVertex** vertexes;
	Offcut** offcuts;

	int lastVertexId;
	int vertexesCount;

	OffcutPolygon(int vertexes=3);
	void addVertex(OffcutVertex* vertex);
	void addVertex(int x, int y);
	void setVertex(int position, OffcutVertex* vertex);
	void setVertex(int position, int x, int y);

	OffcutVertex* getVertex(int position);
	Offcut* getOffcut(int position);

	int getCountVertexes();
};

class OffcutFigure {
public:
	static void draw(Window* win, OffcutTriangle* figure);
	static void draw(Window* win, OffcutRectangle* figure);
	static void draw(Window* win, OffcutPolygon* figure);
};

}