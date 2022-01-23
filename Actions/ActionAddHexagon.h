#ifndef ACTION_ADD_HEXAGON_H
#define ACTION_ADD_HEXAGON_H

#include "ActionAddFigure.h"
#include "..\GUI\GUI.h"


class ActionAddHexagon : public ActionAddFigure
{
public:
	ActionAddHexagon(ApplicationManager* pApp);

	virtual int GetMenuItemIndex();
	virtual void AddFigure();
	void CreateFigure(Point Center, float Rotation, int Radius, GfxInfo SqrGfxInfo);
	void Load(ifstream& input);
};

#endif