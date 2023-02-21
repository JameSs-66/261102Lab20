#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect *Rec1, Rect *Rec2){
	double xLength = 0,yLength = 0, start = 0, end = 0;

	if(Rec1->x + Rec1->w <= Rec2->x || Rec2->x + Rec2->w <= Rec1->x) return 0;
	if(Rec1->y - Rec1->h >= Rec2->y || Rec2->y - Rec2->h >= Rec1->y) return 0;
	if(Rec1->x > Rec2->x) start = Rec1->x;
	else start = Rec2->x;
	if(Rec1->x + Rec1->w < Rec2->x + Rec2->w) end = Rec1->x + Rec1->w;
	else end = Rec2->x + Rec2->w; 
	xLength = start - end;
	start = 0; 
	end = 0;
	if(Rec1->y < Rec2->y) start = Rec1->y;
	else start = Rec2->y;
	if(Rec1->y - Rec1->h > Rec2->y - Rec2->h) end = Rec1->y - Rec1->h;
	else end = Rec2->y - Rec2->h; 
	yLength = start - end;
	return abs(xLength * yLength);
}
