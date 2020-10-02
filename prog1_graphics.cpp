#include <bits/stdc++.h>
#include <graphics.h>
#include <math.h>

int main()
{
	float x,y,x1,y1,x2,y2;
	int gd = DETECT, gm;

	initgraph( &gd, &gm, "c:\\turboc3\\bgi");

	printf("Input the value of x1: ");
	scanf("%f",&x1);

	printf("Input the value of y1 : ");
	scanf("%f",&y1);

	printf("Enter the value of x2 : ");
	scanf("%f",&x2);

	printf("Input the value of y2 : ");
	scanf("%f",&y2);


	float dx = (x2 - x1);
	float dy = (y2 - y1);

 	float parameter_steps;

	if(abs(dx) >= abs(dy) )
		parameter_steps = abs(dx);
	else
		parameter_steps = abs(dy);

	float Xinc = dx/(float)parameter_steps;
	float Yinc = dy/(float)parameter_steps;

	x = x1;
	y = y1;

	int no = 1;

	while(no <= parameter_steps)
	{
		putpixel(x,y,BLUE);
		x = x + Xinc;
		y = y + Yinc;
		no = no + 1;
		delay(100);
	}

 	getch();
	closegraph();
}
