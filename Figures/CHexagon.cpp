#include "CHexagon.h"

CHexagon::CHexagon(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	center = P1;
	firstPoint = P2;
	radius = sqrt(pow(P1.x - P2.x, 2) + pow(P1.y - P2.y, 2));
	// TODO: update the constructor to accept
	// => the center point [Point]
	// => the rotation [float]
	// => the radius [int]
}


void CHexagon::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->figureDrawer->DrawHexagon(center, firstPoint, radius, FigGfxInfo, Selected);
	// Redisign figureDrawer->DrawHexagon to accept
	// => the center point, the radius and the rotation
}

bool CHexagon::isPointIn(int x, int y) const
{
	int length = sqrt(pow(center.x - x, 2) + pow(center.y - y, 2));
	return length <= radius;
}

void CHexagon::Resize(float factor)
{
	radius *= factor;
}