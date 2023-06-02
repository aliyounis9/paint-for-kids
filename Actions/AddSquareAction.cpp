#include "AddSquareAction.h"
#include "..\Figures\CSquare.h" 

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddSquareAction::AddSquareAction(ApplicationManager * pApp):Action(pApp){
}

void AddSquareAction::ReadActionParameters() 
{	
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	PlaySound("Sounds//DrawASquare.wav", NULL, SND_ASYNC);


	pOut->PrintMessage("New Square: Click at square's center");
	pIn->GetPointClicked(P1.x, P1.y);


	do {



	while(P1.y <= 50 )
	{
		pOut->PrintMessage("You clicked on the tool bar. Click on the drawing area") ; 
		pIn ->GetPointClicked(P1.x , P1.y ) ;
	}
	while(P1.y <= 150 && P1.y>50 )
	{
		pOut->PrintMessage("The square corresponding to your click will croos the tool bar. Click BELOW the last click") ; 
		pIn ->GetPointClicked(P1.x , P1.y ) ;
	}
	while(P1.y >= 600 )
	{
		pOut->PrintMessage("You clicked on the status bar. Click on the drawing area") ; 
		pIn ->GetPointClicked(P1.x , P1.y ) ;
	}
	while(P1.y < 600 && P1.y >=500  )
	{
		pOut->PrintMessage("The square corresponding to your click will croos the Status bar. CLICK UP the last click") ; 
		pIn ->GetPointClicked(P1.x , P1.y ) ;
	}
	}while (P1.y >500|| P1.y <150 ) ;

	SquareGfxInfo.isFilled = pOut->getFilled();

	SquareGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SquareGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddSquareAction::Execute(int input) 
{
	if (input == 1) {
		ReadActionParameters();
		DoRecordingOperations();
	}

	if (input == 1 || input == 3) {
		F = new CSquare(P1, SquareGfxInfo);
		DoUndoRedoOperations();
	}
	pManager->AddFigure(F);
}


void AddSquareAction::Undo() {
	pManager->DeleteFigure(F);
}

void AddSquareAction::Redo() {
	Execute(2);
}
