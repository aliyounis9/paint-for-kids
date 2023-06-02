#pragma once 
#include "Action.h" 

class AddCircleAction : public Action 
{
	Point p1, p2 ; 
	GfxInfo CircleGfxInfo ; 
	float radius; 
public : 
	AddCircleAction(ApplicationManager * pApp) ; 
	virtual void ReadActionParameters(); 
	virtual void Execute(int input = true);
	virtual void Undo();
	virtual void Redo();
	virtual ~AddCircleAction(){}
};