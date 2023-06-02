#pragma once 
#include"Action.h"

class RedoAction : public Action {
private:
	int NextOperation;
public:
	RedoAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(int input = 1);
	virtual ~RedoAction() {}
};
