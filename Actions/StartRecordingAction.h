#pragma once 
#include"Action.h"

class StartRecordingAction : public Action {
private:
	bool CanRecord;
public:
	StartRecordingAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(int input = 1);
	virtual ~StartRecordingAction() {}
};
