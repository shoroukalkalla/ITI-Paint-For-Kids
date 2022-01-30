#include "ActionPickFillFigure.h"
#include "..\ApplicationManager.h"
#include "..\CMUgraphicsLib\colors.cpp" 
#include "..\GUI\GUI.h"
#include "..\Figures\CEllipse.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CFigure.h"

ActionPickFillFigure::ActionPickFillFigure(ApplicationManager* pApp) :Action(pApp)
{
	no_colors = 0;
	rightSelect = 0;
	wrongSelect = 0;

	for (int i = 0; i < 12; i++)
	{
		colors[i] = 0;		// set all elemente with 0
	}
}

color ActionPickFillFigure::coloreSelected(CFigure* Fig)
{
	if (Fig->GetGfxInfo().isFilled)
	{
		if (Fig->GetGfxInfo().FillClr == ROYALBLUE)
			return ROYALBLUE;
		else if (Fig->GetGfxInfo().FillClr == CADETBLUE)
			return CADETBLUE;
		else if (Fig->GetGfxInfo().FillClr == LIGHTSEAGREEN)
			return LIGHTSEAGREEN;
		else if (Fig->GetGfxInfo().FillClr == MEDIUMBLUE)
			return MEDIUMBLUE;
		else if (Fig->GetGfxInfo().FillClr == INDIAN)
			return INDIAN;
		else if (Fig->GetGfxInfo().FillClr == SANDYBROWN)
			return SANDYBROWN;
		else if (Fig->GetGfxInfo().FillClr == SALMON)
			return SALMON;
		else if (Fig->GetGfxInfo().FillClr == ORANGERED)
			return ORANGERED;
		else if (Fig->GetGfxInfo().FillClr == PALEVIOLETRED)
			return PALEVIOLETRED;
		else if (Fig->GetGfxInfo().FillClr == DARKCYAN)
			return DARKCYAN;
		else if (Fig->GetGfxInfo().FillClr == YELLOWGREEN)
			return YELLOWGREEN;
	}
	return BLACK;
}

//Calculate the Score
void ActionPickFillFigure::calcScore(int num)
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
		else if (rightSelect == wrongSelect)
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

void ActionPickFillFigure::GetFilledShape()
{
	for (int i = 0; i < pManager->getFigCount(); i++) {
		Fig = pManager->DrawnFigs(i);

		// counting colors exists
		if (Fig->GetGfxInfo().isFilled)
		{
			if (Fig->GetGfxInfo().FillClr == ROYALBLUE)
				colors[0]++;
			else if (Fig->GetGfxInfo().FillClr == CADETBLUE)
				colors[1]++;
			else if (Fig->GetGfxInfo().FillClr == LIGHTSEAGREEN)
				colors[2]++;
			else if (Fig->GetGfxInfo().FillClr == MEDIUMBLUE)
				colors[3]++;
			else if (Fig->GetGfxInfo().FillClr == INDIAN)
				colors[4]++;
			else if (Fig->GetGfxInfo().FillClr == SANDYBROWN)
				colors[5]++;
			else if (Fig->GetGfxInfo().FillClr == SALMON)
				colors[6]++;
			else if (Fig->GetGfxInfo().FillClr == ORANGERED)
				colors[7]++;
			else if (Fig->GetGfxInfo().FillClr == PALEVIOLETRED)
				colors[8]++;
			else if (Fig->GetGfxInfo().FillClr == DARKCYAN)
				colors[9]++;
			else if (Fig->GetGfxInfo().FillClr == YELLOWGREEN)
				colors[10]++;
		}
		else
		{
			colors[11]++;
		}
	}

	for (int i = 0; i < 11; i++)
		if (colors[i] != 0)
		{
			no_colors++;
		}
}

