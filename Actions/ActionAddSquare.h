#ifndef ACTION_ADD_SQUARE_H
#define ACTION_ADD_SQUARE_H

#include "Action.h"
#include "..\GUI\GUI.h"


class ActionAddSquare: public Action
{
	GUI* pGUI;
public:
	ActionAddSquare(ApplicationManager *pApp);
	
	//Add Square to the ApplicationManager
	virtual void Execute() ;
	void CreateFigure(Point topLeft, int SideLength, GfxInfo SqrGfxInfo);
	void Load(ifstream& input);
};

#endif