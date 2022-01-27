#include "ActionPickTypeFillFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include "..\Figures\CEllipse.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CFigure.h"


ActionPickTypeFillFigure::ActionPickTypeFillFigure(ApplicationManager* pApp) :Action(pApp)
{
	for (int i = 0; i < 33; i++)
	{
		combinations[i] = 0;
	}
}
void ActionPickTypeFillFigure::messagePrint(bool message)
{
	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();

	//
	string score;
	if (!message) score = "Wrong!, Your score is: " + to_string(rightSelect) + " Right, and " + to_string(wrongSelect) + " Wrong.";
	if (message) score = "Right!, Your score is: " + to_string(rightSelect) + " Right, and " + to_string(wrongSelect) + " Wrong.";
	pGUI->PrintMessage(score);


}
void ActionPickTypeFillFigure::ReadActionParameters()
{
    GUI* pGUI = pManager->GetGUI();
    for (int i = 0; i < pManager->getFigCount(); i++) {
        Fig = pManager->DrawnFigs(i);
        if (Fig->IsFigFilled()) //counts combinations occurance.
        {

            if (IsEqualColor(Fig->getFilledColor(), pGUI->getColorFromPallet(1)))
            {
                if (dynamic_cast<CSquare*>(Fig))
                    combinations[0]++;
                else if (dynamic_cast<CHexagon*>(Fig))
                    combinations[1]++;
                else
                    combinations[2]++;
            }
            else if (IsEqualColor(Fig->getFilledColor(), pGUI->getColorFromPallet(2)))
            {
                if (dynamic_cast<CSquare*>(Fig))
                    combinations[3]++;
                else if (dynamic_cast<CHexagon*>(Fig))
                    combinations[4]++;
                else
                    combinations[5]++;
            }
            else if (IsEqualColor(Fig->getFilledColor(), pGUI->getColorFromPallet(3)))
            {
                if (dynamic_cast<CSquare*>(Fig))
                    combinations[6]++;
                else if (dynamic_cast<CHexagon*>(Fig))
                    combinations[7]++;
                else
                    combinations[8]++;
            }
            else if (IsEqualColor(Fig->getFilledColor(), pGUI->getColorFromPallet(4)))
            {
                if (dynamic_cast<CSquare*>(Fig))
                    combinations[9]++;
                else if (dynamic_cast<CHexagon*>(Fig))
                    combinations[10]++;
                else
                    combinations[11]++;
            }
            else if (IsEqualColor(Fig->getFilledColor(), pGUI->getColorFromPallet(5)))
            {
                if (dynamic_cast<CSquare*>(Fig))
                    combinations[12]++;
                else if (dynamic_cast<CHexagon*>(Fig))
                    combinations[13]++;
                else
                    combinations[14]++;
            }
            else if (IsEqualColor(Fig->getFilledColor(), pGUI->getColorFromPallet(6)))
            {
                if (dynamic_cast<CSquare*>(Fig))
                    combinations[15]++;
                else if (dynamic_cast<CHexagon*>(Fig))
                    combinations[16]++;
                else
                    combinations[17]++;
            }
            else if (IsEqualColor(Fig->getFilledColor(), pGUI->getColorFromPallet(7)))
            {
                if (dynamic_cast<CSquare*>(Fig))
                    combinations[18]++;
                else if (dynamic_cast<CHexagon*>(Fig))
                    combinations[19]++;
                else
                    combinations[20]++;
            }
            else if (IsEqualColor(Fig->getFilledColor(), pGUI->getColorFromPallet(8)))
            {
                if (dynamic_cast<CSquare*>(Fig))
                    combinations[21]++;
                else if (dynamic_cast<CHexagon*>(Fig))
                    combinations[22]++;
                else
                    combinations[23]++;
            }
            else if (IsEqualColor(Fig->getFilledColor(), pGUI->getColorFromPallet(9)))
            {
                if (dynamic_cast<CSquare*>(Fig))
                    combinations[24]++;
                else if (dynamic_cast<CHexagon*>(Fig))
                    combinations[25]++;
                else
                    combinations[26]++;
            }
            else if (IsEqualColor(Fig->getFilledColor(), pGUI->getColorFromPallet(10)))
            {
                if (dynamic_cast<CSquare*>(Fig))
                    combinations[27]++;
                else if (dynamic_cast<CHexagon*>(Fig))
                    combinations[28]++;
                else
                    combinations[29]++;
            }
            else if (IsEqualColor(Fig->getFilledColor(), pGUI->getColorFromPallet(11)))
            {
                if (dynamic_cast<CSquare*>(Fig))
                    combinations[30]++;
                else if (dynamic_cast<CHexagon*>(Fig))
                    combinations[31]++;
                else
                    combinations[32]++;
            }
        }
    }
}
void ActionPickTypeFillFigure::randomShape(color& c)
{
    GUI* pGUI = pManager->GetGUI();
    numOfFig = pManager->getFigCount();
    int figureFillCount = pManager->GetFilledFigCount();
    if (numOfFig > 0 && figureFillCount >= 2)
    {
        rand_fig_no = rand() % figureFillCount;
        pickFigureInfo = pManager->DrawnFigs(rand_fig_no);
        c = pickFigureInfo->getFilledColor();
        if (IsEqualColor(c, pGUI->getColorFromPallet(1)))
        {
            if (dynamic_cast<CSquare*>(pickFigureInfo))
            {
                picked_fig_no = combinations[0];
                pGUI->PrintMessage("Pick all Blue square !");
            }
            else if (dynamic_cast<CHexagon*>(pickFigureInfo))
            {
                picked_fig_no = combinations[1];
                pGUI->PrintMessage("Pick all Blue Hexagon !");
            }
            else
            {
                picked_fig_no = combinations[2];
                pGUI->PrintMessage("Pick all Blue ellipse !");
            }
        }
        else if (IsEqualColor(c, pGUI->getColorFromPallet(2)))
        {
            if (dynamic_cast<CSquare*>(pickFigureInfo))
            {
                picked_fig_no = combinations[3];
                pGUI->PrintMessage("Pick all SkyBlue square!");
            }
            else if (dynamic_cast<CHexagon*>(pickFigureInfo))
            {
                picked_fig_no = combinations[4];
                pGUI->PrintMessage("Pick all SkyBlue hexagon!");
            }
            else
            {
                picked_fig_no = combinations[5];
                pGUI->PrintMessage("Pick all SkyBlue ellipse !");
            }
        }
        else if (IsEqualColor(c, pGUI->getColorFromPallet(3)))
        {
            if (dynamic_cast<CSquare*>(pickFigureInfo))
            {
                picked_fig_no = combinations[6];
                pGUI->PrintMessage("Pick all Green square !");
            }
            else if (dynamic_cast<CHexagon*>(pickFigureInfo))
            {
                picked_fig_no = combinations[7];
                pGUI->PrintMessage("Pick all Green hexagon !");
            }
            else
            {
                picked_fig_no = combinations[8];
                pGUI->PrintMessage("Pick all Green ellipse !");
            }
        }
        else if (IsEqualColor(c, pGUI->getColorFromPallet(4)))
        {
            if (dynamic_cast<CSquare*>(pickFigureInfo))
            {
                picked_fig_no = combinations[9];
                pGUI->PrintMessage("Pick all DarkBlue square !");
            }
            else if (dynamic_cast<CHexagon*>(pickFigureInfo))
            {
                picked_fig_no = combinations[10];
                pGUI->PrintMessage("Pick all DarkBlue hexagon !");
            }
            else
            {
                picked_fig_no = combinations[11];
                pGUI->PrintMessage("Pick all DarkBlue ellipse !");
            }
        }
        else if (IsEqualColor(c, pGUI->getColorFromPallet(5)))
        {
            if (dynamic_cast<CSquare*>(pickFigureInfo))
            {
                picked_fig_no = combinations[12];
                pGUI->PrintMessage("Pick all Red square !");
            }
            else if (dynamic_cast<CHexagon*>(pickFigureInfo))
            {
                picked_fig_no = combinations[13];
                pGUI->PrintMessage("Pick all Red hexagon !");
            }
            else
            {
                picked_fig_no = combinations[14];
                pGUI->PrintMessage("Pick all Red ellipse !");
            }
        }
        else if (IsEqualColor(c, pGUI->getColorFromPallet(6)))
        {
            if (dynamic_cast<CSquare*>(pickFigureInfo))
            {
                picked_fig_no = combinations[15];
                pGUI->PrintMessage("Pick all SandyBrown square!");
            }
            else if (dynamic_cast<CHexagon*>(pickFigureInfo))
            {
                picked_fig_no = combinations[16];
                pGUI->PrintMessage("Pick all SandyBrown hexagon!");
            }
            else
            {
                picked_fig_no = combinations[17];
                pGUI->PrintMessage("Pick all SandyBrown ellipse!");
            }
        }
        else if (IsEqualColor(c, pGUI->getColorFromPallet(7)))
        {
            if (dynamic_cast<CSquare*>(pickFigureInfo))
            {
                picked_fig_no = combinations[18];
                pGUI->PrintMessage("Pick all Brown square !");
            }
            else if (dynamic_cast<CHexagon*>(pickFigureInfo))
            {
                picked_fig_no = combinations[19];
                pGUI->PrintMessage("Pick all Brown hexagon !");
            }
            else
            {
                picked_fig_no = combinations[20];
                pGUI->PrintMessage("Pick all Brown ellipse !");
            }
        }
        else if (IsEqualColor(c, pGUI->getColorFromPallet(8)))
        {
            if (dynamic_cast<CSquare*>(pickFigureInfo))
            {
                picked_fig_no = combinations[21];
                pGUI->PrintMessage("Pick all Orange square !");
            }
            else if (dynamic_cast<CHexagon*>(pickFigureInfo))
            {
                picked_fig_no = combinations[22];
                pGUI->PrintMessage("Pick all Orange hexagon !");
            }
            else
            {
                picked_fig_no = combinations[23];
                pGUI->PrintMessage("Pick all Orange ellipse !");
            }
        }
        else if (IsEqualColor(c, pGUI->getColorFromPallet(9)))
        {
            if (dynamic_cast<CSquare*>(pickFigureInfo))
            {
                picked_fig_no = combinations[24];
                pGUI->PrintMessage("Pick all Violet square !");
            }
            else if (dynamic_cast<CHexagon*>(pickFigureInfo))
            {
                picked_fig_no = combinations[25];
                pGUI->PrintMessage("Pick all Violet hexagon !");
            }
            else
            {
                picked_fig_no = combinations[26];
                pGUI->PrintMessage("Pick all Violet ellipse !");
            }
        }
        else if (IsEqualColor(c, pGUI->getColorFromPallet(10)))
        {
            if (dynamic_cast<CSquare*>(pickFigureInfo))
            {
                picked_fig_no = combinations[27];
                pGUI->PrintMessage("Pick all Cyan square !");
            }
            else if (dynamic_cast<CHexagon*>(pickFigureInfo))
            {
                picked_fig_no = combinations[28];
                pGUI->PrintMessage("Pick all Cyan hexagon !");
            }
            else
            {
                picked_fig_no = combinations[29];
                pGUI->PrintMessage("Pick all Cyan ellipse !");
            }
        }
        else if (IsEqualColor(c, pGUI->getColorFromPallet(11)))
        {
            if (dynamic_cast<CSquare*>(pickFigureInfo))
            {
                picked_fig_no = combinations[30];
                pGUI->PrintMessage("Pick all YELLOWGREEN square !");
            }
            else if (dynamic_cast<CHexagon*>(pickFigureInfo))
            {
                picked_fig_no = combinations[31];
                pGUI->PrintMessage("Pick all YELLOWGREEN hexagon !");
            }
            else
            {
                picked_fig_no = combinations[32];
                pGUI->PrintMessage("Pick all YELLOWGREEN ellipse !");
            }
        }
    }
    else
    {
        pGUI->PrintMessage("You must have at least two filled  types of figures to play ! ");
    }

}
bool ActionPickTypeFillFigure::IsEqualColor(color& a, color& b) {


    return a.ucRed == b.ucRed && a.ucBlue == b.ucBlue && a.ucGreen == b.ucGreen;
}
void ActionPickTypeFillFigure::match(int& randomShapeCount, color Color)
{
    GUI* pGUI = pManager->GetGUI();
    while (randomShapeCount > 0)
    {
        pGUI->GetPointClicked(p.x, p.y);
        if (p.y > UI.ToolBarHeight || p.x > (UI.MenuItemWidth * PLAY_ITM_COUNT))
        {
            clickedFig = pManager->GetFigure(p.x, p.y);
            if (!clickedFig) {
                pGUI->PrintMessage(" game aborted.");
                return;
            }
            clickedFigColor = clickedFig->getFilledColor();
            if ((dynamic_cast<CSquare*>(clickedFig)) && (dynamic_cast<CSquare*>(pickFigureInfo)) && IsEqualColor(clickedFigColor, Color))
            {
                rightSelect++;
                messagePrint(true);
                hideshape();
                randomShapeCount--;
            }
            else if ((dynamic_cast<CEllipse*>(clickedFig)) && (dynamic_cast<CEllipse*>(pickFigureInfo)) && IsEqualColor(clickedFigColor, Color))
            {
                rightSelect++;
                messagePrint(true);
                hideshape();
                randomShapeCount--;
            }
            else if ((dynamic_cast<CHexagon*>(clickedFig)) && (dynamic_cast<CHexagon*>(pickFigureInfo)) && IsEqualColor(clickedFigColor, Color))
            {
                rightSelect++;
                messagePrint(true);
                hideshape();
                randomShapeCount--;
            }
            else
            {
                wrongSelect++;
                messagePrint(false);
                hideshape();
            }

            if (randomShapeCount == 0) {
                string Message;
                if (rightSelect > wrongSelect)
                {
                    Message = "Well done You win!, Your score is : " + to_string(rightSelect) + " Right, and : " + to_string(wrongSelect) + " Wrong.";
                }
                else if (rightSelect == wrongSelect)
                {
                    Message = "Try again it's Draw!, Your score is : " + to_string(rightSelect) + " Right, and : " + to_string(wrongSelect) + " Wrong.";
                }
                else
                {
                    Message = "Hard Luke you lose !, Your score is : " + to_string(rightSelect) + " Right, and : " + to_string(wrongSelect) + " Wrong.";
                }

                pGUI->PrintMessage(Message);
            }
        }
    }
}
void ActionPickTypeFillFigure::hideshape()
{
    clickedFig->Hide();
    pManager->UpdateInterface();

}
void ActionPickTypeFillFigure::showShapes()
{
    for (int i = 0; i < pManager->getFigCount(); i++) {
        pManager->DrawnFigs(i)->Show();
    }
    pManager->UpdateInterface();
}

//Execute the action
void ActionPickTypeFillFigure::Execute()
{
	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();

    pGUI->HighlightButton(ITM_SELECT_TYPE_FILL);

	pGUI->ClearStatusBar();
	ReadActionParameters();
	randomShape(c);
	match(picked_fig_no, c);
	showShapes();

    pGUI->RemoveButtonHighlight(ITM_SELECT_TYPE_FILL);

}
