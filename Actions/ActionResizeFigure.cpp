#include "ActionResizeFigure.h"


#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

ActionResizeFigure::ActionResizeFigure(ApplicationManager* pApp, float _resizeFactor) : Action(pApp)
{
	resizeFactor = _resizeFactor;
}

void ActionResizeFigure::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	CFigure* fig = pManager->GetSelectedFigure();

	if (fig == NULL) {
		pGUI->PrintMessage("Select a shape to resize");
		Point point;
		pGUI->GetPointClicked(point.x, point.y);
		fig = pManager->GetFigure(point.x, point.y);
	}

	if (fig != NULL)
	{
		bool canResize = fig->Resize(resizeFactor, pGUI);
		if (canResize) {
			pManager->UpdateInterface();
			pGUI->PrintMessage("Shape Resized Successfully ^_^");
		}
		else {
			pGUI->PrintMessage("Can't resize the shape outsize the bounds!");
		}
	}
	else
	{
		pGUI->PrintMessage("You must select a figure first!");
	}
}