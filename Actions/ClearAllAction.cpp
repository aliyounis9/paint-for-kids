#include "ClearAllAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h" 

ClearAllAction::ClearAllAction(ApplicationManager* pApp) : Action(pApp) {}


void ClearAllAction::ReadActionParameters() {
}

void ClearAllAction::Execute(int input) {
	ReadActionParameters();
	if(input == 1) DoRecordingOperations();
	if (input == 3 || pManager->GetRecordingState()) {
		pManager->ClearAll(true);
	}
	else {
		pManager->ClearAll();
	}
}