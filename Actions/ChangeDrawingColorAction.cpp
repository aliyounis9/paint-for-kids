#include "ChangeDrawingColorAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h" 

ChangeDrawingColorAction::ChangeDrawingColorAction(ApplicationManager* pApp) : Action(pApp) {}



void ChangeDrawingColorAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	PlaySound("Sounds//ChangeDrawingColor.wav", NULL, SND_ASYNC);
	pOut->PrintMessage("Please select a color");

	PreviousDrawingColor = pOut->getCrntDrawColor();
	NewDrawingColor = pIn->GetUserAction();

	SetDrawingColor();
}

void ChangeDrawingColorAction::SetDrawingColor() {
	if (NewDrawingColor >= BLACK_ACT && NewDrawingColor <= GREEN_ACT) {
		ChosenColor = (NewDrawingColor == BLACK_ACT ? BLACK : NewDrawingColor == RED_ACT ? RED : NewDrawingColor == YELLOW_ACT ?
			YELLOW : NewDrawingColor == ORANGE_ACT ? ORANGE : NewDrawingColor == BLUE_ACT ? BLUE : GREEN);
		ColorName = UI.GetColorName(ChosenColor);
	}
	else ChosenColor = WHITE;
}

void ChangeDrawingColorAction::Execute(int input) {
	if (input == 1) ReadActionParameters();
	if(input == 1 || input == 3) F = pManager->GetSelectedFigure();
	if (F != NULL) {
		if (input == 1) DoRecordingOperations();
		if(input == 1 || input == 3) DoUndoRedoOperations();
		if (ChosenColor != WHITE) {
			F->ChngDrawClr(ChosenColor);
			Output* pOut = pManager->GetOutput();
			pOut->setCrntDrawColor(ChosenColor);
			string Print;
			if (input) Print += "You changed the Drawing Color to " + ColorName + "." + "\0";
			pOut->PrintMessage(Print);
		}
		else {
			pManager->GetOutput()->PrintMessage("Please select a color");
		}
	}
	else {
		string Print;
		if (input) Print += "Please select a figure first" + '\0';
		pManager->GetOutput()->PrintMessage(Print);
	}
}

void ChangeDrawingColorAction::DoSwaps() {
	swap(ChosenColor, PreviousDrawingColor);
}

void ChangeDrawingColorAction::Undo() {
	DoSwaps();
	Execute(0);
	DoSwaps();
}

void ChangeDrawingColorAction::Redo() {
	Execute(2);
}