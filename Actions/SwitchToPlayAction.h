#pragma once

#include "Action.h" 

class SwitchToPlayAction : public Action 
{
public : 
	SwitchToPlayAction ( ApplicationManager * pApp )   ;
	virtual void  ReadActionParameters() ;

	virtual void  Execute( int input = 1) ;
	virtual ~SwitchToPlayAction() {}
};    