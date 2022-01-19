#ifndef GUI_H
#define GUI_H

#include "..\DEFS.h"
#include "UI_Info.h" 
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "FigureDrawer.h"

class FigureDrawer;

//This class is responsible for Grphical User Interface handling
//All user input and program outputs MUST be done through this class
//No other class is allowed to perform direct I/O
class GUI
{
	//enum { ColorsCount = 4 };
private:
	int ColorsCount;
	color* ColorsPallete;

public:	
	window* pWind;	//Pointer to the Graphics Window
	FigureDrawer* figureDrawer;
	

public:
	GUI();	
	~GUI();	
	window* CreateWind(int, int, int , int) const; //creates the application window

	/////////// Input Functoinality  /////////////////
	void GetPointClicked(int &x, int &y) const;//Get coordinate where user clicks
	string GetSrting() const ;	 //Returns a string entered by the user
	ActionType MapInputToActionType() const; //Read the user click and map to an action
	ActionType MapInputInDrawMood(int x, int y) const;
	int getColorIndex(int x, int y) const;
	ActionType MapInputInPlayMood(int x, int y) const;

	/////////// Output Functoinality  ////////////////
	void CreateStatusBar() const;	//create the status bar
	void CreateDrawToolBar(int buttonIndex) const;	//creates Draw mode toolbar & menu
	void CreateColorsPallete() const; // Create a colors pallete
	void CreatePlayToolBar(int buttonIndex) const;	//creates Play mode toolbar & menu

	void CreateSelectedColorSquare() const;

	void ClearToolBar() const;      //clears the tool bar
	void ClearDrawArea() const;	//Clears the drawing area
	void ResetDrawingArea() const; // Clears the drawing area and draw any needed figres
	void ClearStatusBar() const;	//Clears the status bar

	void PrintMessage(string msg) const;	//Print a message on Status bar

	void HighlightButton(int buttonIndex);
	void RemoveButtonHighlight(int buttonIndex);

	void UpdateCrntDrawColor(int colorIndex) const;
	void UpdateCrntFillColor(int colorIndex) const;
	void UpdateCrntBkColor(int colorIndex) const;
	color getCrntDrawColor() const;			//get current drwawing color
	bool getCrntIsFilled() const;		// get current is filled 
	void setCrntBKColor(color c) const;	// Set window background color
	color getCrntBKColor() const;
	void setCrntDrawColor(color c) const;
	void setCrntFillColor(int colorIndex) const;
	color getCrntFillColor() const;			//get current filling color
	int getCrntPenWidth() const;			//get current pen width

	bool isInsideDrawingArea(int x, int y) const;
	bool isInsideDrawingArea(int* xs, int* ys, int count) const;
	void GUI::drawPoint(int x, int y) const;
};


#endif