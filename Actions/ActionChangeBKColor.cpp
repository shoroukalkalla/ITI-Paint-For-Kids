#include "ActionChangeBKColor.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"
#include <iostream>

ActionChangeBKColor::ActionChangeBKColor(ApplicationManager* pApp) : Action(pApp)
{}

//Execute the action
void ActionChangeBKColor::Execute()
{
	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();

	CFigure* selectedFigure = pManager->GetSelectedFigure();

	ActionType ActType;
	pGUI->PrintMessage("Select a color");
	ActType = pGUI->MapInputToActionType();

	switch (ActType) {
	case SELECT_COLOR_BLUE:
		pGUI->setCrntBKColor(BLUE);
		break;
	case SELECT_COLOR_CYAN:
		pGUI->setCrntBKColor(CYAN);
		break;
	case SELECT_COLOR_GREEN:
		pGUI->setCrntBKColor(GREEN);
		break;
	case SELECT_COLOR_RED:
		pGUI->setCrntBKColor(RED);
		break;
	}
	pGUI->ClearStatusBar();
}
