#include "ActionPickTypeFillFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include "..\Figures\CEllipse.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CFigure.h"


ActionPickTypeFillFigure::ActionPickTypeFillFigure(ApplicationManager* pApp) :Action(pApp)
{
	for (int i = 0; i < 36; i++)
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

void ActionPickTypeFillFigure::GetFilledTypeShape()
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
        else
        {
            if (dynamic_cast<CSquare*>(Fig))
                combinations[33]++;
            else if (dynamic_cast<CHexagon*>(Fig))
                combinations[34]++;
            else
                combinations[35]++;
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
                pGUI->PrintMessage("Pick all ROYALBLUE square !");
            }
            else if (dynamic_cast<CHexagon*>(pickFigureInfo))
            {
                picked_fig_no = combinations[1];
                pGUI->PrintMessage("Pick all ROYALBLUE Hexagon !");
            }
            else
            {
                picked_fig_no = combinations[2];
                pGUI->PrintMessage("Pick all ROYALBLUE ellipse !");
            }
        }
        else if (IsEqualColor(c, pGUI->getColorFromPallet(2)))
        {
            if (dynamic_cast<CSquare*>(pickFigureInfo))
            {
                picked_fig_no = combinations[3];
                pGUI->PrintMessage("Pick all CADETBLUE square!");
            }
            else if (dynamic_cast<CHexagon*>(pickFigureInfo))
            {
                picked_fig_no = combinations[4];
                pGUI->PrintMessage("Pick all CADETBLUE hexagon!");
            }
            else
            {
                picked_fig_no = combinations[5];
                pGUI->PrintMessage("Pick all CADETBLUE ellipse !");
            }
        }
        else if (IsEqualColor(c, pGUI->getColorFromPallet(3)))
        {
            if (dynamic_cast<CSquare*>(pickFigureInfo))
            {
                picked_fig_no = combinations[6];
                pGUI->PrintMessage("Pick all LIGHTSEAGREEN square !");
            }
            else if (dynamic_cast<CHexagon*>(pickFigureInfo))
            {
                picked_fig_no = combinations[7];
                pGUI->PrintMessage("Pick all LIGHTSEAGREEN hexagon !");
            }
            else
            {
                picked_fig_no = combinations[8];
                pGUI->PrintMessage("Pick all LIGHTSEAGREEN ellipse !");
            }
        }
        else if (IsEqualColor(c, pGUI->getColorFromPallet(4)))
        {
            if (dynamic_cast<CSquare*>(pickFigureInfo))
            {
                picked_fig_no = combinations[9];
                pGUI->PrintMessage("Pick all MEDIUMBLUE square !");
            }
            else if (dynamic_cast<CHexagon*>(pickFigureInfo))
            {
                picked_fig_no = combinations[10];
                pGUI->PrintMessage("Pick all MEDIUMBLUE hexagon !");
            }
            else
            {
                picked_fig_no = combinations[11];
                pGUI->PrintMessage("Pick all MEDIUMBLUE ellipse !");
            }
        }
        else if (IsEqualColor(c, pGUI->getColorFromPallet(5)))
        {
            if (dynamic_cast<CSquare*>(pickFigureInfo))
            {
                picked_fig_no = combinations[12];
                pGUI->PrintMessage("Pick all INDIAN square !");
            }
            else if (dynamic_cast<CHexagon*>(pickFigureInfo))
            {
                picked_fig_no = combinations[13];
                pGUI->PrintMessage("Pick all INDIAN hexagon !");
            }
            else
            {
                picked_fig_no = combinations[14];
                pGUI->PrintMessage("Pick all INDIAN ellipse !");
            }
        }
        else if (IsEqualColor(c, pGUI->getColorFromPallet(6)))
        {
            if (dynamic_cast<CSquare*>(pickFigureInfo))
            {
                picked_fig_no = combinations[15];
                pGUI->PrintMessage("Pick all SANDYBROWN square!");
            }
            else if (dynamic_cast<CHexagon*>(pickFigureInfo))
            {
                picked_fig_no = combinations[16];
                pGUI->PrintMessage("Pick all SANDYBROWN hexagon!");
            }
            else
            {
                picked_fig_no = combinations[17];
                pGUI->PrintMessage("Pick all SANDYBROWN ellipse!");
            }
        }
        else if (IsEqualColor(c, pGUI->getColorFromPallet(7)))
        {
            if (dynamic_cast<CSquare*>(pickFigureInfo))
            {
                picked_fig_no = combinations[18];
                pGUI->PrintMessage("Pick all SALMON square !");
            }
            else if (dynamic_cast<CHexagon*>(pickFigureInfo))
            {
                picked_fig_no = combinations[19];
                pGUI->PrintMessage("Pick all SALMON hexagon !");
            }
            else
            {
                picked_fig_no = combinations[20];
                pGUI->PrintMessage("Pick all SALMON ellipse !");
            }
        }
        else if (IsEqualColor(c, pGUI->getColorFromPallet(8)))
        {
            if (dynamic_cast<CSquare*>(pickFigureInfo))
            {
                picked_fig_no = combinations[21];
                pGUI->PrintMessage("Pick all ORANGERED square !");
            }
            else if (dynamic_cast<CHexagon*>(pickFigureInfo))
            {
                picked_fig_no = combinations[22];
                pGUI->PrintMessage("Pick all ORANGERED hexagon !");
            }
            else
            {
                picked_fig_no = combinations[23];
                pGUI->PrintMessage("Pick all ORANGERED ellipse !");
            }
        }
        else if (IsEqualColor(c, pGUI->getColorFromPallet(9)))
        {
            if (dynamic_cast<CSquare*>(pickFigureInfo))
            {
                picked_fig_no = combinations[24];
                pGUI->PrintMessage("Pick all PALEVIOLETRED square !");
            }
            else if (dynamic_cast<CHexagon*>(pickFigureInfo))
            {
                picked_fig_no = combinations[25];
                pGUI->PrintMessage("Pick all PALEVIOLETRED hexagon !");
            }
            else
            {
                picked_fig_no = combinations[26];
                pGUI->PrintMessage("Pick all PALEVIOLETRED ellipse !");
            }
        }
        else if (IsEqualColor(c, pGUI->getColorFromPallet(10)))
        {
            if (dynamic_cast<CSquare*>(pickFigureInfo))
            {
                picked_fig_no = combinations[27];
                pGUI->PrintMessage("Pick all DARKCYAN square !");
            }
            else if (dynamic_cast<CHexagon*>(pickFigureInfo))
            {
                picked_fig_no = combinations[28];
                pGUI->PrintMessage("Pick all DARKCYAN hexagon !");
            }
            else
            {
                picked_fig_no = combinations[29];
                pGUI->PrintMessage("Pick all DARKCYAN ellipse !");
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
        else
        {
            if (dynamic_cast<CSquare*>(pickFigureInfo))
            {
                picked_fig_no = combinations[33];
                pGUI->PrintMessage("Pick all UNFILLED square !");
            }
            else if (dynamic_cast<CHexagon*>(pickFigureInfo))
            {
                picked_fig_no = combinations[34];
                pGUI->PrintMessage("Pick all UNFILLED hexagon !");
            }
            else
            {
                picked_fig_no = combinations[35];
                pGUI->PrintMessage("Pick all UNFILLED ellipse !");
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

    pGUI->HighlightButton(ITM_SELECT_TYPE_FILL);

    while (randomShapeCount > 0)
    {
        pGUI->GetPointClicked(p.x, p.y);

        clickedFig = pManager->GetFigure(p.x, p.y);
        if (clickedFig == NULL) {
            pGUI->ClearStatusBar();  
            showShapes();
            pGUI->RemoveButtonHighlight(ITM_SELECT_TYPE_FILL);
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
                else if (rightSelect == wrongSelect && rightSelect != 0)
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

    
    pGUI->RemoveButtonHighlight(ITM_SELECT_TYPE_FILL);
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
    GetFilledTypeShape();
	randomShape(c);
	match(picked_fig_no, c);
	showShapes();

    pGUI->RemoveButtonHighlight(ITM_SELECT_TYPE_FILL);

}
