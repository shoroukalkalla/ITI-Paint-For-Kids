#include "ActionSelectFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

ActionSelectFigure::ActionSelectFigure(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionSelectFigure::Execute()
{
	Point P1;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();

	pGUI->PrintMessage("Select Figure: Click to select a figure");
	//Read point to select a figure
	pGUI->GetPointClicked(P1.x, P1.y);

	pGUI->ClearStatusBar();

	//Step 4 - Add the Square to the list of figures
	CFigure* selected = pManager->GetFigure(P1.x, P1.y);

	if (selected != NULL) {
		selected->SetSelected(!selected->IsSelected());
	}


}
