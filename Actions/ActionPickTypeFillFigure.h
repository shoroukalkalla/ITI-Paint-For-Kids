#define ACTION_PICK_TYPE_FILL_FIGURE_H

#include "..\Figures\CFigure.h"
#include "Action.h"

class ActionPickTypeFillFigure : public Action
{

public:
	ActionPickTypeFillFigure(ApplicationManager* pApp);

	virtual void Execute();

	~ActionPickTypeFillFigure();
};


