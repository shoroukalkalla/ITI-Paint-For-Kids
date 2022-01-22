#ifndef ACTION_STORE_GRAPH_H
#define ACTION_STORE_GRAPH_H

#include "Action.h"

class ActionStoreGraph : public Action
{
public:
	ActionStoreGraph(ApplicationManager* pApp);

	virtual void Execute();
};

#endif

