#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>

//   map[y][x] 
char map[13][30] = {"#############################",
					"#                           #", 
					"# P                         #",
					"#                           #",
					"#            X              #",
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
	for (int display = 0; display < 14; display++) {
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
			break;
		case 'x':
			running = true;
			break;
		}
	}
}

void setEnemCords()
{
	cordY[0] = 4; cordX[0] = 13;

	direction[0] = 2;

}

void enemMove()
{
	for (s = 0; s < 1; s++)
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
		} // Runter Bewegen

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


}