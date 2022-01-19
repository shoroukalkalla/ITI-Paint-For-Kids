#define ACTION_PICK_TYPE_FIGURE_H

#include "..\Figures\CFigure.h"
#include "Action.h"

class ActionPickTypeFigure : public Action
{
	CFigure* Fig;
	Point p;
	int  no_figs, rand_fig_no, picked_fig_no, wrongSelect, rightSelect;
	int figs[3];
	void calcScore(int);
	void ReadParameters();

public:
	ActionPickTypeFigure(ApplicationManager* pApp);

	virtual void Execute();

	~ActionPickTypeFigure();
};
