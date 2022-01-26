#ifndef ACTION_ADD_SQUARE_H
#define ACTION_ADD_SQUARE_H

#include "ActionAddFigure.h"
#include "..\GUI\GUI.h"


class ActionAddSquare : public ActionAddFigure
{
public:
	ActionAddSquare(ApplicationManager *pApp);
	
	virtual int GetMenuItemIndex();
	virtual void AddFigure() ;
	void CreateFigure(Point topLeft, int SideLength, GfxInfo SqrGfxInfo);
	void Load(ifstream& input);
};

#endif