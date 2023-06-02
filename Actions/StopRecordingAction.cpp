#include "StopRecordingAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h" 

StopRecordingAction::StopRecordingAction(ApplicationManager* pApp) : Action(pApp) {}


void StopRecordingAction::ReadActionParameters() {
	IsRecording = pManager->GetRecordingState();
}

void StopRecordingAction::Execute(int input) {
	ReadActionParameters();
	if (IsRecording) {
		pManager->GetOutput()->PrintMessage("Recording has stopped. Press 'Play' to play your recording.");
		pManager->SetRecordingState(false);
	}
	else {
		pManager->GetOutput()->PrintMessage("There is no recording in progress.");
	}
}