#include "ActionPickTypeFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include "..\Figures\CEllipse.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CHexagon.h"


ActionPickTypeFigure::ActionPickTypeFigure(ApplicationManager* pApp) :Action(pApp)
{
	no_figs = 0;
	rightSelect = 0;
	wrongSelect = 0;

	for (int i = 0; i < 3; i++)
	{
		figs[i] = 0;		// set all elemente with 0
	}
	
}

//Calculate the Score
void ActionPickTypeFigure::calcScore(int num)
{
	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();

	//
	string Message;
	
	if (num == 1)
	{
		rightSelect++;
		Message = "Right!, Your score is: " + to_string(rightSelect) + " Right, and " + to_string(wrongSelect) + " Wrong.";
	}
	else if (num == 2)
	{
		wrongSelect++;
		Message = "Wrong!, Your score is: " + to_string(rightSelect) + " Right, and " + to_string(wrongSelect) + " Wrong.";
	}
	else
	{
		if (rightSelect > wrongSelect)
		{
			Message = "Well done You win!, Your score is : " + to_string(rightSelect) + " Right, and : " + to_string(wrongSelect) + " Wrong.";
		}
		else if (rightSelect == wrongSelect && rightSelect != 0)
		{
			Message = "Try again it's Draw!, Your score is : " + to_string(rightSelect) + " Right, and : " + to_string(wrongSelect) + " Wrong.";
		}
		else
		{
			Message = "Hard Luke you lose !, Your score is : " + to_string(rightSelect) + " Right, and : " + to_string(wrongSelect) + " Wrong.";
		}
	
	}
	
	pGUI->PrintMessage(Message);


}

void ActionPickTypeFigure::ReadParameters()
{
	for (int i = 0; i < pManager->getFigCount(); i++)
	{
		Fig = pManager->DrawnFigs(i);
		if (dynamic_cast<CSquare*>(Fig))
			figs[0]++;
		else if (dynamic_cast<CEllipse*>(Fig))
			figs[1]++;
		else if (dynamic_cast<CHexagon*>(Fig))
			figs[2]++;
		//else figs[3]++;
	}		
	
	for (int i = 0; i < 3; i++)
	{
		if (figs[i] != 0)
			no_figs++;
	}
}

//Execute the action
void ActionPickTypeFigure::Execute()
{
	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();

	pGUI->HighlightButton(ITM_SELECT_TYPE);

	pGUI->ClearStatusBar();

	ReadParameters();

	if (no_figs > 1)
	{
		CFigure* clickedFig;
		// get random number in the range 0 to figCount
		rand_fig_no = rand() % pManager->getFigCount();

		// counting fig instances
		Fig = pManager->DrawnFigs(rand_fig_no);
		
	
		if(dynamic_cast<CSquare*>(Fig))
		{
			picked_fig_no = figs[0];
			pGUI->PrintMessage("Pick up all the Squares !");

		}
		else if (dynamic_cast<CEllipse*>(Fig))
		{
			picked_fig_no = figs[1];
			pGUI->PrintMessage("Pick up all the Ellipses !");

		}
		else
		{
			picked_fig_no = figs[2];
			pGUI->PrintMessage("Pick up all the Hexagons !");

		}

		while (picked_fig_no > 0)
		{
			{
				pGUI->GetPointClicked(p.x, p.y);
				
				clickedFig = pManager->GetFigure(p.x, p.y);

				if (clickedFig != NULL)
				{

					if ((dynamic_cast<CSquare*>(clickedFig)) && (dynamic_cast<CSquare*>(Fig)))
					{
						calcScore(1);
						clickedFig->Hide();
						pManager->UpdateInterface();
						picked_fig_no--;
					}
					else if ((dynamic_cast<CEllipse*>(clickedFig)) && (dynamic_cast<CEllipse*>(Fig)))
					{
						calcScore(1);
						clickedFig->Hide();
						pManager->UpdateInterface();
						picked_fig_no--;
					}
					else if ((dynamic_cast<CHexagon*>(clickedFig)) && (dynamic_cast<CHexagon*>(Fig)))
					{
						calcScore(1);
						clickedFig->Hide();
						pManager->UpdateInterface();
						picked_fig_no--;
					}
					else
					{
						calcScore(2);
						clickedFig->Hide();
						pManager->UpdateInterface();
					}
				
				}
			}

			if (picked_fig_no == 0)
			{
				calcScore(3);
			}
		}
	}
	else
	{
		pGUI->PrintMessage("You must have at least two types of figures to play ! ");
	}

	for (int i = 0; i < pManager->getFigCount(); i++)
	{
		pManager->DrawnFigs(i)->Show();
	}
	pManager->UpdateInterface();

	pGUI->RemoveButtonHighlight(ITM_SELECT_TYPE);
}


ActionPickTypeFigure::~ActionPickTypeFigure() {
	//
}


