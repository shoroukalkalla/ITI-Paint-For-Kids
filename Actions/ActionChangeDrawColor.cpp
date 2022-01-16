#include "ActionChangeDrawColor.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"
#include <iostream>

ActionChangeDrawColor::ActionChangeDrawColor(ApplicationManager* pApp) : Action(pApp)
{}

//Execute the action
void ActionChangeDrawColor::Execute()
{
	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();

	CFigure* selectedFigure = pManager->GetSelectedFigure();

	Point P1;
	pGUI->PrintMessage("Select a figure to color the border with the selected color OR select a color");
	pGUI->GetPointClicked(P1.x, P1.y);
	pGUI->ClearStatusBar();

	// [1] check if the user selects a figure
	selectedFigure = pManager->GetFigure(P1.x, P1.y);
	if (selectedFigure != NULL) {
		// Change the fill color
		selectedFigure->ChngDrawClr(pGUI->getCrntDrawColor());
		return;
	}

	// [2] check if the user selects a color
	int colorIndex = pGUI->getColorIndex(P1.x, P1.y);
	if (colorIndex > -1) {
		pGUI->UpdateCrntDrawColor(colorIndex);
		return;
	}
}
