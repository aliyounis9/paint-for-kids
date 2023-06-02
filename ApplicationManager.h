#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
// "Actions/Action.h"
#include "Figures/CRectangle.h"
#include "Figures/CSquare.h"
#include "Figures/CCircle.h"
#include "Figures/CHexagon.h"
#include "Figures/CTriangle.h"


class Action;
//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200, MaxUndoRedoCount = 5, MaxRecordingsCount = 20};	//Max no of figures

private:
	int FigCount;		//Actual number of figures

	int DeletedFigCount;
	int RecCount;       
	int TriCount ;
	int HexCount ; 
	int CirCount; 
	int SquCount; 
	int BlackFigCount  ;
	int YellowFigCount;
	int OrangeFigCount ; 
	int RedFigCount ; 
	int GreenFigCount ; 
	int BlueFigCount ; 

	int BlackRecCount  ; 
	int YRecCount  ;
	int ORecCount  ;
	int RRecCount  ;
	int GRecCount  ;
	int BlueRecCount  ;

	int BlackSquCount  ;
	int YSquCount  ;
	int OSquCount  ;
	int RSquCount  ;
	int GSquCount  ;
	int BlueSquCount  ;

	int BlackTriCount  ;
	int YTriCount  ;
	int OTriCount  ;
	int RTriCount  ;
	int GTriCount  ;
	int BlueTriCount  ;

	int BlackHexCount  ;
	int YHexCount  ;
	int OHexCount  ;
	int RHexCount  ;
	int GHexCount  ;
	int BlueHexCount  ;

	int BlackCirCount  ;
	int YCirCount  ;
	int OCirCount  ;
	int RCirCount  ;
	int GCirCount  ;
	int BlueCirCount  ;

	int PickedFigCount ; 
	int IDChecker[MaxFigCount]; 
	CFigure* PickedFig[MaxFigCount] ; // List of figure picked in the play mode

	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	CFigure* DeletedFigList[MaxFigCount]; // List of deleted figures

	CFigure* SelectedFig; //Pointer to the selected figure

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

	Action* UndoRedo[MaxUndoRedoCount]; // undo and redo array
	Action* Recordings[MaxRecordingsCount]; // recordings array
	int UndoRedoCount;
	int UndoRedoOrder;
	int RecordingsCount;
	bool RecordingState;
	bool DeleteAction;
public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	void ClearAll(bool Play = false);
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	int GetFigCount() const;
	void DeleteFigure(CFigure* Target); 
	void UpdateDeletedFigList();		// update deleted figure list array when it's full

		
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	

	// -- Selected Figure Related Functions
	void SetSelectedFigure(CFigure* Fig);
	CFigure* GetSelectedFigure() const;

	// -- Undo and Redo Related functions
	void AddToUndoRedo(Action* a);
	void UpdateUndoRedo();
	void SetUndoRedoOrder(int Count);
	int GetUndoRedoOrder() const;
	int GetUndoRedoCount() const;
	int GetMaxUndoRedo() const;
	void Undo();
	void Redo();


	// -- recording related functions
	void AddToRecordings(Action* a);
	int GetRecordingsCount() const;
	int GetMaxRecordings() const;
	bool CanRecord() const;
	void SetRecordingState(bool state);
	bool GetRecordingState() const;
	void PlayRecording() const;

	// save function
	void SaveAll(ofstream& OutputFile);

	// delete action setter
	void SetDeleteAction(bool s);

	///Pick&Hide related functions 
	int  GetCirCount() const ;
	int  GetRecCount() const ;
	int  GetHexCount() const ;
	int  GetTriCount() const ;
	int  GetSquCount() const ;
	int  GetBlackCount() const ;
	int  GetYellowCount() const ;
	int  GetOrangeCount() const ;
	int  GetRedCount() const ;
	int  GetGreenCount() const ;
	int  GetBlueCount() const ;

	int  GetBlackRecCount() const ; 
	int  GetYRecCount() const ; 
    int  GetORecCount() const ; 
    int  GetRRecCount() const ; 
    int  GetGRecCount() const ; 
    int  GetBlueRecCount() const ;

	int  GetBlackSquCount() const ; 
	int  GetYSquCount() const ; 
    int  GetOSquCount() const ; 
    int  GetRSquCount() const ; 
    int  GetGSquCount() const ; 
    int  GetBlueSquCount() const ;

	int  GetBlackTriCount() const ; 
	int  GetYTriCount() const ; 
    int  GetOTriCount() const ; 
    int  GetRTriCount() const ; 
    int  GetGTriCount() const ; 
    int  GetBlueTriCount() const ;
	
	int  GetBlackCirCount() const ; 
	int  GetYCirCount() const ; 
    int  GetOCirCount() const ; 
    int  GetRCirCount() const ; 
    int  GetGCirCount() const ; 
    int  GetBlueCirCount() const ;

	int  GetBlackHexCount() const ; 
	int  GetYHexCount() const ; 
    int  GetOHexCount() const ; 
    int  GetRHexCount() const ; 
    int  GetGHexCount() const ; 
    int  GetBlueHexCount() const ; 

	void TypeCounter()  ; 
	void SetPickedFig (CFigure * ) ; 
	void ReturnAftGame () ; 
	void setIDChecker() ; 
};

#endif