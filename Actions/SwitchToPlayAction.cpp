#include "SwitchToPlayAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h" 


SwitchToPlayAction::SwitchToPlayAction(ApplicationManager* pApp) : Action(pApp) {}




void  SwitchToPlayAction :: ReadActionParameters() 
{	
	pManager->TypeCounter() ;
	pManager->setIDChecker() ; 
}
	
void SwitchToPlayAction :: Execute(int input ) 
{
	if (!pManager->GetRecordingState()) {
		ReadActionParameters();
		Output* pOut = pManager->GetOutput();
		pOut->ClearStatusBar();
		pOut->CreatePlayToolBar();
	}
	else {
		pManager->GetOutput()->PrintMessage("You cannot switch to play mode while recording. Please stop the recording first.");
	}

}