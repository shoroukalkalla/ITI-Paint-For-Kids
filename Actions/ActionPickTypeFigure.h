#define ACTION_PICK_TYPE_FIGURE_H

#include "Action.h"
class ActionPickTypeFigure : public Action
{
public:
	ActionPickTypeFigure(ApplicationManager* pApp);

	virtual void Execute();
};
