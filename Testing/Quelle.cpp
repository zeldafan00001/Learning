#include <windows.h>
#include <time.h>
#include <string>
#include <stdio.h>
#include <conio.h>

using namespace std;
	
	//  [y][x]
char map[10][10] = {"######",
					"#X   #",
					"#    #",
					"#   X#",
					"######" };

int cordY[4], tempY;
int cordX[4], tempX;
int xe2, ye2;
int s;
int direction[4]; 
// 1 UP // 2 DOWN

bool running = false;

void setEnemCords()
{
	cordY[0] = 1; cordX[0] = 1;	
	cordY[1] = 3; cordX[1] = 4;

	direction[0] = 2;
	direction[1] = 1;

}
void drawMap()
{
	for (int d = 0; d < 5; d++)
	{
		printf("%s\n", map[d]);
	}
}
void enemMove()
{
	for (s = 0; s < 2; s++)
	{
		tempY = cordY[s];	tempX = cordX[s];

		if (direction[s] == 1) // Hoch laufen
		{
			if (map[tempY - 1][tempX] != '#')
			{
				map[tempY][tempX] = ' ';
				tempY--;
				map[tempY][tempX] = 'X';
				cordY[s] = tempY;
				cordX[s] = tempX;
			}
			else //(map[tempY - 1][tempX] == '#') 
			{
				direction[s] = 2;
			}
		} // Hoch bewegen!

		if (direction[s] == 2) // Runter laufen
		{
			if (map[tempY + 1][tempX] != '#')
			{
				map[tempY][tempX] = ' ';
				tempY++;
				map[tempY][tempX] = 'X';
				cordY[s] = tempY;
				cordX[s] = tempX;
			}
			else //(map[tempY + 1][tempX] == '#')
			{
				direction[s] = 1;
			}
		} // Runter Bewegen

	}
}
int main()
{
	setEnemCords();
	while (!running)
	{
		system("cls");
		drawMap();
		enemMove();
		Sleep(500);
	}

	system("cls");
	return 0;
}
