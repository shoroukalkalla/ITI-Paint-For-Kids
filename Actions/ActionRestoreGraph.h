#ifndef ACTION_RESTORE_GRAPH_H
#define ACTION_RESTORE_GRAPH_H

#include "Action.h"

class ActionRestoreGraph : public Action
{
public:
	ActionRestoreGraph(ApplicationManager* pApp);

	virtual void Execute();
};

#endif



