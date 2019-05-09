#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

//   map[y][x] Spieler 14/10
char map[26][30] = {	"1222222222#222222222#",
						"#         #         #",
						"# 12# 12# # 12# 12# #",
						"# # # # # # # # # # #",
						"# #2# #2# # #2# #2# #",
						"#                   #",
						"# 12# # 1222# # 12# #",
						"# #2# # #2#2# # #2# #",
						"#     #   #   #     #",
						"#222# #2# # #2# #222#",
						"    # #       # #    ",
						"    # # #---# # #    ",
						"#222# # #   # # #222#",
						"        #222#        ",
						"#222# #   O   # #222#",
						"    # # 1222# # #    ",
						"1222# # #2#2# # #222#",
						"#         #         #",
						"# #2# #2# # #2# #2# #",
						"#   #           #   #",
						"#2# # # 12#2# # # 12#",
						"#2# # # #2#2# # # #2#",
						"#     #   #   #     #",
						"# #222#2# # #2#222# #",
						"#                   #",
						"#2222222222222222222#", };

void RenderMap()
{
	for (int y = 0; y < 27; y++)
	{

		for (int x = 0; x < 31; x++)
		{

		}

	}
}
void Logic(int px, int py)
{
	system(" CLS ");
	for (int i = 0; i < 27; i++)
	{
		printf("%s\n", map[i]);
	}
	printf("W = HOCH  | S = RUNTER");
	printf("A = LINKS | D = RECHTS");
	switch (dir)
	{
	case LEFT:
		if (map[py][px - 1] != '#')
		{
			map[py][px] = ' ';
			px--;
			map[py][px] = 'O';
		}
		break;
	case RIGHT:
		if (map[py][px + 1] != '#')
		{
			map[py][px] = ' ';
			px++;
			map[py][px] = 'O';
		}
		break;
	case UP:
		if (map[py - 1][px] != '#')
		{
			map[py][px] = ' ';
			py--;
			map[py][px] = 'O';
		}
		break;
	case DOWN:
		if (map[py + 1][px] != '#')
		{
			map[py][px] = ' ';
			py++;
			map[py][px] = 'O';
		}
		break;
	}

}
void Input(int px, int py, int running)
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'W':
		case 'w':
			if (map[py - 1][px] != '#')
			{
				dir = UP;
			}
			break;
		case 'A':
		case 'a':
			if (map[py][px - 1] != '#')
			{
				dir = LEFT;
			}
			break;
		case 'D':
		case 'd':
			if (map[py][px + 1] != '#') {
				dir = RIGHT;
			}
			break;
		case 'S':
		case 's':
			if (map[py + 1][px] != '#')
			{
				dir = DOWN;
			}
			break;
		case 'x':
			running = 1;
			break;

		}
	}
}
int main()
{
	
	int x = 14;
	int y = 10;
	int running = 0;
	
	system("mode 22, 30");

	RenderMap();
	Sleep(500);
	while (running == 0)
	{
		Logic(y, x);
		Input(y, x, running);
		Sleep(75);
		
	}
	return 0;
}
