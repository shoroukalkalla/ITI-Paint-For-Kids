#ifndef FIGURES_INFO_H
#define FIGURES_INFO_H

#include "../DEFS.h"

struct HexagonInfo
{
	bool inBounds;
	Point center;
	Point firstVertex;
	float rotation;
	int radius;
	int ipX[6];
	int ipY[6];
};

enum FigureType {
	TYPE_SQUARE,//0
	TYPE_ELLIPSE,//1
	TYPE_HEXAGON//2
};

#endif
