#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\GUI.h"

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	
	/// Add more parameters if needed.

	///~
	color storedColorOfDraw, storedColorOfFill;
	bool IsFilled;

	// for play mode

	// for play mod
	bool figHidden;

public:
	CFigure(GfxInfo FigureGfxInfo);
	void SetSelected(bool );	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected

	virtual void DrawMe(GUI*) const  = 0 ;		//Draw the figure

	virtual bool isPointIn(int x, int y) const = 0;		//Check if the point within the figure boundaries
	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	void SetIsFilled(bool isFilled);

	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	//virtual void Rotate() = 0;	//Rotate the figure
	virtual bool Resize(float factor, GUI*) = 0;	//Resize the figure <---
	//virtual void Move() = 0;		//Move the figure

	virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	//virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar


	// for play mod
	void Hide();
	void Show();
	bool HiddenStatus();			//Shows Current Figure status in playmode.
	GfxInfo CFigure::GetGfxInfo();

	//
	void SetFigInfo();
	void setStored();
	void assignStored();
	void SetGfxInfo(GfxInfo&);
	bool IsFigFilled() ;
	color getFilledColor();


};

#endif