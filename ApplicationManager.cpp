#include <Windows.h>
#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddSquareAction.h"
#include "Actions\AddTriAction.h"
#include "Actions\AddHexAction.h"
#include "Actions\AddCircleAction.h"
#include "Actions/SelectAction.h"
#include "Actions/ChangeDrawingColorAction.h"
#include "Actions/ChangeFillingColorAction.h"
#include "Actions/DeleteFigureAction.h"
#include "Actions/MoveFigureAction.h"
#include "Actions/UndoAction.h"
#include "Actions/RedoAction.h"
#include "Actions/ClearAllAction.h"
#include "Actions/StartRecordingAction.h"
#include "Actions/StopRecordingAction.h"
#include "Actions/PlayRecordingAction.h"
#include "Actions/SaveAction.h"
#include "Actions/LoadAction.h"
#include "Actions\SwitchToPlayAction.h"
#include "Actions\FigureTypeGame.h"
#include "Actions\ColorGame.h"
#include "Actions\FigureAndColorGame.h" 
#include "Actions\SwitchToDrawAction.h"
#include "Actions\ExitAction.h"



//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = NULL;
	pIn = NULL;


	//setting all figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++) {
		FigList[i] = NULL;
		DeletedFigList[i] = NULL;
		PickedFig[i] = NULL;
	}

	//Setting array of undo-redo operations to NULL		
	for (int i = 0; i < MaxUndoRedoCount; i++) {
		UndoRedo[i] = NULL;
	}

	//Setting array of recording operations to NULL		
	for (int i = 0; i < MaxRecordingsCount; i++) {
		Recordings[i] = NULL;
	}

	ClearAll();
}

void ApplicationManager::ClearAll(bool Play) { 
	// clear all arrays and setting all variables to 0 and pointers to NULL (behavior is dependent on play recording action)
	SelectedFig = NULL;
	UndoRedoCount = UndoRedoOrder = FigCount = DeletedFigCount = RecCount = SquCount = TriCount = CirCount = HexCount = PickedFigCount = 0;
	BlackFigCount = RedFigCount = YellowFigCount = OrangeFigCount = GreenFigCount = BlueFigCount = 0; 
	BlackRecCount = YRecCount = ORecCount = RRecCount = GRecCount = BlueRecCount = 0;
    BlackSquCount = YSquCount = OSquCount = RSquCount = GSquCount = BlueSquCount = 0; 
    BlackTriCount = YTriCount = OTriCount = RTriCount = GTriCount = BlueTriCount = 0; 
    BlackCirCount = YCirCount = OCirCount = RCirCount = GCirCount = BlueCirCount = 0; 
    BlackHexCount = YHexCount = OHexCount = RHexCount = GHexCount = BlueHexCount = 0; 
	SelectedFig->SetNextId(0);

	for (int i = 0; i < MaxUndoRedoCount; i++) {
		if (UndoRedo[i] != NULL) {
			bool FoundInRecordings = false;
			for (int j = 0; j < MaxRecordingsCount; j++) {
				if (Recordings[j] == UndoRedo[i]) {
					if (!Play) Recordings[j] = NULL;
					else FoundInRecordings |= 1;
				}
			}
			if (!Play || !FoundInRecordings) delete UndoRedo[i];
			UndoRedo[i] = NULL;
		}
	}

	if (!Play){
		for (int i = 0; i < MaxRecordingsCount; i++) {
			if (Recordings[i] != NULL) {
				delete Recordings[i];
				Recordings[i] = NULL;
			}
		}
		RecordingState = false;
		RecordingsCount = 0;
	}

	for (int i = 0; i < MaxFigCount; i++) {
		if (FigList[i] != NULL) {
			delete FigList[i];
			FigList[i] = NULL;
		}
		if (DeletedFigList[i] != NULL) {
			delete DeletedFigList[i];
			DeletedFigList[i] = NULL;
		}
		if (PickedFig[i] != NULL) {
			delete PickedFig[i];
			PickedFig[i] = NULL;
		}
	}

	if (pOut != NULL) {
		delete pOut;
	}
	pOut = new Output;

	if (pIn != NULL) {
		delete pIn;
	}

	pIn = pOut->CreateInput();
}

