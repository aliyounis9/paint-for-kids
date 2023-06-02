#pragma once 
#include "CFigure.h"

class CHexagon  : public CFigure 
{
private:
	Point Center ; 
public :
	CHexagon(Point, GfxInfo );
	CHexagon() {}
	virtual void Draw (Output * pOut ) const;
	virtual bool IncludesPoint(Point P) const;
	virtual void PrintInfo(Output* pOut) const;
	virtual void MoveFigure(Point DestinationPoint);
	virtual Point GetCenter() const;
	virtual void Save(ofstream& OutputFile) const;
	virtual void Load(ifstream& InputFile);
	virtual ~CHexagon() {}
};