#include "ExitAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h" 


ExitAction::ExitAction(ApplicationManager* pApp) : Action(pApp) {}


void ExitAction::ReadActionParameters(){
}

void ExitAction::Execute(int input) {
	pManager->ClearAll();
}
