#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 2000;
	UI.height = 650;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 50;
	
	UI.DrawColor = BLUE;	//Drawing color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.FillColor = UI.BkGrndColor;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames
	UI.Filled = false;

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearToolBar() const
{
 //Clear Status bar by drawing a filled white rectangle
 pWind->SetPen(UI.BkGrndColor, 1);
 pWind->SetBrush(WHITE);
 pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);

}
/////////////////////////////////////////////////////////////////////////////////////////


void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_SQUARE] = "images\\MenuItems\\Menu_square.jpg";
	MenuItemImages[ITM_TRIANGLE] = "images\\MenuItems\\Menu_triangle.jpg";
	MenuItemImages[ITM_HEXAGON] = "images\\MenuItems\\Menu_hexa.jpg";
	MenuItemImages[ITM_CIRCLE] = "images\\MenuItems\\Menu_circle.jpg";
    MenuItemImages[ITM_SELECT] = "images\\MenuItems\\select.jpg";
	MenuItemImages[ITM_DRAWINGCOLOR] = "images\\MenuItems\\drawing color .jpg";
	MenuItemImages[ITM_FILLCOLOR] = "images\\MenuItems\\fiil_color.jpg";
	MenuItemImages[ITM_BLACK] = "images\\MenuItems\\black.jpg";
	MenuItemImages[ITM_RED] = "images\\MenuItems\\red.jpg";
	MenuItemImages[ITM_YELLOW] = "images\\MenuItems\\yellow.jpg";
	MenuItemImages[ITM_ORANGE] = "images\\MenuItems\\orange.jpg";
	MenuItemImages[ITM_BLUE] = "images\\MenuItems\\blue.jpg";
	MenuItemImages[ITM_GREEN] = "images\\MenuItems\\green.jpg";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\delete.jpg";
	MenuItemImages[ITM_MOVE] = "images\\MenuItems\\move.jpg";
	MenuItemImages[ITM_UNDO] = "images\\MenuItems\\undo.jpg";
	MenuItemImages[ITM_REDO] = "images\\MenuItems\\redo.jpg";
	MenuItemImages[ITM_CLEARALL] = "images\\MenuItems\\clearall.jpg";
	MenuItemImages[ITM_STARTREC] = "images\\MenuItems\\start.jpg";
	MenuItemImages[ITM_STOPREC] = "images\\MenuItems\\stop.jpg";
	MenuItemImages[ITM_PLAY] = "images\\MenuItems\\play.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\load.jpg";
	MenuItemImages[ITM_SWITCHTOPLAYMODE] = "images\\MenuItems\\switch.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";
	
	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{   ClearToolBar() ;
	UI.InterfaceMode = MODE_PLAY;
	string menu2itemimage [PLAY_ITM_COUNT] ; 
	menu2itemimage[HIDE_FIGURETYPE]="images\\MenuItems\\figuretype.jpg";
	menu2itemimage[HIDE_FILLCOLOR]="images\\MenuItems\\fillcolor.jpg";
	menu2itemimage[HIDE_BOTH]="images\\MenuItems\\figure and fill.jpg";
	menu2itemimage[SWITCHTODRAWMODE]="images\\MenuItems\\switch.jpg";

for(int i=0; i<PLAY_ITM_COUNT; i++)
		pWind->DrawImage(menu2itemimage[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::setFilled(bool isFilled) {
	UI.Filled = isFilled;
}

bool Output::getFilled() const {
	return UI.Filled;
}
	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

void Output::setCrntDrawColor(color c) { // set current drawing color
	UI.DrawColor = c;
}

void Output::setCrntFillColor(color c) { // set current filling color
	UI.FillColor = c;
} 
//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	
}

void Output:: Drawtriangle(Point p1 , Point p2 , Point p3 ,GfxInfo triGfxinfo , bool selected  ) const 
{
 color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = triGfxinfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (triGfxinfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(triGfxinfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawTriangle(p1.x, p1.y, p2.x, p2.y,p3.x,p3.y ,  style) ; 
}
void Output :: Drawcircle(Point p1, Point p2, GfxInfo circleGfxInfo, bool selected ) const 
{
	 color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = circleGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (circleGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(circleGfxInfo.FillClr);
	}
	else	
		style = FRAME;
	int r = sqrt((p1.y-p2.y)*(p1.y-p2.y)+(p1.x-p2.x)*(p1.x-p2.x)); 
	pWind->DrawCircle(p1.x, p1.y, r,  style) ; 
}
void Output::DrawRect(Point P1, GfxInfo RectGfxInfo, bool selected) const
{
	 int length = 100;
	 Point P2;
	 P2.x = P1.x + length;
	 P2.y = P1.y + length;
	 P1.x -= length;
	 P1.y-= length;
	 DrawRect(P1, P2, RectGfxInfo, selected);
}


void Output::DrawHexagon(Point P1, GfxInfo HexagonGfxInfo, bool selected) const{
	 int length = 100;
	 int height = (int) (0.87 * length);
	 int Xvals[6], Yvals[6];
	 Xvals[0] = P1.x + length, Yvals[0] = P1.y;
	 Xvals[1] = P1.x + length/2, Yvals[1] = P1.y - height;
	 Xvals[2] = P1.x - length/2, Yvals[2] = P1.y - height;
	 Xvals[3] = P1.x - length, Yvals[3] = P1.y;
	 Xvals[4] = P1.x - length/2, Yvals[4] = P1.y + height;
	 Xvals[5] = P1.x + length/2, Yvals[5] = P1.y + height;


	 color DrawingClr;
	 if(selected) 
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	 else   
		DrawingClr = HexagonGfxInfo.DrawClr;
 
	 pWind->SetPen(DrawingClr,1);
	 drawstyle style;
	 if (HexagonGfxInfo.isFilled) {
		  style = FILLED;  
		  pWind->SetBrush(HexagonGfxInfo.FillClr);
	 }
	 else 
		 style = FRAME;

	 pWind->DrawPolygon(Xvals, Yvals, 6, style);

}




//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

