#include "RedoAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h" 

RedoAction::RedoAction(ApplicationManager* pApp) : Action(pApp) {}


void RedoAction::ReadActionParameters() {
	NextOperation = pManager->GetUndoRedoOrder();
}

void RedoAction::Execute(int input) {
	ReadActionParameters();
	if (NextOperation < pManager->GetUndoRedoCount()) {
		pManager->Redo();
		if (input == 1) DoRecordingOperations();
	}
	else {
		pManager->GetOutput()->PrintMessage("No Actions to Redo");
	}
}