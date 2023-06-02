#pragma once 
#include"Action.h"

class SelectAction : public Action {
private:
	Point P;
public:
	SelectAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(int input = 1);
	virtual ~SelectAction() {}
};