bool ApplicationManager::CanRecord() const { // returns true if user could record at any time, else returns false
	bool valid = true;
	valid &= (UndoRedoCount + UndoRedoOrder + FigCount + RecordingsCount == 0);
	valid &= (SelectedFig == NULL);
	for (int i = 0; i < MaxFigCount; i++) valid &= (FigList[i] == NULL);
	for (int i = 0; i < MaxRecordingsCount; i++) valid &= (Recordings[i] == NULL);
	for (int i = 0; i < MaxUndoRedoCount; i++) valid &= (UndoRedo[i] == NULL);
	return valid;
}


//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;
	DeleteAction = true;

	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case DRAW_RECT:
		pAct = new AddRectAction(this);
		break;
	case DRAW_SQUARE:
		pAct = new AddSquareAction(this);
		break;
	case DRAW_TRIANGLE:
		pAct = new AddTriAction(this);
		break;
	case DRAW_POLY:
		pAct = new AddHexAction(this);
		break;
	case DRAW_CIRCLE:
		pAct = new AddCircleAction(this);
		break;
	case SELECT:
		pAct = new SelectAction(this);
		break;
	case CHANGE_DRAWING_COLOR:
		pAct = new ChangeDrawingColorAction(this);
		break;
	case CHANGE_FILL_COLOR:
		pAct = new ChangeFillingColorAction(this);
		break;
	case ICON_DELETE:
		pAct = new DeleteFigureAction(this);
		break;
	case MOVE:
		pAct = new MoveFigureAction(this);
		break;
	case UNDO:
		pAct = new UndoAction(this);
		break;
	case REDO:
		pAct = new RedoAction(this);
		break;
	case CLEARALL:
		pAct = new ClearAllAction(this);
		break;
	case START:
		pAct = new StartRecordingAction(this);
		break;
	case STOP:
		pAct = new StopRecordingAction(this);
		break;
	case PLAY:
		pAct = new PlayRecordingAction(this);
		break;
	case SAVE:
		pAct = new SaveAction(this);
		break;
	case TO_PLAY:
		pAct =new SwitchToPlayAction (this) ; 
		break; 
	case HIDE_FIGURETYPE_ACT:
		pAct = new FigureTypeGame(this) ; 
		break ; 
	case HIDE_FILLCOLOR_ACT :
		pAct = new ColorGame(this) ; 
		break ; 
	case HIDE_BOTH_ACT : 
		pAct = new FigureAndColorGame(this) ;
		break ; 
	case TO_DRAW :
		pAct = new SwitchToDrawAction(this) ; 
		break ;
	case LOAD:
		pAct = new LoadAction(this);
		break;
	case EXIT:
		pAct = new ExitAction(this);
		break;
	case STATUS:	//a click on the status bar ==> no action
		return;
	}

	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute(); //Execute
		if(DeleteAction) delete pAct;	//You may need to change this line depending to your implementation
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig){
	if (FigCount < MaxFigCount) {
		FigList[FigCount++] = pFig;
		for (int i = 0; i < MaxFigCount; i++) {
			if (DeletedFigList[i] == pFig) {
				DeletedFigList[i] = NULL;
			}
		}
		if (pFig->IsSelected()) {
			if (SelectedFig != NULL) SelectedFig->SetSelected(false);
			SetSelectedFigure(pFig);
		}
		else SetSelectedFigure(SelectedFig);
	}
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL

	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.
	for (int i = FigCount - 1; i >= 0; i--) {
		Point P = {x, y};
		if (FigList[i] == NULL) continue; 
		if (FigList[i]->IncludesPoint(P)) {
			return FigList[i];
		}
	}
	return NULL;
}

// Delete Figure
void ApplicationManager::DeleteFigure(CFigure* Target) {
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i] == Target) {
			DeletedFigList[DeletedFigCount++] = Target;
			if (DeletedFigCount == MaxFigCount) UpdateDeletedFigList();
			FigList[i] = FigList[--FigCount];
			FigList[FigCount] = NULL;

			if (Target == SelectedFig) SetSelectedFigure(NULL);
			else SetSelectedFigure(SelectedFig);
		}
	}
}

// Update Deleted FigList when it's full
void ApplicationManager::UpdateDeletedFigList() {
	delete DeletedFigList[0];
	DeletedFigList[0] = NULL;
	for (int i = 1; i < MaxFigCount; i++) {
		DeletedFigList[i - 1] = DeletedFigList[i];
	}
	DeletedFigList[--DeletedFigCount] = NULL;
}

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	// add clear drawing area
	pOut->ClearDrawArea();

	for(int i=0; i<FigCount; i++)
	{
		 if ( FigList[i] == NULL ) 
	    continue ; 

		FigList[i]->Draw(pOut);		// Call Draw function (virtual member fn)
	}
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}


