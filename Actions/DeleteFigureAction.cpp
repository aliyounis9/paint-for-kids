#include "DeleteFigureAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h" 
#include "..\Figures\CFigure.h"


DeleteFigureAction::DeleteFigureAction(ApplicationManager* pApp) : Action(pApp) {}


void DeleteFigureAction::ReadActionParameters() {
	F = pManager->GetSelectedFigure();
}

void DeleteFigureAction::Execute(int input) {
	if (input == 1 || input == 3) ReadActionParameters();
	if (F != NULL) {
		if (input == 1) DoRecordingOperations();
		if (input == 1 || input == 3) DoUndoRedoOperations();
		pManager->DeleteFigure(F);
	}
	else {
		pManager->GetOutput()->PrintMessage("Please select a figure first");
	}
}

void DeleteFigureAction::Undo() {
	pManager->AddFigure(F);
}

void DeleteFigureAction::Redo() {
	Execute(2);
}