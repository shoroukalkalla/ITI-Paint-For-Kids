#include "ActionChangeFillColor.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

ActionChangeFillColor::ActionChangeFillColor(ApplicationManager* pApp) : Action(pApp)
{}

//Execute the action
void ActionChangeFillColor::Execute()
{
	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();

	pGUI->HighlightButton(ITM_FILL_CLR);

	CFigure* selectedFigure = pManager->GetSelectedFigure();

	Point P1;
	pGUI->PrintMessage("Select a figure to fill with the selected color OR select a color");
	pGUI->GetPointClicked(P1.x, P1.y);
	pGUI->ClearStatusBar();

	// [1] check if the user selects a figure
	selectedFigure = pManager->GetFigure(P1.x, P1.y);
	if (selectedFigure != NULL) { // The user clicks a figure
		// Change the fill color
		if (pGUI->getCrntIsFilled()) { // UI.isFilled
			selectedFigure->ChngFillClr(pGUI->getCrntFillColor());
		}
		else {
			selectedFigure->SetIsFilled(false);
		}

		pGUI->RemoveButtonHighlight(ITM_FILL_CLR);
		return;
	}

	// [2] check if the user selects a color
	int colorIndex = pGUI->getColorIndex(P1.x, P1.y);
	if (colorIndex > -1) {
		pGUI->UpdateCrntFillColor(colorIndex);
	}

	pGUI->RemoveButtonHighlight(ITM_FILL_CLR);
}
