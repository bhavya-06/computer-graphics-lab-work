#include<iostream>
#include <stdio.h> 
#include <dos.h> 
#include <graphics.h> 

void drawCircle(int xc, int yc, int x, int y) 
{ 
	putpixel(xc+x, yc+y, BLUE); 
	putpixel(xc-x, yc+y, BLUE); 
	putpixel(xc+x, yc-y, BLUE); 
	putpixel(xc-x, yc-y, BLUE); 
	putpixel(xc+y, yc+x, BLUE); 
	putpixel(xc-y, yc+x, BLUE); 
	putpixel(xc+y, yc-x, BLUE); 
	putpixel(xc-y, yc-x, BLUE); 
} 

void circleBres(int xc, int yc, int r) 
{ 
	int x = 0, y = r; 
	int d = 3 - 2 * r; 
	drawCircle(xc, yc, x, y); 
	while (y >= x) 
	{ 	
		x++; 
		
		if (d > 0) 
		{ 
			y--; 
			d = d + 4 * (x - y) + 10; 
		} 
		else
			d = d + 4 * x + 6; 
		drawCircle(xc, yc, x, y); 
		delay(50); 
	} 
} 

int main() 
{ 
	int x, y, r;
	int gd = DETECT, gm; 
	initgraph(&gd, &gm, ""); // initialize graph 
	printf("Enter radius of circle: ");
	scanf("%d",&r);

	printf("Enter co-ordinates of center(x and y): ");
	scanf("%d%d",&x,&y);
	circleBres(x, y, r); 
	
	getch();
	closegraph();
	return 0; 
} 

