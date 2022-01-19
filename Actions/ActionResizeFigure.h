#ifndef ACTION_RESIZE_FIGURE_H
#define ACTION_RESIZE_FIGURE_H

#include "Action.h"

class ActionResizeFigure : public Action
{
private:
	float resizeFactor;
public:
	ActionResizeFigure(ApplicationManager* pApp, float);

	virtual void Execute();
};
#endif