#pragma once 
#include"Action.h"

class ChangeFillingColorAction : public Action {
private:
	Point P;
	ActionType NewFillingColor;
	color ChosenColor;
	color PreviousFillingColor;
	string ColorName;
	bool PreviousFillingState;
	bool thisFillingState;
public:
	ChangeFillingColorAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	void SetFillingColor();
	virtual void Execute(int input = 1);
	virtual void Undo();
	virtual void Redo();
	void DoSwaps();
	virtual ~ChangeFillingColorAction() {}

};