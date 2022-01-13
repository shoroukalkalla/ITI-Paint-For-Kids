#ifndef ACTION_CHANGE_FILL_COLOR_H
#define ACTION_CHANGE_FILL_COLOR_H

#include "Action.h"

class ActionChangeFillColor : public Action
{
public:
	ActionChangeFillColor(ApplicationManager* pApp);

	virtual void Execute();

};

#endif