#pragma once 
#include"Action.h"

class StopRecordingAction : public Action {
private:
	bool IsRecording;
public:
	StopRecordingAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(int input = 1);
	virtual ~StopRecordingAction() {}
};
