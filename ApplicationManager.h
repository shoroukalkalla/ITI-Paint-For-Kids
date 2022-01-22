#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"

class Action;	//Forward Declaration


//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	CFigure* SelectedFigure;		//Current selected figure

	//Pointers to Input and Output classes
	GUI* pGUI;
	

public:	
	ApplicationManager(); 
	~ApplicationManager();

	void Run();		//to run the application
	
	// -- Action-Related Functions
	Action* CreateAction(ActionType);
	void ExecuteAction(Action*&) ; //Execute an action
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig); //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y); //Search for a figure given a point inside the figure
	void ApplicationManager::SetSelectedFigure(CFigure* figure);
	CFigure* ApplicationManager::GetSelectedFigure();

	void DeleteSelectedFigures();
	void ClearAllFigures();

	void StoreGraphData(ofstream& OutFile);

	int ApplicationManager::GetSelectedIndexFigure();
	void ApplicationManager::BringToFront(int selectedIndex);
	void ApplicationManager::SendToBack(int selectedIndex);

	////////////////////////////////////////////////////////////////////////////////////

	int getFigCount() const;							// get figure count  //17-1-2022
	CFigure* ApplicationManager::DrawnFigs(int i) const; // draw figure

	void Loop(CFigure* deleted);


	////////////////////////////////////////////////////////////////////////////////////

	// -- Interface Management Functions	
	GUI *GetGUI() const; //Return pointer to the interface
	void UpdateInterface() const;	//Redraws all the drawing window	
};

#endif