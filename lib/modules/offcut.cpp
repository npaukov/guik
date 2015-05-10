#pragma once

#include "../core.h"
#include "offcut.h"
#include "../classes/draw.h"
namespace guik {

Offcut::Offcut(int startX, int startY, int endX, int endY) : startX(startX), startY(startY), endX(endX), endY(endY), color(COLOR_BLACK), inverse(false) {

}

void Offcut::setStartX(int x) {
	this->startX = x;
}

int Offcut::getStartX() {
	return this->startX;
}

void Offcut::setStartY(int y) {
	this->startY = y;
}

int Offcut::getStartY() {
	return this->startY;
}

void Offcut::setEndX(int x) {
	this->endX = x;
}

int Offcut::getEndX() {
	return this->endX;
}

void Offcut::setEndY(int y) {
	this->endY = y;
}

int Offcut::getEndY() {
	return this->endY;
}

void Offcut::setColor(int color) {
	this->color = color;
}

int Offcut::getColor() {
	return this->color;
}

void Offcut::setInverse(bool inverse) {
	this->inverse = inverse;
}

bool Offcut::isInverse() {
	return this->inverse;
}

int Offcut::getType() {
	return CONTROL_OFFCUT;
}

int Offcut::getId() {
	return this->id;
}

void Offcut::draw() {
	this->call(EVENT_DRAW);
	Draw::offcut(this->startX, this->startY, this->endX, this->endY, this->color, this->inverse);
}

// Произвольная фигура
OffcutPolygon::OffcutPolygon(int vertexes) {
	this->vertexesCount = vertexes;
	this->vertexes = new OffcutVertex*[vertexes];
	this->offcuts = new Offcut*[vertexes];

	this->lastVertexId = -1;
}

void OffcutPolygon::addVertex(OffcutVertex* vertex) {
	this->vertexes[this->lastVertexId+1] = new OffcutVertex;
	this->lastVertexId++;

	this->vertexes[this->lastVertexId]->x = vertex->x;
	this->vertexes[this->lastVertexId]->y = vertex->y;
}

void OffcutPolygon::addVertex(int x, int y) {
	this->vertexes[this->lastVertexId+1] = new OffcutVertex;
	this->lastVertexId++;

	this->vertexes[this->lastVertexId]->x = x;
	this->vertexes[this->lastVertexId]->y = y;
}

void OffcutPolygon::setVertex(int position, OffcutVertex* vertex) {
	if (position < 0 || position >= this->vertexesCount) return; 

	if (this->vertexes[position]) delete this->vertexes[position];

	this->vertexes[position] = new OffcutVertex;

	this->vertexes[position]->x = vertex->x;
	this->vertexes[position]->y = vertex->y;
}

void OffcutPolygon::setVertex(int position, int x, int y) {
	if (position < 0 || position >= this->vertexesCount) return; 

	if (this->vertexes[position]) delete this->vertexes[position];

	this->vertexes[position] = new OffcutVertex;

	this->vertexes[position]->x = x;
	this->vertexes[position]->y = y;
}

OffcutVertex* OffcutPolygon::getVertex(int position) {
	if (position < 0 || position >= this->vertexesCount || !this->vertexes[position]) return false;

	return this->vertexes[position];
}

Offcut* OffcutPolygon::getOffcut(int position) {
	if (position < 0 || position >= this->vertexesCount || !this->offcuts[position]) return false;

	return this->offcuts[position];
}

int OffcutPolygon::getCountVertexes() {
	return this->vertexesCount;
}

void OffcutFigure::draw(Window* win, OffcutTriangle* figure) {
	// v1->v2, v2->v3, v3->v1
	OffcutVertex v1 = figure->v1;
	OffcutVertex v2 = figure->v2;
	OffcutVertex v3 = figure->v3;

	Offcut* of1 = new Offcut(v1.x,v1.y, v2.x, v2.y);
	Offcut* of2 = new Offcut(v2.x,v2.y, v3.x, v3.y);
	Offcut* of3 = new Offcut(v3.x,v3.y, v1.x, v1.y);

	win->addControl(of1);
	win->addControl(of2);
	win->addControl(of3);

	figure->o1 = of1;
	figure->o2 = of2;
	figure->o3 = of3;
}

void OffcutFigure::draw(Window* win, OffcutRectangle* figure) {
	// v1->v2, v2->v3, v3->v4, v4->v1
	OffcutVertex v1 = figure->v1;
	OffcutVertex v2 = figure->v2;
	OffcutVertex v3 = figure->v3;
	OffcutVertex v4 = figure->v4;


	Offcut* of1 = new Offcut(v1.x,v1.y, v2.x, v2.y);
	Offcut* of2 = new Offcut(v2.x,v2.y, v3.x, v3.y);
	Offcut* of3 = new Offcut(v3.x,v3.y, v4.x, v4.y);
	Offcut* of4 = new Offcut(v4.x,v4.y, v1.x, v1.y);

	win->addControl(of1);
	win->addControl(of2);
	win->addControl(of3);
	win->addControl(of4);

	figure->o1 = of1;
	figure->o2 = of2;
	figure->o3 = of3;
	figure->o4 = of4;
}

void OffcutFigure::draw(Window* win, OffcutPolygon* figure) {
	int i, count;
	bool status = false;
	count = figure->getCountVertexes();

	for (i=0;i<count;i++) {
		if (i+1 == count) {
			OffcutVertex* vertex = figure->getVertex(i);
			OffcutVertex* firstVertex = figure->getVertex(0);

			figure->offcuts[i] = new Offcut(vertex->x, vertex->y, firstVertex->x, firstVertex->y);
			win->addControl(figure->offcuts[i]);
			break;
		}

		OffcutVertex* vertex = figure->getVertex(i);
		OffcutVertex* vertexNext = figure->getVertex(i+1);
		figure->offcuts[i] = new Offcut(vertex->x, vertex->y, vertexNext->x, vertexNext->y);
		win->addControl(figure->offcuts[i]);
	}
}

}