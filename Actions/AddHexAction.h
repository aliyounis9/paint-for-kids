#pragma once 
#include"Action.h"

class AddHexAction : public Action
{
	Point P;
	GfxInfo HexGfxInfo;
public:
	AddHexAction(ApplicationManager*);
	virtual void ReadActionParameters();
	virtual void Execute(int input = 1);
	virtual void Undo();
	virtual void Redo();
	virtual ~AddHexAction(){}
};