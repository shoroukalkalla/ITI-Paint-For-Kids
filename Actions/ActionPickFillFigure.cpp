#include "ActionPickFillFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include "..\Figures\CEllipse.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CFigure.h"

class GUI;
ActionPickFillFigure::ActionPickFillFigure(ApplicationManager* pApp) :Action(pApp)
{
}



void ActionPickFillFigure::ReadActionParameters()
{
	GUI* pGUI = pManager->GetGUI();


	pGUI->GetPointClicked(p.x, p.y); //Get user's click
}


int ActionPickFillFigure::Random_Color(int& Result)
{
	GUI* pGUI = pManager->GetGUI();
	int FigCount = pManager->getFigCount();
	
	int figureFillCount = pManager->GetFilledFigCount();
	if (FigCount != 0 && figureFillCount >= 2)
	{
		color* colors= pManager->GetFilledFigColor(); //return colors arr
		int RandIndex = rand() % figureFillCount; //rand fig fill 
		color c = colors[RandIndex]; 

		for (int i = 0; i < FigCount; i++)
		{
			if (IsEqualColor(pManager->DrawnFigs(i)->getFilledColor(), c))
				Result++;
		}
		
		return pManager->GetColorIndex(c);
	}

	return 0;
}

void ActionPickFillFigure::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	Result = 0;

	pGUI->HighlightButton(ITM_SELECT_FILL);

	/*
		ColorsPalletE:
		WHITE, ROYALBLUE, CADETBLUE, LIGHTSEAGREEN, MEDIUMBLUE,
		INDIAN, SANDYBROWN, SALMON, ORANGERED, PALEVIOLETRED,
		DARKCYAN, YELLOWGREEN
	*/
	int colorIndex = Random_Color(Result);
	color c = pGUI->getColorFromPallet(colorIndex);
	PrintGameMessg(colorIndex ,pGUI);

	if (colorIndex != 0)
	{
		int actualFigCount= pManager->getFigCount();
		int i, AllCounter = 0;
		int Res = Result;
		int correct = 0;
		int incorrect = 0;
		for (i = 0; i < actualFigCount; )
		{
			if (Result == 0)
				break;

			ReadActionParameters();

			if (pGUI->isInsideDrawingArea(p.x,p.y) )
			{
				Fig = pManager->GetFigure(p.x, p.y);

				if (Fig != NULL)
				{
					i++;

					if (Fig->IsFigFilled() && IsEqualColor(Fig->getFilledColor(), c))
					{
						correct++;
						Result--;
					}
					else {
						incorrect++;
					}
					if (Result==0) {
						break;
					}

					Fig->Hide();
					pManager->UpdateInterface();
					Fig = NULL;
				}
			}
			else 
			{
				break;
			}
			AllCounter++;
		}
		pManager->ShowAllFigures();
		pManager->UpdateInterface();
		pGUI->PrintMessage("Congratulation , EndGame "+ to_string(correct) + " Correct & " + to_string(incorrect) + " InCorrect");
	}

	pGUI->RemoveButtonHighlight(ITM_SELECT_FILL);
}


void  ActionPickFillFigure::PrintGameMessg(int type ,GUI* pGUI) {
	
	if (type == 0)
		pGUI->PrintMessage("Please Draw some Filled shapes !");

	else  if (type == 1)
		
		pGUI->PrintMessage("Pick all Blue shapes !");

	else if (type == 2)
		pGUI->PrintMessage("Pick all SkyBlue shapes!");

	else if (type == 3)
		pGUI->PrintMessage("Pick all Green shapes !");

	else if (type == 4)
		pGUI->PrintMessage("Pick all DarkBlue shapes !");

	else if (type == 5)
		pGUI->PrintMessage("Pick all Red shapes !");
	else if (type == 6)
		pGUI->PrintMessage("Pick all SandyBrown shapes!");

	else if (type == 7)
		pGUI->PrintMessage("Pick all Brown shapes !");

	else if (type == 8)
		pGUI->PrintMessage("Pick all Orange shapes !");

	else if (type == 9)
		pGUI->PrintMessage("Pick all Violet shapes !");
	else if (type == 10)
		pGUI->PrintMessage("Pick all Cyan shapes !");

	else if (type == 11)
		pGUI->PrintMessage("Pick all YELLOWGREEN shapes !");

	

}
bool ActionPickFillFigure::IsEqualColor(color &a ,color &b) {


	return a.ucRed == b.ucRed && a.ucBlue == b.ucBlue && a.ucGreen == b.ucGreen;
}
