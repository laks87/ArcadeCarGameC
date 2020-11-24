#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<process.h>
#include<stdlib.h>
#include<iostream.h>
void main();
void check()
{

  gotoxy(5,5);
  cout<<"              ";
  gotoxy(5,6);
  cout<<"Wanna continue<y/n>";
  char choice;
  choice = getch();
  if ((choice=='y')||(choice=='Y'))
	main();
  else if((choice=='n')||(choice=='N'))
	exit(0);
  else
	gotoxy(5,5);
	cout<<"Invalid Input";
	delay(1000);
	check();
}
void clearscreen()
{
  cleardevice();
  setcolor(RED);
  rectangle(10,60,190,120);
  rectangle(199,0,450,getmaxy());
  setfillstyle(SOLID_FILL,8);
  floodfill(325,getmaxy()/2,RED);
  setcolor(RED);
  rectangle(10,200,190,250);
  gotoxy(5,15);
  cout<<"Press <Esc> to Exit";
}

void enemycar(int x, int y)
{
  setcolor(15);
  rectangle(x+1,y,x+49,y+100);
  rectangle(x+1,y+25,x+49,y+75);
  setfillstyle(1,YELLOW);
  floodfill((x+x+50)/2,(y+y+100)/2,15);
  setfillstyle(1,YELLOW);
  floodfill((x+x+50)/2,(y+y+40)/2,15);
  floodfill((x+x+50)/2,(y+y+160)/2,15);

}

void mycar(int x, int y)
{
  setcolor(15);
  rectangle(x+1,y,x+49,y+100);
  rectangle(x+1,y+25,x+49,y+75);
  setfillstyle(5,RED);
  floodfill((x+x+50)/2,(y+y+100)/2,15);
  setfillstyle(2,BLUE);
  floodfill((x+x+50)/2,(y+y+40)/2,15);
  floodfill((x+x+50)/2,(y+y+160)/2,15);

}

void myclear(int x,int y)
{
 setcolor(8);
 rectangle(x+1,y,x+49,y+100);
 rectangle(x+1,y+25,x+49,y+75);
 setfillstyle(SOLID_FILL,8);
 floodfill((x+x+50)/2,(y+y+100)/2,8);
 floodfill((x+x+50)/2,(y+y+40)/2,8);
 floodfill((x+x+50)/2,(y+y+160)/2,8);

}

void enemyclear(int x,int y)
{
 setcolor(8);
 rectangle(x+1,y,x+49,y+100);
 rectangle(x+1,y+25,x+49,y+75);

}

void main()
{
		int gdriver = DETECT,gmode;
		initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
		int x=300,y=350,ch,life=3,score=0,i=0,j;
		clearscreen();
		setcolor(RED);
		rectangle(199,0,449,getmaxy());
		setfillstyle(SOLID_FILL,8);
		floodfill(325,getmaxy()/2,RED);
		setcolor(RED);
		gotoxy(5,15);
		cout<<"Press <Esc> to Exit";
		for(int level=1;(level<=3)&&(life>0);level++)
		{
			if(level==1)
			{
				gotoxy(5,5);
				cout<<"Starts in 5 Sec";
				gotoxy(5,7);
				cout<<"All the best";
				delay(4000);
				clearscreen();
			}
			else
			{
				gotoxy(5,5);
				cout<<"Next level.";
				gotoxy(5,7);
				cout<<"Starts in 3 Sec";
				delay(3000);
				clearscreen();
			}
			if(level==1)
				j=6;
			else if(level==2)
				j=8;
			else
				j=12;
			for(i=0;(i<j)&&(life>0);i++)
			{
				if((level==3)&&(i==11))
				{
					gotoxy(5,5);
					cout<<"You Won";
					delay(1500);
					check();
				}
				setcolor(RED);
				rectangle(460,125,630,175);
				gotoxy(60,10);
				cout<<"Level = "<<level;
				rectangle(460,250,630,300);
				gotoxy(60,18);
				cout<<"Lives = "<<life;
				rectangle(460,350,630,400);
				gotoxy(60,24);
				cout<<"Score = "<<score;
				int accident=0;
				int y1=1,x1=200+((rand()%5)*50);
				int y2=1,x2=200+((rand()%5)*50);
				int y3=1,x3=200+((rand()%5)*50);
				score += 10;
				while(y1<getmaxy()-1)
				{
					enemyclear(x1,y1);
					enemyclear(x2,y2);
					enemyclear(x3,y3);
					y1++;
					y2++;
					y3++;
					if(accident == 1)
						break;
					enemycar(x1,y1);
					enemycar(x2,y2);
					enemycar(x3,y3);
					mycar(x,y);
					delay(3-level);
					if(kbhit())
					{
						mycar(x,y);
						ch=getch();
						switch(ch)
						{
							case 27: exit(0);
								break;
							case 75:myclear(x,y);
								if(x>200)
									x=x-50;
								if((x==x1)||(x==x2)||(x==x3))
								{
									if( ( ((y-y1)<100)&&((y-y1)>0)) || ( ((y-y2)<100)&&((y-y2)>0) ) )
									{
										accident=1;
										x=x+50;
										mycar(x,y);
										goto Next1;
									}
								}
								mycar(x,y);
								break;
							case 77:myclear(x,y);
								if(x<400)
									x=x+50;
								if((x==x1)||(x==x2)||(x==x3))
								{
									if( ( ((y-y1)<100)&&((y-y1)>0) ) || ( ((y-y2)<100)&&((y-y2)>0)) )
									{
										accident=1;
										x=x-50;
										mycar(x,y);
										goto Next1;
									}
								}
								mycar(x,y);
								break;
							case 72:myclear(x,y);
								if(y>0)
									y=y-5;
								mycar(x,y);
								break;
							case 80:myclear(x,y);
								if(y<getmaxy()-105)
									y=y+5;
								mycar(x,y);
								break;
						}
					}
					if((x==x1)||(x==x2)||(x==x3))
						if( ( ((y-y1)<100)&&((y-y1)>0) ) || ( ((y-y2)<100)&&((y-y2)>0) ) )
							accident=1;

					Next1:
					if(accident==1)
					{
						life =life-1;
						score -= 10;
						if(life==0)
						{
							clearscreen();
							gotoxy(5,5);
							cout<<"GAME OVER ";
							gotoxy(5,6);
							cout<<"You could not save";
							gotoxy(5,7);
							cout<<"Your Car";
							delay(2000);
							clearscreen();
							check();

						}
						clearscreen();
						gotoxy(5,5);
						cout<<"You have lost life";
						gotoxy(5,7);
						cout<<"Starts in 3 Sec";
						delay(3000);
						clearscreen();
					}
				}
			}
		}
}
