#include "ActionPickTypeFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"

ActionPickTypeFigure::ActionPickTypeFigure(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionPickTypeFigure::Execute()
{
	
	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();

	// to do code
	pGUI->ClearStatusBar();
	pGUI->PrintMessage("select a type figre");


}


