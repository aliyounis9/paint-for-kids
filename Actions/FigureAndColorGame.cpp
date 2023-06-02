#include"FigureAndColorGame.h" 
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h" 
#include<string>

FigureAndColorGame:: FigureAndColorGame ( ApplicationManager * pApp ) : Action ( pApp ) 
{
	False=Correct=0 ;
	Output * POUT = pManager->GetOutput() ; 
	Input * PIN = pManager->GetInput() ; 
	pManager->ReturnAftGame();
	pManager->UpdateInterface();


//we will consider 0 as black rectangles and 1 as yellow rectangles and 3 as orange rectangles and 4 as red rectangles and 5 as green rectangles and 6 as blue rectangles  
//and 7 as black squares and 8 as yellow squares and 8 as orange squares and 9 as red squares and 10 as green squares and 11 as blue squares
//and 12 as black triangles and 13 as yellow triangles and 14 as orange triangles and 15 as red triangles and 16 as green triangles and 17 as blue triangles
//and 18 as black circles and 19 as yellow circles and 20 as orange circles and 21 as red circles and 22 as green circles and 23 as blue circles 
//and 24 as black hexagons and 25 as yellow hexagons and 26 as orange hexagons and 27 as red hexagons and 28 as green hexagons and 29 as blue hexagons 

	do 
{
	srand(time(0)) ; 
	Randoumint = rand()%30 ; 
	switch (Randoumint ) 
	{
		case 0 : 
			MaxTrFigCount = pManager->GetBlackRecCount() ; 
			if (MaxTrFigCount !=0 )
	        POUT->PrintMessage("Let's Pick Black Rectangles , click anywere to start ") ;
			break ; 
		case 1 : 
			MaxTrFigCount = pManager->GetYRecCount() ; 
			if (MaxTrFigCount !=0 )
	        POUT->PrintMessage("Let's Pick Yellow Rectangles , click anywere to start ") ;
			break ;
        case 2 : 
			MaxTrFigCount = pManager->GetORecCount() ; 
			if (MaxTrFigCount !=0 )
	        POUT->PrintMessage("Let's Pick Orange Rectangles , click anywere to start ") ;
			break ;
		case 3 : 
			MaxTrFigCount = pManager->GetRRecCount() ; 
			if (MaxTrFigCount !=0 )
	        POUT->PrintMessage("Let's Pick Red Rectangles , click anywere to start ") ;
			break ;
		case 4 : 
			MaxTrFigCount = pManager->GetGRecCount() ; 
			if (MaxTrFigCount !=0 )
	        POUT->PrintMessage("Let's Pick Green Rectangles , click anywere to start ") ;
			break ;
        case 5 : 
			MaxTrFigCount = pManager->GetBlueRecCount() ; 
			if (MaxTrFigCount !=0 )
	        POUT->PrintMessage("Let's Pick Blue Rectangles , click anywere to start ") ;
			break ;
		case 6 : 
			MaxTrFigCount = pManager->GetBlackSquCount() ; 
			if (MaxTrFigCount !=0 )
	        POUT->PrintMessage("Let's Pick Black Squares , click anywere to start ") ;
			break ;
        case 7 : 
			MaxTrFigCount = pManager->GetYSquCount() ; 
			if (MaxTrFigCount !=0 )
	        POUT->PrintMessage("Let's Pick Yellow Squares , click anywere to start ") ;
			break ;
        case 8 : 
			MaxTrFigCount = pManager->GetOSquCount() ; 
			if (MaxTrFigCount !=0 )
	        POUT->PrintMessage("Let's Pick Orange Squares , click anywere to start ") ;
			break ;
       case 9 : 
			MaxTrFigCount = pManager->GetRSquCount() ; 
			if (MaxTrFigCount !=0 )
	        POUT->PrintMessage("Let's Pick Red Squares , click anywere to start ") ;
			break ;
       case 10 : 
			MaxTrFigCount = pManager->GetGSquCount() ; 
			if (MaxTrFigCount !=0 )
	        POUT->PrintMessage("Let's Pick Green Squares , click anywere to start ") ;
			break ;
		case 11 : 
			MaxTrFigCount = pManager->GetBlueSquCount() ; 
			if (MaxTrFigCount !=0 )
	        POUT->PrintMessage("Let's Pick Blue Squares , click anywere to start ") ;
			break ;
		case 12 : 
			MaxTrFigCount = pManager->GetBlackTriCount() ; 
			if (MaxTrFigCount !=0 )
	        POUT->PrintMessage("Let's Pick Black Triangles , click anywere to start ") ;
			break ;
		case 13 : 
			MaxTrFigCount = pManager->GetYTriCount() ; 
			if (MaxTrFigCount !=0 )
	        POUT->PrintMessage("Let's Pick Yellow Triangles , click anywere to start ") ;
			break ;
		case 14 : 
			MaxTrFigCount = pManager->GetOTriCount() ; 
			if (MaxTrFigCount !=0 )
	        POUT->PrintMessage("Let's Pick Orange Triangles , click anywere to start ") ;
			break ;
		case 15 : 
			MaxTrFigCount = pManager->GetRTriCount() ; 
			if (MaxTrFigCount !=0 )
	        POUT->PrintMessage("Let's Pick Red Triangles , click anywere to start ") ;
			break ;
		case 16 : 
			MaxTrFigCount = pManager->GetGTriCount() ; 
			if (MaxTrFigCount !=0 )
	        POUT->PrintMessage("Let's Pick Green Triangles , click anywere to start ") ;
			break ;
		case 17 : 
			MaxTrFigCount = pManager->GetBlueTriCount() ; 
			if (MaxTrFigCount !=0 )
	        POUT->PrintMessage("Let's Pick Blue Triangles , click anywere to start ") ;
			break ;
        case 18 : 
			MaxTrFigCount = pManager->GetBlackCirCount() ; 
			if (MaxTrFigCount !=0 )
	        POUT->PrintMessage("Let's Pick Black Circles , click anywere to start ") ;
			break ;
		case 19 : 
			MaxTrFigCount = pManager->GetYCirCount() ; 
			if (MaxTrFigCount !=0 )
	        POUT->PrintMessage("Let's Pick Yellow Circles , click anywere to start ") ;
			break ;
		case 20 : 
			MaxTrFigCount = pManager->GetOCirCount() ; 
			if (MaxTrFigCount !=0 )
	        POUT->PrintMessage("Let's Pick Orange Circles , click anywere to start ") ;
			break ;
		case 21 : 
			MaxTrFigCount = pManager->GetRCirCount() ; 
			if (MaxTrFigCount !=0 )
	        POUT->PrintMessage("Let's Pick Red Circles , click anywere to start ") ;
			break ;
		case 22 : 
			MaxTrFigCount = pManager->GetGCirCount() ; 
			if (MaxTrFigCount !=0 )
	        POUT->PrintMessage("Let's Pick Green Circles , click anywere to start ") ;
			break ;
		case 23 : 
			MaxTrFigCount = pManager->GetBlueCirCount() ; 
			if (MaxTrFigCount !=0 )
	        POUT->PrintMessage("Let's Pick Blue Circles , click anywere to start ") ;
			break ;
		case 24 : 
			MaxTrFigCount = pManager->GetBlackHexCount() ; 
			if (MaxTrFigCount !=0 )
	        POUT->PrintMessage("Let's Pick Black Hexagons , click anywere to start ") ;
			break ;
		case 25 : 
			MaxTrFigCount = pManager->GetYHexCount() ; 
			if (MaxTrFigCount !=0 )
	        POUT->PrintMessage("Let's Pick Yellow Hexagons , click anywere to start ") ;
			break ;
		case 26 : 
			MaxTrFigCount = pManager->GetOHexCount() ; 
			if (MaxTrFigCount !=0 )
	        POUT->PrintMessage("Let's Pick Orange Hexagons , click anywere to start ") ;
			break ;
		case 27 : 
			MaxTrFigCount = pManager->GetRHexCount() ; 
			if (MaxTrFigCount !=0 )
	        POUT->PrintMessage("Let's Pick Red Hexagons , click anywere to start ") ;
			break ;
		case 28 : 
			MaxTrFigCount = pManager->GetGHexCount() ; 
			if (MaxTrFigCount !=0 )
	        POUT->PrintMessage("Let's Pick Green Hexagons , click anywere to start ") ;
			break ;
		case 29 : 
			MaxTrFigCount = pManager->GetBlueHexCount() ; 
			if (MaxTrFigCount !=0 )
	        POUT->PrintMessage("Let's Pick Blue Hexagons , click anywere to start ") ;
			break ;

}
}while (MaxTrFigCount == 0  ) ;
 int x ,y ; 
	PIN->GetPointClicked(x,y ) ;
}