//==================================================================================//
//							Selected Figure Functions							//
//==================================================================================//

// Setter for selected figure
void ApplicationManager:: SetSelectedFigure(CFigure* Fig) {
	SelectedFig = Fig;
	if (SelectedFig != NULL) SelectedFig->PrintInfo(pOut), SelectedFig->SetSelected(true);
	else pOut->ClearStatusBar();
}

// Getter for slected figure
CFigure* ApplicationManager::GetSelectedFigure() const {
	return SelectedFig;
}


void ApplicationManager::SetDeleteAction(bool s) {
	DeleteAction &= s;
}

// Add to UndoRedo Actions Array
void ApplicationManager::AddToUndoRedo(Action* a) {
	for (int i = UndoRedoOrder; i < UndoRedoCount; i++) {
		UndoRedo[i] = NULL;
	}
	UndoRedo[UndoRedoOrder++] = a;
	UndoRedoCount = UndoRedoOrder;
}

void ApplicationManager::AddToRecordings(Action* a) {
	Recordings[RecordingsCount++] = a;
}

void ApplicationManager::PlayRecording() const {
	for (int i = 0; i < RecordingsCount; i++) {
		Sleep(1000);
		Recordings[i]->Execute(3);
		UpdateInterface();
	}
}

void ApplicationManager::UpdateUndoRedo() {
	bool FoundInRecordings = false;
	for (int i = 0; i < RecordingsCount; i++) {
		FoundInRecordings |= (Recordings[i] == UndoRedo[0]);
	}
	if (!FoundInRecordings) delete UndoRedo[0];
	UndoRedo[0] = NULL;
	for (int i = 1; i < MaxUndoRedoCount; i++) {
		UndoRedo[i - 1] = UndoRedo[i];
	}
	UndoRedoOrder = MaxUndoRedoCount - 1;
	UndoRedo[UndoRedoOrder] = NULL;
}

void ApplicationManager::SaveAll(ofstream& OutputFile) {
	for (int i = 0; i < FigCount; i++) {
		FigList[i]->Save(OutputFile);
	}
}

void ApplicationManager::Undo() {
	UndoRedo[--UndoRedoOrder]->Undo();
}

void ApplicationManager::Redo() {
	UndoRedo[UndoRedoOrder++]->Redo();
}

void ApplicationManager::SetUndoRedoOrder(int Count) {
	UndoRedoOrder = Count;
}

int ApplicationManager::GetUndoRedoOrder() const {
	return UndoRedoOrder;
}

int ApplicationManager::GetUndoRedoCount() const {
	return UndoRedoCount;
}

int ApplicationManager::GetMaxUndoRedo() const {
	return MaxUndoRedoCount;
}

void ApplicationManager::SetRecordingState(bool state) {
	RecordingState = state;
}

bool ApplicationManager::GetRecordingState() const{
	return RecordingState;
}

int ApplicationManager::GetRecordingsCount() const {
	return RecordingsCount;
}

int ApplicationManager::GetMaxRecordings() const {
	return MaxRecordingsCount;
}

int ApplicationManager::GetFigCount() const{
	return FigCount;
}

int ApplicationManager:: GetRecCount()  const 
{
	return RecCount ;  
}

int ApplicationManager:: GetSquCount()  const 
{
	return SquCount ;  
}

int ApplicationManager:: GetTriCount ()  const 
{
	return TriCount ;  
}

int ApplicationManager:: GetCirCount ()  const 
{
	return CirCount ;  
}

int ApplicationManager:: GetHexCount ()  const 
{
	return HexCount ;  
}

int ApplicationManager:: GetBlackCount ()  const 
{
	return BlackFigCount ;  
}

int ApplicationManager:: GetYellowCount ()  const 
{
	return YellowFigCount ;  
}

int ApplicationManager:: GetOrangeCount ()  const 
{
	return OrangeFigCount ;  
}

int ApplicationManager:: GetRedCount ()  const 
{
	return RedFigCount ;  
}

int ApplicationManager:: GetGreenCount ()  const 
{
	return GreenFigCount ;  
}

int ApplicationManager:: GetBlueCount ()  const 
{
	return BlueFigCount ;  
}

///////////////////////////////////////////////////////////////////////////////////
int ApplicationManager:: GetBlackRecCount ()  const 
{
	return BlackRecCount ;  
}

