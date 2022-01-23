#include "CSquare.h"

#include "..\GUI\GUI.h"

#include <fstream>


CSquare::CSquare(Point P1, int len, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	TopLeftCorner = P1;
	length = len;
}


void CSquare::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->figureDrawer->DrawSquare(TopLeftCorner, length, FigGfxInfo, Selected);
}

bool CSquare::isPointIn(int x, int y) const
{
	return (x >= TopLeftCorner.x && x <= TopLeftCorner.x + length)
		&& (y >= TopLeftCorner.y && y <= TopLeftCorner.y + length);
}

bool CSquare::Resize(float factor, GUI* pGUI)
{
	int centerX = TopLeftCorner.x + (length / 2);
	int centerY = TopLeftCorner.y + (length / 2);

	int newLength = length * factor;

	int newTopLeftX = centerX - (newLength / 2);
	int newTopLeftY = centerY - (newLength / 2);

	int bottomRightX = newTopLeftX + newLength;
	int bottomRightY = newTopLeftY + newLength;

	if (newTopLeftX > UI.DrawingAreaTL.x && newTopLeftY > UI.DrawingAreaTL.y
		&& bottomRightX < UI.DrawingAreaBR.x && bottomRightY < UI.DrawingAreaBR.y) {
		length = newLength;
		TopLeftCorner.x = newTopLeftX;
		TopLeftCorner.y = newTopLeftY;

		return true;
	}

	return false;
}

void CSquare::Save(ofstream& OutFile) {
	// Figure	ID	TopLeftCorner.x		TopLeftCorner.y		length	drawColor	fillColor
	// SQR		1	100					200					300		RBG			RBG

	if (OutFile.is_open()) {
		// FigureType
		OutFile << TYPE_SQUARE << "\t";
		// TopLeftCorner.x,	TopLeftCorner.y	length
		OutFile << TopLeftCorner.x << "\t" << TopLeftCorner.y << "\t" << length << "\t";
		// drawColor
		OutFile << (int)FigGfxInfo.DrawClr.ucRed << "\t" << (int)FigGfxInfo.DrawClr.ucGreen << "\t" << (int)FigGfxInfo.DrawClr.ucBlue << "\t";
		// isFilled, fillColor
		OutFile << FigGfxInfo.isFilled;
		if (FigGfxInfo.isFilled) {
			OutFile << "\t" << (int)FigGfxInfo.FillClr.ucRed << "\t" << (int)FigGfxInfo.FillClr.ucGreen << "\t" << (int)FigGfxInfo.FillClr.ucBlue;
		}
	}
}
