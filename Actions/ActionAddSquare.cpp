#include "ActionAddSquare.h"
#include "..\Figures\CSquare.h"

#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"

#include <fstream>

ActionAddSquare::ActionAddSquare(ApplicationManager * pApp) : ActionAddFigure(pApp)
{ }

int ActionAddSquare::GetMenuItemIndex()
{
	return ITM_SQUR;
}

void ActionAddSquare::AddFigure()
{
	Point P1,P2;

	GfxInfo figGfxInfo;
	InitGfxInfo(figGfxInfo);

	//Step 1 - Read Square data from the user

	//Read 1st point and store in point P1
	ReadPoint(P1.x, P1.y, "New Square: Click at first point", true);

	//Read 2nd point and store in point P2
	ReadPoint(P2.x, P2.y, "New Square: Click at second point", false);

	//Step 2 - prepare square data
	//User has entered two points P1&P2
	//2.1. Identify the Top left corner of the square
	Point topLeft ;
	topLeft.x = min(P1.x, P2.x);
	topLeft.y = min(P1.y, P2.y);

	//2.2. Calcuate square side legnth
	//The square side length would be the longer distance between the two points coordinates
	int SideLength = max(abs(P1.x-P2.x), abs(P1.y-P2.y));

	CreateFigure(topLeft, SideLength, figGfxInfo);
}

void ActionAddSquare::CreateFigure(Point topLeft, int SideLength, GfxInfo figGfxInfo)
{
	//Step 3 - Create a Square with the parameters read from the user
	CSquare* squere = new CSquare(topLeft, SideLength, figGfxInfo);

	//Step 4 - Add the Square to the list of figures
	pManager->AddFigure(squere);
}

void ActionAddSquare::Load(ifstream& input)
{
	// TopLeftCorner.x		TopLeftCorner.y		length
	// drawColor
	// isFilled		fillColor

	Point topLeft;
	int SideLength;
	GfxInfo figGfxInfo;
	figGfxInfo.BorderWdth = pGUI->getCrntPenWidth();

	input >> topLeft.x >> topLeft.y >> SideLength;

	int drawC[3];
	input >> drawC[0] >> drawC[1] >> drawC[2];
	figGfxInfo.DrawClr = color((char)drawC[0], (char)drawC[1], (char)drawC[2]);

	input >> figGfxInfo.isFilled;

	if (figGfxInfo.isFilled) {
		int fillC[3];
		input >> fillC[0] >> fillC[1] >> fillC[2];
		figGfxInfo.FillClr = color((char)fillC[0], (char)fillC[1], (char)fillC[2]);
	}

	CreateFigure(topLeft, SideLength, figGfxInfo);
}
