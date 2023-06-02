#pragma once 
#include "CFigure.h"

class CTriangle:public CFigure  
{
private:
   Point P1; 
   Point P2; 
   Point P3;
   int Lengths[3];
public: 
	CTriangle(Point,Point,Point,GfxInfo) ; 
	CTriangle() {}
	virtual void Draw (Output * pOut ) const ; 
	float getArea(Point X, Point Y, Point Z) const;
	void SetSideLengths();
	int GetLength(Point A, Point B) const;
	virtual bool IncludesPoint(Point P) const;
	virtual void PrintInfo(Output* pOut) const;
	virtual Point GetCenter() const;
	virtual void MoveFigure(Point DestinationPoint);
	virtual void Save(ofstream& OutputFile) const;
	virtual void Load(ifstream& InputFile);
	virtual ~CTriangle() {}
};