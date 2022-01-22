#ifndef CELLIPSE_H
#define CELLIPSE_H

#include "CFigure.h"

class CEllipse : public CFigure
{
private:
	Point TopLeftCorner;
	Point BottomRightCorner;

public:
	CEllipse(Point, Point, GfxInfo FigureGfxInfo);
	virtual void DrawMe(GUI* pOut) const;
	virtual bool isPointIn(int x, int y) const;
	bool Resize(float factor, GUI* pGUI);

	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
};

#endif