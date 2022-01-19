#include "ActionAddEllipse.h"
#include "..\Figures\CEllipse.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

ActionAddEllipse::ActionAddEllipse(ApplicationManager* pApp) : Action(pApp)
{}

//Execute the action
void ActionAddEllipse::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();

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


	//Step 2 - prepare Ellipse data Test Edit
	//User has entered two points P1&P2
	//2.1- Identify the Top left corner of the Ellipse
	Point topLeft;
	topLeft.x = P1.x < P2.x ? P1.x : P2.x;
	topLeft.y = P1.y < P2.y ? P1.y : P2.y;

	Point bottomRight;
	bottomRight.x = P1.x > P2.x ? P1.x : P2.x;
	bottomRight.y = P1.y > P2.y ? P1.y : P2.y;

	//Step 3 - Create a Ellipse with the parameters read from the user
	CEllipse* R = new CEllipse(topLeft, bottomRight, SqrGfxInfo);

	//Step 4 - Add the Square to the list of figures
	pManager->AddFigure(R);

	pGUI->RemoveButtonHighlight(ITM_ELPS);
}