void ActionPickFillFigure::Execute()
{
	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();

	pGUI->HighlightButton(ITM_SELECT_FILL);

	pGUI->ClearStatusBar();

	GetFilledShape();

	if (no_colors > 1)
	{
		CFigure* clickedFig;

		// get random number in the range 0 to figCount
		rand_fig_no = rand() % pManager->getFigCount();

		//Counting the the color instances.
		Fig = pManager->DrawnFigs(rand_fig_no);

		if (Fig->GetGfxInfo().isFilled)
		{
			if (Fig->GetGfxInfo().FillClr == ROYALBLUE)
			{
				picked_color_no = colors[0];
				pGUI->PrintMessage("Pick all ROYALBLUE shapes !");
			}
			else if (Fig->GetGfxInfo().FillClr == CADETBLUE)
			{
				picked_color_no = colors[1];
				pGUI->PrintMessage("Pick all CADETBLUE shapes !");
			}
			else if (Fig->GetGfxInfo().FillClr == LIGHTSEAGREEN)
			{
				picked_color_no = colors[2];
				pGUI->PrintMessage("Pick all LIGHTSEAGREEN shapes !");
			}
			else if (Fig->GetGfxInfo().FillClr == MEDIUMBLUE)
			{
				picked_color_no = colors[3];
				pGUI->PrintMessage("Pick all MEDIUMBLUE shapes !");
			}
			else if (Fig->GetGfxInfo().FillClr == INDIAN)
			{
				picked_color_no = colors[4];
				pGUI->PrintMessage("Pick all INDIAN shapes !");
			}
			else if (Fig->GetGfxInfo().FillClr == SANDYBROWN)
			{
				picked_color_no = colors[5];
				pGUI->PrintMessage("Pick all SANDYBROWN shapes !");
			}
			else if (Fig->GetGfxInfo().FillClr == SALMON)
			{
				picked_color_no = colors[6];
				pGUI->PrintMessage("Pick all SALMON shapes !");
			}
			else if (Fig->GetGfxInfo().FillClr == ORANGERED)
			{
				picked_color_no = colors[7];
				pGUI->PrintMessage("Pick all ORANGERED shapes !");
			}
			else if (Fig->GetGfxInfo().FillClr == PALEVIOLETRED)
			{
				picked_color_no = colors[8];
				pGUI->PrintMessage("Pick all PALEVIOLETRED shapes !");
			}
			else if (Fig->GetGfxInfo().FillClr == DARKCYAN)
			{
				picked_color_no = colors[9];
				pGUI->PrintMessage("Pick all DARKCYAN shapes !");
			}
			else if (Fig->GetGfxInfo().FillClr == YELLOWGREEN)
			{
				picked_color_no = colors[10];
				pGUI->PrintMessage("Pick all YELLOWGREEN shapes !");
			}
		}
		else
		{
			picked_color_no = colors[11];
			pGUI->PrintMessage("Pick all UNFILLED shapes !");
		}


		while (picked_color_no > 0)
		{
			pGUI->GetPointClicked(p.x, p.y);
			
			if (p.y > UI.ToolBarHeight || p.x > (UI.MenuItemWidth * PLAY_ITM_COUNT))
			{
				clickedFig = pManager->GetFigure(p.x, p.y);
				if (clickedFig != NULL)
				{
					// unfilled shape
					if (!(Fig->GetGfxInfo().isFilled) && !(clickedFig->GetGfxInfo().isFilled )) 
					{
						calcScore(1);
						clickedFig->Hide();
						pManager->UpdateInterface();
						picked_color_no--;
					}

					// filled color with specific color
					else if (clickedFig->GetGfxInfo().isFilled && clickedFig->GetGfxInfo().FillClr == coloreSelected(Fig))
					{
						calcScore(1);
						clickedFig->Hide();
						pManager->UpdateInterface();
						picked_color_no--;
					}
					else
					{
						calcScore(2);
						clickedFig->Hide();
						pManager->UpdateInterface();
					}
				}
			}
			else {
				picked_color_no = -1;
				pGUI->ClearStatusBar();
			}
		}

		//end Clicked
		if (picked_color_no == 0)
		{
			calcScore(3);
		}
	}
	
	else 
	{
		pGUI->PrintMessage("You must have at least two filled figures to play ! ");
	}

	for (int i = 0; i < pManager->getFigCount(); i++)
	{
		pManager->DrawnFigs(i)->Show();
	}

	pManager->UpdateInterface();

	pGUI->RemoveButtonHighlight(ITM_SELECT_FILL);


}

ActionPickFillFigure::~ActionPickFillFigure() {
	//
}
