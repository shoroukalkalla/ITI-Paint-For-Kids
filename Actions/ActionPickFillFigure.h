#ifndef ACTION_PICK_FILL_FIGURE_H
#define ACTION_PICK_FILL_FIGURE_H


#include "Action.h"
#include "..\ApplicationManager.h"

class ActionPickFillFigure : public Action
{
	CFigure* Fig;
	CFigure* pickFigureInfo;
	Point p;
	
	int Result;
	void ReadActionParameters();
	
public:
	ActionPickFillFigure(ApplicationManager* pApp);
	void PrintGameMessg(int type, GUI* pGUI);
	bool IsEqualColor(color& a, color& b);
	int Random_Color(int&);



	virtual void Execute();

};

#endif

