#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
#include<time.h>
void mouse_reset();
void mouse_on();
void mouse_off();
void get_position(int *x,int *y);
int left_button_pressed();

void main_window();
void window();
void temperature();
void length();
void waight();
void area();
void volume();
void num_sys();
void trigon();
void help();
int bin_to_dec(int num);
void date_show();

void main()
{
	clrscr();
	int gdriver = DETECT, gmode;
	initgraph(&gdriver, &gmode, "c:\\tc\\bgi");

	main_window();
	date_show();
	window();

	getch();
}

void main_window()
{
	setfillstyle(1,5);
	bar(0,0,getmaxx(),getmaxy());              	//border

	setfillstyle(1,0);
	bar(5,330,getmaxx()-5,420);                	//bar4

	setfillstyle(1,3);
	bar(5,5,getmaxx()-5,50);                   	//bar1
	bar(5,302,getmaxx()-5,325);                	//bar3
	bar(5,425,getmaxx()-5,getmaxy()-5);        	//bar5

	setfillstyle(1,8);
	bar(getmaxx()-20,5,getmaxx()-5,20);        	//x:close
	bar(getmaxx()-37,5,getmaxx()-22,20); 		//maximize
	bar(getmaxx()-54,5,getmaxx()-39,20); 		//minimize
	bar(450,305,550,323);                       //clear

	setfillstyle(1,15);
	bar(getmaxx()-33,10,getmaxx()-27,15);
	setcolor(15);
	outtextxy(getmaxx()-50,9,"-");
	setcolor(4);
	outtextxy(getmaxx()-16,9,"x");

	settextstyle(0,0,3);
	setcolor(15);
	outtextxy(190,18,"CONVERTER");
	setcolor(9);
	outtextxy(188,16,"CONVERTER");

	settextstyle(0,0,2);
	setcolor(15);
	outtextxy(240,307,"OUTPUT");
	setcolor(9);
	outtextxy(238,305,"OUTPUT");
	settextstyle(7,0,2);
	setcolor(15);
	outtextxy(470,300,"Clear");

	settextstyle(7,0,2);
	setcolor(15);
	outtextxy(35,getmaxy()-53,"Md.Monowarul Islam");
	outtextxy(35,getmaxy()-30,"CE-09016");
	setcolor(9);
	outtextxy(34,getmaxy()-54,"Md.Monowarul Islam");
	outtextxy(34,getmaxy()-31,"CE-09016");
}
void window()
{
	int end=0,x,y;
	setfillstyle(1,1);
	bar(5,55,getmaxx()-5,297);                 	//bar2
	/////////////*  Button  *//////////////
	setfillstyle(1,8);
	bar(30,80,210,110);   				//tempetature
	bar(30,115,210,145);  				//length
	bar(30,150,210,180);  				//waight
	bar(30,185,210,215);  				//area
	bar(30,220,210,250);				//volume
	bar(300,80,572,110);    			//number system
	bar(300,115,572,145);   			//trigon ratios
	bar(300,150,572,180);   			//help

	settextstyle(7,0,2);
	setcolor(15);
	outtextxy(50,80,"Temperature");
	outtextxy(50,117,"Length");
	outtextxy(50,152,"Waight");
	outtextxy(50,187,"Area");
	outtextxy(50,223,"Volume");
	outtextxy(320,82,"Number System");
	outtextxy(320,117,"Trigonometrical Ratios");
	outtextxy(320,152,"Help");

	mouse_reset();
	mouse_on();

	while(!end)
	{
		if(left_button_pressed())
		{
			get_position(&x,&y);

			if(x>30&&x<210&&y>80&&y<110)
				temperature();
			if(x>30&&x<210&&y>115&&y<145)
				length();
			if(x>30&&x<210&&y>150&&y<180)
				waight();
			if(x>30&&x<210&&y>185&&y<215)
				area();
			if(x>30&&x<210&&y>220&&y<250)
				volume();
			if(x>300&&x<572&&y>80&&y<110)
				num_sys();
			if(x>300&&x<572&&y>115&&y<145)
				trigon();
			if(x>300&&x<572&&y>150&&y<180)
				help();
			if(x>450&&x<550&&y>305&&y<323)       	//clear
			{
				setfillstyle(1,0);
				bar(5,330,getmaxx()-5,420);    		//bar4
			}
			if(x>(getmaxx()-20)&&x<(getmaxx()-5)&&y>5&&y<20)
				exit(0);
		}
	}
}

