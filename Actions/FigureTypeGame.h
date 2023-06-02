#pragma once
#include"Action.h" 
#include <cstdlib>
#include <time.h>


class FigureTypeGame :public Action 
{
	int Correct ; 
	int False ; 
	int randomint ; 
	int MaxTrFigCount ; 
	Point P ;
	CFigure * PickedOne ; 
public:
	FigureTypeGame (ApplicationManager * pApp ); 
	virtual void ReadActionParameters();
	virtual void Execute(int input =1) ;
	virtual ~FigureTypeGame() {}
};
