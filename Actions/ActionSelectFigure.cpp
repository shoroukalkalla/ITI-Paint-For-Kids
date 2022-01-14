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
	do {
		pGUI->GetPointClicked(P1.x, P1.y);
	} while (!pGUI->isInsideDrawingArea(P1.x, P1.y));

	pGUI->ClearStatusBar();

	//Step 4 - Add the Square to the list of figures
	CFigure* selected = pManager->GetFigure(P1.x, P1.y);
	CFigure* lastSelected = pManager->GetSelectedFigure();

	// If -> The user clicks in empty area
	// Or -> The user clicks the selected figure
	// Deselect current selected figure if found
	if (lastSelected != NULL)
	{
		DeselectFigure(lastSelected);
	}

	if (selected != NULL && selected != lastSelected) {
		// If -> The user clicks a figure that is not selected before
		// Toggle selection
		selected->SetSelected(true);
		pManager->SetSelectedFigure(selected);
	}
}

void ActionSelectFigure::DeselectFigure(CFigure* lastSelected) const
{
	lastSelected->SetSelected(false);
	pManager->SetSelectedFigure(NULL);
}


