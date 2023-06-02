#pragma once 
#include"Action.h"

class SaveAction : public Action {
private:
	Output* pOut;
	Input* pIn;
	ofstream OutputFile;
	string FileName;
public:
	SaveAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(int input = 1);
	virtual ~SaveAction() {}
};
