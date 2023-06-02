#include "MoveFigureAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h" 
#include "..\Figures\CFigure.h"


MoveFigureAction::MoveFigureAction(ApplicationManager* pApp) : Action(pApp) {}


void MoveFigureAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	F = pManager->GetSelectedFigure();
	PreviousPoint = F->GetCenter();

	pOut->PrintMessage("Please choose the destination point");
	pIn->GetPointClicked(P.x, P.y);
}

void MoveFigureAction::Execute(int input) {
	if (input == 1 && pManager->GetSelectedFigure() != NULL) ReadActionParameters();
	if (input == 3) F = pManager->GetSelectedFigure();
	if (F != NULL) {
		if (input == 1) DoRecordingOperations();
		if (input == 1 || input == 3) DoUndoRedoOperations();
		F->MoveFigure(P);
		F->PrintInfo(pManager->GetOutput());
	}
	else {
		pManager->GetOutput()->PrintMessage("Please select a figure first");
	}
}
void MoveFigureAction::DoSwaps() {
	swap(PreviousPoint, P);
}
void MoveFigureAction::Undo() {
	DoSwaps();
	Execute(0);
	DoSwaps();
}

void MoveFigureAction::Redo() {
	Execute(2);
}