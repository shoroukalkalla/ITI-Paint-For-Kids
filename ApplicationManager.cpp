#include <fstream>
#include <iostream>

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
#include "Actions\ActionBringFront.h"
#include "Actions\ActionSendToBack.h";
#include "Actions\ActionResizeFigure.h";
#include "Actions\ActionPickFillFigure.h"
#include "Actions\ActionPickTypeFillFigure.h"
#include "Actions\ActionStoreGraph.h"
#include "Actions\ActionDeleteFigure.h"
#include "Actions\ActionRestoreGraph.h"


//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pGUI = new GUI;
	
	ClearAllFigures();
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

	} while(true /*ActType != EXIT*/);
	
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

		case CHNG_DRAW_CLR:
			newAct = new ActionChangeDrawColor(this);
			break;

		case CHNG_FILL_CLR:
			newAct = new ActionChangeFillColor(this);
			break;	

		case CHNG_BK_CLR:
			newAct = new ActionChangeBKColor(this);
			break;

		case SEND_BACK:
			newAct = new ActionSendToBack(this);
			break;

		case BRNG_FRNT:
			newAct = new ActionBringToFront(this);
			break;

		// ----- Resize Cases -----

		case RESIZE_QUARTER:
			newAct = new ActionResizeFigure(this, 0.25);
			break;

		case RESIZE_HALF:
			newAct = new ActionResizeFigure(this, .5);
			break;

		case RESIZE_DOUBLE:
			newAct = new ActionResizeFigure(this, 2);
			break;

		case RESIZE_QUADRUPLE:
			newAct = new ActionResizeFigure(this, 4);
			break;

		case DEL:
			newAct = new ActionDeleteFigure(this);
			break;

		case SAVE:
			newAct = new ActionStoreGraph(this);
			break;

		case LOAD:
			newAct = new ActionRestoreGraph(this);
			break;

		case TO_PLAY:
			newAct = new ActionSwitchToPlay(this);
			break;

		// ----- FOR PLAY MODE -----

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
			ShowConfirmMessage();
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

void ApplicationManager::DeleteSelectedFigures()
{
	for (int j = 0; j < FigCount; j++)
	{
		if (FigList[j]->IsSelected())
		{
			delete FigList[j];
			FigList[j] = NULL;
			for (int i = j; i < FigCount - 1; i++)
				FigList[i] = FigList[i + 1];
			FigList[FigCount - 1] = NULL;
			FigCount--;
		}
	}
	SetSelectedFigure(NULL);
}

void ApplicationManager::ClearAllFigures()
{
	FigCount = 0;

	// (-1) means there is no selected figure
	SelectedFigure = NULL;

	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
		FigList[i] = NULL;
}

void ApplicationManager::StoreGraphData(ofstream& OutFile)
{
	// Draw_Color
	OutFile << (int)UI.DrawColor.ucRed << "\t" << (int)UI.DrawColor.ucGreen << "\t" << (int)UI.DrawColor.ucBlue << "\t";
	// Fill_Color
	OutFile << (int)UI.FillColor.ucRed << "\t" << (int)UI.FillColor.ucGreen << "\t" << (int)UI.FillColor.ucBlue << "\t";
	// Background_Color
	OutFile << (int)UI.BkGrndColor.ucRed << "\t" << (int)UI.BkGrndColor.ucGreen << "\t" << (int)UI.BkGrndColor.ucBlue << "\n";
	// Number_of_Figures
	OutFile << FigCount;

	for (int i = 0; i < FigCount; ++i) {
		OutFile << "\n";
		FigList[i]->Save(OutFile);
	}
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

int ApplicationManager::GetSelectedIndexFigure() {
	for (int i = FigCount - 1; i >= 0; i--) {
		if (FigList[i] != NULL) {
			if (FigList[i]->IsSelected())
				return i;
		}
	}
	return -1;

}

void ApplicationManager::BringToFront(int selectedIndex) {
	CFigure* SelectedFigure = FigList[selectedIndex];
	for (int i = selectedIndex; i < FigCount - 1; i++)
		FigList[i] = FigList[i + 1];

	FigList[FigCount - 1] = SelectedFigure;
}

void ApplicationManager::SendToBack(int selectedIndex) {
	CFigure* SelectedFigure = FigList[selectedIndex];
	for (int i = selectedIndex; i > 0; i--)
		FigList[i] = FigList[i - 1];

	FigList[0] = SelectedFigure;
}

void ApplicationManager::ShowAllFigures()
{
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->IsFigFilled()) {
			FigList[i]->Show();
		}
	}
}

int ApplicationManager::ShowConfirmMessage()
{
	int msgboxID = MessageBox(
		NULL,
		"Are you sure?\nMake sure your graph is saved!",
		"Exit",
		MB_OKCANCEL | MB_DEFBUTTON2 | MB_ICONWARNING
	);

	if (msgboxID == IDOK) {
		exit(0);
	}

	return msgboxID;
}


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
