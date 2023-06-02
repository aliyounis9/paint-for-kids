#pragma once 
#include"Action.h"

class UndoAction : public Action {
private:
	int NextOperation;
public:
	UndoAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(int input = 1);
	virtual ~UndoAction() {}
};
