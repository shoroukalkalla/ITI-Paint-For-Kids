#ifndef ACTION_ADD_ELLIPSE_H
#define ACTION_ADD_ELLIPSE_H

#include "Action.h"

//Add Ellipse Action class
class ActionAddEllipse : public Action
{
public:
	ActionAddEllipse(ApplicationManager* pApp);

	//Add Ellipse to the gApplicationManager
	virtual void Execute();

};

#endif