#include "GUI.h"
#include "FigureDrawer.h"

//constructor make necessary initializations
GUI::GUI()
{
	//Initialize user interface parameters MODE_DRAW, MODE_PLAY
	UI.InterfaceMode = MODE_PLAY;
	
	UI.width = 1300;
	UI.height = 700;
	UI.wx = 5;
	UI.wy =5;

	UI.ToolBarHeight = 70;
	UI.MenuItemWidth = 70;
	UI.StatusBarHeight = 50;
	
	UI.DrawColor = ROYALBLUE;		//Drawing color
	UI.FillColor = MEDIUMSEAGREEN;	//Filling color
	UI.MsgColor = INDIANRED;		//Messages color
	UI.BkGrndColor = ALICEBLUE;		//Background color
	UI.HighlightColor = ORANGERED;	//This color should NOT be used to draw figures. use if for highlight only
	UI.PointColor = BROWN;		//The point where the user clicks to draw
	UI.StatusBarColor = TAN;
	UI.PenWidth = 3;	//width of the figures frames
	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	figureDrawer = new FigureDrawer(this);

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
	GetPointClicked(x, y);	//Get the coordinates of the user click

	if(UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		return MapInputInDrawMood(x, y);
	}
	else	//GUI is in PLAY mode
	{
		return MapInputInPlayMood(x, y);
	}	
}

ActionType GUI::MapInputInDrawMood(int x, int y) const
{
	//[1] If user clicks on the Toolbar
	if (y >= 0 && y < UI.ToolBarHeight)
	{
		//Check which Menu item was clicked
		//==> This assumes that menu items are lined up horizontally <==
		int ClickedItemOrder = (x / UI.MenuItemWidth);
		//Divide x coord of the point clicked by the menu item width (int division)
		//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

		if (isChoosingOption) {
			switch (ClickedItemOrder)
			{
				case OPTION_CLR_BLUE: return SELECT_COLOR_BLUE;
				case OPTION_CANCEL: return TO_DRAW;

				default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}
		else {
			switch (ClickedItemOrder)
			{
				case ITM_CLR_BLUE: return SELECT_COLOR_BLUE;
				case ITM_CLR_CYAN: return SELECT_COLOR_CYAN;
				case ITM_CLR_GREEN: return SELECT_COLOR_GREEN;
				case ITM_CLR_RED: return SELECT_COLOR_RED;
				//case CHNG_FILL_CLR: return CHNG_FILL_CLR;				// not created at enum
				case ITM_SQUR: return DRAW_SQUARE;
				case ITM_ELPS: return DRAW_ELPS;
				case ITM_HEX: return DRAW_HEX;
				case ITM_SLCT: return SELECT_FIGURE;
                
				case ITM_SWICH_PLAY: return TO_PLAY;

				case ITM_EXIT: return EXIT;

				default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

	}

	//[2] User clicks on the drawing area
	if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
	{
		// TODO: Select figure
		// Loop FigList from FigCount : 0
		return DRAWING_AREA;
	}

	//[3] User clicks on the status bar
	return STATUS;
}

ActionType GUI::MapInputInPlayMood(int x, int y) const
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
				
				case ITM_SWICH_DRAW: return TO_DRAW;
				case ITM_SELECT_TYPE: return TO_PICK_TYPE;
				case ITM_EXIT2: return EXIT;

				default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

	//[2] User clicks on the drawing area
	if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
	{
		// TODO: Select figure
		// Loop FigList from FigCount : 0
		return DRAWING_AREA;
	}

	//[3] User clicks on the status bar
	return STATUS;

		//return TO_PLAY;	//just for now. This should be updated
	}	


//======================================================================================//
//								Output Functions										//
//======================================================================================//

/* ----- * ----- * ----- * ----- * ----- * ----- * ----- * ----- *
 * -----> Create Tool bars and Drawing area
 * ----- * ----- * ----- * ----- * ----- * ----- * ----- * ----- */

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

void GUI::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	ClearToolBar();
	
	if (isChoosingOption) {
		string OptionsItemImages[OPTOINS_MENU_COUNT];
		OptionsItemImages[OPTION_CLR_BLUE] = "images\\MenuItems\\color_icon_blue.jpg";
		OptionsItemImages[OPTION_CANCEL] = "images\\MenuItems\\Menu_Exit.jpg";

		//Draw menu item one image at a time
		for (int i = 0; i < OPTOINS_MENU_COUNT; i++)
			pWind->DrawImage(OptionsItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	}
	else {
		string MenuItemImages[DRAW_ITM_COUNT];
		MenuItemImages[ITM_CLR_BLUE] = "images\\MenuItems\\color_icon_blue.jpg";
		MenuItemImages[ITM_CLR_CYAN] = "images\\MenuItems\\color_icon_cyan.jpg";
		MenuItemImages[ITM_CLR_GREEN] = "images\\MenuItems\\color_icon_green.jpg";
		MenuItemImages[ITM_CLR_RED] = "images\\MenuItems\\color_icon_red.jpg";
		MenuItemImages[ITM_SQUR] = "images\\MenuItems\\square_icon.jpg";
		MenuItemImages[ITM_ELPS] = "images\\MenuItems\\ellipse_icon.jpg";
		MenuItemImages[ITM_HEX] = "images\\MenuItems\\hexagon_icon.jpg";
		MenuItemImages[ITM_SLCT] = "images\\MenuItems\\select_icon.jpg";

		MenuItemImages[ITM_SWICH_PLAY] = "images\\MenuItems\\mood_play.jpg";

		MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

		//Draw menu item one image at a time
		for (int i = 0; i < DRAW_ITM_COUNT; i++)
			pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	}
	
	//Draw a line under the toolbar
	pWind->SetPen(DARKCYAN, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	
}

// ----- * ----- * ----- * ----- * ----- * ----- //

void GUI::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;

	ClearToolBar();

	string PlayItemImages[PLAY_ITM_COUNT];
	PlayItemImages[ITM_SWICH_DRAW] = "images\\MenuItems\\mood_draw.jpg";
	PlayItemImages[ITM_SELECT_TYPE] = "images\\MenuItems\\select_icon_02.jpg";
	PlayItemImages[ITM_EXIT2] = "images\\MenuItems\\Menu_Exit.jpg";

	//Draw menu item one image at a time
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
	pWind->DrawImage(PlayItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(CYAN, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}

// ----- * ----- * ----- * ----- * ----- * ----- //

void GUI::CreateSelectedColorSquare() const
{
	pWind->SetPen(UI.DrawColor, 3);
	pWind->SetBrush(UI.FillColor);
	pWind->DrawRectangle(10, UI.ToolBarHeight + 15, 40, UI.ToolBarHeight + 45);
}

// ----- * ----- * ----- * ----- * ----- * ----- //

void GUI::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.25), msg);
}

// ----- * ----- * ----- * ----- * ----- * ----- //

/* ----- * ----- * ----- * ----- * ----- * ----- * ----- * ----- *
 * -----> Clear Tool bars and Drawing area
 * ----- * ----- * ----- * ----- * ----- * ----- * ----- * ----- */

void GUI::ClearToolBar() const
{
	//Clear tool bar by drawing a filled Square
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}

// ----- * ----- * ----- * ----- * ----- * ----- //

void GUI::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}

