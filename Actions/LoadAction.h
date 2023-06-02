#pragma once 
#include"Action.h"

class LoadAction : public Action {
private:
	Output* pOut;
	Input* pIn;
	ifstream InputFile;
	string FileName;
public:
	LoadAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(int input = 1);
	virtual ~LoadAction() {}
};
