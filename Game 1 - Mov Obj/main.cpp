#include <windows.h>
#include <time.h>
#include <string>
#include <stdio.h>
#include <conio.h>

// | W = y-- | S = y++ | A = x-- | S = x++ || 1(A) = x-- | 2(D) = x ++| 3(W) = y-- | 4(D) = y++ |
//   map[y][x] 
char map[10][20] = { "\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1",
					"\xB1      \xB1\xB1         \xB1",
					"\xB1               \xB1\xB1\xB1",
					"\xB1  \xFE              \xB1",
					"\xB1        \xB1\xB1       \xB1",
					"\xB1                 \xB1",
					"\xB1 \xB1\xB1         X    \xB1",
					"\xB1      \xB1\xB1       \xB1\xB1\xB1",
					"\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1" };

// SPIELER
int y = 3;
int x = 3;
int y2;
int x2;
// BOT
int gy = 6;
int gx = 13;
int gy2;
int gx2;



int pointY, pointX, point, pfield = 1, score = 0;
int randWalk;

bool gameover = false;
int keyP;
char keyPC;
HANDLE  hConsole;

void draw() {
	for (int display = 0; display < 9; display++) {
		printf("%s\n", map[display]);
	}
	printf("CORDS : Y:%d | X:%d\nScore: %d\n%d\nSteuerung :\n", y + 1, x + 1, score, randWalk);
	printf("W - HOCH  | A - RUNTER\n");
	printf("S - LINKS | D RECHTS\n");
	printf("X = EXIT");
}

void points() {
	time_t te;
	te = time(NULL);
	srand(te);

	pointY = rand() % 9;
	pointX = rand() % 19;

	while (map[pointY][pointX] == ' ' || map[pointY][pointX] == 'P')
	{
		if (map[pointY][pointX] == ' ' && pfield == 1) {
			map[pointY][pointX] = 'P';
			pfield = 0;
		}
		if (pfield == 0) {
			break;
		}
	}

}

void botEnemy() {
	// | 0(A) = x-- | 1(D) = x++ | 2(W) = y-- | 3(S) = y++ |
	time_t te;
	te = time(NULL);
	srand(te);
	randWalk = rand() % 4;
	if (randWalk == 0) // A
	{
		gx2 = gx - 1;
		if (map[gy][gx2] == ' ' || map[gy][gx2] == 'P')
		{
			if (map[gy][gx2] == 'P') {
				map[gy][gx] = ' ';
				gx--;

				map[gy][gx] = 'X';
				pfield = 1;
			}
			if (map[gy][x2] == ' ') {
				map[gy][gx] = ' ';
				gx--;
				map[gy][gx] = 'X';
			}
		}
	}
	if (randWalk == 1) // D
	{
		gx2 = gx + 1;
		if (map[gy][gx2] == ' ' || map[gy][gx2] == 'P')
		{
			if (map[gy][gx2] == 'P') {
				map[gy][gx] = ' ';
				gx++;
				map[gy][gx] = 'X';
				pfield = 1;
			}
			if (map[gy][gx2] == ' ') {
				map[gy][gx] = ' ';
				gx++;
				map[gy][gx] = 'X';
			}
		}
	}
	if (randWalk == 2) // W
	{
		gy2 = gy - 1;
		if (map[gy2][gx] == ' ' || map[gy2][gx] == 'P')
		{
			if (map[gy2][gx] == 'P') {
				map[gy][gx] = ' ';
				gy--;
				map[gy][gx] = 'X';
				pfield = 1;
			}
			if (map[gy2][gx] == ' ') {
				map[gy][gx] = ' ';
				gy--;
				map[gy][gx] = 'X';
			}
		}
	}
	if (randWalk == 3) // S
	{
		gy2 = gy + 1;
		if (map[gy2][gx] == ' ' || map[gy2][gx] == 'P')
		{
			if (map[gy2][gx] == 'P') {
				map[gy][gx] = ' ';
				gy++;
				map[gy][gx] = 'X';
				pfield = 1;
			}
			if (map[gy2][gx] == ' ') {
				map[gy][gx] = ' ';
				gy++;
				map[gy][gx] = 'X';
			}
		}
	}
}

void input() {

	keyP = _getch();

	if (keyP == 'W' || keyP == 'w') {
		y2 = y - 1;
		if (map[y2][x] == ' ' || map[y2][x] == 'P' || map[y2][x] == 'X')
		{
			if (map[y2][x] == 'X') {
				map[y][x] = ' ';
				y++;
				map[y][x] = 'X';
				gameover = true;
			}
			if (map[y2][x] == 'P') {
				map[y][x] = ' ';
				y--;
				map[y][x] = '\xFE';
				pfield = 1;
				score++;
			}
			if (map[y2][x] == ' ') {
				map[y][x] = ' ';
				y--;
				map[y][x] = '\xFE';
			}
		}
	}
	if (keyP == 'S' || keyP == 's') {
		y2 = y + 1;
		if (map[y2][x] == ' ' || map[y2][x] == 'P' || map[y2][x] == 'X')
		{
			if (map[y2][x] == 'X') {
				map[y][x] = ' ';
				y++;
				map[y][x] = 'X';
				gameover = true;
			}
			if (map[y2][x] == 'P') {
				map[y][x] = ' ';
				y++;
				map[y][x] = '\xFE';
				pfield = 1;
				score++;
			}
			if (map[y2][x] == ' ') {
				map[y][x] = ' ';
				y++;
				map[y][x] = '\xFE';
			}
		}
	}
	if (keyP == 'A' || keyP == 'a') {
		x2 = x - 1;
		if (map[y][x2] == ' ' || map[y][x2] == 'P' || map[y][x2] == 'X')
		{
			if (map[y][x2] == 'X') {
				map[y][x] = ' ';
				y++;
				map[y][x] = 'X';
				gameover = true;
			}
			if (map[y][x2] == 'P') {
				map[y][x] = ' ';
				x--;

				map[y][x] = '\xFE';
				pfield = 1;
				score++;
			}
			if (map[y][x2] == ' ') {
				map[y][x] = ' ';
				x--;
				map[y][x] = '\xFE';
			}
		}
	}
	if (keyP == 'D' || keyP == 'd') {
		x2 = x + 1;
		if (map[y][x2] == ' ' || map[y][x2] == 'P' || map[y][x2] == 'X')
		{
			if (map[y][x2] == 'X') {
				map[y][x] = ' ';
				y++;
				map[y][x] = 'X';
				gameover = true;
			}
			if (map[y][x2] == 'P') {
				map[y][x] = ' ';
				x++;
				map[y][x] = '\xFE';
				pfield = 1;
				score++;
			}
			if (map[y][x2] == ' ') {
				map[y][x] = ' ';
				x++;
				map[y][x] = '\xFE';
			}
		}
	}
	if (keyP == 'X' || keyP == 'x') {
		exit(-1);
	}
}


int main()
{

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("mode 30, 17");
	while (gameover == false) {
		system("cls");
		points();
		draw();
		input();
		botEnemy();


	}
}