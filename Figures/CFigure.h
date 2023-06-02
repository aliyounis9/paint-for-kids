#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"
#include <fstream>

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info

	/// Add more parameters if needed.
	static int NextID;
public:
	CFigure(GfxInfo FigureGfxInfo);
	CFigure();

	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	void SetNextId(int id);

	virtual void Draw(Output* pOut) const = 0;		//Draw the figure

	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(bool state, color Fclr);	//changes the figure's filling color

	int GetID() const;
	void SetID(int id);
	GfxInfo GetGfxInfo() const;
	color GetDrawingColor() const;
	color GetFillColor() const;


	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	
	virtual bool IncludesPoint(Point P) const = 0;

	//virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	//virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	virtual void PrintInfo(Output* pOut) const = 0;	//print all figure info on the status bar
	virtual void MoveFigure(Point DestinationPoint) = 0;
	virtual Point GetCenter() const = 0;
	virtual void Save(ofstream& OutputFile) const = 0;
	virtual void Load(ifstream& InputFile) = 0;
	virtual ~CFigure(){}
};

#endif