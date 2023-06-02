#include "StartRecordingAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h" 

StartRecordingAction::StartRecordingAction(ApplicationManager* pApp) : Action(pApp) {}


void StartRecordingAction::ReadActionParameters() {
	CanRecord = pManager->CanRecord();
}

void StartRecordingAction::Execute(int input) {
	ReadActionParameters();
	if (pManager->GetRecordingState()) {
		return pManager->GetOutput()->PrintMessage("Recording is already in progress."), void();
	}
	if (CanRecord) {
		pManager->GetOutput()->PrintMessage("Recording is in progress.");
		pManager->SetRecordingState(true);
	}
	else {
		pManager->GetOutput()->PrintMessage("You cannot start recording at this moment. Please press on 'Clear All' button.");
	}
}