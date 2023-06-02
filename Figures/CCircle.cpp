#include "CCircle.h" 

CCircle :: CCircle ( Point x ,Point y  , GfxInfo CicleGfxInfo ) : CFigure(CicleGfxInfo) {
	Center = x; 
	On_Radius = y;
}


void CCircle :: Draw (Output * pOut ) const {
	pOut->Drawcircle(Center , On_Radius , FigGfxInfo  , Selected ) ; 
}

bool CCircle::IncludesPoint(Point P) const {
	return ((P.x - Center.x) * (P.x - Center.x) + (P.y - Center.y) * (P.y - Center.y) <= GetRadius() * GetRadius());
}

int CCircle::GetRadius() const {
	return (int) sqrt((Center.y - On_Radius.y) * (Center.y - On_Radius.y) + (Center.x - On_Radius.x) * (Center.x - On_Radius.x));
}

void CCircle::PrintInfo(Output* pOut) const {
	string s = "Figure ID: " + to_string(ID) + ". Figure Type: Circle. " + "Center is (" + to_string(Center.x) +
		", " + to_string(Center.y) + "). Radius is " + to_string(GetRadius()) + "." + "\0";
	pOut->PrintMessage(s);
}

Point CCircle::GetCenter() const {
	return Center;
}

void CCircle::MoveFigure(Point NewDestination) {
	int radius = GetRadius();
	Center = NewDestination;
	Point New_On_Radius = { Center.x + radius, Center.y };
	On_Radius = New_On_Radius;
}

void CCircle::Save(ofstream& OutputFile) const {
	if (OutputFile.is_open()) {
		OutputFile << "CIRC" << '\t' << ID << '\t' << Center.x << "\t" << Center.y << '\t' << GetRadius() << '\t' <<
			UI.GetColorName(GetDrawingColor()) << '\t' << UI.GetColorName(GetFillColor()) << endl;
	}
}

void CCircle::Load(ifstream& InputFile) {
	if (InputFile.is_open()) {
		int id, Center_x, Center_y, radius;
		string DrawingColor, FillColor;
		InputFile >> id >> Center_x >> Center_y >> radius >> DrawingColor >> FillColor;
		ID = id;
		Center.x = Center_x;
		Center.y = Center_y;
		On_Radius.x = Center_x;
		On_Radius.y = Center_y + radius;
		ChngDrawClr(UI.GetColor(DrawingColor));
		ChngFillClr(true, UI.GetColor(FillColor));
	}
}