void temperature()
{
	mouse_off();
	int x,y;
	setfillstyle(1,1);
	bar(5,55,getmaxx()-5,297);

	setfillstyle(1,8);
	bar(30,80,300,110);    // C to F
	bar(330,80,600,110);   // F to K
	bar(30,150,300,180);   // C to K
	bar(330,150,600,180);   // F to R
	bar(30,220,300,250);    // C to R
	bar(330,220,600,250);   // K to R
	bar(getmaxx()-80,267,getmaxx()-10,292);   //back

	settextstyle(7,0,2);
	setcolor(15);
	outtextxy(50,80,"Celcious to Fahrenheit");
	outtextxy(50,150,"Celcious to Kelvin");
	outtextxy(50,220,"Celcious to Rankine");
	outtextxy(350,80,"Fahrenheit to kelvin");
	outtextxy(350,150,"Fahrenheit to Rankine");
	outtextxy(350,220,"Kelvin to Rankine");
	outtextxy(getmaxx()-70,267,"Back");
	mouse_on();
	while(1)
	{
		if(left_button_pressed())
		{
			get_position(&x,&y);
			if(x>30&&x<300&&y>80&&y<110)     //C to F
			{   float a;
				gotoxy(3,22);
				printf("Celcious to Fahrenheit press 1");
				gotoxy(3,24);
				printf("Fahrenheit to Celcious press 2");
				char ch=getche();
				setfillstyle(1,0);
				bar(5,330,getmaxx()-5,420);    		//bar4
				switch(ch)
				{
					case '1':	gotoxy(3,22);
								printf("Input value in Celcious:");
								scanf("%f",&a);
								float f=1.8*a+32;
								gotoxy(3,24);
								printf("Value in Fahrenheit:%f",f);
								break;
					case '2': 	gotoxy(3,22);
								printf("Input value in Fahrenheit:");
								scanf("%f",&a);
								float c=(a-32)/1.8;
								gotoxy(3,24);
								printf("Value in Celcious:%f",c);
								break;
					default :   gotoxy(3,22);
								printf("Wrong selection.");
				}
			}
			if(x>30&&x<300&&y>150&&y<180)        //C to K
			{   float a;
				gotoxy(3,22);
				printf("Celcious to Kelvin press 1");
				gotoxy(3,24);
				printf("Kelvin to Celcious press 2");
				char ch=getche();
				setfillstyle(1,0);
				bar(5,330,getmaxx()-5,420);    		//bar4
				switch(ch)
				{
					case '1':	gotoxy(3,22);
								printf("Input value in Celcious:");
								scanf("%f",&a);
								float k=a+273;
								gotoxy(3,24);
								printf("Value in Kelvin:%f",k);
								break;
					case '2': 	gotoxy(3,22);
								printf("Input value in Kelvin:");
								scanf("%f",&a);
								float c=a-273;
								gotoxy(3,24);
								printf("Value in Celcious:%f",c);
								break;
					default :   gotoxy(3,22);
								printf("Wrong selection.");
				}
			}
			if(x>30&&x<300&&y>220&&y<250)      //C to  R
			{   float a;
				gotoxy(3,22);
				printf("Celcious to Rankine press 1");
				gotoxy(3,24);
				printf("Rankine to Celcious press 2");
				char ch=getche();
				setfillstyle(1,0);
				bar(5,330,getmaxx()-5,420);    		//bar4
				switch(ch)
				{
					case '1':	gotoxy(3,22);
								printf("Input value in Celcious:");
								scanf("%f",&a);
								float r=(a*1.8)+492;
								gotoxy(3,24);
								printf("Value in Rankine:%f",r);
								break;
					case '2': 	gotoxy(3,22);
								printf("Input value in Rankine:");
								scanf("%f",&a);
								float c=(a-492)/1.8;
								gotoxy(3,24);
								printf("Value in Celcious:%f",c);
								break;
					default :   gotoxy(3,22);
								printf("Wrong selection.");
				}
			}
			if(x>330&&x<600&&y>80&&y<110)         //F to K
			{   float a;
				gotoxy(3,22);
				printf("Fahrenheit to Kelvin press 1");
				gotoxy(3,24);
				printf("Kelvin to Fahrenheit press 2");
				char ch=getche();
				setfillstyle(1,0);
				bar(5,330,getmaxx()-5,420);    		//bar4
				switch(ch)
				{
					case '1':	gotoxy(3,22);
								printf("Input value in Fahrenheit:");
								scanf("%f",&a);
								float k=(a-32)/1.8+273;
								gotoxy(3,24);
								printf("Value in Kelvin:%f",k);
								break;
					case '2': 	gotoxy(3,22);
								printf("Input value in Kelvin:");
								scanf("%f",&a);
								float f=(a-273)*1.8+32;
								gotoxy(3,24);
								printf("Value in Fahrenheit:%f",f);
								break;
					default :   gotoxy(3,22);
								printf("Wrong selection.");
				}
			}
			if(x>330&&x<600&&y>150&&y<180)       //F to R
			{   float a;
				gotoxy(3,22);
				printf("Fahrenheit to Rankine press 1");
				gotoxy(3,24);
				printf("Rankine to Fahrenheit press 2");
				char ch=getche();
				setfillstyle(1,0);
				bar(5,330,getmaxx()-5,420);    		//bar4
				switch(ch)
				{
					case '1':	gotoxy(3,22);
								printf("Input value in Fahrenheit:");
								scanf("%f",&a);
								float r=a+460;
								gotoxy(3,24);
								printf("Value in Rankine:%f",r);
								break;
					case '2': 	gotoxy(3,22);
								printf("Input value in Rankine:");
								scanf("%f",&a);
								float f=a-460;
								gotoxy(3,24);
								printf("Value in Fahrenheit:%f",f);
								break;
					default :   gotoxy(3,22);
								printf("Wrong selection.");
				}
			}
			if(x>330&&x<600&&y>220&&y<250)       //K to R
			{   float a;
				gotoxy(3,22);
				printf("Kelvin to Rankine press 1");
				gotoxy(3,24);
				printf("Rankine to Kelvin press 2");
				char ch=getche();
				setfillstyle(1,0);
				bar(5,330,getmaxx()-5,420);    		//bar4
				switch(ch)
				{
					case '1':	gotoxy(3,22);
								printf("Input value in Kelvin:");
								scanf("%f",&a);
								float r=(a-273)*1.8+492;
								gotoxy(3,24);
								printf("Value in Rankine:%f",r);
								break;
					case '2': 	gotoxy(3,22);
								printf("Input value in Rankine:");
								scanf("%f",&a);
								float k=(a-492)/1.8+273;
								gotoxy(3,24);
								printf("Value in Kelvin:%f",k);
								break;
					default :   gotoxy(3,22);
								printf("Wrong selection.");
				}
			}
			if(x>(getmaxx()-80)&&y>267&&x<(getmaxx()-10)&&y<292) //back
				window();       					//back
			if(x>450&&x<550&&y>305&&y<323)       	//clear
			{
				setfillstyle(1,0);
				bar(5,330,getmaxx()-5,420);    		//bar4
			}
			if(x>(getmaxx()-20)&&x<(getmaxx()-5)&&y>5&&y<20)
				exit(0);
		}
	}
}