void  FigureAndColorGame::  ReadActionParameters () 
{
	Input * PIN = pManager->GetInput() ; 
	Output * POUT = pManager->GetOutput() ; 
	POUT->PrintMessage("please pick fig ") ;
	PIN ->GetPointClicked(P.x,P.y) ; 

}


void FigureAndColorGame::   Execute (int input ) 
{
	do 
	{
		pManager->UpdateInterface() ; 
	ReadActionParameters() ; 
    PickedOne = pManager->GetFigure(P.x,P.y) ;
	if (PickedOne==0)
		continue ; 
	pManager->SetPickedFig(PickedOne) ;  
	switch(Randoumint) 
	{
     	case  0 : 
			if (  dynamic_cast<CRectangle * > ( PickedOne) &&  (PickedOne->GetGfxInfo().FillClr)==BLACK  ) 
			Correct++ ;
			else 
			False++ ; 
			break ; 
	   case  1 : 
		   if (  dynamic_cast<CRectangle * > ( PickedOne) &&  (PickedOne->GetGfxInfo().FillClr)==YELLOW ) 
			Correct++ ; 
			else 
			False++ ; 
			break ;
		case  2 : 
			if (  dynamic_cast<CRectangle * > ( PickedOne) &&  (PickedOne->GetGfxInfo().FillClr)==ORANGE ) 
			Correct++ ; 
			else 
			False++ ; 
			break ;
		case  3 : 
		   if (  dynamic_cast<CRectangle * > ( PickedOne) &&  (PickedOne->GetGfxInfo().FillClr)==RED ) 
			Correct++ ; 
			else 
			False++ ; 
			break ;
		case  4 : 
		   if (  dynamic_cast<CRectangle * > ( PickedOne) &&  (PickedOne->GetGfxInfo().FillClr)==GREEN ) 
			Correct++ ; 
			else 
			False++ ; 
			break ;
		case  5 : 
		   if (  dynamic_cast<CRectangle * > ( PickedOne) &&  (PickedOne->GetGfxInfo().FillClr)==BLUE ) 
			Correct++ ; 
			else 
			False++ ; 
			break ;
		case  6 : 
			if (  dynamic_cast<CSquare * > ( PickedOne) &&  (PickedOne->GetGfxInfo().FillClr)==BLACK ) 
			Correct++ ; 
			else 
			False++ ; 
			break ;
		case  7 : 
			if (  dynamic_cast<CSquare * > ( PickedOne) &&  (PickedOne->GetGfxInfo().FillClr)==YELLOW) 
			Correct++ ; 
			else 
			False++ ; 
			break ;
		case  8 : 
			if (  dynamic_cast<CSquare * > ( PickedOne) &&  (PickedOne->GetGfxInfo().FillClr)==ORANGE) 
			Correct++ ; 
			else 
			False++ ; 
			break ;
		case  9 : 
			if (  dynamic_cast<CSquare * > ( PickedOne) &&  (PickedOne->GetGfxInfo().FillClr)==RED ) 
			Correct++ ; 
			else 
			False++ ; 
			break ;
		case  10 : 
			if (  dynamic_cast<CSquare * > ( PickedOne) &&  (PickedOne->GetGfxInfo().FillClr)==GREEN  ) 
			Correct++ ; 
			else 
			False++ ; 
			break ;
		case  11: 
			if (  dynamic_cast<CSquare * > ( PickedOne) &&  (PickedOne->GetGfxInfo().FillClr)==BLUE ) 
			Correct++ ; 
			else 
			False++ ; 
			break ;
		case  12 : 
			if (  dynamic_cast<CTriangle* > ( PickedOne) &&  (PickedOne->GetGfxInfo().FillClr)==BLACK ) 
			Correct++ ; 
			else 
			False++ ; 
			break ;
		case  13 : 
			if (  dynamic_cast<CTriangle* > ( PickedOne) &&  (PickedOne->GetGfxInfo().FillClr)==YELLOW) 
			Correct++ ; 
			else 
			False++ ; 
			break ;
		case  14 : 
			if (  dynamic_cast<CTriangle* > ( PickedOne) &&  (PickedOne->GetGfxInfo().FillClr)==ORANGE) 
			Correct++ ; 
			else 
			False++ ; 
			break ;
		case  15 : 
			if (  dynamic_cast<CTriangle* > ( PickedOne) &&  (PickedOne->GetGfxInfo().FillClr)==RED ) 
			Correct++ ; 
			else 
			False++ ; 
			break ;
		case  16 : 
			if (  dynamic_cast<CTriangle* > ( PickedOne) &&  (PickedOne->GetGfxInfo().FillClr)==GREEN ) 
			Correct++ ; 
			else 
			False++ ; 
			break ;
		case  17 : 
			if (  dynamic_cast<CTriangle* > ( PickedOne) &&  (PickedOne->GetGfxInfo().FillClr)==BLUE ) 
			Correct++ ; 
			else 
			False++ ; 
			break ;
        case  18 : 
			if (  dynamic_cast<CCircle* > ( PickedOne) &&  (PickedOne->GetGfxInfo().FillClr)==BLACK  ) 
			Correct++ ; 
			else 
			False++ ; 
			break ;
		case  19 : 
			if (  dynamic_cast<CCircle* > ( PickedOne) &&  (PickedOne->GetGfxInfo().FillClr)==YELLOW  ) 
			Correct++ ; 
			else 
			False++ ; 
			break ;       
		case  20 : 
			if (  dynamic_cast<CCircle* > ( PickedOne) &&  (PickedOne->GetGfxInfo().FillClr)==ORANGE ) 
			Correct++ ; 
			else 
			False++ ; 
			break ;       
		case  21 : 
			if (  dynamic_cast<CCircle* > ( PickedOne) &&  (PickedOne->GetGfxInfo().FillClr)==RED  ) 
			Correct++ ; 
			else 
			False++ ; 
			break ;       
		case  22 : 
			if (  dynamic_cast<CCircle* > ( PickedOne) &&  (PickedOne->GetGfxInfo().FillClr)==GREEN  ) 
			Correct++ ; 
			else 
			False++ ; 
			break ;       
		case  23 : 
			if (  dynamic_cast<CCircle* > ( PickedOne) &&  (PickedOne->GetGfxInfo().FillClr)==BLUE  ) 
			Correct++ ; 
			else 
			False++ ; 
			break ;
		case  24 : 
			if (  dynamic_cast<CHexagon* > ( PickedOne) &&  (PickedOne->GetGfxInfo().FillClr)==BLACK  ) 
			Correct++ ; 
			else 
			False++ ; 
			break ;       
        case  25 : 
			if (  dynamic_cast<CHexagon* > ( PickedOne) &&  (PickedOne->GetGfxInfo().FillClr)==YELLOW) 
			Correct++ ; 
			else 
			False++ ; 
			break ;       
		case  26 : 
			if (  dynamic_cast<CHexagon* > ( PickedOne) &&  (PickedOne->GetGfxInfo().FillClr)==ORANGE ) 
			Correct++ ; 
			else 
			False++ ; 
			break ;       
		case  27 : 
			if (  dynamic_cast<CHexagon* > ( PickedOne) &&  (PickedOne->GetGfxInfo().FillClr)==RED     ) 
			Correct++ ; 
			else 
			False++ ; 
			break ;       
		case  28 : 
			if (  dynamic_cast<CHexagon* > ( PickedOne) &&  (PickedOne->GetGfxInfo().FillClr)==GREEN) 
			Correct++ ; 
			else 
			False++ ; 
			break ;
        case  29 : 
			if (  dynamic_cast<CHexagon* > ( PickedOne) &&  (PickedOne->GetGfxInfo().FillClr)==BLUE ) 
			Correct++ ; 
			else 
			False++ ; 
			break ;       
		
	}


	}while(Correct != MaxTrFigCount ) ;
	Output * pOut = pManager->GetOutput () ; 
string Print ;
Print += "Correct Picks : " + to_string(Correct)+ "    False Picks :  " + to_string(False)   ;  
pOut ->PrintMessage(Print)  ;   
pManager->UpdateInterface() ; 
}