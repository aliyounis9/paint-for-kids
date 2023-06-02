#include"ColorGame.h" 
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h" 
#include<string>

ColorGame :: ColorGame (ApplicationManager * pApp ) : Action ( pApp ) 
{
    False=Correct=0 ;
	Output * POUT = pManager->GetOutput() ; 
	Input * PIN = pManager->GetInput() ; 
	pManager->ReturnAftGame();
	pManager->UpdateInterface();


	if(pManager->GetBlackCount() +pManager->GetYellowCount()+pManager->GetOrangeCount()+pManager->GetRedCount() + pManager->GetGreenCount() + pManager->GetBlueCount() !=0 )  
	{
	do 
	{srand(time(0)) ;        // returns integer and we wiill consider 0 coressponding to Black color and 1 coressponding to Yellow color and 2 coressponding to Orange color
	Randoumint = rand()%6 ; // and 3 coressponding to Red color  and 4 coressponding to Green Color and 5 corresponding to Blue Color   
    switch(Randoumint )
	{
		case  0 : 
			MaxTrFigCount = pManager->GetBlackCount() ; 
			if (MaxTrFigCount !=0 )
	        POUT->PrintMessage("Let's Pick Black Figures , click anywere to start ") ;
			break ; 
	   case  1 : 
			MaxTrFigCount = pManager->GetYellowCount() ; 
			if (MaxTrFigCount !=0 )
			POUT->PrintMessage("Let's Pick Yellow Figures, click anywere to start ") ;
			break ;
       case  2 : 
			MaxTrFigCount = pManager->GetOrangeCount() ; 
			if (MaxTrFigCount !=0 )
			POUT->PrintMessage("Let's Pick Orange Figures, click anywere to start ") ;
			break ;
	   case  3 : 
			MaxTrFigCount = pManager->GetRedCount() ; 
			if (MaxTrFigCount !=0 )
			POUT->PrintMessage("Let's Pick Red Figures , click anywere to start ") ;
			break ;
       case  4 : 
			MaxTrFigCount = pManager->GetGreenCount() ; 
			if (MaxTrFigCount !=0 )
			POUT->PrintMessage("Let's Pick Green Figures, click anywere to start ") ;
			break ;
	   case 5 : 
		   MaxTrFigCount = pManager->GetBlueCount() ; 
			if (MaxTrFigCount !=0 )
			POUT->PrintMessage("Let's Pick Blue Figures, click anywere to start ") ;
			break ;

	}
	}while (MaxTrFigCount == 0);
	}
	else 
	{
		POUT->PrintMessage("there isn't any colored figures , Please chanage the game  " ) ; 
        valid = 0 ; 	
	}
	if (valid !=  0 )
	{
		int x ,y ; 
	PIN->GetPointClicked(x,y ) ; 
	}
} 

void ColorGame ::  ReadActionParameters () 
{
	Input * PIN = pManager->GetInput() ; 
	Output * POUT = pManager->GetOutput() ; 
	POUT->PrintMessage("please pick fig ") ;
	PIN ->GetPointClicked(P.x,P.y) ; 


} 

void ColorGame ::  Execute (int input ) 
{
	if (valid == 0 ) 
		return ; 
do 
{
	pManager->UpdateInterface() ; 
	ReadActionParameters() ; 
    PickedOne = pManager->GetFigure(P.x,P.y) ;
	if (PickedOne==0)
		continue ; 
	pManager->SetPickedFig(PickedOne) ; 
	switch(Randoumint){
		case  0 : 
			if (   (PickedOne->GetGfxInfo().FillClr)==BLACK ) 
			Correct++ ; 
			else 
			False++ ; 
			break ; 
	   case  1 : 
		   if (  (PickedOne->GetGfxInfo().FillClr)==YELLOW ) 
			Correct++ ; 
			else 
			False++ ; 
			break ;
       case  2 : 
			if ( (PickedOne->GetGfxInfo().FillClr)==ORANGE  ) 
			Correct++ ; 
			else 
			False++ ; 
			break ;
	   case  3 : 
			if ( (PickedOne->GetGfxInfo().FillClr)==RED  ) 
			Correct++ ; 
			else 
			False++ ; 
			break ;
       case  4 : 
		   if (  (PickedOne->GetGfxInfo().FillClr)==GREEN  ) 
			Correct++ ; 
			else 
			False++ ; 
			break ;
		case  5 : 
		   if (  (PickedOne->GetGfxInfo().FillClr)==BLUE  ) 
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