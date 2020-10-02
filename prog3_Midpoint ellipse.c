#include <bits/stdc++.h>
#include <graphics.h>

void mid_point_ellipse(int rx, int ry, int xc, int yc)
{
    float dx, dy, pk, pk1, x, y;
    x = 0;
    y = ry;
    
	// Initial decision parameter of region 1 
    pk = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;
	
	// For region 1 
    while (dx < dy)
    {
        putpixel(x + xc, y + yc, BLUE);
        putpixel(-x + xc, y + yc, BLUE);
        putpixel(x + xc, -y + yc, BLUE);
        putpixel(-x + xc, -y + yc, BLUE);

        if (pk < 0)
        {
            x++;
            dx = dx + (2 * ry * ry);
            pk1 = pk + dx + (ry * ry);
        }
        else
        {
            x++;
            y--;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            pk1 = pk + dx - dy + (ry * ry);
        }
        pk = pk1;
    }
	
	// Decision parameter of region 2 
    pk = ((ry * ry) * ((x + 0.5) * (x + 0.5))) +
			 ((rx * rx) * ((y - 1) * (y - 1))) - (rx * rx * ry * ry);
	
	// For region 2
    while (y >= 0)
    {
        putpixel(x + xc, y + yc, BLUE);
        putpixel(-x + xc, y + yc, BLUE);
        putpixel(x + xc, -y + yc, BLUE);
        putpixel(-x + xc, -y + yc, BLUE);

        if (pk > 0)
        {
            y--;
            dy = dy - (2 * rx * rx);
            pk1 = pk + (rx * rx) - dy;
        }
        else
        {
            y--;
            x++;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            pk1 = pk + dx - dy + (rx * rx);
        }
        pk = pk1;
    }
    
    getch();
	closegraph();
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "c:\\turboc3\\bgi");
    
	int rx,ry,xc,yc;
    
    printf("Input the value of minor radius: ");
	scanf("%d",&ry);

	printf("Input the value of major radius : ");
	scanf("%d",&rx);

	printf("Enter the value of centre if ellipse : ");
	scanf("%d%d",&xc,&yc);

    mid_point_ellipse(rx,ry,xc,yc);
    delay(5000);
    
    return 0;
}