void length()
{
	mouse_off();
	int x,y;
	setfillstyle(1,1);
	bar(5,55,getmaxx()-5,297);

	setfillstyle(1,8);
	bar(200,65,430,95);
	bar(200,105,430,135);
	bar(200,145,430,175);
	bar(200,185,430,215);
	bar(200,225,430,255);
	bar(getmaxx()-80,267,getmaxx()-10,292);   //back

	settextstyle(7,0,2);
	setcolor(15);
	outtextxy(220,65,"Mile to Kilo-Metre");
	outtextxy(220,105,"Yard to Metre");
	outtextxy(220,145,"Foot to Metre");
	outtextxy(220,185,"Foot to Centi-Metre");
	outtextxy(217,225,"Inch to Centi-Metre");
	outtextxy(getmaxx()-70,267,"Back");
	mouse_on();
	while(1)
	{
		if(left_button_pressed())
		{
			get_position(&x,&y);
			if(x>200&&x<430&&y>65&&y<95)        //mile to km
			{   float a,b;
				gotoxy(3,22);
				printf("Mile to KM press 1");
				gotoxy(3,24);
				printf("KM to Mile press 2");
				char ch=getche();
				setfillstyle(1,0);
				bar(5,330,getmaxx()-5,420);    		//bar4
				switch(ch)
				{
					case '1':	gotoxy(3,22);
								printf("Input value in Mile:");
								scanf("%f",&a);
								b=a*1.609;
								gotoxy(3,24);
								printf("Value in KM:%f",b);
								break;
					case '2': 	gotoxy(3,22);
								printf("Input value in KM:");
								scanf("%f",&a);
								b=a*0.621504;
								gotoxy(3,24);
								printf("Value in Mile:%f",b);
								break;
					default :   gotoxy(3,22);
								printf("Wrong selection.");

				}

			}
			if(x>200&&x<430&&y>105&&y<135)     //yard to metre
			{   float a,b;
				gotoxy(3,22);
				printf("Yard to Metre press 1");
				gotoxy(3,24);
				printf("Metre to Yard press 2");
				char ch=getche();
				setfillstyle(1,0);
				bar(5,330,getmaxx()-5,420);    		//bar4
				switch(ch)
				{
					case '1':	gotoxy(3,22);
								printf("Input value in Yard:");
								scanf("%f",&a);
								b=a*.9144;
								gotoxy(3,24);
								printf("Value in Metre:%f",b);
								break;
					case '2': 	gotoxy(3,22);
								printf("Input value in Metre:");
								scanf("%f",&a);
								b=a*1.0936133;
								gotoxy(3,24);
								printf("Value in Yard:%f",b);
								break;
					default :   gotoxy(3,22);
								printf("Wrong selection.");

				}

			}
			if(x>200&&x<430&&y>145&&y<175)      //foot to metre
			{   float a,b;
				gotoxy(3,22);
				printf("Foot to metre press 1");
				gotoxy(3,24);
				printf("Metre to Foot press 2");
				char ch=getche();
				setfillstyle(1,0);
				bar(5,330,getmaxx()-5,420);    		//bar4
				switch(ch)
				{
					case '1':	gotoxy(3,22);
								printf("Input value in Foot:");
								scanf("%f",&a);
								b=a*.3048;
								gotoxy(3,24);
								printf("Value in Metre:%f",b);
								break;
					case '2': 	gotoxy(3,22);
								printf("Input value in Metre:");
								scanf("%f",&a);
								b=a*3.2808399;
								gotoxy(3,24);
								printf("Value in Foot:%f",b);
								break;
					default :   gotoxy(3,22);
								printf("Wrong selection.");

				}

			}
			if(x>200&&x<430&&y>185&&y<215)       //foot to cm
			{   float a,b;
				gotoxy(3,22);
				printf("Foot to CM press 1");
				gotoxy(3,24);
				printf("CM to Foot press 2");
				char ch=getche();
				setfillstyle(1,0);
				bar(5,330,getmaxx()-5,420);    		//bar4
				switch(ch)
				{
					case '1':	gotoxy(3,22);
								printf("Input value in Foot:");
								scanf("%f",&a);
								b=a*30.48;
								gotoxy(3,24);
								printf("Value in CM:%f",b);
								break;
					case '2': 	gotoxy(3,22);
								printf("Input value in CM:");
								scanf("%f",&a);
								b=a*.0328084;
								gotoxy(3,24);
								printf("Value in Foot:%f",b);
								break;
					default :   gotoxy(3,22);
								printf("Wrong selection.");

				}

			}
			if(x>200&&x<430&&y>225&&y<255)       //inch to cm
			{   float a,b;
				gotoxy(3,22);
				printf("Inch to CM press 1");
				gotoxy(3,24);
				printf("CM to Inch press 2");
				char ch=getche();
				setfillstyle(1,0);
				bar(5,330,getmaxx()-5,420);    		//bar4
				switch(ch)
				{
					case '1':	gotoxy(3,22);
								printf("Input value in Inch:");
								scanf("%f",&a);
								b=a*2.54;
								gotoxy(3,24);
								printf("Value in CM:%f",b);
								break;
					case '2': 	gotoxy(3,22);
								printf("Input value in CM:");
								scanf("%f",&a);
								b=a*.3937008;
								gotoxy(3,24);
								printf("Value in Inch:%f",b);
								break;
					default :   gotoxy(3,22);
								printf("Wrong selection.");

				}

			}
			if(x>(getmaxx()-80)&&y>267&&x<(getmaxx()-10)&&y<292) //back
				window();       					//back
			if(x>450&&x<550&&y>305&&y<323)       	//clear
			{
				setfillstyle(1,0);
				bar(5,330,getmaxx()-5,420);    		//bar4
			}
			if(x>(getmaxx()-20)&&x<(getmaxx()-5)&&y>5&&y<20)
				exit(0);
		}
	}
}

