#pragma once 
#include "CFigure.h"

class CSquare : public CFigure 
{
private:
	Point Center ;
public :
	CSquare (Point , GfxInfo SquareGfxInfo ) ; 
	CSquare() {}
	virtual void Draw(Output * pOut ) const ; 
	virtual bool IncludesPoint(Point P) const;
	virtual void PrintInfo(Output* pOut) const;
	virtual void MoveFigure(Point DestinationPoint);
	virtual Point GetCenter() const;
	virtual void Save(ofstream& OutputFile) const;
	virtual void Load(ifstream& InputFile);
	virtual ~CSquare() {}
};