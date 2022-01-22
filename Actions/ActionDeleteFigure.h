#ifndef ACTION_DELETE_FIGURE_H
#define ACTION_DELETE_FIGURE_H

#include "Action.h"
#include "../ApplicationManager.h"


class ActionDeleteFigure :public Action
{
public:
	ActionDeleteFigure(ApplicationManager* pApp);
	void Execute();
};

#endif