#pragma once 
#include"Action.h"
#include "..\Figures\CFigure.h"

class MoveFigureAction : public Action {
private:
	Point P;
	Point PreviousPoint;
public:
	MoveFigureAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(int input = 1);
	virtual void Undo();
	virtual void Redo();
	void DoSwaps();
	virtual ~MoveFigureAction() {}
};
