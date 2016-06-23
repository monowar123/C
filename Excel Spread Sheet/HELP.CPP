void delay_text(int x,int y,char *str)
{
	char *ch;
	 for(int i=0;str[i]!='\0';i++)
	 {
		if(kbhit()) break;

		ch[0]=str[i];
		ch[1]='\0';
		outtextxy(x=x+textwidth("w"),y,ch);
		delay(30);
	 }
}
void rules(void)
{
	mouse_off();
	int j;
	setfillstyle(1,0);
	bar(0,0,640,480);

	setfillstyle(8,2);
	bar(50,60,590,420);

	setfillstyle(1,0);
	bar(65,75,575,405);
	bar(50,60,150,75);

	setcolor(6);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	settextstyle(0,0,3);
	outtextxy(320,40,"HelP");

	settextjustify(LEFT_TEXT,TOP_TEXT);
	settextstyle(0,0,2);
	outtextxy(50,60,"Page 1");

	settextstyle(0,0,1);
	setcolor(15);
	outtextxy(180,440,"Press any key to see next page...");

	j=115;
	setcolor(6);
	settextstyle(0,0,1);
	delay_text(70,j,"1) This is a simple Excel Spread Sheet.You can write your");
	delay_text(70,j+=10,"   document in this sheet and can make some calculation");
	delay_text(70,j+=10,"   through it.");
	delay_text(70,j+=20,"2) Click any part of the table and select the corresponding");
	delay_text(70,j+=10,"   box.Then it will be ready to give input.To stop press");
	delay_text(70,j+=10,"   `Enter'.");
	delay_text(70,j+=20,"3) If you click the calculative button then a small window");
	delay_text(70,j+=10,"   will appear to calculate.");
	delay_text(70,j+=20,"4) Click on the `position',`to' or `destination' box to select");
	delay_text(70,j+=10,"   them and for deselect press Enter.");
	delay_text(70,j+=20,"5) Input the started position in the `position' box and ending");
	delay_text(70,j+=10,"   position in the next box.Then in the `destination' box");
	delay_text(70,j+=10,"   input the position where the calculative result will be");
	delay_text(70,j+=10,"   stored.");
	delay_text(70,j+=20,"6) Press `ok' to perform the calculation or press `cancel'");
	delay_text(70,j+=10,"   to cancel the operation.");
	delay_text(70,j+=20,"7) If there is an error message then there is something");
	delay_text(70,j+=10,"   wrong in the inputed data or calculative data.");

	getch();
	cleardevice();
						/*page 2*/
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	settextstyle(0,0,3);
	outtextxy(320,40,"HelP");

	setfillstyle(1,0);
	bar(0,60,640,480);

	setfillstyle(8,2);
	bar(50,60,590,420);

	setfillstyle(1,0);
	bar(65,75,575,405);
	bar(50,60,150,75);

	settextjustify(LEFT_TEXT,TOP_TEXT);
	settextstyle(0,0,2);
	outtextxy(50,60,"Page 2");

	settextstyle(0,0,1);
	setcolor(15);
	outtextxy(180,440,"Press any key to back main menu...");

	j=115;
	setcolor(6);
	settextstyle(0,0,1);
	delay_text(70,j,"8) To open a new sheet click `File->New'.");
	delay_text(70,j+=30,"9) To open a saved file press `File->Open',give the file");
	delay_text(70,j+=10,"   name and press OK.");
	delay_text(70,j+=30,"10) To save the current file press `File->Save', give a");
	delay_text(70,j+=10,"   new name and press OK.");

	mouse_on();
	getch();
}