#include "ActionSwitchToPlay.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"

#include <fstream>

ActionSwitchToPlay::ActionSwitchToPlay(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionSwitchToPlay::Execute()
{
	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();

	// to do code
	pGUI->ClearStatusBar();
	pGUI->PrintMessage("welcome to play mode !");



	pGUI->CreatePlayToolBar();

}


