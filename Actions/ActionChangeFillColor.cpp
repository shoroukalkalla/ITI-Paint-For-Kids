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

	ActionType ActType;
	pGUI->PrintMessage("Select a color");
	ActType = pGUI->MapInputToActionType();

	if (selectedFigure) { // if there is a selected shape
		switch (ActType) {
			case SELECT_COLOR_BLUE:
				selectedFigure->ChngFillClr(BLUE);
				break;
			case SELECT_COLOR_CYAN:
				selectedFigure->ChngFillClr(CYAN);
				break;
			case SELECT_COLOR_GREEN:
				selectedFigure->ChngFillClr(GREEN);
				break;
			case SELECT_COLOR_RED:
				selectedFigure->ChngFillClr(RED);
				break;
		}
	}
	else { // Change all the coming fill shapes
		switch (ActType) {
		case SELECT_COLOR_BLUE:
			pGUI->setCrntFillColor(BLUE);
			break;
		case SELECT_COLOR_CYAN:
			pGUI->setCrntFillColor(CYAN);
			break;
		case SELECT_COLOR_GREEN:
			pGUI->setCrntFillColor(GREEN);
			break;
		case SELECT_COLOR_RED:
			pGUI->setCrntFillColor(RED);
			break;
		}
	}
	pGUI->ClearStatusBar();
}
