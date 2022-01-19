#include "FigureDrawer.h"

#include "GUI.h"
#include "UI_Info.h"
#include "FiguresInfo.h"


FigureDrawer::FigureDrawer(GUI* _pGUI) {
	this->pGUI = _pGUI;
}

drawstyle FigureDrawer::setupStyle(GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pGUI->pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width
	//pWind->SetBrush(RectGfxInfo.FillClr);

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pGUI->pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;

	return style;
}

void FigureDrawer::DrawSquare(Point P1, int length, GfxInfo RectGfxInfo, bool selected) const
{
	drawstyle style = setupStyle(RectGfxInfo, selected);

	pGUI->pWind->DrawRectangle(P1.x, P1.y, P1.x + length, P1.y + length, style);
	//pGUI->pWind->DrawLine(P1.x, P1.y, P1.x + length, P1.y + length, style);
}

void FigureDrawer::DrawEllipse(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	drawstyle style = setupStyle(RectGfxInfo, selected);

	pGUI->pWind->DrawEllipse(P1.x, P1.y, P2.x, P2.y, style);
}

void FigureDrawer::GetHexagonDrawingInfo(HexagonInfo& hexagon)
{
	if (hexagon.radius == NULL) {
		// Calculate the radius of the hexagon
		hexagon.radius = sqrt(pow(hexagon.center.x - hexagon.firstVertex.x, 2)
			+ pow(hexagon.center.y - hexagon.firstVertex.y, 2));
	}

	float angle = hexagon.rotation;

	if (angle == NULL) {
		// Get the rotation angle of the first point
		angle = atan2((float)hexagon.firstVertex.y - (float)hexagon.center.y,
			(float)hexagon.firstVertex.x - (float)hexagon.center.x);
		hexagon.rotation = angle;
	}
	
	// Find the hexagon vertex
	for (int i = 0; i < 6; i++) {
		hexagon.ipX[i] = (float)hexagon.center.x + (hexagon.radius * cos(angle));
		hexagon.ipY[i] = (float)hexagon.center.y + (hexagon.radius * sin(angle));

		angle += (3.14159265 / 3);
	}

	// Check if the hexagon is within the drawing area bounds
	if (!pGUI->isInsideDrawingArea(hexagon.ipX, hexagon.ipY, 6)) {
		hexagon.inBounds = false;
	}
	else {
		hexagon.inBounds = true;
	}
}

void FigureDrawer::DrawHexagon(Point center, float rotation, int radius, GfxInfo RectGfxInfo, bool selected)
{
	drawstyle style = setupStyle(RectGfxInfo, selected);

	HexagonInfo hexagon;
	hexagon.center = center;
	hexagon.rotation = rotation;
	hexagon.radius = radius;

	// Get the drawing info
	GetHexagonDrawingInfo(hexagon);

	if (hexagon.inBounds) {
		pGUI->pWind->DrawPolygon(hexagon.ipX, hexagon.ipY, 6, style);
	}
	else {
		pGUI->PrintMessage("Can't draw outsite the drawing area!");
	}
}
