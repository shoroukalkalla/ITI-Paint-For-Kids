#ifndef ACTION_ADD_FIGURE_H
#define ACTION_ADD_FIGURE_H

#include "Action.h"
#include "..\GUI\GUI.h"

class ActionAddFigure : public Action
{
protected:
	GUI* pGUI;
public:
	ActionAddFigure(ApplicationManager* pApp);

	void ReadPoint(int& x, int& y, string msg, bool highlight) const;
	void ActionAddFigure::InitGfxInfo(GfxInfo& gfxInfo) const;

	virtual void Execute();

	virtual int GetMenuItemIndex() = 0;
	virtual void AddFigure() = 0;
	virtual void Load(ifstream& input) = 0;
};

#endif

