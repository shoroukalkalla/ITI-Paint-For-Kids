#include "CEllipse.h"

#include <iostream>
#include <fstream>


CEllipse::CEllipse(Point P1, Point P2, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	TopLeftCorner = P1;
	BottomRightCorner = P2;
}


void CEllipse::DrawMe(GUI* pGUI) const
{
	pGUI->figureDrawer->DrawEllipse(TopLeftCorner, BottomRightCorner, FigGfxInfo, Selected);
}

bool CEllipse::isPointIn(int x, int y) const
{
	return (x >= TopLeftCorner.x && x <= BottomRightCorner.x)
		&& (y >= TopLeftCorner.y && y <= BottomRightCorner.y);
}

bool CEllipse::Resize(float factor, GUI* pGUI)
{
	int horizontal = BottomRightCorner.x - TopLeftCorner.x;
	int vertical = BottomRightCorner.y - TopLeftCorner.y;

	int centerX = (BottomRightCorner.x + TopLeftCorner.x) / 2;
	int centerY = (BottomRightCorner.y + TopLeftCorner.y) / 2;

	horizontal *= factor;
	vertical *= factor;

	int newTopLeftX = centerX - (horizontal / 2);
	int newTopLeftY = centerY - (vertical / 2);

	int newBottomRightX = centerX + (horizontal / 2);
	int newBottomRightY = centerY + (vertical / 2);

	if (newTopLeftX > UI.DrawingAreaTL.x && newTopLeftY > UI.DrawingAreaTL.y
		&& newBottomRightX < UI.DrawingAreaBR.x && newBottomRightY < UI.DrawingAreaBR.y) {
		TopLeftCorner.x = newTopLeftX;
		TopLeftCorner.y = newTopLeftY;

		BottomRightCorner.x = newBottomRightX;
		BottomRightCorner.y = newBottomRightY;
		return true;
	}

	return false;
}

void CEllipse::Save(ofstream& OutFile) {
	// Figure	TopLeftCorner.x		TopLeftCorner.y		BottomRightCorner.x		BottomRightCorner.y		drawColor	isFilled	fillColor	

	if (OutFile.is_open()) {
		// FigureType
		OutFile << TYPE_ELLIPSE << "\t";
		// TopLeftCorner.x		TopLeftCorner.y
		OutFile << TopLeftCorner.x << "\t" << TopLeftCorner.y << "\t";
		// BottomRightCorner.x	BottomRightCorner.y
		OutFile << BottomRightCorner.x << "\t" << BottomRightCorner.y << "\t";
		// drawColor
		OutFile << (int)FigGfxInfo.DrawClr.ucRed << "\t" << (int)FigGfxInfo.DrawClr.ucGreen << "\t" << (int)FigGfxInfo.DrawClr.ucBlue << "\t";
		// isFilled, fillColor
		OutFile << FigGfxInfo.isFilled;
		if (FigGfxInfo.isFilled) {
			OutFile << "\t" << (int)FigGfxInfo.FillClr.ucRed << "\t" << (int)FigGfxInfo.FillClr.ucGreen << "\t" << (int)FigGfxInfo.FillClr.ucBlue;
		}
	}
}
