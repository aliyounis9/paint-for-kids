#include "SaveAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h" 

SaveAction::SaveAction(ApplicationManager* pApp) : Action(pApp) {}


void SaveAction::ReadActionParameters() {
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();
	pOut->PrintMessage("Please enter a file name: ");
	FileName = pIn->GetSrting(pOut);
	pOut->ClearStatusBar();
	FileName += ".txt" + '\0';
	OutputFile.open(FileName);
}

void SaveAction::Execute(int input) {
	if (pManager->GetRecordingState()) {
		return pManager->GetOutput()->PrintMessage("You cannot save a file while recording. Please stop the recording first."), void();
	}
	ReadActionParameters();
	OutputFile << UI.GetColorName(pOut->getCrntDrawColor()) << '\t' << UI.GetColorName(pOut->getCrntFillColor()) << endl <<
		pManager->GetFigCount() << endl;
	pManager->SaveAll(OutputFile);
	OutputFile.close();
}