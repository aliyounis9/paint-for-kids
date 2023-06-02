#include "CTriangle.h"

CTriangle :: CTriangle(Point x , Point y, Point z , GfxInfo  TriangleGfxInfo ) : CFigure(TriangleGfxInfo){
	P1 = x;
	P2 = y; 
	P3 = z; 
	SetSideLengths();
}


void CTriangle:: Draw (Output * pOut )const{
	pOut->Drawtriangle(P1 , P2 , P3 , FigGfxInfo , Selected ) ; 
}

float CTriangle::getArea(Point X, Point Y, Point Z) const {
	return abs(1.0 * (X.x * (Y.y - Z.y) + Y.x * (Z.y - X.y) + Z.x * (X.y - Y.y)) / 2.0);
}

bool CTriangle::IncludesPoint(Point P) const {
	float A = getArea(P1, P2, P3);

	float A1 = getArea(P, P2, P3);
	float A2 = getArea(P1, P, P3);
	float A3 = getArea(P1, P2, P);

	return (A == A1 + A2 + A3);
}

int CTriangle::GetLength(Point A, Point B) const{
	return (int)sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

void CTriangle::SetSideLengths() {
	Lengths[0] = GetLength(P1, P2);
	Lengths[1] = GetLength(P2, P3);
	Lengths[2] = GetLength(P1, P3);
}

void CTriangle::PrintInfo(Output* pOut) const {
	string s = "Figure ID: " + to_string(ID) + ". Figure Type: Triangle. " + "Points: (" + to_string(P1.x) +
		", " + to_string(P1.y) + "), (" + to_string(P2.x) + ", " + to_string(P2.y) + "), and (" + to_string(P3.x)
		+ ", " + to_string(P3.y) + "). " + "Side Lengths: " + to_string(Lengths[0]) + ", " + to_string(Lengths[1]) + ", and " +
		to_string(Lengths[2]) + "." + "\0";
	pOut->PrintMessage(s);
}

Point CTriangle::GetCenter() const {
	Point C;
	C.x=(P1.x + P2.x + P3.x) / 3;
	C.y=(P1.y + P2.y + P3.y) / 3 ;
	return C;
}


void CTriangle::MoveFigure(Point DestinationPoint) {
	Point Center = GetCenter();
	Point newP1 = {P1.x + DestinationPoint.x - Center.x, P1.y + DestinationPoint.y - Center.y};
	Point newP2 = { P2.x + DestinationPoint.x - Center.x, P2.y + DestinationPoint.y - Center.y };
	Point newP3 = { P3.x + DestinationPoint.x - Center.x, P3.y + DestinationPoint.y - Center.y };
	P1 = newP1, P2 = newP2, P3 = newP3;
}

void CTriangle::Save(ofstream& OutputFile) const {
	if (OutputFile.is_open()) {
		OutputFile << "TRIANG" << '\t' << ID << '\t' << P1.x << "\t" << P1.y << '\t' << P2.x << "\t" << P2.y <<
			'\t' << P3.x << "\t" << P3.y << '\t' << UI.GetColorName(GetDrawingColor()) << '\t' << UI.GetColorName(GetFillColor()) << endl;
	}
}

void CTriangle::Load(ifstream& InputFile) {
	if (InputFile.is_open()) {
		int id, p1_x, p1_y, p2_x, p2_y, p3_x, p3_y;
		string DrawingColor, FillColor;
		InputFile >> id >> p1_x >> p1_y >> p2_x >> p2_y >> p3_x >> p3_y >> DrawingColor >> FillColor;
		ID = id;
		P1.x = p1_x, P1.y = p1_y;
		P2.x = p2_x, P2.y = p2_y;
		P3.x = p3_x, P3.y = p3_y;
		ChngDrawClr(UI.GetColor(DrawingColor));
		ChngFillClr(true, UI.GetColor(FillColor));
	}
}