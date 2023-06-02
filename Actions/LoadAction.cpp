#include "LoadAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h" 

LoadAction::LoadAction(ApplicationManager* pApp) : Action(pApp) {}


void LoadAction::ReadActionParameters() {
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();
	pOut->PrintMessage("Please enter the file name: ");
	FileName = pIn->GetSrting(pOut);
	pOut->ClearStatusBar();
	FileName += ".txt" + '\0';
	InputFile.open(FileName);
}

void LoadAction::Execute(int input) {
	if (pManager->GetRecordingState()) {
		return pManager->GetOutput()->PrintMessage("You cannot load a file while recording. Please stop the recording first."), void();
	}
	ReadActionParameters();
	if (InputFile.is_open()) {
		pManager->ClearAll(true);
		string DrawingColor, FillingColor;
		int NumberOfFigures;
		InputFile >> DrawingColor >> FillingColor >> NumberOfFigures;
		pOut->setCrntDrawColor(UI.GetColor(DrawingColor));
		pOut->setCrntFillColor(UI.GetColor(FillingColor));
		if (UI.GetColor(FillingColor) != UI.BkGrndColor) pOut->setFilled(true);

		for (int i = 0; i < NumberOfFigures; i++) {
			string FigType;
			InputFile >> FigType;
			CFigure* Fig;

			if (FigType == "TRIANG") Fig = new CTriangle;
			else if (FigType == "SQU") Fig = new CSquare;
			else if (FigType == "HEXA") Fig = new CHexagon;
			else if (FigType == "RECT") Fig = new CRectangle;
			else Fig = new CCircle;

			Fig->Load(InputFile);
			pManager->AddFigure(Fig);

		}
		InputFile.close();
	}
	else {
		pOut->PrintMessage("File not found. Please make sure you entered the name correctly and don't add the file extension");
	}
}