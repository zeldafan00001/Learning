#include <windows.h>
#include <time.h>
#include <string>
#include <stdio.h>
#include <conio.h>

using namespace std;
	
	//  [y][x]
char map[4][4] = {	"###",
					"###",
					"###" };

int cordY[4], tempY;
int cordX[4], tempX;

int main()
{
	cordY[0] = 0; cordX[0] = 0;
	cordY[1] = 1; cordX[1] = 1;
	cordY[2] = 2; cordX[2] = 2;

	for (int d = 0; d < 4; d++)
	{
		printf("%s\n", map[d]);
	}
	for (int s = 0; s < 4; s++)
	{

		tempY = cordY[s]; tempX = cordX[s];
		map[tempY][tempX] = 'X';
		printf("Y%d  X%d\n", tempY, tempX);
		Sleep(1500);
		for (int d = 0; d < 4; d++)
		{
			printf("%s\n", map[d]);
		}
		printf("\n\n");
	}

	getchar();
	return 0;
}