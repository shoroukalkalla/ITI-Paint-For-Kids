#include "ActionChangeDrawColor.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"
#include <iostream>

ActionChangeDrawColor::ActionChangeDrawColor(ApplicationManager* pApp) : Action(pApp)
{}

//Execute the action
void ActionChangeDrawColor::Execute()
{

	GUI* pGUI = pManager->GetGUI();

	CFigure* selectedFigure = pManager->GetSelectedFigure();

	ActionType ActType;
	pGUI->PrintMessage("Select a color");
	ActType = pGUI->MapInputToActionType();

	if (selectedFigure) { // if there is a selected shape
		switch (ActType) {
		case SELECT_COLOR_BLUE:
			selectedFigure->ChngDrawClr(BLUE);
			break;
		case SELECT_COLOR_CYAN:
			selectedFigure->ChngDrawClr(CYAN);
			break;
		case SELECT_COLOR_GREEN:
			selectedFigure->ChngDrawClr(GREEN);
			break;
		case SELECT_COLOR_RED:
			selectedFigure->ChngDrawClr(RED);
			break;
		}
	}
	else { // Change all the coming fill shapes
		switch (ActType) {
		case SELECT_COLOR_BLUE:
			pGUI->setCrntDrawColor(BLUE);
			break;
		case SELECT_COLOR_CYAN:
			pGUI->setCrntDrawColor(CYAN);
			break;
		case SELECT_COLOR_GREEN:
			pGUI->setCrntDrawColor(GREEN);
			break;
		case SELECT_COLOR_RED:
			pGUI->setCrntDrawColor(RED);
			break;
		}
	}
	pGUI->ClearStatusBar();
}
