#include "PlayRecordingAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h" 

PlayRecordingAction::PlayRecordingAction(ApplicationManager* pApp) : Action(pApp) {}


void PlayRecordingAction::ReadActionParameters() {
	RecState = pManager->GetRecordingState();
	RecCount = pManager->GetRecordingsCount();
}

void PlayRecordingAction::Execute(int input) {
	ReadActionParameters();
	if (!RecState) {
		if (RecCount) {
			pManager->GetOutput()->PrintMessage("Your last recording will be played in 3 seconds.");
			Sleep(1000);
			for (int i = 3; i >= 1; i--) {
				pManager->GetOutput()->PrintMessage(to_string(i) + "..." + '\0');
				Sleep(1000);
			}
			pManager->ClearAll(true);
			pManager->PlayRecording();
		}
		else {
			pManager->GetOutput()->PrintMessage("There are no recorded actions.");
		}
	}
	else {
		pManager->GetOutput()->PrintMessage("Please stop the recording in progress so you can play it.");
	}
}