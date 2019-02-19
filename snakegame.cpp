#include<iostream>
#include<stdlib.h>
#include<vector>
#include<windows.h>
#include<conio.h>
using namespace std;
static int length = 0;
class board
{
	public :
		char a[100][100];
		int length,breadth;
		//create the board
		board()
		{
			length=100;
			breadth=50;
			for(int i=0;i<breadth;i++)
			{
				for(int j=0;j<length;j++)
				{
					if(i==0)
					a[i][j]='1';
					else if(i==breadth-1)
					a[i][j]='1';
					else if(j==0)
					a[i][j]='1';
					else if(j==length-1)
					a[i][j]='1';
					else
					a[i][j]=' ';
				}
			}
		}
		//print the board
		void printBoard()
		{
			for(int i=0;i<breadth;i++)
			{
				for(int j=0;j<length;j++)
				{
					cout<<a[i][j];
				}
				cout<<endl;
			}
		}
};


class food
{
	public :
		int posb;
		int posl;
		char value;
		food()
		{
			value = 'f';
		}
		//setting food position for board
		void foodLoc(board &b)
		{
			posb = 25;
			posl = 27;
		}
		//moving food to board
		void moveToBoard(board &b)
		{
			b.a[posb][posl] = value;
	 	}
};


class body
{
	public :
		char value;
		int x,y;
		body()
		{
			value = '#';
		}
		void setLoc()
		{
			x=25;
			y=25;
		}
		void moveToBoard(board &bo)
		{
			bo.a[x][y]='#';
		}
};
void refresh(board &bo,food &fo)
{
	for(int i=0;i<bo.breadth;i++)
	{
		for(int j=0;j<bo.length;j++)
		{
			if(i==0)
			bo.a[i][j]='1';
			else if(i==bo.breadth - 1)
			bo.a[i][j]='1';
			else if(j==0)
			bo.a[i][j]='1';
			else if(j==bo.length -1)
			bo.a[i][j]='1';
			else
			bo.a[i][j]=' ';
		}
	}
	bo.a[fo.posb][fo.posl] = fo.value;
}

void leftShift(body b[],board &bo,food &fo)
{
	refresh(bo,fo);
	int prevx = b[0].x;
	int prevy = b[0].y;
	b[0].y--;
	b[0].moveToBoard(bo);
	
	
	if(b[0].x == fo.posb && b[0].y == fo.posl)
	{
		length++;
		fo.posb = rand()%bo.breadth + 1;
		fo.posl = rand()%bo.length + 1;
		fo.moveToBoard(bo);
	}
	
	
	for(int i=1;i<=length;i++)
	{
		int py = b[i].y;
		int px = b[i].x;
		//giving co-ordinates to snake body	
		b[i].y = prevy;
		b[i].x = prevx;
		
		prevy = py;
		prevx = px;
		//pushing value to board at given coordinates
		b[i].moveToBoard(bo);
	}
}
void downShift(body b[],board &bo,food &fo)
{
	refresh(bo,fo);
	int prevx = b[0].x;
	int prevy = b[0].y;
	b[0].x++;
	b[0].moveToBoard(bo);
	if(b[0].x == fo.posb && b[0].y == fo.posl)
	{
		length++;
		fo.posb = rand()%bo.breadth + 1;
		fo.posl = rand()%bo.length + 1;
		fo.moveToBoard(bo);
	}
	
	
	for(int i=1;i<=length;i++)
	{
		int py = b[i].y;
		int px = b[i].x;
		
		b[i].y = prevy;
		b[i].x = prevx;
		
		prevy = py;
		prevx = px;
		
		b[i].moveToBoard(bo);
	}
}
void upShift(body b[],board &bo,food &fo)
{
	refresh(bo,fo);
	int prevx = b[0].x;
	int prevy = b[0].y;
	b[0].x--;
	b[0].moveToBoard(bo);
	if(b[0].x == fo.posb && b[0].y == fo.posl)
	{
		length++;
		fo.posb = rand()%bo.breadth + 1; 
		fo.posl = rand()%bo.length + 1;
		fo.moveToBoard(bo);
	}
	
	
	for(int i=1;i<=length;i++)
	{
		int py = b[i].y;
		int px = b[i].x;
		
		b[i].y = prevy;
		b[i].x = prevx;
		
		prevy = py;
		prevx = px;
		
		b[i].moveToBoard(bo);
	}
}
void rightShift(body b[],board &bo,food &fo)
{
	refresh(bo,fo);
	int prevx = b[0].x;
	int prevy = b[0].y;
	b[0].y++;
	b[0].moveToBoard(bo);
	if(b[0].x == fo.posb && b[0].y == fo.posl)
	{
		length++;
		fo.posb = rand()%bo.breadth + 1;
		fo.posl = rand()%bo.length + 1;
		fo.moveToBoard(bo);
	}
	
	
	for(int i=1;i<=length;i++)
	{
		int py = b[i].y;
		int px = b[i].x;
		
		b[i].y = prevy;
		b[i].x = prevx;
		
		prevy = py;
		prevx = px;
		
		b[i].moveToBoard(bo);
	}
}
int main()
{
	board bo;
	food fo;
	//setting food location
	fo.foodLoc(bo);
	//moving food to board
	fo.moveToBoard(bo);
	
	
	body b[100];
	//setting initial value(starting of body) of snake
	b[length].setLoc();
	b[length].moveToBoard(bo);
	
	//initially displaying the value of board
	bo.printBoard();
	
	char ch = 'a';
	
	//start moving the snake
	while(1)
	{
		if(kbhit())
		{
			ch = getch();
		}
		if(ch=='a')
		{
			system("cls");
			leftShift(b,bo,fo);
			bo.printBoard();
		}	
		if(ch == 's')
		{
			system("cls");
			downShift(b,bo,fo);
			bo.printBoard();
		}
		if(ch == 'w')
		{
			system("cls");
			upShift(b,bo,fo);
			bo.printBoard();
		}
		if(ch == 'd')
		{
			system("cls");
			rightShift(b,bo,fo);
			bo.printBoard();
		}
		if(ch == 'o')
		{
			break;
		}
	}
}
