#include<iostream>
#include <stdio.h> 
#include <dos.h> 
#include <graphics.h> 
using namespace std;

void drawcircle(int x0, int y0, int radius)
{
    int x = radius;
    int y = 0;
    int err = 0;

    while (x >= y)
    {
	putpixel(x0 + x, y0 + y, BLUE);
	putpixel(x0 + y, y0 + x, BLUE);
	putpixel(x0 - y, y0 + x, BLUE);
	putpixel(x0 - x, y0 + y, BLUE);
	putpixel(x0 - x, y0 - y, BLUE);
	putpixel(x0 - y, y0 - x, BLUE);
	putpixel(x0 + y, y0 - x, BLUE);
	putpixel(x0 + x, y0 - y, BLUE);

	if (err <= 0)
	{
	    y += 1;
	    err += 2*y + 1;
	}

	if (err > 0)
	{
	    x -= 1;
	    err -= 2*x + 1;
	}
    }
}

int main()
{
	int x, y, r;
	int gd = DETECT, gm; 
	initgraph(&gd, &gm, "c:\\turboc3\\bgi"); // initialize graph 
	printf("Enter radius of circle: ");
	scanf("%d",&r);

	printf("Enter co-ordinates of center(x and y): ");
	scanf("%d%d",&x,&y);
	drawcircle(x, y, r);
	getch();

	return 0;
}
