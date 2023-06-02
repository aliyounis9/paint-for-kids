#include "AddRectAction.h"
#include "..\Figures\CRectangle.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


AddRectAction::AddRectAction(ApplicationManager * pApp):Action(pApp){
}

void AddRectAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	PlaySound("Sounds//DrawARectangle.wav", NULL, SND_ASYNC);


	pOut->PrintMessage("New Rectangle: Click at first corner");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	while(P1.y <= 50 )
	{
		pOut->PrintMessage("You clicked on the tool bar. Click on the drawing area") ; 
		pIn ->GetPointClicked(P1.x , P1.y ) ;
	}
	while(P1.y >= 600 )
	{
		pOut->PrintMessage("You clicked on the status bar. Click on the drawing area") ; 
		pIn ->GetPointClicked(P1.x , P1.y ) ;
	}

	pOut->PrintMessage("New Rectangle: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	while(P2.y <= 50 )
	{
		pOut->PrintMessage("you clicked on the tool bar , click on the drawing area") ; 
		pIn ->GetPointClicked(P2.x , P2.y ) ;
	}
	while(P2.y >= 600 )
	{
		pOut->PrintMessage("you clicked on the status bar , click on the drawing area") ; 
		pIn ->GetPointClicked(P2.x , P2.y ) ;
	}

	RectGfxInfo.isFilled = pOut->getFilled();
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddRectAction::Execute(int input) 
{
	//This action needs to read some parameters first
	if (input == 1) {
		ReadActionParameters();
		DoRecordingOperations();
	}

	if (input == 1 || input == 3) {
		F = new CRectangle(P1, P2, RectGfxInfo);
		DoUndoRedoOperations();
	}

	//Add the rectangle to the list of figures
	pManager->AddFigure(F);
}

void AddRectAction::Undo() {
	pManager->DeleteFigure(F);
}

void AddRectAction::Redo() {
	Execute(2);
}
