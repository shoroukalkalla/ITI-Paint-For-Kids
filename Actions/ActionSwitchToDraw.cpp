#include "ActionSwitchToDraw.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"

ActionSwitchToDraw::ActionSwitchToDraw(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionSwitchToDraw::Execute()
{
	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();

	pGUI->ClearStatusBar();

	pGUI->PrintMessage("welcome to Draw mode !");

	pGUI->CreateDrawToolBar();


}
