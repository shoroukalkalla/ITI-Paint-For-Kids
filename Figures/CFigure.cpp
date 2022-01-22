#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;

	figHidden = false;		//17-1-2022
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

void CFigure::SetIsFilled(bool isFilled) {
	FigGfxInfo.isFilled = isFilled;

}

bool CFigure::IsFigFilled() 
{
	return FigGfxInfo.isFilled;
}

color CFigure::getFilledColor() {
	return FigGfxInfo.FillClr;
}

/////~

void CFigure::setStored()
{
	storedColorOfFill = FigGfxInfo.FillClr;
	storedColorOfDraw = FigGfxInfo.DrawClr;
	IsFilled = FigGfxInfo.isFilled;
}

void CFigure::assignStored()
{
	FigGfxInfo.isFilled = IsFilled;
	FigGfxInfo.FillClr = storedColorOfFill;
	FigGfxInfo.DrawClr = storedColorOfDraw;
}

void CFigure::SetGfxInfo(GfxInfo& PickFigureInfo)
{
	PickFigureInfo.isFilled = IsFilled;
	PickFigureInfo.FillClr = storedColorOfFill;
	PickFigureInfo.DrawClr = storedColorOfDraw;
}

//---------------------> for play mode		//17-1-2022

//Hides Figures
void CFigure::Hide()
{
	figHidden = true;
}
//Shows Figures
void CFigure::Show()
{
	figHidden = false;
}

//Gives Current Status
bool CFigure::HiddenStatus()
{
	return figHidden;
}
