#include <windows.h>
#include <time.h>
#include <string>
#include <stdio.h>
#include <conio.h>

char menu[4][20] = { " ",
					"SPIELEN",
					"OPTIONE",
					"EXIT" };
int x = 1;
int keyP;
bool running = false;
HANDLE  hConsole;

void drawMenu() {
	for (int display = 0; display < 4; display++) {
		if (display == x) {
			SetConsoleTextAttribute(hConsole, 10);
			printf("%s\n", menu[display]);
			SetConsoleTextAttribute(hConsole, 15);
		}
		if (display != x) {
			printf("%s\n", menu[display]);
		}
	}
}
void input() {
	keyP = _getch();
	switch (keyP)
	{
	case 119:
		x--;
		if (x == 0) { x = 1; }
		break;
	case 115:
		x++;
		if (x == 4) { x = 3; }
		break;
	}
}

int main()
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	while (!running) {
		system("cls");
		drawMenu();
		input();
	}
}
