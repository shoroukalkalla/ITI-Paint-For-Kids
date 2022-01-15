#pragma once
#ifndef ACTION_CHANGE_BK_COLOR_H
#define ACTION_CHANGE_BK_COLOR_H

#include "Action.h"

//Add Ellipse Action class
class ActionChangeBKColor : public Action
{
public:
	ActionChangeBKColor(ApplicationManager* pApp);

	virtual void Execute();

};

#endif