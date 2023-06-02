#include"CHexagon.h"

CHexagon::CHexagon(Point c,GfxInfo HexGfxInfo  ): CFigure(HexGfxInfo) 
{
	Center = c;
}

void CHexagon :: Draw (Output * pOut )const 
{
	pOut ->DrawHexagon(Center, FigGfxInfo, Selected) ; 
}

bool CHexagon:: IncludesPoint(Point P) const {
	if (abs(P.x-Center.x) <= 50){
		return abs(P.y - Center.y) <= 87;
	}
	else if (abs(P.x - Center.x) <= 100) {
		int base = (P.x >= Center.x ? Center.x + 100 - P.x : P.x - (Center.x - 100));
		int maxHeight = (int)(1.73 * base * 1.0);
		return abs(P.y - Center.y) <= maxHeight;
	}
	return false;
}

void CHexagon::PrintInfo(Output* pOut) const {
	string s = "Figure ID: " + to_string(ID) + ". Figure Type: Hexagon. " + "Center is (" + to_string(Center.x) +
		", " + to_string(Center.y) + "). Circumradius is 100. Inradius is 87" + "." + "\0";
	pOut->PrintMessage(s);
}

void CHexagon::MoveFigure(Point DestinationPoint) {
	Center = DestinationPoint;
}

Point CHexagon::GetCenter() const {
	return Center;
}


void CHexagon::Save(ofstream& OutputFile) const {
	if (OutputFile.is_open()) {
		OutputFile << "HEXA" << '\t' << ID << '\t' << Center.x << "\t" << Center.y << '\t' <<
			UI.GetColorName(GetDrawingColor()) << '\t' << UI.GetColorName(GetFillColor()) << endl;
	}
}

void CHexagon::Load(ifstream& InputFile) {
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