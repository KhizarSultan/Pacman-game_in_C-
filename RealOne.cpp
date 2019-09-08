#include<iostream>
#include<string>
#include<Windows.h>
#include<iomanip>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
using namespace std;
void gotoxy(int x, int y);
bool checkHardalz(int x, int y);
int key = 0;
int main()
{
	bool NotGameOver = true;
	//int x1, y1;
	char CopyMap[16][30];
	char Map[16][30] =
	{
		"-----------------------------",
		"|E--------------------------|",
		"|--------------------_______|",
		"|-------------- | --------- |",
		"|-------------- | --------- |",
		"|----||---------------||----|",
		"|----||---------------||----|",
		"|----||---------------||----|",
		"|-----------|||||-----------|",
		"|---------------------------|",
		"|---------------------------|",
		"|----------=======----------|",
		"|---------------------------|",
		"|---------------------------|",
		"|             S             |",
		"|---------------------------|",
	};
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			cout << Map[i][j];
		}
		cout << endl;
	}
	int count = 0;
	int x, y, x1, y1;
	int random = 0;
	x = 14, y = 14;
	x1 = x, y1 = y;
	int i=1, j=2;
	while (NotGameOver)
	{
		gotoxy(x1, y1);
		cout << " ";
		if (checkHardalz(x, y) == true)
		{
			gotoxy(x, y);
			cout << "S";
			key = _getch();
			x1 = x; y1 = y;
			if (key == 80)
			{
				y++;  //for Up
				count++;
			}
			if (key == 72)
			{
				y--;  //for Down
				count++;
			}
			if (key == 77)
			{
				x++;  //right
				count++;
			}
			if (key == 75)
			{
				x--;   //left
				count++;
			}
		}
		else
		{
			key = _getch();
			//x1 = x; y1 = y;
			if (key == 80)
			{
				y--;
			}
			if (key == 72)
			{
				y++;
			}
			if (key == 77)
			{
				x--;
			}
			if (key == 75)
			{
				x++;
			}
		}
	}
		system("pause>0");
}
void gotoxy(int x, int y)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { x, y };
	SetConsoleCursorPosition(hStdout, position);
}
bool checkHardalz(int x, int y)
{
	if (x >20 && y == 2)
		return false;
	else if (x > 14 && x <= 17 && y> 2 && y <= 4)
	{
		return false;
	}
	else if (x > 21 && x < 24 && y >= 5 && y <= 7)
	{
		return false;
	}
	else if (x > 4 && x < 7 && y > 4 && y<=7)
	{
		return false;
	}
	else if (x > 11 && x < 17 && y == 8)
	{
		return false;
	}
	else if (x > 10 && x < 18 && y==11)
	{
		return false;
	}
	else if (x == 0 && y >= 0 && y < 15)
	{
		return false;
	}
	else if (x >= 0 && x <= 28 && y == 0)
	{
		return false;
	}
	else if (x > 27 && y >= 0 && y <= 15)
	{
		return false;
	}
	else if (x >0 && x <= 27 && y == 15)
	{
		return false;
	}
	else 
	{
		return true;
	}
}
