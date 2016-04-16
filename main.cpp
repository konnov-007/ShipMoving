#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <time.h>
#include <math.h>
const int M=800; const int N=600;

void ship (int x, int y)
{
	setcolor(5);
moveto(x, y);
lineto(x-10, y-20);
lineto(x+180, y-20);
lineto(x+170, y);
lineto(x, y);
moveto(x+30, y-20);
lineto(x+30, y-40);
lineto(x+140, y-40);
lineto(x+140, y-20);
moveto(x+120, y-40);
lineto(x+120, y-130);
lineto(x+100, y-130);
lineto(x+100, y-40);	
moveto(x-4, y-20);
lineto(x-4, y-80);
lineto(x-20, y-75);
lineto(x-4, y-66);
}


void deleteship(int x, int y)
{	setcolor(0);
moveto(x, y);
lineto(x-10, y-20);
lineto(x+180, y-20);
lineto(x+170, y);
lineto(x, y);
moveto(x+30, y-20);
lineto(x+30, y-40);
lineto(x+140, y-40);
lineto(x+140, y-20);
moveto(x+120, y-40);
lineto(x+120, y-130);
lineto(x+100, y-130);
lineto(x+100, y-40);	
moveto(x-4, y-20);
lineto(x-4, y-80);
lineto(x-20, y-75);
lineto(x-4, y-66);
}


void free(){
int dir, x, y, end, i, a, b;   
initwindow(M,N); 
x=300;y=300; 
while(!kbhit()){  
a=3;
b=3;
end=30+rand()%200; 
dir=rand()%175;
for (i=0;i<end;i++){ 
ship(x,y); 
delay(15); 
deleteship(x,y);
if (x>M-196) a=-a; if (x<24) a=-a; if (y>N-12) b=-b; if (y<136) b=-b; 
if(dir<=25)x+=a; if(dir>25&&dir<=50)x-=a; if(dir>50&&dir<=75)y-=b; if(dir>75&&dir<=100){x+=a;y+=b;} if(dir>100&&dir<=125){x-=a;y-=b;} if(dir>125&&dir<=150){x+=a;y-=b;} if(dir>150){x-=a;y+=b;}
printf("x=%d, y=%d\n", x, y); } 
} 
}

void keyb(){ 
int x, y, code;
initwindow(M, N); 
x=300;y=300; 
while(1){ 
ship(x, y); 
code=getch();
if(code==27) closegraph();  
deleteship(x,y); 
switch(code) 
{ 
case 52:if(x>24) x=x-6;break; 
case 54:if(x<M-196) x=x+6;break; 
case 56:if(y>136) y=y-6;break; 
case 50:if(y<N-12) y=y+6;break; 

case 75:if(x>24) x=x-6;break; 
case 77:if(x<M-196) x=x+6;break; 
case 72:if(y>136) y=y-6;break; 
case 80:if(y<N-12) y=y+6;break; 

}
printf("x=%d, y=%d\n", x, y); 
} 
}




int main(){ 
srand(time(NULL)); 
int select; 
printf(" 1.Randomn direction\n 2.Keyboard move\n 3.Exit\n"); 
scanf("%d", &select); 
switch(select){ 
case 1: { 
free(); 
break; 
} 
case 2: { 
keyb(); 
break; 
}  
default: break; 
} 	
	return 0;
}
