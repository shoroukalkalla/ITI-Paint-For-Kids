#ifndef FIGURE_DRAW_H
#define FIGURE_DRAW_H

#include "GUI.h"
#include "..\DEFS.h"
#include "UI_Info.h" 
#include "..\CMUgraphicsLib\CMUgraphics.h"

class GUI;

class FigureDrawer
{
private:
	GUI* pGUI;
public:
	FigureDrawer(GUI* _pGUI);

	drawstyle setupStyle(GfxInfo RectGfxInfo, bool selected) const;

	void DrawSquare(Point P1, int length, GfxInfo RectGfxInfo, bool selected = false) const;
	void DrawEllipse(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const;
	void DrawHexagon(Point P1, Point P2, int radius, GfxInfo RectGfxInfo, bool selected) const;
};

#endif