int ApplicationManager:: GetYRecCount ()  const 
{
	return YRecCount ;  
}

int ApplicationManager:: GetORecCount ()  const 
{
	return ORecCount ;  
}

int ApplicationManager:: GetRRecCount ()  const 
{
	return RRecCount ;  
}

int ApplicationManager:: GetGRecCount ()  const 
{
	return GRecCount ;  
}

int ApplicationManager:: GetBlueRecCount ()  const 
{
	return BlueRecCount ;  
} 
///////////////////////////////////////////////////////////////////////
int ApplicationManager:: GetBlackSquCount ()  const 
{
	return BlackSquCount ;  
}

int ApplicationManager:: GetYSquCount ()  const 
{
	return YSquCount ;  
}

int ApplicationManager:: GetOSquCount ()  const 
{
	return OSquCount ;  
}

int ApplicationManager:: GetRSquCount ()  const 
{
	return RSquCount ;  
}

int ApplicationManager:: GetGSquCount ()  const 
{
	return GSquCount ;  
}

int ApplicationManager:: GetBlueSquCount ()  const 
{
	return BlueSquCount ;  
} 
///////////////////////////////////////////////////////////////////////
int ApplicationManager:: GetBlackTriCount ()  const 
{
	return BlackTriCount ;  
}

int ApplicationManager:: GetYTriCount ()  const 
{
	return YTriCount ;  
}

int ApplicationManager:: GetOTriCount ()  const 
{
	return OTriCount ;  
}

int ApplicationManager:: GetRTriCount ()  const 
{
	return RTriCount ;  
}

int ApplicationManager:: GetGTriCount ()  const 
{
	return GTriCount ;  
}

int ApplicationManager:: GetBlueTriCount ()  const 
{
	return BlueTriCount ;  
} 
//////////////////////////////////////////////////////////////////////
int ApplicationManager:: GetBlackCirCount ()  const 
{
	return BlackCirCount ;  
}

int ApplicationManager:: GetYCirCount ()  const 
{
	return YCirCount ;  
}

int ApplicationManager:: GetOCirCount ()  const 
{
	return OCirCount ;  
}

int ApplicationManager:: GetRCirCount ()  const 
{
	return RCirCount ;  
}

int ApplicationManager:: GetGCirCount ()  const 
{
	return GCirCount ;  
}

int ApplicationManager:: GetBlueCirCount ()  const 
{
	return BlueCirCount ;  
} 
///////////////////////////////////////////////////////////////////
int ApplicationManager:: GetBlackHexCount ()  const 
{
	return BlackHexCount ;  
}
	
int ApplicationManager:: GetYHexCount ()  const 
{
	return YHexCount ;  
}

int ApplicationManager:: GetOHexCount ()  const 
{
	return OHexCount ;  
}

int ApplicationManager:: GetRHexCount ()  const 
{
	return RHexCount ;  
}

int ApplicationManager:: GetGHexCount ()  const 
{
	return GHexCount ;  
}

int ApplicationManager:: GetBlueHexCount ()  const 
{
	return BlueHexCount ;  
} 
//////////////////////////////////////////////////////////////////////////


