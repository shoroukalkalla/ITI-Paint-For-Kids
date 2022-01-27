#ifndef ACTION_ADD_ELLIPSE_H
#define ACTION_ADD_ELLIPSE_H

#include "ActionAddFigure.h"
#include "..\GUI\GUI.h"


class ActionAddEllipse : public ActionAddFigure
{
public:
	ActionAddEllipse(ApplicationManager* pApp);

	virtual int GetMenuItemIndex();
	virtual void AddFigure();
	void CreateFigure(Point topLeft, Point bottomRight, GfxInfo SqrGfxInfo);
	void Load(ifstream& input);
};

#endif