void GUI::ResetDrawingArea() const
{
	ClearDrawArea();
	CreateSelectedColorSquare();
}

// ----- * ----- * ----- * ----- * ----- * ----- //

void GUI::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white Square
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}


/* ----- * ----- * ----- * ----- * ----- * ----- * ----- * ----- *
 * -----> Get and Set colors (drawing, filling)
 * ----- * ----- * ----- * ----- * ----- * ----- * ----- * ----- */

color GUI::getCrntDrawColor() const	//get current drwawing color
{	return UI.DrawColor;	}

void GUI::setCrntDrawColor(color c) const
{
	UI.DrawColor = c;
}

color GUI::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}

// ----- * ----- * ----- * ----- * ----- * ----- //
	
int GUI::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

// ----- * ----- * ----- * ----- * ----- * ----- //

// ----- * Check if a point of (x, y) is inside the drawing area * ----- //
bool GUI::isInsideDrawingArea(int x, int y) const
{
	return x > 0 && x < UI.width
		&& y > UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight;
}

// ----- * Draw a point where the user clicks to draw a figure * ----- //
void GUI::drawPoint(int x, int y) const
{
	pWind->SetPen(UI.PointColor, 2);
	pWind->SetBrush(UI.PointColor);
	pWind->DrawEllipse(x-7, y-7, x+7, y+7, FILLED);
}

// ----- * ----- * ----- * ----- * ----- * ----- //

GUI::~GUI()
{
	delete pWind;
}

