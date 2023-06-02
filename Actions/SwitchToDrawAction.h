#pragma once 

#include "Action.h"


class SwitchToDrawAction : public Action 
{
public :
	
	SwitchToDrawAction ( ApplicationManager * pApp )   ;
	virtual void  ReadActionParameters() ;
	virtual void  Execute( int input = 1);
	virtual ~SwitchToDrawAction() {}

};