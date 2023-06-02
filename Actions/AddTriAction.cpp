#include"AddTriAction.h"
#include "..\Figures\CTriangle.h"
#include"..\ApplicationManager.h"
#include"..\GUI\Input.h"
#include"..\GUI\Output.h"

AddTriAction::AddTriAction(ApplicationManager* pApp) :Action(pApp) {
}

void AddTriAction :: ReadActionParameters() 
{
	Output * pOut = pManager->GetOutput() ; 
	Input * pIn = pManager->GetInput() ; 
	PlaySound("Sounds//DrawATriangle.wav", NULL, SND_ASYNC);


	pOut->PrintMessage("New Triangle : click at first point") ; 
	pIn->GetPointClicked(p1.x ,p1.y ) ;

	while(p1.y <= 50 )
	{
		pOut->PrintMessage("you clicked on the tool bar , click on the drawing area") ; 
		pIn ->GetPointClicked(p1.x , p1.y ) ;
	}
	while(p1.y >= 600 )
	{
		pOut->PrintMessage("you clicked on the status bar , click on the drawing area") ; 
		pIn ->GetPointClicked(p1.x , p1.y ) ;
	}

	pOut->PrintMessage("New Triangle : click at second point ") ; 
	pIn->GetPointClicked(p2.x ,p2.y ) ;
	
	while(p2.y <= 50 )
	{
		pOut->PrintMessage("you clicked on the tool bar , click on the drawing area") ; 
		pIn ->GetPointClicked(p2.x , p2.y ) ;
	}
	while(p2.y >= 600 )
	{
		pOut->PrintMessage("you clicked on the status bar , click on the drawing area") ; 
		pIn ->GetPointClicked(p2.x , p2.y ) ;
	}
	pOut->PrintMessage("New Triangle : click at third point ") ;
	pIn->GetPointClicked(p3.x ,p3.y ) ; 

	while(p3.y <= 50 )
	{
		pOut->PrintMessage("you clicked on the tool bar , click on the drawing area") ; 
		pIn ->GetPointClicked(p3.x , p3.y ) ;
	}
	while(p3.y >= 600 )
	{
		pOut->PrintMessage("you clicked on the status bar , click on the drawing area") ; 
		pIn ->GetPointClicked(p3.x , p3.y ) ;
	}

	TriGfxInfo.isFilled = pOut->getFilled();

	TriGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}


void  AddTriAction :: Execute (int input)
{
	if (input == 1) {
		ReadActionParameters();
		DoRecordingOperations();
	}

	if (input == 1 || input == 3) {
		F = new CTriangle(p1, p2, p3, TriGfxInfo);
		DoUndoRedoOperations();
	}
	pManager->AddFigure(F); 

}


void AddTriAction::Undo() {
	pManager->DeleteFigure(F);
}

void AddTriAction::Redo() {
	Execute(2);
}
