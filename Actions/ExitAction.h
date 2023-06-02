#pragma once 
#include"Action.h"
#include "..\Figures\CFigure.h"

class ExitAction : public Action {
public:
	ExitAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(int input = 1);
	virtual ~ExitAction() {}
};
