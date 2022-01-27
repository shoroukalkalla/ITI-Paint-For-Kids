#include "ActionAddEllipse.h"
#include "..\Figures\CEllipse.h"

#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"

#include <fstream>

ActionAddEllipse::ActionAddEllipse(ApplicationManager* pApp) : ActionAddFigure(pApp)
{ }

int ActionAddEllipse::GetMenuItemIndex()
{
	return ITM_ELPS;
}

void ActionAddEllipse::AddFigure()
{
	Point P1, P2;

	GfxInfo figGfxInfo;
	InitGfxInfo(figGfxInfo);

	//Step 1 - Read Ellipse data from the user

	//Read 1st point and store in point P1
	ReadPoint(P1.x, P1.y, "New Ellipse: Click at first point", true);

	//Read 2nd point and store in point P2
	ReadPoint(P2.x, P2.y, "New Ellipse: Click at second point", false);

	//Step 2 - prepare Ellipse
	//2.1- Identify the Top left corner of the Ellipse
	Point topLeft;
	topLeft.x = P1.x < P2.x ? P1.x : P2.x;
	topLeft.y = P1.y < P2.y ? P1.y : P2.y;

	Point bottomRight;
	bottomRight.x = P1.x > P2.x ? P1.x : P2.x;
	bottomRight.y = P1.y > P2.y ? P1.y : P2.y;

	CreateFigure(topLeft, bottomRight, figGfxInfo);
}

void ActionAddEllipse::CreateFigure(Point topLeft, Point bottomRight, GfxInfo figGfxInfo)
{
	//Step 3 - Create a Ellipse with the parameters read from the user
	CEllipse* ellipse = new CEllipse(topLeft, bottomRight, figGfxInfo);

	//Step 4 - Add the Square to the list of figures
	pManager->AddFigure(ellipse);
}

void ActionAddEllipse::Load(ifstream& input)
{
	// TopLeftCorner.x		TopLeftCorner.y
	// BottomRightCorner.x		BottomRightCorner.y	
	// drawColor	isFilled	fillColor	

	Point TopLeftCorner, BottomRightCorner;
	GfxInfo figGfxInfo;
	figGfxInfo.BorderWdth = pGUI->getCrntPenWidth();

	input >> TopLeftCorner.x >> TopLeftCorner.y;
	input >> BottomRightCorner.x >> BottomRightCorner.y;
	
	int drawC[3];
	input >> drawC[0] >> drawC[1] >> drawC[2];
	figGfxInfo.DrawClr = color((char)drawC[0], (char)drawC[1], (char)drawC[2]);

	input >> figGfxInfo.isFilled;

	if (figGfxInfo.isFilled) {
		int fillC[3];
		input >> fillC[0] >> fillC[1] >> fillC[2];
		figGfxInfo.FillClr = color((char)fillC[0], (char)fillC[1], (char)fillC[2]);
	}

	CreateFigure(TopLeftCorner, BottomRightCorner, figGfxInfo);
}
