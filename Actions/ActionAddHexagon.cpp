#include "ActionAddHexagon.h"
#include "..\Figures\CHexagon.h"

#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"

#include <fstream>

ActionAddHexagon::ActionAddHexagon(ApplicationManager* pApp) :Action(pApp)
{
	pGUI = pApp->GetGUI();
}

//Execute the action
void ActionAddHexagon::Execute()
{
	Point Center, FirstVertex;

	//Get a Pointer to the Interface
	
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
		CreateFigure(hexagon.center, hexagon.rotation, hexagon.radius, SqrGfxInfo);
	}
	else {
		pGUI->PrintMessage("Can't draw outsite the drawing area!");
	}

	pGUI->RemoveButtonHighlight(ITM_HEX);
}

void ActionAddHexagon::CreateFigure(Point Center, float Rotation, int Radius, GfxInfo SqrGfxInfo)
{
	//Step 3 - Create a Hexagon with the parameters read from the user
	CHexagon* R = new CHexagon(Center, Rotation, Radius, SqrGfxInfo);

	//Step 4 - Add the Square to the list of figures
	pManager->AddFigure(R);
}

void ActionAddHexagon::Load(ifstream& input)
{
	// Center.x		Center.y	Rotation	Radius
	// drawColor
	// isFilled		fillColor

	Point Center;
	float Rotation;
	int Radius;
	GfxInfo SqrGfxInfo;
	SqrGfxInfo.BorderWdth = pGUI->getCrntPenWidth();

	input >> Center.x >> Center.y >> Rotation >> Radius;
	
	int drawC[3];
	input >> drawC[0] >> drawC[1] >> drawC[2];
	SqrGfxInfo.DrawClr = color((char)drawC[0], (char)drawC[1], (char)drawC[2]);

	input >> SqrGfxInfo.isFilled;

	if (SqrGfxInfo.isFilled) {
		int fillC[3];
		input >> fillC[0] >> fillC[1] >> fillC[2];
		SqrGfxInfo.FillClr = color((char)fillC[0], (char)fillC[1], (char)fillC[2]);
	}

	CreateFigure(Center, Rotation, Radius, SqrGfxInfo);
}
