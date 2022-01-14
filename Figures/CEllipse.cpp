#include "CEllipse.h"

CEllipse::CEllipse(Point P1, Point P2, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	TopLeftCorner = P1;
	BottomRightCorner = P2;
}


void CEllipse::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	//pGUI->DrawSquare(TopLeftCorner, length, FigGfxInfo, Selected);

	pGUI->figureDrawer->DrawEllipse(TopLeftCorner, BottomRightCorner, FigGfxInfo, Selected);

}

bool CEllipse::isPointIn(int x, int y) const
{
	return (x >= TopLeftCorner.x && x <= BottomRightCorner.x)
		&& (y >= TopLeftCorner.y && y <= BottomRightCorner.y);
}