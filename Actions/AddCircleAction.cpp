#include "AddCircleAction.h"
#include "..\Figures\CCircle.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h" 

AddCircleAction :: AddCircleAction( ApplicationManager * pApp ) : Action(pApp ) {
}

void AddCircleAction:: ReadActionParameters () 
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	PlaySound("Sounds//DrawACircle.wav", NULL, SND_ASYNC);


	pOut ->PrintMessage("New Circle: Click First Point.") ;
	pIn ->GetPointClicked(p1.x , p1.y ) ; 
	while(p1.y <= 50 )
	{
		pOut->PrintMessage("You clicked on the tool bar. Click on the drawing area") ; 
		pIn ->GetPointClicked(p1.x , p1.y ) ;
	}
	while(p1.y >= 600 )
	{
		pOut->PrintMessage("You clicked on the status bar. Click on the drawing area") ; 
		pIn ->GetPointClicked(p1.x , p1.y ) ;
	}

    pOut ->PrintMessage("New Circle: Click Second Point ") ;
	pIn ->GetPointClicked(p2.x , p2.y ) ;

	while(p2.y <= 50 )
	{
		pOut->PrintMessage("You clicked on the tool bar. Click on the drawing area") ; 
		pIn ->GetPointClicked(p2.x , p2.y ) ;
	}
	while(p2.y >= 600 )
	{
		pOut->PrintMessage("You clicked on the status bar. Click on the drawing area") ; 
		pIn ->GetPointClicked(p2.x , p2.y ) ;
	}
	float r = sqrt((p1.y-p2.y)*(p1.y-p2.y)+(p1.x-p2.x)*(p1.x-p2.x)) ;
	radius = r ; 
	while (p1.y-r <50 || p1.y +r > 600  )
	{
		pOut->PrintMessage("The circle coresponding to this radius will go out from the drawing area. Please use a smaller radius. Re-click Second Point") ; 
		pIn ->GetPointClicked(p2.x , p2.y ) ;
		r = sqrt((p1.y-p2.y)*(p1.y-p2.y)+(p1.x-p2.x)*(p1.x-p2.x)) ;
	}
	CircleGfxInfo.isFilled = pOut->getFilled();  
	
	CircleGfxInfo.DrawClr = pOut->getCrntDrawColor() ; 
	CircleGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

void AddCircleAction::Execute(int input) {
	if (input == 1) {
		ReadActionParameters();
		DoRecordingOperations();
	}
	if (input == 1 || input == 3) {
		F = new CCircle(p1, p2, CircleGfxInfo);
		DoUndoRedoOperations();
	}
	pManager->AddFigure(F);
}

void AddCircleAction::Undo() {
	pManager->DeleteFigure(F);
}

void AddCircleAction::Redo() {
	Execute(2);
}
