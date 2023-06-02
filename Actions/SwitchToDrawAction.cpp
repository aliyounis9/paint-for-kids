#include "SwitchToDrawAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h" 


SwitchToDrawAction :: 	SwitchToDrawAction ( ApplicationManager * pApp )   : Action(pApp) 
{
}



	void  SwitchToDrawAction :: ReadActionParameters() 
	{	
	

	}
	
    void SwitchToDrawAction :: Execute(int input ) 
	{
		ReadActionParameters() ; 
    	Output* pOut = pManager->GetOutput(); 
		pOut ->ClearStatusBar() ; 
		pManager->ReturnAftGame();
		pManager->UpdateInterface();
	    pOut->CreateDrawToolBar() ;
	}