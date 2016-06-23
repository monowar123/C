//#include<stdio.h>
//#include<conio.h>
//#include<graphics.h>
//#include<dos.h>
//#include<stdlib.h>

void music ();
void front_page()
{
	setfillstyle(1,9);
	floodfill(10,10,getmaxcolor());
	settextstyle(1,0,5);
	setcolor(14);
	outtextxy(100,20,"EXCEL SPREAD SHEET");

	delay(1000);
	settextstyle(7,0,1);
	setcolor(5);
	outtextxy(130,90,"1. MD. MONOWARUL ISLAM");
	delay(100);
	outtextxy(130,110,"2. MD. NASIR UDDIN");
	delay(100);
	outtextxy(130,130,"3. TANVIR ZAHAN TANIN");
	delay(100);

	setcolor(14);
	settextstyle(4,0,3);
	outtextxy(150,150,"Special thank's to...... ");
	settextstyle(7,0,1);
	outtextxy(160,180,"HONOURABLE TEACHER");
	outtextxy(160,200,"MD. RASHADUL HASAN RAKIB");

	music ();

	setfillstyle(1,5);
	floodfill(10,10,getmaxcolor());
	settextstyle(1,0,3);
	setcolor(3);
	outtextxy(150,220,"LOADING ......................");
	rectangle(150,250,383,250);
	settextstyle(1,0,3);
	setcolor(14);
	outtextxy(150,250,"Please,Wait..................");
	setcolor(4);
	for(int a=150;a<=383;a++)
	{
		line(a,250,a,250);
		delay(10);
	}
	delay(10);
	//settextstyle(0,0,0);
	//setcolor(0);
	//setfillstyle(1,0);
	//bar3d(0,0,639,479,0,0);
}
void music ()
{
	float ss[7]={639,509,680,572,429,458,764};
	int m, j ,i=16;
	while ( !kbhit() )
	{
		setcolor(i--);
		gotoxy(20,25);
		if(i%2==0)
			gotoxy(21,25);
		settextstyle(4,0,4);
		outtextxy(100,350,"Press any key to continue... ");
		m = random ( 7 );
		sound ( ss[m] * 4 );
		delay ( 100 );
	}
	nosound();
}
/*void main()
{
	clrscr();
	int gmode,gd=DETECT;
	initgraph(&gd, &gmode, "c:\\tc\\bgi");
	front_page();
	getch();
} */