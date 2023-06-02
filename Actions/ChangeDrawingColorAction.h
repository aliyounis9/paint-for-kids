#pragma once 
#include"Action.h"

class ChangeDrawingColorAction : public Action {
private:
	Point P;
	ActionType NewDrawingColor;
	color ChosenColor;
	color PreviousDrawingColor;
	string ColorName;
public:
	ChangeDrawingColorAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	void SetDrawingColor();
	virtual void Execute(int input = 1);
	virtual void Undo();
	virtual void Redo();
	void DoSwaps();
	virtual ~ChangeDrawingColorAction() {}
};