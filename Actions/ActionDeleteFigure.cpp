#include "ActionDeleteFigure.h"

ActionDeleteFigure::ActionDeleteFigure(ApplicationManager* pApp) :Action(pApp)
{}

void ActionDeleteFigure::Execute()
{
	Point P1;

	GUI* pGUI = pManager->GetGUI();

	pGUI->HighlightButton(ITM_DELETE_SELECTED);

	CFigure* selected = pManager->GetSelectedFigure();

	if (selected == NULL) {
		pGUI->PrintMessage("Delete figure: select a figure to delete");
		pGUI->GetPointClicked(P1.x, P1.y);
		pGUI->ClearStatusBar();

		selected = pManager->GetFigure(P1.x, P1.y);
		selected->SetSelected(true);
		pManager->SetSelectedFigure(selected);
	}

	pGUI->RemoveButtonHighlight(ITM_DELETE_SELECTED);

	pManager->DeleteSelectedFigures();
}