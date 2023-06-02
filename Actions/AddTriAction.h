#pragma once 
#include "Action.h"

class AddTriAction : public Action 
{
	Point p1,p2,p3 ;
	GfxInfo TriGfxInfo;
public :
	AddTriAction(ApplicationManager *);

	virtual void ReadActionParameters();

	virtual void Execute(int input = 1);
	virtual void Undo();
	virtual void Redo();
	virtual ~AddTriAction(){}
};