void waight()
{
	mouse_off();
	int x,y;
	setfillstyle(1,1);
	bar(5,55,getmaxx()-5,297);

	setfillstyle(1,8);
	bar(200,65,430,95);
	bar(200,105,430,135);
	bar(200,145,430,175);
	bar(200,185,430,215);
	bar(200,225,430,255);
	bar(getmaxx()-80,267,getmaxx()-10,292);   //back

	settextstyle(7,0,2);
	setcolor(15);
	outtextxy(220,65,"Pound to Kilo");
	outtextxy(220,105,"Carat to Gram");
	outtextxy(220,145,"Ounce to Gram");
	outtextxy(220,185,"Troy oz. to Gram");
	outtextxy(217,225,"Stone to Kilo");
	outtextxy(getmaxx()-70,267,"Back");
	mouse_on();
	while(1)
	{
		if(left_button_pressed())
		{
			get_position(&x,&y);
			if(x>200&&x<430&&y>65&&y<95)     //pound to kilo
			{   float a,b;
				gotoxy(3,22);
				printf("Pound to Kilo press 1");
				gotoxy(3,24);
				printf("Kilo to Pound press 2");
				char ch=getche();
				setfillstyle(1,0);
				bar(5,330,getmaxx()-5,420);    		//bar4
				switch(ch)
				{
					case '1':	gotoxy(3,22);
								printf("Input value in Pound:");
								scanf("%f",&a);
								b=a*.4536;
								gotoxy(3,24);
								printf("Value in Kilo:%f",b);
								break;
					case '2': 	gotoxy(3,22);
								printf("Input value in Kilo:");
								scanf("%f",&a);
								b=a*2.2045955;
								gotoxy(3,24);
								printf("Value in Pound:%f",b);
								break;
					default :   gotoxy(3,22);
								printf("Wrong selection.");
				}

			}
			if(x>200&&x<430&&y>105&&y<135)     //carat to gram
			{   float a,b;
				gotoxy(3,22);
				printf("Carat to Gram press 1");
				gotoxy(3,24);
				printf("Gram to Carat press 2");
				char ch=getche();
				setfillstyle(1,0);
				bar(5,330,getmaxx()-5,420);    		//bar4
				switch(ch)
				{
					case '1':	gotoxy(3,22);
								printf("Input value in Carat:");
								scanf("%f",&a);
								b=a*.2;
								gotoxy(3,24);
								printf("Value in Gram:%f",b);
								break;
					case '2': 	gotoxy(3,22);
								printf("Input value in Gram:");
								scanf("%f",&a);
								b=a*5;
								gotoxy(3,24);
								printf("Value in Carat:%f",b);
								break;
					default :   gotoxy(3,22);
								printf("Wrong selection.");
				}

			}
			if(x>200&&x<430&&y>145&&y<175)     //ounce to gram
			{   float a,b;
				gotoxy(3,22);
				printf("Ounce to Gram press 1");
				gotoxy(3,24);
				printf("Gram to Ounce press 2");
				char ch=getche();
				setfillstyle(1,0);
				bar(5,330,getmaxx()-5,420);    		//bar4
				switch(ch)
				{
					case '1':	gotoxy(3,22);
								printf("Input value in Ounce:");
								scanf("%f",&a);
								b=a*28.35;
								gotoxy(3,24);
								printf("Value in Gram:%f",b);
								break;
					case '2': 	gotoxy(3,22);
								printf("Input value in Gram:");
								scanf("%f",&a);
								b=a*.0352734;
								gotoxy(3,24);
								printf("Value in Ounce:%f",b);
								break;
					default :   gotoxy(3,22);
								printf("Wrong selection.");
				}

			}
			if(x>200&&x<430&&y>185&&y<215)     // troy.oz to gram
			{   float a,b;
				gotoxy(3,22);
				printf("Troy.oz to Gram press 1");
				gotoxy(3,24);
				printf("Gram to Troy.oz press 2");
				char ch=getche();
				setfillstyle(1,0);
				bar(5,330,getmaxx()-5,420);    		//bar4
				switch(ch)
				{
					case '1':	gotoxy(3,22);
								printf("Input value in Troy.oz:");
								scanf("%f",&a);
								b=a*31.103477;
								gotoxy(3,24);
								printf("Value in Gram:%f",b);
								break;
					case '2': 	gotoxy(3,22);
								printf("Input value in Gram:");
								scanf("%f",&a);
								b=a*.0321507;
								gotoxy(3,24);
								printf("Value in Troy.oz:%f",b);
								break;
					default :   gotoxy(3,22);
								printf("Wrong selection.");
				}

			}
			if(x>200&&x<430&&y>225&&y<255)     //stone to kilo
			{   float a,b;
				gotoxy(3,22);
				printf("Stone to Kilo press 1");
				gotoxy(3,24);
				printf("Kilo to Stone press 2");
				char ch=getche();
				setfillstyle(1,0);
				bar(5,330,getmaxx()-5,420);    		//bar4
				switch(ch)
				{
					case '1':	gotoxy(3,22);
								printf("Input value in Stone:");
								scanf("%f",&a);
								b=a*6.3502932;
								gotoxy(3,24);
								printf("Value in Kilo:%f",b);
								break;
					case '2': 	gotoxy(3,22);
								printf("Input value in Kilo:");
								scanf("%f",&a);
								b=a*.157473;
								gotoxy(3,24);
								printf("Value in Stone:%f",b);
								break;
					default :   gotoxy(3,22);
								printf("Wrong selection.");
				}

			}
			if(x>(getmaxx()-80)&&y>267&&x<(getmaxx()-10)&&y<292) //back
				window();       					//back
			if(x>450&&x<550&&y>305&&y<323)       	//clear
			{
				setfillstyle(1,0);
				bar(5,330,getmaxx()-5,420);    		//bar4
			}
			if(x>(getmaxx()-20)&&x<(getmaxx()-5)&&y>5&&y<20)
				exit(0);
		}
	}
}

