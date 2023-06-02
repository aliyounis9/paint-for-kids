#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

bool CRectangle::IncludesPoint(Point P) const {
	return P.x >= min(Corner1.x, Corner2.x) && P.x <= max(Corner1.x, Corner2.x) && 
		P.y >= min(Corner1.y, Corner2.y) && P.y <= max(Corner1.y, Corner2.y);
}

int CRectangle::GetLength() const {
	return max(abs(Corner1.x - Corner2.x), abs(Corner1.y-Corner2.y));
}

int CRectangle::GetWidth() const {
	return min(abs(Corner1.x - Corner2.x), abs(Corner1.y - Corner2.y));
}

void CRectangle::PrintInfo(Output* pOut) const {
	string s = "Figure ID: " + to_string(ID) + ". Figure Type: Rectangle. " + "Starting Point: (" + to_string(Corner1.x) +
		", " + to_string(Corner1.y) + "). Ending Point: (" + to_string(Corner2.x) + ", " + to_string(Corner2.y) + "). Width: " 
		+ to_string(GetWidth()) + ". Height: " + to_string(GetLength()) + "." + "\0";
	pOut->PrintMessage(s);
}


Point CRectangle::GetCenter() const {
	Point C = { (Corner1.x + Corner2.x) >> 1, (Corner1.y + Corner2.y) >> 1 };
	return C;
}

void CRectangle::MoveFigure(Point NewDestination) {
	Point Center = GetCenter();
	Point newCorner1 = { Corner1.x + NewDestination.x - Center.x, Corner1.y + NewDestination.y - Center.y };
	Point newCorner2 = { Corner2.x + NewDestination.x - Center.x, Corner2.y + NewDestination.y - Center.y };
	Corner1 = newCorner1;
	Corner2 = newCorner2;
}


void CRectangle::Save(ofstream& OutputFile) const {
	if (OutputFile.is_open()) {
		OutputFile << "RECT" << '\t' << ID << '\t' << Corner1.x << "\t" << Corner1.y << '\t' << Corner2.x << '\t' <<
			Corner2.y<<'\t'<<UI.GetColorName(GetDrawingColor()) << '\t' << UI.GetColorName(GetFillColor()) << endl;
	}
}

void CRectangle::Load(ifstream& InputFile) {
	if (InputFile.is_open()) {
		int id, Corner1_x, Corner1_y, Corner2_x, Corner2_y;
		string DrawingColor, FillColor;
		InputFile >> id >> Corner1_x >> Corner1_y >> Corner2_x >> Corner2_y >>DrawingColor >> FillColor;
		ID = id;
		Corner1.x = Corner1_x;
		Corner1.y = Corner1_y;
		Corner2.x = Corner2_x;
		Corner2.y = Corner2_y;
		ChngDrawClr(UI.GetColor(DrawingColor));
		ChngFillClr(true, UI.GetColor(FillColor));
	}
}