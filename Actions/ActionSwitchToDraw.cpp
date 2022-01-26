#include "ActionSwitchToDraw.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"

ActionSwitchToDraw::ActionSwitchToDraw(ApplicationManager* pApp) :Action(pApp)
{}


void ActionSwitchToDraw::Execute()
{
	GUI* pGUI = pManager->GetGUI();

	pGUI->ClearStatusBar();
	pGUI->PrintMessage("Welcome to Draw mode!");

	pGUI->CreateDrawToolBar(-1);

	pManager->ShowAllFigures();
}
