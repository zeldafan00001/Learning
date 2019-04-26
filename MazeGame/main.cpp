#include <windows.h>
#include <time.h>
#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;
HANDLE  hConsole;

//   map[y][x]
char map[13][30] = {"#############################", //0
					"#   #                      X#", //1
					"# P    #X      #R#X         #", //2
					"#   #                      X#", //3
					"#########################   #", //4
					"#                   #RRR#   #", //5
					"#                   #X      #", //6
					"#                   #      X#", //7
					"#                   #X      #", //8
					"#                   #      X#", //9
					"# Z                 #X      #", //10
					"#                           #",
					"#############################" };
// Spieler
int y = 2;
int x = 2;
// Gegner
int cordY[10], tempY;
int cordX[10], tempX;
int s;
int direction[10];
bool running = false;
int punkte = 500;
bool winb = false;

void draw() {
	system("cls");
	//for (int display = 0; display < 13; display++) {
	//	printf("%s\n", map[display]);
	//}
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 30; j++) {
			if (map[i][j] == 'X')
			{
				SetConsoleTextAttribute(hConsole, 12);
				cout << map[i][j];
				SetConsoleTextAttribute(hConsole, 15);
			}
			if (map[i][j] == 'R')
			{
				SetConsoleTextAttribute(hConsole, 10);
				cout << map[i][j];
				SetConsoleTextAttribute(hConsole, 15);
			}
			if (map[i][j] != 'R' && map[i][j] != 'X')
			{
				cout << map[i][j];
			}
		}
		cout << endl;
	}
	
	printf("CORDS : Y:%d | X:%d\nPUNKTE : %d \nSteuerung :\n", y + 1, x + 1, punkte);
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
					running = true;
				}
				if (map[y][x - 1] == ' ') {
					punkte -= 10;
					map[y][x] = ' ';
					x--;
					map[y][x] = 'P';
				}
				if (map[y][x - 1] == 'Z') { // for Z
					winb = true;
					running = true;
				}
				if (map[y][x - 1] == 'R') // POINTS
				{
					punkte += 50;
					map[y][x] = ' ';
					x--;
					map[y][x] = 'P';
				}
			}
			break;
		case 'd':
			if (map[y][x + 1] != '#')
			{
				if (map[y][x + 1] == 'X') {
					running = true;
				}
				if (map[y][x + 1] == ' ') {
					punkte -= 10;
					map[y][x] = ' ';
					x++;
					map[y][x] = 'P';
				}
				if (map[y][x+1] == 'Z') { // for Z
					winb = true;
					running = true;
				}
				if (map[y][x + 1] == 'R') // POINTS
				{
					punkte += 50;
					map[y][x] = ' ';
					x++;
					map[y][x] = 'P';
				}
			}
			break;
		case 'w':
			if (map[y - 1][x] != '#')
			{
				if (map[y - 1][x] == 'X') {
					running = true;
				}
				if (map[y - 1][x] == ' ') {
					punkte -= 10;
					map[y][x] = ' ';
					y--;
					map[y][x] = 'P';
				}
				if (map[y - 1][x] == 'Z') { // for Z
					winb = true;
					running = true;
				}
				if (map[y-1][x] == 'R') // POINTS
				{
					punkte += 50;
					map[y][x] = ' ';
					y--;
					map[y][x] = 'P';
				}
			}
			break;
		case 's':
			if (map[y + 1][x] != '#')
			{
				if (map[y + 1][x] == 'X') { // Enem
					running = true;
				}
				if (map[y + 1][x] == ' ') { // Nor MOV
					punkte -= 10;
					map[y][x] = ' ';
					y++;
					map[y][x] = 'P';
				}
				if (map[y + 1][x] == 'Z') { // for Z
					winb = true;
					running = true;
				}
				if (map[y+1][x] == 'R') // POINTS
				{
					punkte += 50;
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
	// 1 HOCH | 2 RUNTER | 3 RECHTS | 4 LINKS
	cordY[0] = 1; cordX[0] = 27;
	cordY[1] = 2; cordX[1] = 8;
	cordY[2] = 3; cordX[2] = 27;
	cordY[3] = 2; cordX[3] = 18;
	cordY[4] = 6; cordX[4] = 21;
	cordY[5] = 7; cordX[5] = 27;
	cordY[6] = 8; cordX[6] = 21;
	cordY[7] = 9; cordX[7] = 27;
	cordY[8] = 10; cordX[8] = 21;
	direction[0] = 4;
	direction[1] = 3;
	direction[2] = 4;
	direction[3] = 3;
	direction[4] = 3;
	direction[5] = 4;
	direction[6] = 3;
	direction[7] = 4;
	direction[8] = 3;
}
void enemMove()
{
	for (s = 0; s < 9; s++)
	{
		tempY = cordY[s];	tempX = cordX[s];
		if (direction[s] == 1) // Hoch laufen
		{
			if (map[tempY - 1][tempX] == 'P')
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
			if (map[tempY + 1][tempX] == 'P')
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
			if (map[tempY][tempX + 1] == 'P')
			{
				map[tempY][tempX] = ' ';
				tempX++;
				map[tempY][tempX] = 'X';
				running = true;
			}
			if (map[tempY][tempX + 1] != '#' && map[tempY][tempX + 1] != 'P')
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
			if (map[tempY][tempX - 1] == 'P')
			{
				map[tempY][tempX] = ' ';
				tempY--;
				map[tempY][tempX] = 'X';
				running = true;
			}
			if (map[tempY][tempX - 1] != '#' && map[tempY][tempX - 1] != 'P')
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
void win() {
	if (winb == true)
	{
		system("cls");
		printf("Gewonnen! mit %d Punkten!", punkte);
	}
	else if (winb == false)
	{
		system("cls");
		printf("Verloren!");
	}
}
int main()
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	setEnemCords();
	while (!running)
	{
		draw();
		Input();
		enemMove();
		Sleep(50);
	}
	win();
	getchar();
	return 0;
}