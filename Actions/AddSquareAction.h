#ifndef ADD_SQUARE_ACTION_H
#define ADD_SQUARE_ACTION_H

#include "Action.h"

//Add Square Action class
class AddSquareAction: public Action
{
private:
	Point P1 ; 
	GfxInfo SquareGfxInfo;
public:
	AddSquareAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();

	virtual void Execute(int input = 1);
	virtual void Undo();
	virtual void Redo();
	virtual ~AddSquareAction(){}
};

#endif