void area()
{
	mouse_off();
	int x,y;
	setfillstyle(1,1);
	bar(5,55,getmaxx()-5,297);

	setfillstyle(1,8);
	bar(150,65,500,95);
	bar(150,105,500,135);
	bar(150,145,500,175);
	bar(150,185,500,215);
	bar(150,225,500,255);
	bar(getmaxx()-80,267,getmaxx()-10,292);   //back

	settextstyle(7,0,2);
	setcolor(15);
	outtextxy(170,65,"Square Foot to Square Metre");
	outtextxy(170,105,"Square Inch to Square CM");
	outtextxy(170,145,"Square Yard to Square Metre");
	outtextxy(170,185,"Square Milw to Square KM");
	outtextxy(170,225,"Acre to Hectare");
	outtextxy(getmaxx()-70,267,"Back");
	mouse_on();
	while(1)
	{
		if(left_button_pressed())
		{
			get_position(&x,&y);
			if(x>150&&x<500&&y>65&&y<95)    //s foot to s metre
			{   float a,b;
				gotoxy(3,22);
				printf("Square Foot to Square Metre press 1");
				gotoxy(3,24);
				printf("Square Metre to Square Foot press 2");
				char ch=getche();
				setfillstyle(1,0);
				bar(5,330,getmaxx()-5,420);    		//bar4
				switch(ch)
				{
					case '1':	gotoxy(3,22);
								printf("Input value in Square Foot:");
								scanf("%f",&a);
								b=a*.0929;
								gotoxy(3,24);
								printf("Value in Square Metre:%f",b);
								break;
					case '2': 	gotoxy(3,22);
								printf("Input value in Square Metre:");
								scanf("%f",&a);
								b=a*10.764263;
								gotoxy(3,24);
								printf("Value in Square Foot:%f",b);
								break;
					default :   gotoxy(3,22);
								printf("Wrong selection.");
				}

			}
			if(x>150&&x<500&&y>105&&y<135)    //s inch to s cm
			{   float a,b;
				gotoxy(3,22);
				printf("Square Inch to Square CM press 1");
				gotoxy(3,24);
				printf("Square CM to Square Inch press 2");
				char ch=getche();
				setfillstyle(1,0);
				bar(5,330,getmaxx()-5,420);    		//bar4
				switch(ch)
				{
					case '1':	gotoxy(3,22);
								printf("Input value in Square Inch:");
								scanf("%f",&a);
								b=a*6.4516;
								gotoxy(3,24);
								printf("Value in Square CM:%f",b);
								break;
					case '2': 	gotoxy(3,22);
								printf("Input value in Square CM:");
								scanf("%f",&a);
								gotoxy(3,24);
								b=a*.1550003;
								printf("Value in Square Inch:%f",b);
								break;
					default :   gotoxy(3,22);
								printf("Wrong selection.");
				}

			}
			if(x>150&&x<500&&y>145&&y<175)    //s yard to s metre
			{   float a,b;
				gotoxy(3,22);
				printf("Square Yard to Square Metre press 1");
				gotoxy(3,24);
				printf("Square Metre to Square Yard press 2");
				char ch=getche();
				setfillstyle(1,0);
				bar(5,330,getmaxx()-5,420);    		//bar4
				switch(ch)
				{
					case '1':	gotoxy(3,22);
								printf("Input value in Square Yard:");
								scanf("%f",&a);
								b=a*.8361274;
								gotoxy(3,24);
								printf("Value in Square Metre:%f",b);
								break;
					case '2': 	gotoxy(3,22);
								printf("Input value in Square Metre:");
								scanf("%f",&a);
								b=a*1.19599;
								gotoxy(3,24);
								printf("Value in Square Yard:%f",b);
								break;
					default :   gotoxy(3,22);
								printf("Wrong selection.");
				}

			}
			if(x>150&&x<500&&y>185&&y<215)    //s mile to s km
			{   float a,b;
				gotoxy(3,22);
				printf("Square Mile to Square KM press 1");
				gotoxy(3,24);
				printf("Square KM to Square Mile press 2");
				char ch=getche();
				setfillstyle(1,0);
				bar(5,330,getmaxx()-5,420);    		//bar4
				switch(ch)
				{
					case '1':	gotoxy(3,22);
								printf("Input value in Square Mile:");
								scanf("%f",&a);
								b=a*2.59;
								gotoxy(3,24);
								printf("Value in Square KM:%f",b);
								break;
					case '2': 	gotoxy(3,22);
								printf("Input value in Square KM:");
								scanf("%f",&a);
								b=a*.3861004;
								gotoxy(3,24);
								printf("Value in Square Mile:%f",b);
								break;
					default :   gotoxy(3,22);
								printf("Wrong selection.");
				}

			}
			if(x>150&&x<500&&y>225&&y<255)    //acre to hectare
			{   float a,b;
				gotoxy(3,22);
				printf("Acre to Hectare press 1");
				gotoxy(3,24);
				printf("Hectare to Acre press 2");
				char ch=getche();
				setfillstyle(1,0);
				bar(5,330,getmaxx()-5,420);    		//bar4
				switch(ch)
				{
					case '1':	gotoxy(3,22);
								printf("Input value in Acre:");
								scanf("%f",&a);
								b=a*.4047;
								gotoxy(3,24);
								printf("Value in Hectare:%f",b);
								break;
					case '2': 	gotoxy(3,22);
								printf("Input value in Hectare:");
								scanf("%f",&a);
								b=a*2.4709661;
								gotoxy(3,24);
								printf("Value in Acre:%f",b);
								break;
					default :   gotoxy(3,22);
								printf("Wrong selection.");
				}

			}
			if(x>(getmaxx()-80)&&y>267&&x<(getmaxx()-10)&&y<292) //back
				window();       					//back
			if(x>450&&x<550&&y>305&&y<323)       	//clear
			{
				setfillstyle(1,0);
				bar(5,330,getmaxx()-5,420);    		//bar4
			}
			if(x>(getmaxx()-20)&&x<(getmaxx()-5)&&y>5&&y<20)
				exit(0);
		}
	}
}

