#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY	//Playing mode
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	//ITM_CLR_BLUE,		//Select Blue Color in the menu
	//ITM_CLR_CYAN,		//Select Cyan Color in the menu
	//ITM_CLR_GREEN,		//Select Green Color in the menu
	//ITM_CLR_RED,		//Select Red Color in the menu

	ITM_SQUR,		//Square item in menu
	ITM_ELPS,		//Ellipse item in menu
	ITM_HEX,		//Hexagon item in menu

	ITM_SLCT,		// Select Figure item in menu
	ITM_DRAW_CLR,		// Select Draw color in the menu.
	ITM_FILL_CLR,		//Select Fill Color in the menu,
	ITM_BK_CLR,			//Select window background Color in the menu,
	ITM_SEND_TO_BACK,
	ITM_BRNG_FRNT,

	ITM_RESIZE_QUARTER,		// Decrease the figrue size 4 times
	ITM_RESIZE_HALF,		// Decrease the figrue size 2 times
	ITM_RESIZE_DOUBLE,		// Increase the figrue size 2 times
	ITM_RESIZE_QUADRUPLE,	// Increase the figrue size 4 times

	// icon to swtich between draw mode and play mode
	ITM_SWICH_PLAY,	   // switch item in menu

	ITM_EXIT,		//Exit item,
	
	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
};

enum ColorsPalleteItem {
	COLOR_ROYALBLUE,
	COLOR_CADETBLUE,
	COLOR_LIGHTSEAGREEN,
	COLOR_LIGHTYELLOW,
	COLOR_INDIAN,
	COLOR_SANDYBROWN,
	COLOR_SALMON,
	COLOR_ORANGERED,
	COLOR_PALEVIOLETRED,
	COLOR_DARKCYAN
};

enum OptionsMenuItem {
	OPTION_CLR_BLUE,
	OPTION_CANCEL,
	OPTOINS_MENU_COUNT
};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	// icon to swtich between draw mode and play mode
	ITM_SWICH_DRAW,	   // switch item in menu
	ITM_SELECT_TYPE,   // to selecte figure
	ITM_EXIT2,		   //Exit item

	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
};





__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	
	int	width, height,	//Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		ColorsPalleteSize,
		MenuItemWidth;		//Width of each item in toolbar menu
	
	POINT DrawingAreaTL;	// The top left point of drawing area
	POINT DrawingAreaBR;	// The bottom right point of drawing area

	color SelectedColor;	//Current Selected Color
	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color PointColor;		//The point where the user clicks to draw
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed
	bool isFilled;
	
}UI;	//create a global object UI

#endif