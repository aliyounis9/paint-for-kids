#include"AddHexAction.h"
#include"..\ApplicationManager.h"
#include"..\Figures\CHexagon.h"
#include"..\GUI\Output.h"
#include"..\GUI\Input.h" 

AddHexAction ::AddHexAction(ApplicationManager * pApp ) : Action ( pApp ) {
}

void AddHexAction :: ReadActionParameters() 
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	PlaySound("Sounds//DrawAHexagon.wav", NULL, SND_ASYNC);


	pOut->PrintMessage("New Hexagon : Click at Hexagon's Center" );
	pIn->GetPointClicked(P.x , P.y ) ; 
	do {
	while(P.y <= 50 )
	{
		pOut->PrintMessage("you clicked on the tool bar , click on the drawing area") ; 
		pIn ->GetPointClicked(P.x , P.y ) ;
	}
	while(P.y > 50 && P.y <= (50+87)  )
	{
		pOut->PrintMessage("the Hexagon corresponding to your click will croos the tool bar , CLICK DOWN the last click") ; 
		pIn ->GetPointClicked(P.x , P.y ) ;
	}
	while(P.y >= 600 )
	{
		pOut->PrintMessage("you clicked on the status bar , click on the drawing area") ; 
		pIn ->GetPointClicked(P.x , P.y ) ;
	}
	while(P.y <600 && P.y >(600-87)  )
	{
		pOut->PrintMessage("the Hexagon corresponding to your click will croos the tool bar , CLICK UP the last click") ; 
		pIn ->GetPointClicked(P.x , P.y ) ;
	}
	}while(P.y >(600-87) || P.y <(50+87) );
	HexGfxInfo.isFilled = pOut->getFilled();

	HexGfxInfo.DrawClr=pOut->getCrntDrawColor() ; 
	HexGfxInfo.FillClr=pOut->getCrntFillColor();

	pOut->ClearStatusBar();


}

void AddHexAction:: Execute(int input) {
	if (input == 1) {
		ReadActionParameters();
		DoRecordingOperations();
	}
	if (input == 1 || input == 3) {
		F = new CHexagon(P, HexGfxInfo);
		DoUndoRedoOperations();
	}
	pManager->AddFigure(F); 
}

void AddHexAction::Undo() {
	pManager->DeleteFigure(F);
}

void AddHexAction::Redo() {
	Execute(2);
}
