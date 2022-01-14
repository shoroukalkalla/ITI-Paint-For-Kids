#include "FigureDrawer.h"

#include "GUI.h"

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

void FigureDrawer::DrawHexagon(Point P1, Point P2, int radius, GfxInfo RectGfxInfo, bool selected) const
{
	drawstyle style = setupStyle(RectGfxInfo, selected);

	// Center => (P1.x, P1.y)

	int ipX[6];
	int ipY[6];

	//ipX[0] = P1.x + radius;
	//ipY[0] = P1.y;
	//float angle = 0;

	// The first point => (P2.x, P2.y)
	ipX[0] = P2.x;
	ipY[0] = P2.y;
	float angle = atan2((float)P2.y - (float)P1.y, (float)P2.x - (float)P1.x);

	for (int i = 1; i < 6; i++) {
		angle += (3.14159265 / 3);

		ipX[i] = (float)P1.x + (radius * cos(angle));
		ipY[i] = (float)P1.y + (radius * sin(angle));

		if (!pGUI->isInsideDrawingArea(ipX[i], ipY[i])) {
			// TODO Show message (can't draw outside the boundaries)
			return;
		}
	}

	//for (int i = 0; i < 6; i++) {
	//	printf("\n(x%d, y%d) : (%d, %d)", i + 1, i + 1, ipX[i], ipY[i]);
	//}

	pGUI->pWind->DrawPolygon(ipX, ipY, 6, style);
}
