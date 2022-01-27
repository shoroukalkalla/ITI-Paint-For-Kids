#include "ActionAddFigure.h"

#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"


ActionAddFigure::ActionAddFigure(ApplicationManager* pApp) : Action(pApp)
{
	pGUI = pApp->GetGUI();
}

void ActionAddFigure::Execute()
{
	pGUI->HighlightButton(GetMenuItemIndex());
	AddFigure();
	pGUI->RemoveButtonHighlight(GetMenuItemIndex());
}

void ActionAddFigure::ReadPoint(int& x, int& y, string msg, bool highlight) const
{
	pGUI->PrintMessage(msg);

	do {
		pGUI->GetPointClicked(x, y);
	} while (!pGUI->isInsideDrawingArea(x, y));

	pGUI->ClearStatusBar();

	if (highlight) { // Highlight the point clicked if needed
		pGUI->drawPoint(x, y);
	}
		
}

void ActionAddFigure::InitGfxInfo(GfxInfo& gfxInfo) const
{
	gfxInfo.isFilled = pGUI->getCrntIsFilled();
	gfxInfo.DrawClr = pGUI->getCrntDrawColor();
	gfxInfo.FillClr = pGUI->getCrntFillColor();
	gfxInfo.BorderWdth = pGUI->getCrntPenWidth();
}
