#include "SelectAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h" 

SelectAction::SelectAction(ApplicationManager* pApp) : Action(pApp) {
}


void SelectAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	PlaySound("Sounds//SelectAFig.wav", NULL, SND_ASYNC);
	pOut->PrintMessage("Please select a figure");
	pIn->GetPointClicked(P.x, P.y);
}

void SelectAction::Execute(int input) {
	if (input == 1) ReadActionParameters();
	F = pManager->GetFigure(P.x, P.y);
	if (F != NULL) {
		if (input == 1) DoRecordingOperations();
		CFigure* SelectedFig = pManager->GetSelectedFigure();
		if (SelectedFig != NULL) {
			pManager->SetSelectedFigure(NULL);
			SelectedFig->SetSelected(false);
		}
		if (F != SelectedFig) {
			pManager->SetSelectedFigure(F);
		}
	}
	else {
		pManager->GetOutput()->ClearStatusBar();
	}
}