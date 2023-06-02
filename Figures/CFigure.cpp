#include "CFigure.h"
#include "../Actions/Action.h"

int CFigure::NextID = 0;

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	SetID(++NextID);
}

CFigure::CFigure() {
	Selected = false;
}

void CFigure::SetSelected(bool s){
	Selected = s; 
}

bool CFigure::IsSelected() const{
	return Selected; 
}

void CFigure::ChngDrawClr(color Dclr){
	FigGfxInfo.DrawClr = Dclr; 
}

void CFigure::ChngFillClr(bool state, color Fclr){
	if (Fclr == UI.BkGrndColor) FigGfxInfo.isFilled = false;
	else FigGfxInfo.isFilled = state;
	FigGfxInfo.FillClr = Fclr; 
}

void CFigure::SetID(int id) {
	ID = id;
}

int CFigure::GetID() const{
	return ID;
}

color CFigure::GetDrawingColor() const{
	return FigGfxInfo.DrawClr;
}

color CFigure::GetFillColor() const{
	if (!FigGfxInfo.isFilled) return UI.BkGrndColor;
	return FigGfxInfo.FillClr;
}

GfxInfo CFigure::GetGfxInfo() const {
	return FigGfxInfo;
}

void CFigure::SetNextId(int id) {
	NextID = id;
}
