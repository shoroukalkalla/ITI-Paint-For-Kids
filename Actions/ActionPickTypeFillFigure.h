#define ACTION_PICK_TYPE_FILL_FIGURE_H

#include "..\Figures\CFigure.h"
#include "Action.h"
#include "..\ApplicationManager.h"

class ActionPickTypeFillFigure : public Action
{
	CFigure* Fig;
	CFigure* pickFigureInfo;
	CFigure* clickedFig;
	color clickedFigColor;
	color c;
	Point p;
	int  rand_fig_no = 0, picked_fig_no = 0, wrongSelect = 0, rightSelect = 0, numOfFig = 0;
	int combinations[33];
	void randomShape(color&);
	void showShapes();
	void match(int&, color);
	void hideshape();
	void messagePrint(bool);
	bool IsEqualColor(color& a, color& b);
	void ReadActionParameters();

public:
	ActionPickTypeFillFigure(ApplicationManager* pApp);

	virtual void Execute();
};


