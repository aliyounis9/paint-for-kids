#ifndef ACTION_H
#define ACTION_H

#include "..\DefS.h"
#include"../ApplicationManager.h"
#include"..\GUI\UI_Info.h"
#include<fstream>

//class ApplicationManager; //forward class declaration


//Base class for all possible actions
class Action
{
protected:
	ApplicationManager *pManager;	//Actions needs AppMngr to do their job
	CFigure* F;
public:

	Action(ApplicationManager* pApp) { pManager = pApp; F = NULL; }	//constructor

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters() = 0;
	
	//Execute action (code depends on action type)
	virtual void Execute(int input = 1) = 0;
	virtual void Undo() { }
	virtual void Redo() { }
	void DoUndoRedoOperations(){ 
		if (pManager->GetUndoRedoOrder() == pManager->GetMaxUndoRedo()) {
			pManager->UpdateUndoRedo();
		}
		pManager->AddToUndoRedo(this);
		pManager->SetDeleteAction(false);
	}
	void DoRecordingOperations() {
		if (pManager->GetRecordingState()) {
			if (pManager->GetRecordingsCount() < pManager->GetMaxRecordings()) {
				pManager->AddToRecordings(this);
				pManager->SetDeleteAction(false);
			}
		}
	}
	virtual ~Action(){}
};

#endif