void ApplicationManager:: TypeCounter() 
{   
	for(int i=0 ; i < FigCount ; i++ )  
	{
	if ( dynamic_cast<CCircle * > (FigList[i] ) )	
	{	
		CirCount++ ;
	if(FigList[i]->GetGfxInfo().FillClr == BLACK ) 
		BlackCirCount ++ ;
	if(FigList[i]->GetGfxInfo().FillClr == YELLOW ) 
		YCirCount ++ ;
    if(FigList[i]->GetGfxInfo().FillClr == RED ) 
		RCirCount ++ ;
	if(FigList[i]->GetGfxInfo().FillClr == ORANGE ) 
		OCirCount ++ ;
	if(FigList[i]->GetGfxInfo().FillClr == GREEN ) 
		GCirCount ++ ;
	if(FigList[i]->GetGfxInfo().FillClr == BLUE ) 
		BlueCirCount ++ ;
	}
	if (dynamic_cast<CHexagon * > (FigList[i] )) 
    {
		HexCount++ ; 
	if(FigList[i]->GetGfxInfo().FillClr == BLACK ) 
		BlackHexCount ++ ;
	if(FigList[i]->GetGfxInfo().FillClr == YELLOW ) 
		YHexCount ++ ;
    if(FigList[i]->GetGfxInfo().FillClr == RED ) 
		RHexCount ++ ;
	if(FigList[i]->GetGfxInfo().FillClr == ORANGE ) 
		OHexCount ++ ;
	if(FigList[i]->GetGfxInfo().FillClr == GREEN ) 
		GHexCount ++ ;
	if(FigList[i]->GetGfxInfo().FillClr == BLUE ) 
		BlueHexCount ++ ;
	}
	if (dynamic_cast<CSquare * > (FigList[i] ) )
	{
		SquCount++ ;
	if(FigList[i]->GetGfxInfo().FillClr == BLACK ) 
		BlackSquCount ++ ;
	if(FigList[i]->GetGfxInfo().FillClr == YELLOW ) 
		YSquCount ++ ;
    if(FigList[i]->GetGfxInfo().FillClr == RED ) 
		RSquCount ++ ;
	if(FigList[i]->GetGfxInfo().FillClr == ORANGE ) 
		OSquCount ++ ;
	if(FigList[i]->GetGfxInfo().FillClr == GREEN ) 
		GSquCount ++ ;
	if(FigList[i]->GetGfxInfo().FillClr == BLUE ) 
		BlueSquCount ++ ;
	}
	if (dynamic_cast<CRectangle * > (FigList[i] ) )
	{	
		RecCount++ ;
    if(FigList[i]->GetGfxInfo().FillClr == BLACK ) 
		BlackRecCount ++ ;
	if(FigList[i]->GetGfxInfo().FillClr == YELLOW ) 
		YRecCount ++ ;
    if(FigList[i]->GetGfxInfo().FillClr == RED ) 
		RRecCount ++ ;
	if(FigList[i]->GetGfxInfo().FillClr == ORANGE ) 
		ORecCount ++ ;
	if(FigList[i]->GetGfxInfo().FillClr == GREEN ) 
		GRecCount ++ ;
	if(FigList[i]->GetGfxInfo().FillClr == BLUE ) 
		BlueRecCount ++ ;
	}
    if ( dynamic_cast<CTriangle * > (FigList[i] ) 	)
	{
		TriCount++ ;
	if(FigList[i]->GetGfxInfo().FillClr == BLACK ) 
		BlackTriCount ++ ;
	if(FigList[i]->GetGfxInfo().FillClr == YELLOW ) 
		YTriCount ++ ;
    if(FigList[i]->GetGfxInfo().FillClr == RED ) 
		RTriCount ++ ;
	if(FigList[i]->GetGfxInfo().FillClr == ORANGE ) 
		OTriCount ++ ;
	if(FigList[i]->GetGfxInfo().FillClr == GREEN ) 
		GTriCount ++ ;
	if(FigList[i]->GetGfxInfo().FillClr == BLUE ) 
		BlueTriCount ++ ;
	}
	if((FigList[i] ->GetGfxInfo()).isFilled )
	{ 
		color temp =  (FigList[i] ->GetGfxInfo()).FillClr  ; 
		if ( temp == RED ) 
			RedFigCount++ ; 
		if ( temp == GREEN ) 
			GreenFigCount++ ; 
		if ( temp == YELLOW ) 
			YellowFigCount++ ; 
		if ( temp == ORANGE ) 
			OrangeFigCount++ ; 
		if ( temp == BLUE ) 
			BlueFigCount++ ; 
		if ( temp == BLACK ) 
			BlackFigCount++ ; 
	}
	}
}

void ApplicationManager::  SetPickedFig (CFigure *  pf)
{
	PickedFig[PickedFigCount++]= pf ;
		for ( int i =0 ; i < FigCount ; i++ ) 
	{
		if ( FigList[i] == pf ) 
		{
			FigList[i]=NULL ; 
		}
	}



}


void ApplicationManager:: ReturnAftGame () 
{  for ( int j=0 ; j < PickedFigCount ;) 
	for ( int i = 0; i < FigCount    ; i ++ ) 
	{
		if ( FigList[i] == NULL )
		{
			if(PickedFig[j]->GetID()==IDChecker[i]) 
			{	FigList[i] = PickedFig[j]  ;
		        PickedFig[j]=NULL ;
          		j++ ; 
        		
			}
		}

	}
	PickedFigCount=0 ; 
}  


void ApplicationManager:: setIDChecker () 
{
	for( int i =0 ; i < FigCount ; i ++ ) 
		IDChecker[i] = FigList[i]->GetID() ; 
}
