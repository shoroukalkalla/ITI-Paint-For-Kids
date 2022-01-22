#include "ActionAddEllipse.h"
#include "..\Figures\CEllipse.h"

#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"

#include <fstream>

ActionAddEllipse::ActionAddEllipse(ApplicationManager* pApp) : Action(pApp)
{
	pGUI = pApp->GetGUI();
}

//Execute the action
void ActionAddEllipse::Execute()
{
	Point P1, P2;

	pGUI->HighlightButton(ITM_ELPS);

	GfxInfo SqrGfxInfo;
	SqrGfxInfo.isFilled = pGUI->getCrntIsFilled();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SqrGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	SqrGfxInfo.FillClr = pGUI->getCrntFillColor();
	SqrGfxInfo.BorderWdth = pGUI->getCrntPenWidth();


	//Step 1 - Read Ellipse data from the user

	pGUI->PrintMessage("New Ellipse: Click at first point");
	//Read 1st point and store in point P1
	do {
		pGUI->GetPointClicked(P1.x, P1.y);
	} while (!pGUI->isInsideDrawingArea(P1.x, P1.y));

	// Highlight the point clicked
	pGUI->drawPoint(P1.x, P1.y);

	pGUI->PrintMessage("New Ellipse: Click at second point");
	//Read 2nd point and store in point P2
	do {
		pGUI->GetPointClicked(P2.x, P2.y);
	} while (!pGUI->isInsideDrawingArea(P2.x, P2.y));

	pGUI->ClearStatusBar();

	//Step 2 - prepare Ellipse
	//2.1- Identify the Top left corner of the Ellipse
	Point topLeft;
	topLeft.x = P1.x < P2.x ? P1.x : P2.x;
	topLeft.y = P1.y < P2.y ? P1.y : P2.y;

	Point bottomRight;
	bottomRight.x = P1.x > P2.x ? P1.x : P2.x;
	bottomRight.y = P1.y > P2.y ? P1.y : P2.y;

	CreateFigure(topLeft, bottomRight, SqrGfxInfo);

	pGUI->RemoveButtonHighlight(ITM_ELPS);
}

void ActionAddEllipse::CreateFigure(Point topLeft, Point bottomRight, GfxInfo SqrGfxInfo)
{
	//Step 3 - Create a Ellipse with the parameters read from the user
	CEllipse* ellipse = new CEllipse(topLeft, bottomRight, SqrGfxInfo);

	//Step 4 - Add the Square to the list of figures
	pManager->AddFigure(ellipse);
}

void ActionAddEllipse::Load(ifstream& input)
{
	// TopLeftCorner.x		TopLeftCorner.y
	// BottomRightCorner.x		BottomRightCorner.y	
	// drawColor	isFilled	fillColor	

	Point TopLeftCorner, BottomRightCorner;
	GfxInfo SqrGfxInfo;
	SqrGfxInfo.BorderWdth = pGUI->getCrntPenWidth();

	input >> TopLeftCorner.x >> TopLeftCorner.y;
	input >> BottomRightCorner.x >> BottomRightCorner.y;
	
	int drawC[3];
	input >> drawC[0] >> drawC[1] >> drawC[2];
	SqrGfxInfo.DrawClr = color((char)drawC[0], (char)drawC[1], (char)drawC[2]);

	input >> SqrGfxInfo.isFilled;

	if (SqrGfxInfo.isFilled) {
		int fillC[3];
		input >> fillC[0] >> fillC[1] >> fillC[2];
		SqrGfxInfo.FillClr = color((char)fillC[0], (char)fillC[1], (char)fillC[2]);
	}

	CreateFigure(TopLeftCorner, BottomRightCorner, SqrGfxInfo);
}