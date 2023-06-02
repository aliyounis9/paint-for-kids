#include "ChangeFillingColorAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h" 

ChangeFillingColorAction::ChangeFillingColorAction(ApplicationManager* pApp) : Action(pApp) {}



void ChangeFillingColorAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	PlaySound("Sounds//ChangeFillingColor.wav", NULL, SND_ASYNC);

	pOut->PrintMessage("Please select a color");

	PreviousFillingColor = pOut->getCrntFillColor();
	PreviousFillingState = pOut->getFilled();
	thisFillingState = true;
	NewFillingColor = pIn->GetUserAction();
	SetFillingColor();
}

void ChangeFillingColorAction::SetFillingColor() {
	if (NewFillingColor >= BLACK_ACT && NewFillingColor <= GREEN_ACT) {
		ChosenColor = (NewFillingColor == BLACK_ACT ? BLACK : NewFillingColor == RED_ACT ? RED : NewFillingColor == YELLOW_ACT ?
			YELLOW : NewFillingColor == ORANGE_ACT ? ORANGE : NewFillingColor == BLUE_ACT ? BLUE : GREEN);
		ColorName = UI.GetColorName(ChosenColor);
	}
	else ChosenColor = WHITE;
}

void ChangeFillingColorAction::Execute(int input) {
	if (input == 1) ReadActionParameters();
	if (input == 1 || input == 3) F = pManager->GetSelectedFigure(), SetFillingColor();
	if (F != NULL) {
		if(input == 1) DoRecordingOperations();
		if (input == 1 || input == 3) DoUndoRedoOperations();
		if (ChosenColor != WHITE) {
			F->ChngFillClr(thisFillingState, ChosenColor);
			Output* pOut = pManager->GetOutput();
			pOut->setCrntFillColor(ChosenColor);
			pOut->setFilled(thisFillingState);
			string Print;
			if (input) {
				Print += "You changed the Filling Color to " + ColorName + "." + "\0";
			}
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
void ChangeFillingColorAction::DoSwaps() {
	swap(thisFillingState, PreviousFillingState);
	swap(PreviousFillingColor, ChosenColor);
}
void ChangeFillingColorAction::Undo() {
	DoSwaps();
	Execute(0);
	DoSwaps();
}

void ChangeFillingColorAction::Redo() {
	Execute(2);
}