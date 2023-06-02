#pragma once
# include "Action.h" 
#include <cstdlib>
#include <time.h>

class ColorGame : public Action 
{
	int Correct ; 
	int False ; 
	int MaxTrFigCount ; 
	int Randoumint ; 
	CFigure * PickedOne ; 
	Point P ;
	bool valid ;
public : 
	ColorGame(ApplicationManager * ) ; 
	virtual void  ReadActionParameters() ; 
	virtual void  Execute (int input =1 ) ; 
	virtual ~ColorGame() {}
};