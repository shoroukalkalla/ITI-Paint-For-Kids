#ifndef CSQUARE_H
#define CSQUARE_H

#include "CFigure.h"

class CSquare : public CFigure
{
private:
	Point TopLeftCorner;	
	int length;
public:
	CSquare(Point , int, GfxInfo FigureGfxInfo );
	virtual void DrawMe(GUI* pOut) const;
	virtual bool isPointIn(int x, int y) const;
	void Resize(float);
};

#endif