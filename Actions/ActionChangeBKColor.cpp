#include "ActionChangeBKColor.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

ActionChangeBKColor::ActionChangeBKColor(ApplicationManager* pApp) : Action(pApp)
{}

//Execute the action
void ActionChangeBKColor::Execute()
{
	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();

	Point P1;
	pGUI->PrintMessage("Select a color to fill the background");
	pGUI->GetPointClicked(P1.x, P1.y);
	pGUI->ClearStatusBar();

	int colorIndex = pGUI->getColorIndex(P1.x, P1.y);
	if (colorIndex > -1) {
		pGUI->UpdateCrntBkColor(colorIndex);
		return;
	}
}
