#include "ActionAddHexagon.h"
#include "..\Figures\CHexagon.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

ActionAddHexagon::ActionAddHexagon(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionAddHexagon::Execute()
{
	Point Center, FirstVertex;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();

	pGUI->HighlightButton(ITM_HEX);

	//get drawing, filling colors and pen width from the interface
	GfxInfo SqrGfxInfo;
	SqrGfxInfo.isFilled = pGUI->getCrntIsFilled();
	SqrGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	SqrGfxInfo.FillClr = pGUI->getCrntFillColor();
	SqrGfxInfo.BorderWdth = pGUI->getCrntPenWidth();


	//Step 1 - Read Hexagon data from the user

	pGUI->PrintMessage("New Hexagon: Click at center point");
	//Read 1st point and store in point Center
	do {
		pGUI->GetPointClicked(Center.x, Center.y);
	} while (!pGUI->isInsideDrawingArea(Center.x, Center.y));

	// Highlight the Center point
	pGUI->drawPoint(Center.x, Center.y);

	pGUI->PrintMessage("New Hexagon: Click at first point");
	//Read 2nd point and store in point FirstVertex
	do {
		pGUI->GetPointClicked(FirstVertex.x, FirstVertex.y);
	} while (!pGUI->isInsideDrawingArea(FirstVertex.x, FirstVertex.y));

	pGUI->ClearStatusBar();

	HexagonInfo hexagon;
	hexagon.rotation = NULL;
	hexagon.radius = NULL;
	hexagon.center = Center;
	hexagon.firstVertex = FirstVertex;

	// Get the drawing info
	pGUI->figureDrawer->GetHexagonDrawingInfo(hexagon);

	if (hexagon.inBounds) {
		//Step 3 - Create a Hexagon with the parameters read from the user
		CHexagon* R = new CHexagon(hexagon.center, hexagon.rotation, hexagon.radius, SqrGfxInfo);

		//Step 4 - Add the Square to the list of figures
		pManager->AddFigure(R);
	}
	else {
		pGUI->PrintMessage("Can't draw outsite the drawing area!");
	}

	pGUI->RemoveButtonHighlight(ITM_HEX);
}
