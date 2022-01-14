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
	//color colorPallete[ColorsCount] = { ROYALBLUE, MEDIUMSEAGREEN, INDIANRED, DARKCYAN }; // List of color pallete
	//CFigure* colorsSquars[ColorsCount];
	bool isChoosingOption = false; // ??
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
	ActionType MapInputInPlayMood(int x, int y) const;

	/////////// Output Functoinality  ////////////////
	void CreateStatusBar() const;	//create the status bar
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu

	void CreateSelectedColorSquare() const;

	void ClearToolBar() const;      //clears the tool bar
	void ClearDrawArea() const;	//Clears the drawing area
	void ResetDrawingArea() const; // Clears the drawing area and draw any needed figres
	void ClearStatusBar() const;	//Clears the status bar
	
	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;			//get current drwawing color
	void GUI::setCrntDrawColor(color c) const;
	color getCrntFillColor() const;			//get current filling color
	int getCrntPenWidth() const;			//get current pen width

	bool isInsideDrawingArea(int x, int y) const;
	void GUI::drawPoint(int x, int y) const;
};


#endif