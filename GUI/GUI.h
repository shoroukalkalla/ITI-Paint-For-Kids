#ifndef GUI_H
#define GUI_H

#include "..\DEFS.h"
#include "UI_Info.h" 
#include "..\CMUgraphicsLib\CMUgraphics.h"


//This class is responsible for Grphical User Interface handling
//All user input and program outputs MUST be done through this class
//No other class is allowed to perform direct i/o
class GUI	
{
	//enum { ColorsCount = 4 };
private:
	//color colorPallete[ColorsCount] = { ROYALBLUE, MEDIUMSEAGREEN, INDIANRED, DARKCYAN }; // List of color pallete
	//CFigure* colorsSquars[ColorsCount];
	bool isChoosingOption = false;
public:	
	window* pWind;	//Pointer to the Graphics Window
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
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar

	void ClearStatusBar() const;	//Clears the status bar
	void CreateSelectedColorSquare() const;
	void ClearDrawArea() const;	//Clears the drawing area
	
	drawstyle GUI::setupStyle(GfxInfo RectGfxInfo, bool selected) const;
	// -- Figures Drawing functions
	void DrawSquare(Point P1, int length, GfxInfo RectGfxInfo, bool selected=false) const;  //Draw a Square
	
	///TODO: Make similar functions for drawing all other figures.
	void DrawEllipse(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const;
	void GUI::DrawHexagon(Point P1, Point P2, int radius, GfxInfo RectGfxInfo, bool selected) const;

	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;			//get current drwawing color
	void GUI::setCrntDrawColor(color c) const;
	color getCrntFillColor() const;			//get current filling color
	int getCrntPenWidth() const;			//get current pen width
};


#endif