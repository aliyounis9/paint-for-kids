#include "UndoAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h" 

UndoAction::UndoAction(ApplicationManager* pApp) : Action(pApp) {}


void UndoAction::ReadActionParameters() {
	NextOperation = pManager->GetUndoRedoOrder();
}

void UndoAction::Execute(int input) {
	ReadActionParameters();
	if (NextOperation) {
		pManager->Undo();
		if (input == 1) DoRecordingOperations();
	}
	else {
		pManager->GetOutput()->PrintMessage("No Actions to Undo");
	}
}