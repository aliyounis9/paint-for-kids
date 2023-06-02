#include"FigureTypeGame.h" 
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h" 
#include<string>

FigureTypeGame ::FigureTypeGame (ApplicationManager * pApp ):Action(pApp)
{   
	False=Correct=0 ;
	Output * POUT = pManager->GetOutput() ; 
	Input * PIN = pManager->GetInput() ; 
	pManager->ReturnAftGame();
	pManager->UpdateInterface();

	do 
	{srand(time(0)) ;// returns integer and we wiill consider 0 coressponding to rectangle shape and 1 coressponding to square shape and 2 coressponding to triangle shape 
	randomint = rand()%5 ; // and 3 coressponding to circle shape and 4 coressponding to hexagon shape  
    switch(randomint){
		case  0 : 
			MaxTrFigCount = pManager->GetRecCount() ; 
			if (MaxTrFigCount !=0 )
	        POUT->PrintMessage("Let's Pick Rectangles , click anywere to start ") ;
			break ; 
	   case  1 : 
			MaxTrFigCount = pManager->GetSquCount() ; 
			if (MaxTrFigCount !=0 )
			POUT->PrintMessage("Let's Pick Squares, click anywere to start ") ;
			break ;
       case  2 : 
			MaxTrFigCount = pManager->GetTriCount() ; 
			if (MaxTrFigCount !=0 )
			POUT->PrintMessage("Let's Pick Triangles, click anywere to start ") ;
			break ;
	   case  3 : 
			MaxTrFigCount = pManager->GetCirCount() ; 
			if (MaxTrFigCount !=0 )
			POUT->PrintMessage("Let's Pick Circles, click anywere to start ") ;
			break ;
       case  4 : 
			MaxTrFigCount = pManager->GetHexCount() ; 
			if (MaxTrFigCount !=0 )
			POUT->PrintMessage("Let's Pick Hexagons, click anywere to start ") ;
			break ;
	}
	}while (MaxTrFigCount == 0);
    int x ,y ; 
	PIN->GetPointClicked(x,y ) ; 
}

void FigureTypeGame:: ReadActionParameters()
{
	
	Input * PIN = pManager->GetInput() ; 
	Output * POUT = pManager->GetOutput() ; 
	POUT->PrintMessage("please pick fig ") ;
	PIN ->GetPointClicked(P.x,P.y) ; 
	

}

void FigureTypeGame:: Execute(int input) 
{   do 
{
	pManager->UpdateInterface() ; 
	ReadActionParameters() ; 
    PickedOne = pManager->GetFigure(P.x,P.y) ;
	if (PickedOne==0)
		continue ; 
	pManager->SetPickedFig(PickedOne) ; 
	switch(randomint){
		case  0 : 
			if (  dynamic_cast<CRectangle * > ( PickedOne) ) 
			Correct++ ; 
			else 
			False++ ; 
			break ; 
	   case  1 : 
		   if (  dynamic_cast<CSquare * > ( PickedOne) ) 
			Correct++ ; 
			else 
			False++ ; 
			break ;
       case  2 : 
			if (  dynamic_cast<CTriangle * > ( PickedOne) ) 
			Correct++ ; 
			else 
			False++ ; 
			break ;
	   case  3 : 
			if (  dynamic_cast<CCircle * > ( PickedOne) ) 
			Correct++ ; 
			else 
			False++ ; 
			break ;
       case  4 : 
		   if (  dynamic_cast<CHexagon * > ( PickedOne) ) 
			Correct++ ; 
			else 
			False++ ; 
			break ;
	}
}while( Correct != MaxTrFigCount ) ; 
Output * pOut = pManager->GetOutput () ; 
string Print ;
Print += "Correct Picks : " + to_string(Correct)+ "    False Picks :  " + to_string(False)   ;  
pOut ->PrintMessage(Print)  ;   
pManager->UpdateInterface() ; 
}

