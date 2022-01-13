#include "GUI.h"

//constructor make necessary initializations
GUI::GUI()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1300;
	UI.height = 700;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 50;
	
	UI.DrawColor = ROYALBLUE;	//Drawing color
	UI.FillColor = MEDIUMSEAGREEN;	//Filling color
	UI.MsgColor = INDIANRED;		//Messages color
	UI.BkGrndColor = ALICEBLUE;	//Background color
	UI.HighlightColor = ORANGERED;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TAN;
	UI.PenWidth = 3;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	CreateDrawToolBar();
	CreateStatusBar();
	CreateSelectedColorSquare();
	
}


//======================================================================================//
//								Input Functions										    //
//======================================================================================//


void GUI::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string GUI::GetSrting() const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if(Key == 8 )	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label+= Key;
		PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType GUI::MapInputToActionType() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_CLR_BLUE: return SELECT_COLOR_BLUE;
			case ITM_CLR_CYAN: return SELECT_COLOR_CYAN;
			case ITM_CLR_GREEN: return SELECT_COLOR_GREEN;
			case ITM_CLR_RED: return SELECT_COLOR_RED;
			case ITM_SQUR: return DRAW_SQUARE;
			case ITM_ELPS: return DRAW_ELPS;
			case ITM_HEX: return DRAW_HEX;
			case ITM_SLCT: return SELECT;
			case ITM_EXIT: return EXIT;
			
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			// TODO: Select figure
			// Loop FigList from FigCount : 0
			return DRAWING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		return TO_PLAY;	//just for now. This should be updated
	}	

}
//======================================================================================//
//								Output Functions										//
//======================================================================================//

window* GUI::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
// ----- * ----- * ----- * ----- * ----- * ----- //
void GUI::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}

// ----- * ----- * ----- * ----- * ----- * ----- //

void GUI::CreateSelectedColorSquare() const
{
	pWind->SetPen(UI.DrawColor, 3);
	pWind->SetBrush(UI.FillColor);
	pWind->DrawRectangle(10, UI.StatusBarHeight + 10, 40, UI.StatusBarHeight + 40);
}

// ----- * ----- * ----- * ----- * ----- * ----- //
void GUI::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white Square
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
// ----- * ----- * ----- * ----- * ----- * ----- //
void GUI::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_CLR_BLUE] = "images\\MenuItems\\color_icon_blue.jpg";
	MenuItemImages[ITM_CLR_CYAN] = "images\\MenuItems\\color_icon_cyan.jpg";
	MenuItemImages[ITM_CLR_GREEN] = "images\\MenuItems\\color_icon_green.jpg";
	MenuItemImages[ITM_CLR_RED] = "images\\MenuItems\\color_icon_red.jpg";
	MenuItemImages[ITM_SQUR] = "images\\MenuItems\\square_icon.jpg";
	MenuItemImages[ITM_ELPS] = "images\\MenuItems\\ellipse_icon.jpg";
	MenuItemImages[ITM_HEX] = "images\\MenuItems\\hexagon_icon.jpg";
	MenuItemImages[ITM_SLCT] = "images\\MenuItems\\select_icon.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth,0,UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
// ----- * ----- * ----- * ----- * ----- * ----- //

void GUI::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	///TODO: write code to create Play mode menu
}
// ----- * ----- * ----- * ----- * ----- * ----- //

void GUI::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);	
	
}
// ----- * ----- * ----- * ----- * ----- * ----- //

void GUI::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
// ----- * ----- * ----- * ----- * ----- * ----- //

color GUI::getCrntDrawColor() const	//get current drwawing color
{	return UI.DrawColor;	}
// ----- * ----- * ----- * ----- * ----- * ----- //

void GUI::setCrntDrawColor(color c) const
{
	UI.DrawColor = c;
}

color GUI::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
// ----- * ----- * ----- * ----- * ----- * ----- //
	
int GUI::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}


//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

drawstyle GUI::setupStyle(GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width
	//pWind->SetBrush(RectGfxInfo.FillClr);

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;

	return style;
}

void GUI::DrawSquare(Point P1, int length, GfxInfo RectGfxInfo, bool selected) const
{
	drawstyle style = setupStyle(RectGfxInfo, selected);

	pWind->DrawRectangle(P1.x, P1.y, P1.x +length, P1.y+length, style);
	pWind->DrawLine(P1.x, P1.y, P1.x + length, P1.y + length, style);
}

void GUI::DrawEllipse(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	drawstyle style = setupStyle(RectGfxInfo, selected);


	pWind->DrawEllipse(P1.x, P1.y, P2.x, P2.y, style);
}

void GUI::DrawHexagon(Point P1, Point P2, int radius, GfxInfo RectGfxInfo, bool selected) const
{
	drawstyle style = setupStyle(RectGfxInfo, selected);

	// Center => (P1.x, P1.y)

	int ipX[6];
	int ipY[6];

	//ipX[0] = P1.x + radius;
	//ipY[0] = P1.y;
	//float angle = 0;

	// The first point => (P2.x, P2.y)
	ipX[0] = P2.x;
	ipY[0] = P2.y;
	float angle = atan2((float)P2.y - (float)P1.y, (float)P2.x - (float)P1.x);

	for (int i = 1; i < 6; i++) {
		angle += (3.14159265 / 3);

		ipX[i] = (float)P1.x + (radius * cos(angle));
		ipY[i] = (float)P1.y + (radius * sin(angle));
	}

	//for (int i = 0; i < 6; i++) {
	//	printf("\n(x%d, y%d) : (%d, %d)", i + 1, i + 1, ipX[i], ipY[i]);
	//}

	pWind->DrawPolygon(ipX, ipY, 6, style);
}

// ----- * ----- * ----- * ----- * ----- * ----- //
GUI::~GUI()
{
	delete pWind;
}

