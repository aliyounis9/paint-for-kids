#pragma once 
#include"Action.h"
#include "..\Figures\CFigure.h"

class DeleteFigureAction : public Action {
public:
	DeleteFigureAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(int input = 1);
	virtual void Undo();
	virtual void Redo();
	virtual ~DeleteFigureAction() {}
};
