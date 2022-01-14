#ifndef ACTION_SELECT_FIGURE
#define ACTION_SELECT_FIGURE

#include "Action.h"
#include "../Figures/CFigure.h"

//Add Square Action class
class ActionSelectFigure : public Action
{
public:
	ActionSelectFigure(ApplicationManager* pApp);

	//Add Square to the ApplicationManager
	virtual void Execute();

	void DeselectFigure(CFigure* lastSelected) const;
};

#endif
