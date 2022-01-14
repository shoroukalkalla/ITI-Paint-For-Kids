#include "CHexagon.h"

CHexagon::CHexagon(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	center = P1;
	firstPoint = P2;
	radius = sqrt(pow(P1.x - P2.x, 2) + pow(P1.y - P2.y, 2));
}


void CHexagon::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->figureDrawer->DrawHexagon(center, firstPoint, radius, FigGfxInfo, Selected);
}

bool CHexagon::isPointIn(int x, int y) const
{
	int length = sqrt(pow(center.x - x, 2) + pow(center.y - y, 2));
	return length <= radius;
}