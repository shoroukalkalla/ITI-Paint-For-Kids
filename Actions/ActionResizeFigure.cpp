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

	if (fig != NULL)
	{
		fig->Resize(resizeFactor);
		pManager->UpdateInterface();
		pGUI->PrintMessage("Shape Resized Successfully");
	}
	else
	{
		pGUI->PrintMessage("select the shape first");
	}
}