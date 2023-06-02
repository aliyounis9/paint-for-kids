#pragma once
# include "Action.h" 
#include <cstdlib>
#include <time.h>

class FigureAndColorGame : public Action 
{
	int Correct ; 
	int False ; 
	int MaxTrFigCount ; 
	int Randoumint ; 
	CFigure * PickedOne ; 
	Point P ;
	bool valid ; 
public : 
	FigureAndColorGame (ApplicationManager * ) ; 
	virtual void  ReadActionParameters() ; 
	virtual void  Execute (int input =1 ) ; 
	virtual ~FigureAndColorGame() {}

};