void volume()
{
	mouse_off();
	int x,y;
	setfillstyle(1,1);
	bar(5,55,getmaxx()-5,297);

	setfillstyle(1,8);
	bar(200,70,430,100);
	bar(200,115,430,145);
	bar(200,160,430,190);
	bar(200,205,430,235);
	bar(getmaxx()-80,267,getmaxx()-10,292);   //back

	settextstyle(7,0,2);
	setcolor(15);
	outtextxy(220,70,"V Inch to V CM");
	outtextxy(220,115,"V Foot to V Metre");
	outtextxy(220,160,"V Metre to V Yard");
	outtextxy(220,205,"Gallon to Litre");
	outtextxy(getmaxx()-70,267,"Back");
	mouse_on();
	while(1)
	{
		if(left_button_pressed())
		{
			get_position(&x,&y);
			if(x>200&&x<430&&y>70&&y<100)    // v inch to v cm
			{   float a,b;
				gotoxy(3,22);
				printf("Cubic Inch to Cubic CM press 1");
				gotoxy(3,24);
				printf("Cubic CM to Cubic Inch press 2");
				char ch=getche();
				setfillstyle(1,0);
				bar(5,330,getmaxx()-5,420);    		//bar4--output bar
				switch(ch)
				{
					case '1':	gotoxy(3,22);
								printf("Input value in Cubic Inch:");
								scanf("%f",&a);
								b=a*16.387064;
								gotoxy(3,24);
								printf("Value in Cubic CM:%f",b);
								break;
					case '2': 	gotoxy(3,22);
								printf("Input value in Cubic CM:");
								scanf("%f",&a);
								b=a*.0610237;
								gotoxy(3,24);
								printf("Value in Cubic Inch:%f",b);
								break;
					default :   gotoxy(3,22);
								printf("Wrong selection.");
				}

			}
			if(x>200&&x<430&&y>115&&y<145)    //v foot to v metre
			{   float a,b;
				gotoxy(3,22);
				printf("Cubic Foot to Cubic Metre press 1");
				gotoxy(3,24);
				printf("Cubic Metre to Cubic Foot press 2");
				char ch=getche();
				setfillstyle(1,0);
				bar(5,330,getmaxx()-5,420);    		//bar4
				switch(ch)
				{
					case '1':	gotoxy(3,22);
								printf("Input value in Cubic Foot:");
								scanf("%f",&a);
								b=a*.0283168;
								gotoxy(3,24);
								printf("Value in Cubic Metre:%f",b);
								break;
					case '2': 	gotoxy(3,22);
								printf("Input value in Cubic Metre:");
								scanf("%f",&a);
								b=a*35.314667;
								gotoxy(3,24);
								printf("Value in Cubic Foot:%f",b);
								break;
					default :   gotoxy(3,22);
								printf("Wrong selection.");
				}

			}
			if(x>200&&x<430&&y>160&&y<190)    //v metre to v yard
			{   float a,b;
				gotoxy(3,22);
				printf("Cubic Metre to Cubic Yard press 1");
				gotoxy(3,24);
				printf("Cubic Yard to Cubic Metre press 2");
				char ch=getche();
				setfillstyle(1,0);
				bar(5,330,getmaxx()-5,420);    		//bar4
				switch(ch)
				{
					case '1':	gotoxy(3,22);
								printf("Input value in Cubic Metre:");
								scanf("%f",&a);
								b=a*1.3079505;
								gotoxy(3,24);
								printf("Value in Cubic Yard:%f",b);
								break;
					case '2': 	gotoxy(3,22);
								printf("Input value in Cubic Yard:");
								scanf("%f",&a);
								b=a*.7645549;
								gotoxy(3,24);
								printf("Value in Cubic Metre:%f",b);
								break;
					default :   gotoxy(3,22);
								printf("Wrong selection.");
				}

			}
			if(x>200&&x<430&&y>205&&y<235)    // gallon to litre
			{   float a,b;
				gotoxy(3,22);
				printf("Gallon to Litre press 1");
				gotoxy(3,24);
				printf("Litre to Gallon press 2");
				char ch=getche();
				setfillstyle(1,0);
				bar(5,330,getmaxx()-5,420);    		//bar4
				switch(ch)
				{
					case '1':	gotoxy(3,22);
								printf("Input value in Gallon:");
								scanf("%f",&a);
								b=a*3.78541;
								gotoxy(3,24);
								printf("Value in Litre:%f",b);
								break;
					case '2': 	gotoxy(3,22);
								printf("Input value in Litre:");
								scanf("%f",&a);
								b=a*.2641722;
								gotoxy(3,24);
								printf("Value in Gallon:%f",b);
								break;
					default :   gotoxy(3,22);
								printf("Wrong selection.");
				}

			}
			if(x>(getmaxx()-80)&&y>267&&x<(getmaxx()-10)&&y<292) //back
				window();       					//back
			if(x>450&&x<550&&y>305&&y<323)       	//clear
			{
				setfillstyle(1,0);
				bar(5,330,getmaxx()-5,420);    		//bar4
			}
			if(x>(getmaxx()-20)&&x<(getmaxx()-5)&&y>5&&y<20)
				exit(0);
		}
	}
}

