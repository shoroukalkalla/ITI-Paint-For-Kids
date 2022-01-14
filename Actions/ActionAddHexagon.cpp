#include "ActionAddHexagon.h"
#include "..\Figures\CHexagon.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

ActionAddHexagon::ActionAddHexagon(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionAddHexagon::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	GfxInfo SqrGfxInfo;
	SqrGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SqrGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	SqrGfxInfo.FillClr = pGUI->getCrntFillColor();
	SqrGfxInfo.BorderWdth = pGUI->getCrntPenWidth();


	//Step 1 - Read Hexagon data from the user

	pGUI->PrintMessage("New Hexagon: Click at center point");
	//Read 1st point and store in point P1
	do {
		pGUI->GetPointClicked(P1.x, P1.y);
	} while (!pGUI->isInsideDrawingArea(P1.x, P1.y));

	// Highlight the point clicked
	pGUI->drawPoint(P1.x, P1.y);

	pGUI->PrintMessage("New Hexagon: Click at first point");
	//Read 2nd point and store in point P2
	do {
		pGUI->GetPointClicked(P2.x, P2.y);
	} while (!pGUI->isInsideDrawingArea(P2.x, P2.y));

	pGUI->ClearStatusBar();

	//Step 3 - Create a Square with the parameters read from the user
	CHexagon* R = new CHexagon(P1, P2, SqrGfxInfo);

	//Step 4 - Add the Square to the list of figures
	pManager->AddFigure(R);
}
