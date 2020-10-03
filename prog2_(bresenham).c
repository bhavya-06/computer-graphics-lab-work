#include <bits/stdc++.h>
#include <graphics.h>
#include <math.h>

void Bresenham_algo(int x0, int y0, int x1, int y1)  
{  
    int dx, dy, p, x, y;  
    dx = x1-x0;  
    dy = y1-y0; 
	
	int slope = dy/dx;
	
	x = x0;  
    y = y0;  
    
    //take a decision parameter
    p = (2*dy-dx); 
    
	if(slope < 1){
		while(x < x1){  
	        if(p>=0)  
	        {  
	            putpixel(x,y,BLUE);  
	            y=y+1;  
	            p = p + (2*dy-2*dx);  
	        }  
	        else  
	        {  
	            putpixel(x,y,7);  
	            p = p + (2*dy);
			}  
	            x=x+1; 
				printf("( %d , %d )\n",x,y); 
        }
	} 
	else{
		//if slope >= 1
		while(x < x1){  
	        if(p>=0)  
	        {  
	            putpixel(x,y,BLUE);  
	            x=x+1;  
	            p = p + (2*dx-2*dy);  
	        }  
	        else  
	        {  
	            putpixel(x,y,7);  
	            p = p + (2*dx);
			}  
	            y=y+1;  
	        printf("( %d , %d )\n",x,y);
        }
	}
      		 
    getch();
	closegraph();
}  
int main()
{
	int x0,y0,x1,y1,x2,y2;
	int gd = DETECT, gm;
 
	initgraph( &gd, &gm, "c:\\turboc3\\bgi");
	 
    printf("Input the value of x0: ");
	scanf("%d",&x0);

	printf("Input the value of y0 : ");
	scanf("%d",&y0);

	printf("Enter the value of x1 : ");
	scanf("%d",&x1);

	printf("Input the value of y1 : ");
	scanf("%d",&y1);
	
    Bresenham_algo(x0, y0, x1, y1);
	  
    return 0;  
		
}
