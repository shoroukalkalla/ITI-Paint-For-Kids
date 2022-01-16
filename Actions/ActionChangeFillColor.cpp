#include "ActionChangeFillColor.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"
#include <iostream>

ActionChangeFillColor::ActionChangeFillColor(ApplicationManager* pApp) : Action(pApp)
{}

//Execute the action
void ActionChangeFillColor::Execute()
{
	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();

	CFigure* selectedFigure = pManager->GetSelectedFigure();

	Point P1;
	pGUI->PrintMessage("Select a figure to fill with the selected color OR select a color");
	pGUI->GetPointClicked(P1.x, P1.y);
	pGUI->ClearStatusBar();

	// [1] check if the user selects a figure
	selectedFigure = pManager->GetFigure(P1.x, P1.y);
	if (selectedFigure != NULL) {
		// Change the fill color
		if (pGUI->getCrntIsFilled()) {
			selectedFigure->ChngFillClr(pGUI->getCrntFillColor());
		}
		else {
			selectedFigure->SetIsFilled(false);
		}
		return;
	}

	// [2] check if the user selects a color
	int colorIndex = pGUI->getColorIndex(P1.x, P1.y);
	if (colorIndex > -1) {
		pGUI->UpdateCrntFillColor(colorIndex);
		return;
	}
}