void num_sys()
{
	mouse_off();
	int x,y;
	setfillstyle(1,1);
	bar(5,55,getmaxx()-5,297);

	setfillstyle(1,8);
	bar(30,80,300,110);    //
	bar(330,80,600,110);   //
	bar(30,150,300,180);   //
	bar(330,150,600,180);   //
	bar(30,220,300,250);    //
	bar(330,220,600,250);   //
	bar(getmaxx()-80,267,getmaxx()-10,292);   //back

	settextstyle(7,0,2);
	setcolor(15);
	outtextxy(50,80,"Decimal to Binary");
	outtextxy(40,150,"Decimal to Hexadecimal");
	outtextxy(50,220,"Decimal to Octal");
	outtextxy(340,80,"Binary to Hexadecimal");
	outtextxy(350,150,"Binary to Octal");
	outtextxy(350,220,"Hexadecimal to Octal");
	outtextxy(getmaxx()-70,267,"Back");
	mouse_on();
	while(1)
	{
		if(left_button_pressed())
		{
			get_position(&x,&y);
			if(x>30&&x<300&&y>80&&y<110)  // decimal to binary
			{   int a;
				gotoxy(3,22);
				printf("Decimal to Binary press 1");
				gotoxy(3,24);
				printf("Binary to Decimal press 2");
				char ch=getche();
				setfillstyle(1,0);
				bar(5,330,getmaxx()-5,420);    		//bar4
				switch(ch)
				{
					case '1':	gotoxy(3,22);
								printf("Input value in Decimal:");
								scanf("%d",&a);
								int arr[100],i=0;
								while(a!=0)
								{
									arr[i]=a%2;
									a/=2; i++;
								}
								gotoxy(3,24);
								printf("Value in Binary:");
								for(int j=i-1;j>=0;j--)
									printf("%d",arr[j]);
								break;
					case '2': 	gotoxy(3,22);
								printf("Input value in Binary:");
								scanf("%d",&a);
								gotoxy(3,24);
								printf("Value in Decimal:%d",bin_to_dec(a));
								break;
					default :   gotoxy(3,22);
								printf("Wrong selection.");
				}
			}
			if(x>30&&x<300&&y>150&&y<180)  //decimal to hexadecimal
			{   int a;
				gotoxy(3,22);
				printf("Decimal to Hexadecimal press 1");
				gotoxy(3,24);
				printf("Hexadecimal to Decimal press 2");
				char ch=getche();
				setfillstyle(1,0);
				bar(5,330,getmaxx()-5,420);    		//bar4
				switch(ch)
				{
					case '1':	gotoxy(3,22);
								printf("Input value in Decimal:");
								scanf("%d",&a);
								gotoxy(3,24);
								printf("Value in Hexadecimal:%X",a);
								break;
					case '2': 	gotoxy(3,22);
								printf("Input value in Hexadecimal:");
								scanf("%X",&a);
								gotoxy(3,24);
								printf("Value in Decimal:%d",a);
								break;
					default :   gotoxy(3,22);
								printf("Wrong selection.");
				}
			}
			if(x>30&&x<300&&y>220&&y<250)  // decimal to octal
			{   int a;
				gotoxy(3,22);
				printf("Decimal to Octal press 1");
				gotoxy(3,24);
				printf("Octal to Decimal press 2");
				char ch=getche();
				setfillstyle(1,0);
				bar(5,330,getmaxx()-5,420);    		//bar4
				switch(ch)
				{
					case '1':	gotoxy(3,22);
								printf("Input value in Decimal:");
								scanf("%d",&a);
								gotoxy(3,24);
								printf("Value in Octal:%o",a);
								break;
					case '2': 	gotoxy(3,22);
								printf("Input value in Octal:");
								scanf("%o",&a);
								gotoxy(3,24);
								printf("Value in Decimal:%d",a);
								break;
					default :   gotoxy(3,22);
								printf("Wrong selection.");
				}
			}
			if(x>330&&x<600&&y>80&&y<110)  // binary to hexadecimal
			{   int a;
				gotoxy(3,22);
				printf("Binary to Hexadecimal press 1");
				gotoxy(3,24);
				printf("Hexadecimal to Binary press 2");
				char ch=getche();
				setfillstyle(1,0);
				bar(5,330,getmaxx()-5,420);    		//bar4
				switch(ch)
				{
					case '1':	gotoxy(3,22);
								printf("Input value in Binary:");
								scanf("%d",&a);
								int p=bin_to_dec(a);
								gotoxy(3,24);
								printf("Value in Hexadecimal:%X",p);
								break;
					case '2': 	gotoxy(3,22);
								printf("Input value in Hexadecimal:");
								scanf("%X",&a);
								int arr[100],i=0;
								while(a!=0)
								{
									arr[i]=a%2;
									a/=2; i++;
								}
								gotoxy(3,24);
								printf("Value in Binary:");
								for(int j=i-1;j>=0;j--)
									printf("%d",arr[j]);
								break;
					default :   gotoxy(3,22);
								printf("Wrong selection.");
				}
			}
			if(x>330&&x<600&&y>150&&y<180)  // binary to octal
			{   int a;
				gotoxy(3,22);
				printf("Binary to Octal press 1");
				gotoxy(3,24);
				printf("Octal to Binary press 2");
				char ch=getche();
				setfillstyle(1,0);
				bar(5,330,getmaxx()-5,420);    		//bar4
				switch(ch)
				{
					case '1':	gotoxy(3,22);
								printf("Input value in Binary:");
								scanf("%d",&a);
								int p=bin_to_dec(a);
								gotoxy(3,24);
								printf("Value in Octal:%o",p);
								break;
					case '2': 	gotoxy(3,22);
								printf("Input value in Octal:");
								scanf("%o",&a);
								int arr[100],i=0;
								while(a!=0)
								{
									arr[i]=a%2;
									a/=2; i++;
								}
								gotoxy(3,24);
								printf("Value in Binary:");
								for(int j=i-1;j>=0;j--)
									printf("%d",arr[j]);
								break;
					default :   gotoxy(3,22);
								printf("Wrong selection.");
				}
			}
			if(x>330&&x<600&&y>220&&y<250)  //hexadecimal to octal
			{   int a;
				gotoxy(3,22);
				printf("Hexadecimal to Octal press 1");
				gotoxy(3,24);
				printf("Octal to Hexadecimal press 2");
				char ch=getche();
				setfillstyle(1,0);
				bar(5,330,getmaxx()-5,420);    		//bar4
				switch(ch)
				{
					case '1':	gotoxy(3,22);
								printf("Input value in Hexadecimal:");
								scanf("%X",&a);
								gotoxy(3,24);
								printf("Value in Octal:%o",a);
								break;
					case '2': 	gotoxy(3,22);
								printf("Input value in Octal:");
								scanf("%o",&a);
								gotoxy(3,24);
								printf("Value in Hexadecimal:%X",a);
								break;
					default :   gotoxy(3,22);
								printf("Wrong selection.");
				}
			}
			if(x>(getmaxx()-80)&&y>267&&x<(getmaxx()-10)&&y<292) //back
				window();       					//back
			if(x>450&&x<550&&y>305&&y<323)       	//clear
			{
				setfillstyle(1,0);
				bar(5,330,getmaxx()-5,420);    		//bar4
			}
			if(x>(getmaxx()-20)&&x<(getmaxx()-5)&&y>5&&y<20)
				exit(0);
		}
	}
}

