#include "ActionPickFillFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include "..\Figures\CEllipse.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CFigure.h"

//class GUI;
ActionPickFillFigure::ActionPickFillFigure(ApplicationManager* pApp) :Action(pApp)
{
}

void ActionPickFillFigure::ReadActionParameters()
{
	//Get a Pointer to the Input Interfaces
	GUI* pGUI = pManager->GetGUI();
	 //Get user's click
	pGUI->GetPointClicked(p.x, p.y);
}

int ActionPickFillFigure::Random_Color(int& Result)
{
	GUI* pGUI = pManager->GetGUI();
	int FigCount = pManager->getFigCount();				 // number of figer
	int figureFillCount = pManager->GetFilledFigCount(); // number of filled figer

	if (FigCount != 0 && figureFillCount >= 2)
	{
		color* colors= pManager->GetFilledFigColor(); //return colors arr
		int RandIndex = rand() % figureFillCount;     //rand fig fill 
		color c = colors[RandIndex];

		for (int i = 0; i < FigCount; i++)
		{
			if (IsEqualColor(pManager->DrawnFigs(i)->getFilledColor(), c))
				Result++;
		}
		return pManager->GetColorIndex(c);
	}
	
	
}

void ActionPickFillFigure::CalacScore(int correct, int incorrect)
{
	GUI* pGUI = pManager->GetGUI();

	if ( correct > incorrect )
	{
		pGUI->PrintMessage("Well done You win !, Your score is : " + to_string(correct) + " Right, and : " + to_string(incorrect) + " Wrong.");
	}
	else if (correct == incorrect && correct != 0)
	{
		pGUI->PrintMessage("Try again , Your score is : " + to_string(correct) + " Right, and : " + to_string(incorrect) + " Wrong.");
	}
	else if (correct < incorrect)
	{
		pGUI->PrintMessage("Hard Luke you lose !, Your score is : " + to_string(correct) + " Right, and : " + to_string(incorrect) + " Wrong.");
	}
}


void ActionPickFillFigure::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	Result = 0;

	pGUI->HighlightButton(ITM_SELECT_FILL);
	
	int colorIndex = Random_Color(Result);
	
	color c = pGUI->getColorFromPallet(colorIndex);
	
	PrintGameMessg(colorIndex ,pGUI);

	if (colorIndex != 0)
	{
		int actualFigCount= pManager->getFigCount();
		int i;
		int correct = 0;
		int incorrect = 0;
		for (i = 0; i < actualFigCount; )
		{
			if (Result == 0)
				break;

			
			
			
				
			/*if (Fig == NULL) {
				pGUI->PrintMessage(" game aborted.");
				showShapes();
				pGUI->RemoveButtonHighlight(ITM_SELECT_TYPE_FILL);
				return;

			}*/
			
			
			/*if (pGUI->isInsideDrawingArea(p.x,p.y) )
			{*/
			ReadActionParameters();
				Fig = pManager->GetFigure(p.x, p.y);

				if (Fig != NULL)
				{
					i++;

					if (Fig->IsFigFilled() && IsEqualColor(Fig->getFilledColor(), c))
					{
						correct++;
						hideshape();
						pGUI->PrintMessage("Right!, Your score is : " + to_string(correct) + " Right, and " + to_string(incorrect) + " Wrong.");
						Result--;


					}
					else {
						incorrect++;
						hideshape();
						pGUI->PrintMessage("Wrong!, Your score is : " + to_string(correct) + " Right, and " + to_string(incorrect) + " Wrong.");

					}
					
					if (Result==0) {
						showShapes();
						pManager->UpdateInterface();
						CalacScore(correct, incorrect);
				
						break;
					}

					/*hideshape();*/
					pManager->UpdateInterface();
					Fig = NULL;
				

				}	
			
			
		}
		
		
	}

	pGUI->RemoveButtonHighlight(ITM_SELECT_FILL);

}

void ActionPickFillFigure::hideshape()
{
	Fig->Hide();
	pManager->UpdateInterface();

}
void ActionPickFillFigure::showShapes()
{
	for (int i = 0; i < pManager->getFigCount(); i++) {
		pManager->DrawnFigs(i)->Show();
	}
	pManager->UpdateInterface();
}
void  ActionPickFillFigure::PrintGameMessg(int type ,GUI* pGUI) {
	
	if (type == 0)
		pGUI->PrintMessage("You must have at least two filled figures to play ! ");

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
