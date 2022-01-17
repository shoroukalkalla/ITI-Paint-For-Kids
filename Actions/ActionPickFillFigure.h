#define ACTION_PICK_FILL_FIGURE_H

#include "..\Figures\CFigure.h"
#include "Action.h"

class ActionPickFillFigure : public Action
{

public:
	ActionPickFillFigure(ApplicationManager* pApp);

	virtual void Execute();

	~ActionPickFillFigure();
};

