#pragma once 
#include"Action.h"

class PlayRecordingAction : public Action {
private:
	bool RecState;
	int RecCount;
public:
	PlayRecordingAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(int input = 1);
	virtual ~PlayRecordingAction() {}
};
