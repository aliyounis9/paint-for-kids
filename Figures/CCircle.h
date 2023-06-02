#pragma once 
#include "CFigure.h"

class  CCircle : public CFigure 
{
private:
	Point Center ; 
	Point On_Radius;
public :
	CCircle( Point , Point , GfxInfo) ;
	CCircle() {}
	virtual void Draw ( Output * pOut ) const;
	virtual bool IncludesPoint(Point P) const;
	int GetRadius() const;
	virtual void PrintInfo(Output* pOut) const;
	virtual void MoveFigure(Point DestinationPoint);
	virtual Point GetCenter() const;
	virtual void Save(ofstream& OutputFile) const;
	virtual void Load(ifstream& InputFile);
	virtual ~CCircle() {}
};
