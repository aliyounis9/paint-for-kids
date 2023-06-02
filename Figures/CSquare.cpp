#include "CSquare.h" 

CSquare :: CSquare(Point c , GfxInfo SquareGfxInfo ) :CFigure(SquareGfxInfo) 
{
	Center = c ;
}


void CSquare :: Draw(Output * pOut ) const
{
	pOut->DrawRect(Center,FigGfxInfo,Selected) ; 

}

bool CSquare::IncludesPoint(Point P) const {
	return abs(P.x - Center.x) <= 100 && abs(P.y - Center.y) <= 100;
}

void CSquare::PrintInfo(Output* pOut) const {
	string s = "Figure ID: " + to_string(ID) + ". Figure Type: Square. " + "Starting Point: (" + to_string(Center.x - 100) +
		", " + to_string(Center.y - 100) + "). Ending Point: (" + to_string(Center.x + 100) + ", " + to_string(Center.y + 100) +
		"). Side Length: 200." + "\0";
	pOut->PrintMessage(s);
}

void CSquare::MoveFigure(Point DestinationPoint) {
	Center = DestinationPoint;
}

Point CSquare::GetCenter() const {
	return Center;
}


void CSquare::Save(ofstream& OutputFile) const {
	if (OutputFile.is_open()) {
		OutputFile << "SQU" << '\t' << ID << '\t' << Center.x << "\t" << Center.y << '\t' <<
			UI.GetColorName(GetDrawingColor()) << '\t' << UI.GetColorName(GetFillColor()) << endl;
	}
}

void CSquare::Load(ifstream& InputFile) {
	if (InputFile.is_open()) {
		int id, Center_x, Center_y;
		string DrawingColor, FillColor;
		InputFile >> id >> Center_x >> Center_y >> DrawingColor >> FillColor;
		ID = id;
		Center.x = Center_x;
		Center.y = Center_y;
		ChngDrawClr(UI.GetColor(DrawingColor));
		ChngFillClr(true, UI.GetColor(FillColor));
	}
}