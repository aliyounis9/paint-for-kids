#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_RECT,		//Draw Rectangle
	DRAW_SQUARE,
	DRAW_TRIANGLE,
	DRAW_POLY,
	DRAW_CIRCLE,
	SELECT,
	CHANGE_DRAWING_COLOR,
	CHANGE_FILL_COLOR,
	BLACK_ACT,
	RED_ACT,
	YELLOW_ACT,
	ORANGE_ACT,
	BLUE_ACT,
	GREEN_ACT,
	ICON_DELETE,
	MOVE,
	UNDO,
	REDO,
	CLEARALL,
	START,
	STOP,
	PLAY,
	SAVE,
	LOAD,
    TO_PLAY,
    EXIT,
	PLAY_MODE_COUNT,
	HIDE_FIGURETYPE_ACT,
	HIDE_FILLCOLOR_ACT,
	HIDE_BOTH_ACT,
	TO_DRAW,
	DRAW_MODE_COUNT,
	DRAWING_AREA,	//A click on the drawing area
	PLAYING_AREA,
	EMPTY,			//A click on empty place in the toolbar
	STATUS,			//A click on the status bar

	///TODO: Add the other action types of the two modes
};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders
};

#endif