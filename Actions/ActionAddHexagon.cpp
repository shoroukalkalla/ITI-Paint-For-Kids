#include "ActionAddHexagon.h"
#include "..\Figures\CHexagon.h"

#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"

#include <fstream>

ActionAddHexagon::ActionAddHexagon(ApplicationManager* pApp) : ActionAddFigure(pApp)
{ }

int ActionAddHexagon::GetMenuItemIndex()
{
	return ITM_HEX;
}

void ActionAddHexagon::AddFigure()
{
	Point Center, FirstVertex;

	GfxInfo figGfxInfo;
	InitGfxInfo(figGfxInfo);

	//Step 1 - Read Hexagon data from the user

	//Read 1st point and store in point Center
	ReadPoint(Center.x, Center.y, "New Hexagon: Click at center point", true);

	//Read 2nd point and store in point FirstVertex
	ReadPoint(FirstVertex.x, FirstVertex.y, "New Hexagon: Click at center point", false);

	HexagonInfo hexagon;
	hexagon.inBounds = false;
	hexagon.rotation = NULL;
	hexagon.radius = NULL;
	hexagon.center = Center;
	hexagon.firstVertex = FirstVertex;

	// Get the drawing info
	pGUI->figureDrawer->GetHexagonDrawingInfo(hexagon);

	if (hexagon.inBounds) {
		CreateFigure(hexagon.center, hexagon.rotation, hexagon.radius, figGfxInfo);
	}
	else {
		pGUI->PrintMessage("Can't draw outsite the drawing area!");
	}
}

void ActionAddHexagon::CreateFigure(Point Center, float Rotation, int Radius, GfxInfo figGfxInfo)
{
	//Step 3 - Create a Hexagon with the parameters read from the user
	CHexagon* R = new CHexagon(Center, Rotation, Radius, figGfxInfo);

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
	GfxInfo figGfxInfo;
	figGfxInfo.BorderWdth = pGUI->getCrntPenWidth();

	input >> Center.x >> Center.y >> Rotation >> Radius;
	
	int drawC[3];
	input >> drawC[0] >> drawC[1] >> drawC[2];
	figGfxInfo.DrawClr = color((char)drawC[0], (char)drawC[1], (char)drawC[2]);

	input >> figGfxInfo.isFilled;

	if (figGfxInfo.isFilled) {
		int fillC[3];
		input >> fillC[0] >> fillC[1] >> fillC[2];
		figGfxInfo.FillClr = color((char)fillC[0], (char)fillC[1], (char)fillC[2]);
	}

	CreateFigure(Center, Rotation, Radius, figGfxInfo);
}