void trigon()
{

}

void help()
{

}

int bin_to_dec(int num)
{
	int a[100],i=0,j=0,sum=0;
	while(num!=0)
	{
		a[i]=num%10;
		num/=10;i++;
	}
	for(j=0;j<i;j++)
		sum+=a[j]*pow(2,j);
	return sum;
}

void date_show()
{
	char *wday[]={"Sunday","Monday","Tuesday","Wednasday","Thursday","Friday","Saturday","Unknown"};
	struct date d;
	getdate(&d);
	gotoxy(10,28);
	//printf("%d:%d:%d",d.da_day,d.da_mon,d.da_year);

	char *str1,*str2,*str3;          //date showing
	gcvt(d.da_day,5,str1);
	gcvt(d.da_mon,5,str2);
	gcvt(d.da_year,5,str3);
	setcolor(4);
	outtextxy(getmaxx()-200,getmaxy()-55,str1);
	outtextxy(getmaxx()-170,getmaxy()-55,"-");
	outtextxy(getmaxx()-145,getmaxy()-55,str2);
	outtextxy(getmaxx()-130,getmaxy()-55,"-");
	outtextxy(getmaxx()-115,getmaxy()-55,str3);

	struct tm time_check;              //name of the day
	time_check.tm_year=d.da_year-1900;
	time_check.tm_mon=d.da_mon-1;
	time_check.tm_mday=d.da_day;
	time_check.tm_hour=0;
	time_check.tm_min=0;
	time_check.tm_sec=1;
	time_check.tm_isdst=-1;

	if(mktime(&time_check)==-1)
		time_check.tm_wday=7;
	setcolor(4);
	outtextxy(getmaxx()-185,getmaxy()-35,wday[time_check.tm_wday]);
}

void mouse_reset()
{
	union REGS r;
	r.x.ax=0;
	int86(0x33,&r,&r);
	if(int(r.x.ax)!=-1)
	{
		printf("Hardware failure!");
		exit(1);
	}
}
void mouse_on()
{
	union REGS r;
	r.x.ax=1;
	int86(0x33,&r,&r);
}
void mouse_off()
{
	union REGS r;
	r.x.ax=2;
	int86(0x33,&r,&r);
}
void get_position(int *x,int *y)
{
	union REGS r;
	r.x.ax=3;
	int86(0x33,&r,&r);
	*x=r.x.cx;
	*y=r.x.dx;
}
int left_button_pressed()
{
	union REGS r;
	r.x.ax=3;
	int86(0x33,&r,&r);
	return(r.x.bx & 1);
}