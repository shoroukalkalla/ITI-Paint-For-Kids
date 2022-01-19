#include "CHexagon.h"

CHexagon::CHexagon(Point _center, float _rotation, int _radius, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	center = _center;
	rotation = _rotation;
	radius = _radius;
}


void CHexagon::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->figureDrawer->DrawHexagon(center, rotation, radius, FigGfxInfo, Selected);
}

bool CHexagon::isPointIn(int x, int y) const
{
	int length = sqrt(pow(center.x - x, 2) + pow(center.y - y, 2));
	return length <= radius;
}

bool CHexagon::Resize(float factor, GUI* pGUI)
{
	HexagonInfo hexagon;
	hexagon.inBounds = false;
	hexagon.center = center;
	hexagon.rotation = rotation;
	hexagon.radius = radius * factor;

	// Get the drawing info
	pGUI->figureDrawer->GetHexagonDrawingInfo(hexagon);

	if (hexagon.inBounds) {
		radius *= factor;
		return true;
	}

	return false;
}