#include "ApplicationManager.h"
#include "Actions\ActionAddSquare.h"
#include "Actions\ActionAddEllipse.h"
#include "Actions\ActionAddHexagon.h"
#include "Actions\ActionSelectFigure.h"
#include "Actions\ActionSwitchToPlay.h"
#include "Actions\ActionSwitchToDraw.h"
#include "Actions\ActionPickTypeFigure.h"
#include "Actions\ActionChangeFillColor.h"
#include "Actions\ActionChangeDrawColor.h"
#include "Actions\ActionChangeBKColor.h"
#include "Actions\ActionPickFillFigure.h"
#include "Actions\ActionPickTypeFillFigure.h"



//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pGUI = new GUI;
	
	FigCount = 0;

	// (-1) means there is no selected figure
	SelectedFigure = NULL;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

void ApplicationManager::Run()
{
	ActionType ActType;
	do
	{		
		//1- Read user action
		ActType = pGUI->MapInputToActionType();

		//2- Create the corresponding Action
		Action* pAct = CreateAction(ActType);
		
		//3- Execute the action
		ExecuteAction(pAct);

		//4- Update the interface
		UpdateInterface();

	} while(ActType != EXIT);
	
}


//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
//Creates an action
Action* ApplicationManager::CreateAction(ActionType ActType) 
{
	Action* newAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_SQUARE:
			newAct = new ActionAddSquare(this);
			break;

		case DRAW_ELPS:
			newAct = new ActionAddEllipse(this);
			break;

		case DRAW_HEX:
			newAct = new ActionAddHexagon(this);
			break;

		case SELECT_FIGURE:
			newAct = new ActionSelectFigure(this);
			break;

		case CHNG_FILL_CLR:
			newAct = new ActionChangeFillColor(this);
			break;	

		case CHNG_DRAW_CLR:
			newAct = new ActionChangeDrawColor(this);
			break;

		case CHNG_BK_CLR:
			newAct = new ActionChangeBKColor(this);
			break;

		case TO_PLAY:
			newAct = new ActionSwitchToPlay(this);
			break;

		// FOR PLAY MODE

		case TO_DRAW:
			newAct = new ActionSwitchToDraw(this);
			break;

		case TO_PICK_TYPE:
			newAct = new ActionPickTypeFigure(this);
			break;

		case TO_PICK_FILL:
			newAct = new ActionPickFillFigure(this);
			break;

		case TO_PICK_TYPE_FILL:
			newAct = new ActionPickTypeFillFigure(this);
			break;

		case EXIT:
			///create ExitAction here
			break;
					
		case STATUS:	//a click on the status bar ==> no action
			return NULL;
			break;
	}	
	return newAct;
}
//////////////////////////////////////////////////////////////////////
//Executes the created Action
void ApplicationManager::ExecuteAction(Action* &pAct) 
{	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y)
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL

	///Add your code here to search for a figure given a point x,y

	// old ---> 17/1/2022
	/*for (int i = FigCount - 1; i >= 0; i--) {
		if (FigList[i] != NULL) {
			if (FigList[i]->isPointIn(x, y)) {
				return FigList[i];
			}
		}
	}*/

	// new  ---> 17/1/2022
	for (int i = FigCount - 1; i >= 0; i--) {
		if (FigList[i]->HiddenStatus() == false)
			if (FigList[i]->isPointIn(x, y))
				return FigList[i];
	}

	return NULL;
}

void ApplicationManager::SetSelectedFigure(CFigure* figure)
{
	SelectedFigure = figure;
}

CFigure* ApplicationManager::GetSelectedFigure()
{
	return SelectedFigure;
}




////////////////////////////////////////////////////////////////////////////////////

//Transfer FigCount to playmode to avoid unnessecary loops   //17-1-2022
int ApplicationManager::getFigCount() const
{
	return FigCount;
}

//Transfer figures in FigList to playmode
CFigure* ApplicationManager::DrawnFigs(int i) const
{
	return FigList[i];
}

//void ApplicationManager::Loop(CFigure* deleted) {
//	for (int i = 0; i < FigCount; i++)
//		if (deleted == FigList[i])
//		{
//			delete FigList[i];
//			FigList[i] = NULL;
//			//PasteFlag = SelectFlag = 0;
//			FigCount--;
//			for (int j = i; j < FigCount; j++)
//				FigList[j] = FigList[j + 1];
//			break;
//		}
//}

int ApplicationManager::GetFilledFigCount()
{
	int count=0;

	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->IsFigFilled()) {
			count++;

		}

	}
	return count;
}

color* ApplicationManager::GetFilledFigColor()
{
	int count = GetFilledFigCount();
	color* colors= new color[count];
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->IsFigFilled()) {
			colors[i]= FigList[i]->getFilledColor();
			
		}

	}
	return colors;
}

int ApplicationManager::GetColorIndex(color& c) {
	
	
	for (int i=0; i < pGUI->GetColorsCount(); i++) {
		if (IsEqualColor(c, pGUI->getColorFromPallet(i)))
		{
			return i;
		}

	}
	return -1;
}


bool ApplicationManager::IsEqualColor(color& a, color& b) {


	return a.ucRed == b.ucRed && a.ucBlue == b.ucBlue && a.ucGreen == b.ucGreen;
}
////////////////////////////////////////////////////////////////////////////////////




//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	pGUI->ResetDrawingArea();

	// old ----> 17/1/2022
	/*for (int i = 0; i < FigCount; i++)
		FigList[i]->DrawMe(pGUI);*/		//Call Draw function (virtual member fn)
		
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->HiddenStatus() == false)
			FigList[i]->DrawMe(pGUI);		//Call Draw function (virtual member fn)
	}

}

////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the interface
GUI *ApplicationManager::GetGUI() const
{	return pGUI; }

////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pGUI;
	
}



//////////////////////////////////////////////////////////////////////////////////////////////
