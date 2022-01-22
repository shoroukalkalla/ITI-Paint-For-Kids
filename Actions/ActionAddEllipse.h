#ifndef ACTION_ADD_ELLIPSE_H
#define ACTION_ADD_ELLIPSE_H

#include "Action.h"
#include "..\GUI\GUI.h"


class ActionAddEllipse : public Action
{
	GUI* pGUI;
public:
	ActionAddEllipse(ApplicationManager* pApp);

	//Add Ellipse to the gApplicationManager
	virtual void Execute();
	void CreateFigure(Point topLeft, Point bottomRight, GfxInfo SqrGfxInfo);
	void Load(ifstream& input);
};

#endif