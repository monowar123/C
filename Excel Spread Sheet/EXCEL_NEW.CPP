#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<graphics.h>
#include<dos.h>
#include<ctype.h>

#include"front.cpp"
#include"mouse.cpp"
#include"help.cpp"

int x,y,Xmin=5,Ymin=113,Xmax=635,Ymax=475,row,col;
float arr[30][30]={NULL};
char arr_string[30][30][30]={NULL};
int a=NULL,b=NULL,c=NULL,d=NULL,e=NULL,f=NULL,i,j,p,q;
void main_window();
void window();
void minimize();
void file();
void edit();
void view();
void help();
void credit();
void summation();
void subtraction();
void multiplication();
void divition();
void average();
void square();
void power();
void error_mess();
void select();
void file_open();
void file_save();

void main()
{
	clrscr();
	int gdriver = DETECT, gmode;
	initgraph(&gdriver, &gmode, "c:\\tc\\bgi");

	//cleardevice();
	//front_page();

	mouse_reset();
	mouse_on();

	window();
	main_window();
}

void main_window()
{
	mouse_off();
	setfillstyle(1,5);
	bar(0,0,getmaxx(),112);              		//border
	bar(0,110,5, getmaxy());                	//border
	bar(getmaxx()-5,110,getmaxx(),getmaxy());   //border
	bar(0,getmaxy()-5,getmaxx(),getmaxy());     //border
	setfillstyle(1,3);
	bar(5,5,getmaxx()-5,25);                   	//bar1
	bar(5,28,getmaxx()-5,110);                  //bar2
	//setfillstyle(1,0);
	//bar(5,113,getmaxx()-5,getmaxy()-5);         //bar3

	setfillstyle(1,8);
	bar(getmaxx()-20,5,getmaxx()-5,20);        	//x:close
	bar(getmaxx()-37,5,getmaxx()-22,20); 		//maximize
	bar(getmaxx()-54,5,getmaxx()-39,20); 		//minimize

	setfillstyle(1,15);
	bar(getmaxx()-33,10,getmaxx()-27,15);       //maximize
	setcolor(15);
	outtextxy(getmaxx()-50,9,"-");             //minimize
	setcolor(4);
	outtextxy(getmaxx()-16,9,"x");            //close

	settextstyle(1,0,1);
	setcolor(15);
	outtextxy(210,3,"Excel Spread Sheet");
	setcolor(9);
	outtextxy(209,2,"Excel Spread Sheet");
				 ///////menu bar///////
	setfillstyle(1,7);
	setcolor(4);
	bar3d(10,30,60,45,2,2);           //file
	bar3d(70,30,120,45,2,2);          //edit
	bar3d(130,30,180,45,2,2);         //veiw
	bar3d(190,30,240,45,2,2);        //help
	bar3d(250,30,300,45,2,2);        //credit

	bar3d(10,55,110,75,2,2);          //summation
	bar3d(120,55,220,75,2,2);        //subtraction
	bar3d(230,55,330,75,2,2);        //multiplication
	bar3d(340,55,440,75,2,2);        //divition

	bar3d(10,85,110,105,2,2);        //average
	bar3d(120,85,220,105,2,2);       //square
	bar3d(230,85,330,105,2,2);       //power

	settextstyle(2,0,5);
	setcolor(5);
	outtextxy(20,30,"File");
	outtextxy(80,30,"Edit");
	outtextxy(140,30,"View");
	outtextxy(200,30,"Help");
	outtextxy(255,30,"Credit");

	outtextxy(25,57,"Summation");
	outtextxy(130,57,"Subtraction");
	outtextxy(233,57,"Multiplication");
	outtextxy(360,57,"Divition");
	outtextxy(30,87,"Average");
	outtextxy(140,87,"Square");
	outtextxy(260,87,"Power");

	window();
	mouse_on();
	while(1)
	{
			get_position(&x,&y);
			gotoxy(60,3);
			printf("Xpos=%3d  Ypos=%3d",x,y);

		if(left_button_pressed())
		{
			if(x>(getmaxx()-54)&&x<(getmaxx()-39)&&y>5&&y<20)
				minimize();
			if(x>10&&x<60&&y>30&&y<45)
				file();
			if(x>70&&x<120&&y>30&&y<45)
				edit();
			if(x>130&&x<180&&y>30&&y<45)
				view();
			if(x>190&&x<240&&y>30&&y<45)
				help();
			if(x>250&&x<300&&y>30&&y<45)
				credit();
			if(x>10&&x<110&&y>55&&y<75)
				summation();
			if(x>120&&x<220&&y>55&&y<75)
				subtraction();
			if(x>230&&x<330&&y>55&&y<75)
				multiplication();
			if(x>340&&x<440&&y>55&&y<75)
				divition();
			if(x>10&&x<110&&y>85&&y<105)
				average();
			if(x>120&&x<220&&y>85&&y<105)
				square();
			if(x>230&&x<330&&y>85&&y<105)
				power();
			if(x>(getmaxx()-20)&&x<(getmaxx()-5)&&y>5&&y<20)
				exit(0);
			if(x>20&&x<620&&y>125&&y<470)
				select();
		}
	}
}
void select()
{
	mouse_off();
	char ch,str[2]={NULL},str_value[20]={NULL};
	static int p,q;
	setcolor(3);
	rectangle(p,q,p+50,q+15);
	p=(x-20)/50*50+20;
	q=(y-125)/15*15+125;
	setcolor(4);
	rectangle(p,q,p+50,q+15);
	int temp=p;
	while(ch!=13)        //ch not equal to enter.
	{
		ch=getche();
		if(ch==8)
			break;
		str[0]=ch;
		outtextxy(temp+1,q,str);
		temp=temp+8;
		strcat(str_value,str);
	}
	int m=20,n=125,i=1,j=1,count=1;
	while(m<getmaxx())
	{
		if(x>m && x<m+50)
		{
			i=count;
			break;
		}
		count++;
		m=m+50;
	}
	count=1;
	while(n<getmaxy())
	{
		if(y>n && y<n+15)
		{
			j=count;
			break;
		}
		count++;
		n=n+15;
	}
	int k,flag=0,len;
	len=strlen(str_value);
	for(k=0;k<len-1;k++)
	{
		if(!(isdigit(str_value[k])))
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
		arr[i][j]=atof(str_value);
	else
	{
		for(k=0;k<len-1;k++)
			arr_string[i][j][k]=str_value[k];
	}
	mouse_on();
}
void window()
{
	mouse_off();
	setfillstyle(1,15);
	bar(5,113,getmaxx()-5,getmaxy()-5);         //bar3 or back ground
	setfillstyle(1,11);
	bar(5,113,getmaxx()-5,125);     //a b c d bar

	setfillstyle(1,11);
	bar(5,113,20,getmaxy()-5);      //1 2 3 4 bar

			/////////// ////     line          ///////////////
	int i;
	setcolor(3);
	for(i=20;i<=getmaxx();i+=50)
	{
		line(i,113,i,getmaxy()-5);       //vertical line
	}
	for(i=125;i<=getmaxx();i+=15)
	{
		line(5,i,getmaxx()-5,i);         //horizontal line
	}
			  /////  A B C D    1 2 3 4  /////
	int n=0;
	char *str,*ch[]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","X","Y","Z"};
	settextstyle(2,0,5);
	setcolor(5);
	for(i=42;i<=getmaxx();i+=50)
		{
			outtextxy(i,110,*(ch+n));       //A B C D
			n++;
		}
	n=1;
	for(i=125;i<=getmaxy();i+=15)
		{
			gcvt(n,5,str);
			outtextxy(5,i,str);             //1 2 3 4
			n++;
		}

			/*display the data that is stored in array*/
	char string1[50]={NULL};

	for(i=1;i<14;i++)                    //for numaric value
		for(j=1;j<24;j++)
		{
			if(arr[i][j]==NULL)
				goto level;
			sprintf(string1,"%.4g",arr[i][j]);
			outtextxy((i-1)*50+20,(j-1)*15+125,string1);
			level:     //if the value is null then nothing will print.
		}

	int k;
	char string2[50]={NULL};
	for(i=1;i<14;i++)                      //for string value
		for(j=1;j<24;j++)
		{
			for(k=0;k<10;k++)
				string2[k]=arr_string[i][j][k];
		outtextxy((i-1)*50+20,(j-1)*15+125,string2);
		}
		mouse_on();
}
void minimize()
{
	mouse_off();
	cleardevice();
	int x,y;
	bar(0,getmaxy()-20,180,getmaxy());
	setcolor(4);
	outtextxy(10,getmaxy()-23,"Excel Spread Sheet");
	mouse_on();
	while(1)
	{
		if(left_button_pressed())
		{
			get_position(&x,&y);

			if(x>0&&x<180&&y>getmaxy()-20&&y<getmaxy())
			{
				 main_window();
			}
		}
	}
}
void file()
{
	mouse_off();
	setfillstyle(1,7);
	bar(10,45,90,175);

	setfillstyle(1,5);
	bar(15,50,85,70);      //new
	bar(15,75,85,95);      //open
	bar(15,100,85,120);      //save
	bar(15,125,85,145);      //close
	bar(15,150,85,170);      //exit

	settextstyle(1,0,1);
	setcolor(15);
	outtextxy(25,47,"New");
	outtextxy(25,72,"Open");
	outtextxy(25,97,"Save");
	outtextxy(25,122,"Close");
	outtextxy(25,147,"Exit");
	delay(100);
	mouse_on();
	while(1)
	{
		if(left_button_pressed())
		{
			get_position(&x,&y);

			if(x>10&&x<60&&y>30&&y<45)
				{
					delay(100);
					main_window();
				}
			if(x>15&&x<85&&y>50&&y<70)         //new
				window();
			if(x>15&&x<85&&y>125&&y<145)       //close
			{
				mouse_off();
				setfillstyle(1,0);
				bar(5,113,getmaxx()-5,getmaxy()-5);         //bar3
				mouse_on();
			}
			if(x>15&&x<85&&y>150&&y<170)
				exit(0);
		}
	}
}
void edit()
{
	mouse_off();
	setfillstyle(1,7);
	bar(70,45,150,150);

	setfillstyle(1,5);
	bar(75,50,145,70);      //cut
	bar(75,75,145,95);      //copy
	bar(75,100,145,120);      //paste
	bar(75,125,145,145);      //delete

	settextstyle(1,0,1);
	setcolor(15);
	outtextxy(80,47,"Cut");
	outtextxy(80,72,"Copy");
	outtextxy(80,97,"Paste");
	outtextxy(80,122,"Delete");
	delay(100);
	mouse_on();
	while(1)
	{
		if(left_button_pressed())
		{
			get_position(&x,&y);

			if(x>70&&x<120&&y>30&&y<45)
				{
					delay(100);
					main_window();
				}
		}
	}
}
void view()
{
	mouse_off();
	setfillstyle(1,7);
	bar(130,45,245,100);

	setfillstyle(1,5);
	bar(135,50,240,70);      //full screen
	bar(135,75,240,95);      //clasical

	settextstyle(1,0,1);
	setcolor(15);
	outtextxy(140,47,"Full Screen");
	outtextxy(140,72,"Classical");
	delay(100);
	mouse_on();
	while(1)
	{
		if(left_button_pressed())
		{
			get_position(&x,&y);

			if(x>130&&x<180&&y>30&&y<45)
				{
					delay(100);
					main_window();
				}
		}
	}
}
void help()
{
	mouse_off();
	setfillstyle(1,7);
	bar(190,45,310,100);

	setfillstyle(1,5);
	bar(195,50,305,70);      //help
	bar(195,75,305,95);      //online help

	settextstyle(1,0,1);
	setcolor(15);
	outtextxy(200,47,"Help");
	outtextxy(200,72,"Online Help");
	delay(100);
	mouse_on();
	while(1)
	{
		if(left_button_pressed())
		{
			get_position(&x,&y);

			if(x>190&&x<240&&y>30&&y<45)
				{
					delay(100);
					main_window();
				}
			if(x>195&&x<305&&y>50&&y<70)     //help
			{
				rules();
				main_window();
			}
		}
	}
}

void credit()
{
	cleardevice();
	mouse_off();
	int x1=20,y1=20;
	setfillstyle(1,9);
	bar(0,0,getmaxx(),getmaxy());
	setfillstyle(1,6);
	bar(x1,y1,619,459);

	setcolor(0);
	line(0,0,20,20);
	line(619,20,639,0);
	line(0,479,20,459);
	line(639,479,619,459);

	line(20,20,619,20);
	line(20,20,20,459);
	line(619,20,619,459);
	line(20,459,619,459);

	setcolor(3);
	outtextxy(280,45,"!!*DEVELOPER*!!");
	settextstyle(1,0,2);
	setcolor(1);
	outtextxy(245,65,"THE STUDENT'S OF");
	outtextxy(35,95,"MAWLANA BHASHANI SCIENCE & TECHNOLOGY UNIVERSITY");
	setcolor(2);
	outtextxy(90,135,"DEPT. OF COMPUTER SCIENCE & ENGINEERING");
	settextstyle(0,0,1);
	setcolor(3);
	outtextxy(100,200,"1.Md.Monowarul Islam");
	outtextxy(100,215,"CE-09016");
	outtextxy(100,245,"2.Md.Nasir Uddin");
	outtextxy(100,260,"CE-09014");
	outtextxy(100,290,"3.Tanvir Jahan Tanin");
	outtextxy(100,305,"CE-09008");

	outtextxy(350,200,"Adviced by...... ");
	outtextxy(350,230,"HONOURABLE TEACHER");
	outtextxy(350,245,"MD. RASHADUL HASAN RAKIB");

	setfillstyle(1,0);
	bar(100,410,150,435);    //back
	setcolor(15);
	outtextxy(110,420,"BACK");
	mouse_on();
	while(1)
	{
		if(left_button_pressed())
		{
			get_position(&x,&y);

			if(x>100&&x<150&&y>410&&y<435)     //back
				{
					cleardevice();
					main_window();
				}
		}
	}

}
void summation()
{
	mouse_off();
	setfillstyle(1,1);
	bar(200,180,400,340);    //background bar

	setfillstyle(1,5);
	bar(205,185,395,200);    //title bar

	setfillstyle(1,15);
	bar(310,210,395,230);    //position
	bar(310,240,395,260);    //to
	bar(310,270,395,290);    //destination

	setfillstyle(1,8);
	bar(230,310,300,330);    //cancel
	bar(310,310,380,330);    //ok

	settextstyle(1,0,1);
	setcolor(3);
	outtextxy(248,181,"SUMMATION");
	setcolor(14);
	outtextxy(205,210,"Position");
	outtextxy(205,240,"To");
	outtextxy(205,270,"Destination");
	setcolor(15);
	outtextxy(238,308,"Cancel");
	outtextxy(333,308,"OK");
	mouse_on();

	while(1)
	{
		char ch=NULL,str[2]={NULL},str_value[5]={NULL},str_out[20]={NULL};
		int temp;
		if(left_button_pressed())
		{
			get_position(&x,&y);

			if(x>230&&x<300&&y>310&&y<330)     //cancel
			{
				main_window();
			}
			if(x>310&&x<395&&y>210&&y<230)       //position
			{
				mouse_off();
				temp=310;
				setcolor(4);
				while(ch!=13)
				{
					ch=getche();
					str[0]=ch;
					outtextxy(temp,210,str);
					temp=temp+15;
					strcat(str_value,str);
				}
				a=str_value[0]-64;
				if(str_value[3]==NULL)
					b=str_value[1]-48;
				else
				{
					p=str_value[1]-48;
					q=str_value[2]-48;
					b=p*10+q;
				}
				mouse_on();
			}
			if(x>310&&x<395&&y>240&&y<260)        //to
			{
				mouse_off();
				temp=310;
				setcolor(4);
				while(ch!=13)
				{
					ch=getche();
					str[0]=ch;
					outtextxy(temp,240,str);
					temp=temp+15;
					strcat(str_value,str);
				}
				c=str_value[0]-64;
				if(str_value[3]==NULL)
					d=str_value[1]-48;
				else
				{
					p=str_value[1]-48;
					q=str_value[2]-48;
					d=p*10+q;
				}
				mouse_on();
			}
			if(x>310&&x<395&&y>270&&y<290)       //destination
			{
				mouse_off();
				temp=310;
				setcolor(4);
				while(ch!=13)
				{
					ch=getche();
					str[0]=ch;
					outtextxy(temp,270,str);
					temp=temp+15;
					strcat(str_value,str);
				}
				e=str_value[0]-64;
				if(str_value[3]==NULL)
					f=str_value[1]-48;
				else
				{
					p=str_value[1]-48;
					q=str_value[2]-48;
					f=p*10+q;
				}
				mouse_on();
			}
			if(x>310&&x<380&&y>310&&y<330)     //ok
			{   temp=0;
				for(i=a;i<=c;i++)
					for(j=b;j<=d;j++)
						temp+=arr[i][j];
				arr[e][f]=temp;
				sprintf(str_out,"%.4g",arr[e][f]);
				outtextxy((e-1)*50+20,(f-1)*15+125,str_out);
				main_window();
				 //error_mess();

			}
		}
	}
}
void subtraction()
{
	mouse_off();
	setfillstyle(1,1);
	bar(200,180,400,340);    //background bar

	setfillstyle(1,5);
	bar(205,185,395,200);    //title bar

	setfillstyle(1,15);
	bar(310,210,395,230);    //position
	bar(310,240,395,260);    //to
	bar(310,270,395,290);    //destination

	setfillstyle(1,8);
	bar(230,310,300,330);    //cancel
	bar(310,310,380,330);    //ok

	settextstyle(1,0,1);
	setcolor(3);
	outtextxy(242,181,"SUBTRACTION");
	setcolor(14);
	outtextxy(205,210,"Position");
	outtextxy(205,240,"And");
	outtextxy(205,270,"Destination");
	setcolor(15);
	outtextxy(238,308,"Cancel");
	outtextxy(333,308,"OK");
	mouse_on();
	while(1)
	{
		char ch=NULL,str[2]={NULL},str_value[5]={NULL},str_out[20]={NULL};
		int temp;
		if(left_button_pressed())
		{
			get_position(&x,&y);

			if(x>230&&x<300&&y>310&&y<330)     //cancel
				main_window();
			if(x>310&&x<395&&y>210&&y<230)       //position
			{
				mouse_off();
				temp=310;
				setcolor(4);
				while(ch!=13)
				{
					ch=getche();
					str[0]=ch;
					outtextxy(temp,210,str);
					temp=temp+15;
					strcat(str_value,str);
				}
				a=str_value[0]-64;
				if(str_value[3]==NULL)
					b=str_value[1]-48;
				else
				{
					p=str_value[1]-48;
					q=str_value[2]-48;
					b=p*10+q;
				}
				mouse_on();
			}
			if(x>310&&x<395&&y>240&&y<260)        //to
			{
				mouse_off();
				temp=310;
				setcolor(4);
				while(ch!=13)
				{
					ch=getche();
					str[0]=ch;
					outtextxy(temp,240,str);
					temp=temp+15;
					strcat(str_value,str);
				}
				c=str_value[0]-64;
				if(str_value[3]==NULL)
					d=str_value[1]-48;
				else
				{
					p=str_value[1]-48;
					q=str_value[2]-48;
					d=p*10+q;
				}
				mouse_on();
			}
			if(x>310&&x<395&&y>270&&y<290)       //destination
			{
				mouse_off();
				temp=310;
				setcolor(4);
				while(ch!=13)
				{
					ch=getche();
					str[0]=ch;
					outtextxy(temp,270,str);
					temp=temp+15;
					strcat(str_value,str);
				}
				e=str_value[0]-64;
				if(str_value[3]==NULL)
					f=str_value[1]-48;
				else
				{
					p=str_value[1]-48;
					q=str_value[2]-48;
					f=p*10+q;
				}
				mouse_on();
			}
			if(x>310&&x<380&&y>310&&y<330)     //ok
			{
				arr[e][f]=arr[a][b]-arr[c][d];
				sprintf(str_out,"%.4g",arr[e][f]);
				outtextxy((e-1)*50+20,(f-1)*15+125,str_out);
				main_window();
				//error_mess();
			}
		}
	}
}
void multiplication()
{
	mouse_off();
	setfillstyle(1,1);
	bar(200,180,400,340);    //background bar

	setfillstyle(1,5);
	bar(205,185,395,200);    //title bar

	setfillstyle(1,15);
	bar(310,210,395,230);    //position
	bar(310,240,395,260);    //to
	bar(310,270,395,290);    //destination

	setfillstyle(1,8);
	bar(230,310,300,330);    //cancel
	bar(310,310,380,330);    //ok

	settextstyle(1,0,1);
	setcolor(3);
	outtextxy(232,181,"MULTIPLICATION");
	setcolor(14);
	outtextxy(205,210,"Position");
	outtextxy(205,240,"To");
	outtextxy(205,270,"Destination");
	setcolor(15);
	outtextxy(238,308,"Cancel");
	outtextxy(333,308,"OK");
	mouse_on();
	while(1)
	{
		char ch=NULL,str[2]={NULL},str_value[5]={NULL},str_out[20]={NULL};
		int temp;
		if(left_button_pressed())
		{
			get_position(&x,&y);

			if(x>230&&x<300&&y>310&&y<330)     //cancel
				main_window();
			if(x>310&&x<395&&y>210&&y<230)       //position
			{
				mouse_off();
				temp=310;
				setcolor(4);
				while(ch!=13)
				{
					ch=getche();
					str[0]=ch;
					outtextxy(temp,210,str);
					temp=temp+15;
					strcat(str_value,str);
				}
				a=str_value[0]-64;
				if(str_value[3]==NULL)
					b=str_value[1]-48;
				else
				{
					p=str_value[1]-48;
					q=str_value[2]-48;
					b=p*10+q;
				}
				mouse_on();
			}
			if(x>310&&x<395&&y>240&&y<260)        //to
			{
				mouse_off();
				temp=310;
				setcolor(4);
				while(ch!=13)
				{
					ch=getche();
					str[0]=ch;
					outtextxy(temp,240,str);
					temp=temp+15;
					strcat(str_value,str);
				}
				c=str_value[0]-64;
				if(str_value[3]==NULL)
					d=str_value[1]-48;
				else
				{
					p=str_value[1]-48;
					q=str_value[2]-48;
					d=p*10+q;
				}
				mouse_on();
			}
			if(x>310&&x<395&&y>270&&y<290)       //destination
			{
				mouse_off();
				temp=310;
				setcolor(4);
				while(ch!=13)
				{
					ch=getche();
					str[0]=ch;
					outtextxy(temp,270,str);
					temp=temp+15;
					strcat(str_value,str);
				}
				e=str_value[0]-64;
				if(str_value[3]==NULL)
					f=str_value[1]-48;
				else
				{
					p=str_value[1]-48;
					q=str_value[2]-48;
					f=p*10+q;
				}
				mouse_on();
			}
			if(x>310&&x<380&&y>310&&y<330)     //ok
			{
				temp=1;
				for(i=a;i<=c;i++)
					for(j=b;j<=d;j++)
						temp*=arr[i][j];
				arr[e][f]=temp;
				sprintf(str_out,"%.4g",arr[e][f]);
				outtextxy((e-1)*50+20,(f-1)*15+125,str_out);
				main_window();
				//error_mess();
			}
		}
	}
}
void divition()
{
	mouse_off();
	setfillstyle(1,1);
	bar(200,180,400,340);    //background bar

	setfillstyle(1,5);
	bar(205,185,395,200);    //title bar

	setfillstyle(1,15);
	bar(310,210,395,230);    //position
	bar(310,240,395,260);    //and
	bar(310,270,395,290);    //destination

	setfillstyle(1,8);
	bar(230,310,300,330);    //cancel
	bar(310,310,380,330);    //ok

	settextstyle(1,0,1);
	setcolor(3);
	outtextxy(260,181,"DIVITION");
	setcolor(14);
	outtextxy(205,210,"Position");
	outtextxy(205,240,"And");
	outtextxy(205,270,"Destination");
	setcolor(15);
	outtextxy(238,308,"Cancel");
	outtextxy(333,308,"OK");
	mouse_on();
	while(1)
	{
		char ch=NULL,str[2]={NULL},str_value[5]={NULL},str_out[20]={NULL};
		int temp;
		if(left_button_pressed())
		{
			get_position(&x,&y);

			if(x>230&&x<300&&y>310&&y<330)     //cancel
				main_window();
			if(x>310&&x<395&&y>210&&y<230)       //position
			{
				mouse_off();
				temp=310;
				setcolor(4);
				while(ch!=13)
				{
					ch=getche();
					str[0]=ch;
					outtextxy(temp,210,str);
					temp=temp+15;
					strcat(str_value,str);
				}
				a=str_value[0]-64;
				if(str_value[3]==NULL)
					b=str_value[1]-48;
				else
				{
					p=str_value[1]-48;
					q=str_value[2]-48;
					b=p*10+q;
				}
				mouse_on();
			}
			if(x>310&&x<395&&y>240&&y<260)        //and
			{
				mouse_off();
				temp=310;
				setcolor(4);
				while(ch!=13)
				{
					ch=getche();
					str[0]=ch;
					outtextxy(temp,240,str);
					temp=temp+15;
					strcat(str_value,str);
				}
				c=str_value[0]-64;
				if(str_value[3]==NULL)
					d=str_value[1]-48;
				else
				{
					p=str_value[1]-48;
					q=str_value[2]-48;
					d=p*10+q;
				}
				mouse_on();
			}
			if(x>310&&x<395&&y>270&&y<290)       //destination
			{
				mouse_off();
				temp=310;
				setcolor(4);
				while(ch!=13)
				{
					ch=getche();
					str[0]=ch;
					outtextxy(temp,270,str);
					temp=temp+15;
					strcat(str_value,str);
				}
				e=str_value[0]-64;
				if(str_value[3]==NULL)
					f=str_value[1]-48;
				else
				{
					p=str_value[1]-48;
					q=str_value[2]-48;
					f=p*10+q;
				}
				mouse_on();
			}
			if(x>310&&x<380&&y>310&&y<330)     //ok
			{
				arr[e][f]=arr[a][b] / arr[c][d];
				sprintf(str_out,"%.4g",arr[e][f]);
				outtextxy((e-1)*50+20,(f-1)*15+125,str_out);
				main_window();
				//error_mess();
			}
		}
	}
}
void average()
{
	mouse_off();
	setfillstyle(1,1);
	bar(200,180,400,340);    //background bar

	setfillstyle(1,5);
	bar(205,185,395,200);    //title bar

	setfillstyle(1,15);
	bar(310,210,395,230);    //position
	bar(310,240,395,260);    //to
	bar(310,270,395,290);    //destination

	setfillstyle(1,8);
	bar(230,310,300,330);    //cancel
	bar(310,310,380,330);    //ok

	settextstyle(1,0,1);
	setcolor(3);
	outtextxy(260,181,"AVERAGE");
	setcolor(14);
	outtextxy(205,210,"Position");
	outtextxy(205,240,"To");
	outtextxy(205,270,"Destination");
	setcolor(15);
	outtextxy(238,308,"Cancel");
	outtextxy(333,308,"OK");
	mouse_on();
	while(1)
	{
		char ch=NULL,str[2]={NULL},str_value[5]={NULL},str_out[20]={NULL};
		int temp;
		float count;
		if(left_button_pressed())
		{
			get_position(&x,&y);

			if(x>230&&x<300&&y>310&&y<330)     //cancel
				main_window();
			if(x>310&&x<395&&y>210&&y<230)       //position
			{
				mouse_off();
				temp=310;
				setcolor(4);
				while(ch!=13)
				{
					ch=getche();
					str[0]=ch;
					outtextxy(temp,210,str);
					temp=temp+15;
					strcat(str_value,str);
				}
				a=str_value[0]-64;
				if(str_value[3]==NULL)
					b=str_value[1]-48;
				else
				{
					p=str_value[1]-48;
					q=str_value[2]-48;
					b=p*10+q;
				}
				mouse_on();
			}
			if(x>310&&x<395&&y>240&&y<260)        //to
			{
				mouse_off();
				temp=310;
				setcolor(4);
				while(ch!=13)
				{
					ch=getche();
					str[0]=ch;
					outtextxy(temp,240,str);
					temp=temp+15;
					strcat(str_value,str);
				}
				c=str_value[0]-64;
				if(str_value[3]==NULL)
					d=str_value[1]-48;
				else
				{
					p=str_value[1]-48;
					q=str_value[2]-48;
					d=p*10+q;
				}
				mouse_on();
			}
			if(x>310&&x<395&&y>270&&y<290)       //destination
			{
				mouse_off();
				temp=310;
				setcolor(4);
				while(ch!=13)
				{
					ch=getche();
					str[0]=ch;
					outtextxy(temp,270,str);
					temp=temp+15;
					strcat(str_value,str);
				}
				e=str_value[0]-64;
				if(str_value[3]==NULL)
					f=str_value[1]-48;
				else
				{
					p=str_value[1]-48;
					q=str_value[2]-48;
					f=p*10+q;
				}
				mouse_on();
			}
			if(x>310&&x<380&&y>310&&y<330)     //ok
			{
				temp=0; count=0;
				for(i=a;i<=c;i++)
					for(j=b;j<=d;j++)
						{temp+=arr[i][j];
						count++;}
				arr[e][f]=temp/count;
				sprintf(str_out,"%.4g",arr[e][f]);
				outtextxy((e-1)*50+20,(f-1)*15+125,str_out);
				main_window();
				//error_mess();
			}
		}
	}
}
void square()
{
	mouse_off();
	setfillstyle(1,1);
	bar(200,180,400,340);    //background bar

	setfillstyle(1,5);
	bar(205,185,395,200);    //title bar

	setfillstyle(1,15);
	bar(310,210,395,230);    //position
	bar(310,250,395,270);    //destination

	setfillstyle(1,8);
	bar(230,310,300,330);    //cancel
	bar(310,310,380,330);    //ok

	settextstyle(1,0,1);
	setcolor(3);
	outtextxy(265,181,"SQUARE");
	setcolor(14);
	outtextxy(205,210,"Position");
	outtextxy(205,250,"Destination");
	setcolor(15);
	outtextxy(238,308,"Cancel");
	outtextxy(333,308,"OK");
	mouse_on();
	while(1)
	{
		char ch=NULL,str[2]={NULL},str_out[20]={NULL};
		int temp;
		if(left_button_pressed())
		{
			get_position(&x,&y);

			if(x>230&&x<300&&y>310&&y<330)     //cancel
				main_window();
			if(x>310&&x<395&&y>210&&y<230)       //position
			{
				char str_value[5]={NULL};
				mouse_off();
				temp=310;
				setcolor(4);
				while(ch!=13)
				{
					ch=getche();
					str[0]=ch;
					outtextxy(temp,210,str);
					temp=temp+15;
					strcat(str_value,str);
				}
				a=str_value[0]-64;
				if(str_value[3]==NULL)
					b=str_value[1]-48;
				else
				{
					p=str_value[1]-48;
					q=str_value[2]-48;
					b=p*10+q;
				}
				mouse_on();
			}
			if(x>310&&x<395&&y>250&&y<270)       //destination
			{
				char str_value[5]={NULL};
				mouse_off();
				temp=310;
				setcolor(4);
				while(ch!=13)
				{
					ch=getche();
					str[0]=ch;
					outtextxy(temp,250,str);
					temp=temp+15;
					strcat(str_value,str);
				}
				e=str_value[0]-64;
				if(str_value[3]==NULL)
					f=str_value[1]-48;
				else
				{
					p=str_value[1]-48;
					q=str_value[2]-48;
					f=p*10+q;
				}
				mouse_on();
			}
			if(x>310&&x<380&&y>310&&y<330)     //ok
			{
				arr[e][f]=arr[a][b]*arr[a][b];
				sprintf(str_out,"%.4g",arr[e][f]);
				outtextxy((e-1)*50+20,(f-1)*15+125,str_out);
				main_window();
				//error_mess();
			}
		}
	}
}
void power()
{
	mouse_off();
	setfillstyle(1,1);
	bar(200,180,400,340);    //background bar

	setfillstyle(1,5);
	bar(205,185,395,200);    //title bar

	setfillstyle(1,15);
	bar(310,210,395,230);    //position
	bar(310,240,395,260);    //power
	bar(310,270,395,290);    //destination

	setfillstyle(1,8);
	bar(230,310,300,330);    //cancel
	bar(310,310,380,330);    //ok

	settextstyle(1,0,1);
	setcolor(3);
	outtextxy(267,181,"POWER");
	setcolor(14);
	outtextxy(205,210,"Position");
	outtextxy(205,240,"Power");
	outtextxy(205,270,"Destination");
	setcolor(15);
	outtextxy(238,308,"Cancel");
	outtextxy(333,308,"OK");
	mouse_on();
	while(1)
	{
		char ch=NULL,str[2]={NULL},str_value[5]={NULL},str_out[20]={NULL};
		int temp,power;
		if(left_button_pressed())
		{
			get_position(&x,&y);

			if(x>230&&x<300&&y>310&&y<330)     //cancel
				main_window();
			if(x>310&&x<395&&y>210&&y<230)       //position
			{
				mouse_off();
				temp=310;
				setcolor(4);
				while(ch!=13)
				{
					ch=getche();
					str[0]=ch;
					outtextxy(temp,210,str);
					temp=temp+15;
					strcat(str_value,str);
				}
				a=str_value[0]-64;
				if(str_value[3]==NULL)
					b=str_value[1]-48;
				else
				{
					p=str_value[1]-48;
					q=str_value[2]-48;
					b=p*10+q;
				}
				mouse_on();
			}
			if(x>310&&x<395&&y>240&&y<260)        //power
			{
				mouse_off();
				temp=310;
				setcolor(4);
				while(ch!=13)
				{
					ch=getche();
					str[0]=ch;
					outtextxy(temp,240,str);
					temp=temp+15;
					strcat(str_value,str);
					//power=atoi(str_value);
				}
				power=str_value[0]-48;
				mouse_on();
			}
			if(x>310&&x<395&&y>270&&y<290)       //destination
			{
				mouse_off();
				temp=310;
				setcolor(4);
				while(ch!=13)
				{
					ch=getche();
					str[0]=ch;
					outtextxy(temp,270,str);
					temp=temp+15;
					strcat(str_value,str);
				}
				e=str_value[0]-64;
				if(str_value[3]==NULL)
					f=str_value[1]-48;
				else
				{
					p=str_value[1]-48;
					q=str_value[2]-48;
					f=p*10+q;
				}
				mouse_on();
			}
			if(x>310&&x<380&&y>310&&y<330)     //ok
			{
				temp=1;
				for(i=1;i<=power;i++)
					temp*=arr[a][b];
				arr[e][f]=temp;
				sprintf(str_out,"%.4g",arr[e][f]);
				outtextxy((e-1)*50+20,(f-1)*15+125,str_out);
				main_window();
				//error_mess();
			}
		}
	}
}
void error_mess()
{
	mouse_off();
	sound(764);
	delay(500);
	nosound();
	setfillstyle(1,4);
	bar(245,205,350,300); //back ground
	setfillstyle(1,5);
	bar(250,210,345,295); //fore ground
	setfillstyle(1,8);
	bar(265,270,330,290);  //ok

	setcolor(1);
	outtextxy(270,210,"ERROR");
	outtextxy(250,230,"OPERATION");
	setcolor(15);
	outtextxy(285,268,"OK");
	mouse_on();
	while(1)
	{
		if(left_button_pressed())
		{
			get_position(&x,&y);

			if(x>265&&x<330&&y>270&&y<290)     //ok
				main_window();
		}
	}
}
/*void file_save()
{
	mouse_off();
	int i,j;
	FILE *fp;
	fp=fopen("project.bmp","w");
	for(i=Ymin;i<Ymax;i++)
		for(j=Xmin;j<Xmax;j++)
			fprintf(fp,"%d\t",(int)getpixel(j,i));
	fclose(fp);
	mouse_on();
}
void file_open()
{
	mouse_off();
	int i,j,pix=15;
	FILE *fp;
	fp=fopen("project.bmp","r");
	while(fscanf(fp,"%d",&pix)!=EOF)
		putpixel(j,i,pix);
	fclose(fp);
	mouse_on();
} */
/*
void file_save(void)
 {
  mouse_off();
  settextstyle(7,0,1);
  int i=Ymin,j=Xmin;
  FILE *f;
  f=fopen("Paint.txt","w");
  int k=0;
  for(i=Ymin;i<Ymax;i++)
   {
	for(j=Xmin;j<Xmax;j++)
	 {
	  fprintf(f,"%d\n",(int)getpixel(j,i));
	  if(j==Xmin)
	   {
	setcolor(14);
	line(Xmin+k+5,Ymax+4,Xmin+k+5,Ymax+26);
	k++;
	   }
	 }
	setcolor(5);
	outtextxy(Xmin+10,Ymax+2,"Please wait while saving image...");
   }
  fclose(f);
  setcolor(2);
  setfillstyle(1,8);

  bar(Xmin+1,Ymax+2,Xmax-1,Ymax+28);
  settextstyle(0,0,0);
  mouse_on();
}


void file_open(void)
 {
  mouse_off();
  settextstyle(7,0,1);
  int i=Ymin,j=Xmin;
  FILE *f;
  f=fopen("Paint.txt","r");
  int pix=15,k=0;
  while(fscanf(f,"%d",&pix)!=EOF)
   {
	putpixel(j,i,pix);
	if(j==Xmax)
	 {
	  setcolor(14);
	  line(Xmin+k+5,Ymax+4,Xmin+k+5,Ymax+26);
	  k++;
	 }
	if(j>=Xmax)
	 {
	  j=125;
	  setcolor(5);
	  outtextxy(Xmin+10,Ymax+2,"Please wait while opening image...");
	  i++;
	 }
	if(i>=Ymax)
	 {
	  break;
	 }
	if(kbhit())
	{
	 break;
	}
   j++;
  }
  fclose(f);
  setcolor(2);
  setfillstyle(1,8);
  bar(Xmin+1,Ymax+2,Xmax-1,Ymax+28);
  settextstyle(0,0,0);
  mouse_on();
} */

