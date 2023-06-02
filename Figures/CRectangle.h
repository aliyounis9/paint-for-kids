#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
public:
	CRectangle(Point, Point, GfxInfo FigureGfxInfo);
	CRectangle() {}
	virtual void Draw(Output* pOut) const;
	virtual bool IncludesPoint(Point P) const;
	int GetLength() const;
	int GetWidth() const;
	virtual void PrintInfo(Output* pOut) const;
	virtual Point GetCenter() const;
	virtual void MoveFigure(Point DestinationPoint);
	virtual void Save(ofstream& OutputFile) const;
	virtual void Load(ifstream& InputFile);
	virtual ~CRectangle() {}
};

#endif