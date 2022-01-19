#include "ActionPickTypeFillFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include "..\Figures\CEllipse.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CHexagon.h"


ActionPickTypeFillFigure::ActionPickTypeFillFigure(ApplicationManager* pApp) :Action(pApp)
{
}


//Execute the action
void ActionPickTypeFillFigure::Execute()
{
	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();

	pGUI->ClearStatusBar();

	pGUI->PrintMessage("pick type filled figure ! ");

}
