#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>

//   map[y][x] 
char map[13][30] = {"#############################",
					"#    #                     X#", 
					"# P      #X                 #",
					"#    #                     X#",
					"#########################   #",
					"#                           #",
					"#                           #",
					"#                           #",
					"#                           #",
					"#                           #",
					"#                           #",
					"#                           #",
					"#############################"};
// Spieler
int y = 2;
int x = 2;
// Gegner
int cordY[4], tempY;
int cordX[4], tempX;
int s;
int direction[4];

bool running = false;


void draw() {
	system("cls");
	for (int display = 0; display < 13; display++) {
		printf("%s\n", map[display]);
	}
	printf("CORDS : Y:%d | X:%d\n\nSteuerung :\n", y + 1, x + 1);
	printf("W - HOCH  | A - RUNTER\n");
	printf("S - LINKS | D RECHTS\n");
	printf("X = EXIT");
}

void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			if (map[y][x - 1] != '#')
			{
				if (map[y][x - 1] == 'X') {
					map[y][x] = ' ';
					x--;
					map[y][x] = 'X';
					running = true;
				}
				if (map[y][x - 1] == ' ') {
					map[y][x] = ' ';
					x--;
					map[y][x] = 'P';
				}
			}
			break;
		case 'd':
			if (map[y][x+1] != '#')
			{
				if (map[y][x+1] == 'X') {
					map[y][x] = ' ';
					x++;
					map[y][x] = 'X';
					running = true;
				}
				if (map[y][x+1] == ' ') {
					map[y][x] = ' ';
					x++;
					map[y][x] = 'P';
				}
			}
			break;
		case 'w':
			if (map[y-1][x] != '#')
			{
				if (map[y-1][x] == 'X') {
					map[y][x] = ' ';
					y--;
					map[y][x] = 'X';
					running = true;
				}		
				if (map[y-1][x] == ' ') {
					map[y][x] = ' ';
					y--;
					map[y][x] = 'P';
				}
			}
			break;
		case 's':
			if (map[y + 1][x] != '#')
			{
				if (map[y + 1][x] == 'X') {
					map[y][x] = ' ';
					y++;
					map[y][x] = 'X';
					running = true;
				}
				if (map[y + 1][x] == ' ') {
					map[y][x] = ' ';
					y++;
					map[y][x] = 'P';
				}
			}
			break;
		case 'x':
			running = true;
			break;
		}
	}
}
void setEnemCords()
{
	cordY[0] = 1; cordX[0] = 27;
	cordY[1] = 2; cordX[1] = 10;
	cordY[2] = 3; cordX[2] = 27;
	direction[0] = 4;
	direction[1] = 3;
	direction[2] = 4;

}
void enemMove()
{
	for (s = 0; s < 4; s++)
	{
		tempY = cordY[s];	tempX = cordX[s];
		if (direction[s] == 1) // Hoch laufen
		{
			if (map[tempY-1][tempX] == 'P')
			{
				map[tempY][tempX] = ' ';
				tempY--;
				map[tempY][tempX] = 'X';
				running = true;
			}
			if (map[tempY - 1][tempX] != '#' && map[tempY - 1][tempX] != 'P')
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
			if (map[tempY+1][tempX] == 'P')
			{
				map[tempY][tempX] = ' ';
				tempY--;
				map[tempY][tempX] = 'X';
				running = true;
			}
			if (map[tempY + 1][tempX] != '#' && map[tempY + 1][tempX] != 'P')
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
		} // RUNTER Bewegen

		if (direction[s] == 3) // RECHTS laufen
		{
			if (map[tempY][tempX+1] == 'P')
			{
				map[tempY][tempX] = ' ';
				tempX++;
				map[tempY][tempX] = 'X';
				running = true;
			}
			if (map[tempY][tempX+1] != '#' && map[tempY][tempX+1] != 'P')
			{
				map[tempY][tempX] = ' ';
				tempX++;
				map[tempY][tempX] = 'X';
				cordY[s] = tempY;
				cordX[s] = tempX;
			}
			else 
			{
				direction[s] = 4;
			}
		} // RECHTS Bewegen

		if (direction[s] == 4) // LINKS laufen
		{
			if (map[tempY][tempX-1] == 'P')
			{
				map[tempY][tempX] = ' ';
				tempY--;
				map[tempY][tempX] = 'X';
				running = true;
			}
			if (map[tempY][tempX-1] != '#' && map[tempY][tempX-1] != 'P')
			{
				map[tempY][tempX] = ' ';
				tempX--;
				map[tempY][tempX] = 'X';
				cordY[s] = tempY;
				cordX[s] = tempX;
			}
			else 
			{
				direction[s] = 3;
			}
		} // LINKS Bewegen

	}
}
int main()
{
	setEnemCords();
	while (!running)
	{
		draw();
		Input();
		enemMove();
		Sleep(50);
	}


	return 0;

}