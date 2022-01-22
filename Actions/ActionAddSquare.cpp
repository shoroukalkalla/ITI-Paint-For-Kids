#include "ActionAddSquare.h"
#include "..\Figures\CSquare.h"

#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"

#include <fstream>

ActionAddSquare::ActionAddSquare(ApplicationManager * pApp):Action(pApp)
{
	pGUI = pApp->GetGUI();
}

//Execute the action
void ActionAddSquare::Execute() 
{
	Point P1,P2;

	pGUI->HighlightButton(ITM_SQUR);

	GfxInfo SqrGfxInfo;
	SqrGfxInfo.isFilled = pGUI->getCrntIsFilled();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SqrGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	SqrGfxInfo.FillClr = pGUI->getCrntFillColor();
	SqrGfxInfo.BorderWdth = pGUI->getCrntPenWidth();

	//Step 1 - Read Square data from the user

	pGUI->PrintMessage("New Square: Click at first point");	
	//Read 1st point and store in point P1
	do {
		pGUI->GetPointClicked(P1.x, P1.y);
	} while (!pGUI->isInsideDrawingArea(P1.x, P1.y));

	// Highlight the point clicked
	pGUI->drawPoint(P1.x, P1.y);

	pGUI->PrintMessage("New Square: Click at second point");
	//Read 2nd point and store in point P2
	do {
		pGUI->GetPointClicked(P2.x, P2.y);
	} while (!pGUI->isInsideDrawingArea(P2.x, P2.y));

	pGUI->ClearStatusBar();


	//Step 2 - prepare square data
	//User has entered two points P1&P2
	//2.1- Identify the Top left corner of the square
	Point topLeft ;
	topLeft.x = min(P1.x, P2.x);
	topLeft.y = min(P1.y, P2.y);

	//2.2- Calcuate square side legnth
	//The square side length would be the longer distance between the two points coordinates
	int SideLength = max(abs(P1.x-P2.x), abs(P1.y-P2.y));

	CreateFigure(topLeft, SideLength, SqrGfxInfo);

	pGUI->RemoveButtonHighlight(ITM_SQUR);
}

void ActionAddSquare::CreateFigure(Point topLeft, int SideLength, GfxInfo SqrGfxInfo)
{
	//Step 3 - Create a Square with the parameters read from the user
	CSquare* squere = new CSquare(topLeft, SideLength, SqrGfxInfo);

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
	GfxInfo SqrGfxInfo;
	SqrGfxInfo.BorderWdth = pGUI->getCrntPenWidth();

	input >> topLeft.x >> topLeft.y >> SideLength;

	int drawC[3];
	input >> drawC[0] >> drawC[1] >> drawC[2];
	SqrGfxInfo.DrawClr = color((char)drawC[0], (char)drawC[1], (char)drawC[2]);

	input >> SqrGfxInfo.isFilled;

	if (SqrGfxInfo.isFilled) {
		int fillC[3];
		input >> fillC[0] >> fillC[1] >> fillC[2];
		SqrGfxInfo.FillClr = color((char)fillC[0], (char)fillC[1], (char)fillC[2]);
	}

	CreateFigure(topLeft, SideLength, SqrGfxInfo);
}